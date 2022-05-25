#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoMainMenuOption.h"

#include "ImageLibrary/ImageFormatFactory.h"

#include "ImageLibrary/ImageFormat/ImageJPG.h"

#include "ImageEffects/ImageEffect.h"
#include "ImageEffects/GrayscaleEffect/GrayscaleEffect.h"

#include "ImageEffects/GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.h"
#include "ImageEffects/GrayscaleEffect/Algorithms/LinearGrayscaleStrategy.h"
#include "ImageEffects/NegativeEffect/NegativeEffect.h"

#include "ImageEffects/Convolution/ConvolutionKernels/ImageKernel.h"
#include "ImageEffects/Convolution/ConvolutionProcessor.h"

#include "ImageEffects/Convolution/ConvolutionKernels/Blur/BoxBlurImageKernel.h"
#include "ImageEffects/Convolution/ConvolutionKernels/Blur/GaussianBlurImageKernel.h"
#include "ImageEffects/Convolution/ConvolutionKernels/Sobel/SobelImageKernel.h"

#include "ImageEffects/ASCII/AsciiArtEffect.h"

#include "ImageEffects/ImageEffectFactory.h"

#include "ImageLibrary/ImagesLibrary.h"
#include "UserMenu/MenuGroups/MenuGroupFactory.h"

#include "UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplySobelOption.h"

#include <cstdio>
#include <filesystem>
#include <unistd.h>

#include <string>
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include <limits.h>

static void tmpStoreImg(ImageData& data, const ImageFormat& format, const std::string& name){
    data.Name = data.Name + "_" + name;
    format.SaveImageData(data, "../TestRes");
}

int main() {

    auto a =  "--212";

    int l = std::stoi(a);

    return 1 ;
    ImageFormatFactory formatFactory;

    auto jpgFormat = formatFactory.CreateImageFormat("JPG");

    std::string file = "../Resources/lenna.jpg";

    auto res = jpgFormat->LoadImageData(file);
    if(res!= nullptr){
        std::cout << "image: " << std::endl;
        std::cout << "\tname: " << res->Name << std::endl;
        std::cout << "\tW: " << res->Width << std::endl;
        std::cout << "\tH: " << res->Height << std::endl;
    }
    else
        std::cout << "does not work" << std::endl;

    std::string inputAlpha = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,¨^`'. ";
    inputAlpha = "$@B%8&WM#;:,¨^`'. ";


   ImageEffectFactory imageFactory2(*res);
    auto effectGrayscale = imageFactory2.CreateLinearGrayScale();
    effectGrayscale->ProcessImageData();
    //jpgFormat->SaveImageData(*effectGrayscale->GetProcessedImageData(), "../TestRes");
    //
    auto dat = effectGrayscale->GetProcessedImageData();
    ImageEffectFactory imageFactory(*dat);

    auto effect = imageFactory.CreateAsciiArtEffectByScale(inputAlpha, 1, 1 / (double)100, std::cout);
    effect->ProcessImageData();


    return 1;

    ImagesLibrary imagesLibrary;

    MenuGroupFactory menuGroupsFactory(imagesLibrary);

    UserMenu userMenu(menuGroupsFactory);



    userMenu.Initialize("/mnt/c/Users/kriz/CLionProjects/ImageProcessor/Resources");
    userMenu.Update();

    return 0;
}