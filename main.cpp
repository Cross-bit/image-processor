#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoIdleMenuOption.h"

#include "ImageLibrary/ImageFormatFactory.h"
#include "External/includes/jpeglib.h"


int main() {

    UserMenu userMenu;
    userMenu.Update();
    //struct jpeg_decompress_struct info;

    struct jpeg_decompress_struct cinfo;
    /*struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);*/
    //jpeg_create_decompress(&cinfo);

    return 0;
}
