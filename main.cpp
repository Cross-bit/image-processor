#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoIdleMenuOption.h"

#include "ImageLibrary/ImageFormatFactory.h"

#include "ImageLibrary/ImageFormat/ImageJPG.h"

#include <cstdio>

int main() {

    ImageJPG jpgFormat;

    std::string file = "../test/algo.jpg";

    auto res = jpgFormat.LoadImageData(file);
    if(res!= nullptr){
        std::cout << "image: " << std::endl;
        std::cout << "\tname: " << res->Name << std::endl;
        std::cout << "\tW: " << res->Width << std::endl;
        std::cout << "\tH: " << res->Height << std::endl;
    }
    else
        std::cout << "does not work" << std::endl;

    // set new file name:
    res->Name = res->Name + "_";

    jpgFormat.SaveImageData(*res, "../test");



    UserMenu userMenu;
    userMenu.Update();

    return 0;
}