#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoIdleMenuOption.h"

#include "ImageLibrary/ImageFormatFactory.h"

#include <jpeglib.h>

int main() {

    UserMenu userMenu;
    userMenu.Update();

    //struct jpeg_decompress_struct info;
     FILE* outfile = fopen("/tmp/test.jpeg", "wb");

     struct jpeg_compress_struct cinfo;
     struct jpeg_error_mgr       jerr;

     cinfo.err = jpeg_std_error(&jerr);
     jpeg_create_compress(&cinfo);
     jpeg_stdio_dest(&cinfo, outfile);

     cinfo.image_width      = 5;
     cinfo.image_height     = 5;
     cinfo.input_components = 3;
     cinfo.in_color_space   = JCS_RGB;

    return 0;
}
