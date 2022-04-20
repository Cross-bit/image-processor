//
// Created by kriz on 10.03.2022.
//

#ifndef MAIN_CPP_IMAGEJPG_H
#define MAIN_CPP_IMAGEJPG_H


#include "../ImageFormat.h"
#include <jpeglib.h>
#include <setjmp.h>

//#include "../../External/includes/turbojpeg.h" todo: recreate with faster turbojpeg

class ImageJPG : public ImageFormat {
public:
    std::unique_ptr<ImageData> LoadImageData(const std::string &inpFileName) const override;
    bool SaveImageData(const ImageData &dataToSave, const std::string &outFileName) const override;

    virtual ~ImageJPG() = default;

protected:

    static const int COMPRESSION_QUALITY = 90; // jpeglib specific constant

    std::string AddExstention(const std::string &fileName) const override;

    ImageData::ColorSpaces DecodeColorSpaceMapping(int index) const override;

    int EncodeColorSpaceMapping(ImageData::ColorSpaces colorSpace) const override;

private:

    struct ErrorManager {
        jpeg_error_mgr defaultErrorManager;
        jmp_buf jumpBuffer;
    };

    static void ErrorExit(j_common_ptr cinfo);
    static void OutputMessage(j_common_ptr cinfo);

};


#endif //MAIN_CPP_IMAGEJPG_H
