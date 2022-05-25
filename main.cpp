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
void tmpStoreImg(ImageData& data, const ImageFormat& format, const std::string& name){
    data.Name = data.Name + "_" + name;
    format.SaveImageData(data, "../TestRes");
}

int main() {
    ImageFormatFactory formatFactory;

    auto jpgFormat = formatFactory.CreateImageFormat("JPG");

    std::string file = "../Resources/cube.jpg";

    auto res = jpgFormat->LoadImageData(file);
    if(res!= nullptr){
        std::cout << "image: " << std::endl;
        std::cout << "\tname: " << res->Name << std::endl;
        std::cout << "\tW: " << res->Width << std::endl;
        std::cout << "\tH: " << res->Height << std::endl;
    }
    else
        std::cout << "does not work" << std::endl;

    ImageEffectFactory imageFactory(*res);

    //LinearGrayscaleStrategy algorithm;
    auto effect1 = imageFactory.CreateLinearGrayScale();// grayscale linear
    effect1->ProcessImageData();

    std::string inputAlpha = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,¨^`'. ";
    inputAlpha = "$@B%8&WM#;:,¨^`'. ";

    ImageEffectFactory imageFactory2(effect1->GetProcessedImageDataReference());

    //auto effect = imageFactory2.CreateAsciiArtEffectByScale(inputAlpha, 100, 0.4, std::cout); // grayscale avg*/
   // auto effect = imageFactory.CreateBoxBlurConvolution(); // box blur
    //auto effect = imageFactory.CreateGaussianBlurConvolution(11, 11); // gaussian blur
   // auto effect = imageFactory.CreateColorInversion(1);

   // -- tranformations --
 //   auto effect = imageFactory.CreateFlipTransform(FlipTransform::VERTICAL);

    //effect->ProcessImageData();

   // tmpStoreImg(effect->GetProcessedImageDataReference(), *jpgFormat, "tr");

    ImagesLibrary imagesLibrary;

    MenuGroupFactory menuGroupsFactory(imagesLibrary);

    UserMenu userMenu(menuGroupsFactory);

    userMenu.Initialize("/mnt/c/Users/kriz/CLionProjects/ImageProcessor/Resources");
    userMenu.Update();

    return 0;
}