//
// Created by kriz on 10.03.2022.
//

#include "ImageJPG.h"

#include <cstdio>

#include <fstream>
#include <cstring>
#include <jpeglib.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "cassert"

std::unique_ptr<ImageData> ImageJPG::LoadImageData(const std::string &inpFileName) const {
    // todo: add error handling of some api functions (e. g. jpeg_read_header ...)
    struct jpeg_decompress_struct cinfo;
    struct ErrorManager errorManager;

    // Try to load image
    FILE* fp;
    if ((fp = std::fopen(inpFileName.c_str(), "rb")) == NULL)
        return nullptr;

    // Set up error handling

    cinfo.err = jpeg_std_error(&errorManager.defaultErrorManager);
    errorManager.defaultErrorManager.error_exit = ErrorExit;
    errorManager.defaultErrorManager.output_message = OutputMessage;

    // Setting up jump for error handling
    if (setjmp(errorManager.jumpBuffer)){

        jpeg_destroy_decompress ( &cinfo );
        fclose ( fp );
        return nullptr;
    }

    // Create decompression object
    jpeg_create_decompress ( &cinfo );

    /* Specify data source */
    jpeg_stdio_src(&cinfo, fp);

    /* Read file header */
    jpeg_read_header(&cinfo, TRUE);

    /* Decompression phase */
    jpeg_start_decompress(&cinfo);

    std::unique_ptr<ImageData> imageData = std::make_unique<ImageData>(
            std::move(ParseFileName(inpFileName)),
            cinfo.image_width,
            cinfo.image_height,
            cinfo.num_components,
            cinfo.image_width * cinfo.image_height * cinfo.num_components,
            DecodeColorSpaceMapping(cinfo.jpeg_color_space)
    );

    /* One line of image pixels in bytes */
    int rowWidth = cinfo.image_width * cinfo.num_components;

    /* Read image line by line */
    while ( cinfo.output_scanline < cinfo.output_height ) {
        uint8_t* p= &(imageData->Data)[cinfo.output_scanline * rowWidth];
        jpeg_read_scanlines(&cinfo, &p, 1);
    }

    /* Finish compression */
    jpeg_finish_decompress ( &cinfo );

    jpeg_destroy_decompress ( &cinfo );

    fclose ( fp );

    return std::move(imageData);
}

bool ImageJPG::SaveImageData(const ImageData &dataToSave, const std::string &outFileDir) const {

    struct jpeg_compress_struct cinfo;
    struct ErrorManager errorManager;

    struct jpeg_error_mgr jerr;
    FILE * fp;

    // if provided dir does not exsist
    if (!std::filesystem::exists(outFileDir)) {
        std::filesystem::create_directory(outFileDir);
    }

    cinfo.err = jpeg_std_error ( &errorManager.defaultErrorManager );
    errorManager.defaultErrorManager.error_exit = ErrorExit;
    errorManager.defaultErrorManager.output_message = OutputMessage;

    // Setting up jump for error handling
    if (setjmp(errorManager.jumpBuffer)) {
        jpeg_destroy_compress( &cinfo );

        fclose ( fp );
        return false;
    }

    /* Create compression object before opening path */
    jpeg_create_compress ( &cinfo );

    if (( fp = std::fopen (AddExstention (outFileDir + "/" + dataToSave.Name ).c_str(), "wb" ) ) == nullptr )
        return false;

    jpeg_stdio_dest ( &cinfo, fp );

    cinfo.image_width = dataToSave.Width;
    cinfo.image_height = dataToSave.Height;
    cinfo.input_components = dataToSave.Channels;
    cinfo.in_color_space =  J_COLOR_SPACE(EncodeColorSpaceMapping(dataToSave.ColorSpace));

    jpeg_set_defaults ( &cinfo );

    jpeg_set_quality ( &cinfo, COMPRESSION_QUALITY, TRUE );

    jpeg_start_compress ( &cinfo, TRUE );

    /* Size of one line of pixels (in bytes) */
    int rowWidth = cinfo.image_width * cinfo.num_components;

    while ( cinfo.next_scanline < dataToSave.Height ) {
        uint8_t* p= &(dataToSave.Data)[cinfo.next_scanline * rowWidth];
        jpeg_write_scanlines(&cinfo, &p, 1);
    }

    jpeg_finish_compress ( &cinfo );
    jpeg_destroy_compress ( &cinfo );

    return true;
}

void ImageJPG::ErrorExit(j_common_ptr cinfo) {

    /* Cinfo common struct to custom errormanager */
    ErrorManager * myerr = (ErrorManager*) cinfo -> err;

    /* Display error message */
    //(*cinfo->err->output_message)(cinfo); // todo:

    /* Return control to the setjmp point */
    longjmp ( myerr->jumpBuffer, 1 );

}

void ImageJPG::OutputMessage(j_common_ptr cinfo){
    // disable error messages
    char buffer[JMSG_LENGTH_MAX];
    (*cinfo->err->format_message) (cinfo, buffer);
    fprintf(stderr, "-> %s !!!\n", buffer);
}

std::string ImageJPG::AddExstention(const std::string &fileName) const {
    return fileName + ".jpg";
}

// -- color spaces mapping --
ImageData::ColorSpaces ImageJPG::DecodeColorSpaceMapping(int j_color_space) const {

    switch (j_color_space) {
        case JCS_UNKNOWN: assert("Unknown color space provided!");		/* error/unspecified */
        case JCS_GRAYSCALE: return ImageData::GRAYSCALE;		/* monochrome */
        case JCS_RGB: return ImageData::sRGB;		/* red/green/blue, standard RGB (sRGB) */
    }

    return ImageData::sRGB;
}

int ImageJPG::EncodeColorSpaceMapping(ImageData::ColorSpaces colorSpace) const {
    switch (colorSpace) {
        case ImageData::sRGB: return 2;
        case ImageData::GRAYSCALE: return 1;
        default: assert("This format does not support given colorspace!");
    }

    return 0;
}