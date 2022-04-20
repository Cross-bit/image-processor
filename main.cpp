#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoIdleMenuOption.h"

#include "ImageLibrary/ImageFormatFactory.h"

#include "ImageLibrary/ImageFormat/ImageJPG.h"

#include "ImageEffects/ImageEffect.h"
#include "ImageEffects/GrayscaleEffect/GrayscaleEffect.h"
#include "ImageEffects/GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.h"

#include <cstdio>

int main() {

    ImageJPG jpgFormat;

    std::string file = "../Resources/cube.jpg";

    auto res = jpgFormat.LoadImageData(file);
    if(res!= nullptr){
        std::cout << "image: " << std::endl;
        std::cout << "\tname: " << res->Name << std::endl;
        std::cout << "\tW: " << res->Width << std::endl;
        std::cout << "\tH: " << res->Height << std::endl;
    }
    else
        std::cout << "does not work" << std::endl;

    std::unique_ptr<GrayscaleStrategyBase> strategyBase = std::make_unique<AverageGrayscaleStrategy>();

    auto effect = new GrayscaleEffect(*res, *strategyBase);
    effect->ApplyEffect();


    // set new file name:
    res->Name = res->Name + "_";

    jpgFormat.SaveImageData(*res, "../Resources");

    UserMenu userMenu;
    userMenu.Update();

    return 0;
}