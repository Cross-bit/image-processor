#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoIdleMenuOption.h"

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

#include <cstdio>
 void tmpStoreImg(ImageData& data, const ImageFormat& format, const std::string& name){
    data.Name = data.Name + "_" + name;
    format.SaveImageData(data, "../TestRes");
}

int main() {

    ImageJPG jpgFormat;

    std::string file = "../Resources/harysek_2.jpg";

    auto res = jpgFormat.LoadImageData(file);
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
    //auto effect = imageFactory.CreateLinearGrayScale();// grayscale linear

    /*std::string inputAlpha = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,¨^`'. ";
    inputAlpha = "$@B%8&WM#;:,¨^`'. ";

    auto effect = imageFactory.CreateAsciiArtEffectByScale(inputAlpha, 100, 0.65, std::cout); // grayscale avg*/
   // auto effect = imageFactory.CreateBoxBlurConvolution(); // box blur
   // auto effect = imageFactory.CreateGaussianBlurConvolution(11, 11); // gaussian blur
    auto effect = imageFactory.CreateColorInversion(1);

    effect->ProcessImageData();
    tmpStoreImg(effect->GetProcessedImageData(), jpgFormat, "i");

    return 0;
}