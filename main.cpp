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


#include <cstdio>

int main() {

    ImageJPG jpgFormat;

    std::string file = "../Resources/parrot.jpg";

    auto res = jpgFormat.LoadImageData(file);
    if(res!= nullptr){
        std::cout << "image: " << std::endl;
        std::cout << "\tname: " << res->Name << std::endl;
        std::cout << "\tW: " << res->Width << std::endl;
        std::cout << "\tH: " << res->Height << std::endl;
    }
    else
        std::cout << "does not work" << std::endl;


    std::unique_ptr<GrayscaleStrategyBase> strategyBase = std::make_unique<LinearGrayscaleStrategy>(.2126, .7152, .0722);

//    auto effect = new GrayscaleEffect(*res, *strategyBase);

    /*auto effect = new NegativeEffect(*res, 0.5);
    effect->ApplyEffect();*/
    printf("img h: %d\n", res->Height);
    printf("ref: %d\n", res->Data[res->DataSize - 4]);
    //std::cout << "reference: " << unsigned (res->Data[2]);



    auto imgKernelTest = new ImageKernel(3);
    auto convolutionProcessor = new ConvolutionProcessor(*res, *imgKernelTest);

    convolutionProcessor->ProcessImageData();

    auto& filtered = convolutionProcessor->GetConvolutedImageData();
    filtered.Name = filtered.Name + "_c";

    jpgFormat.SaveImageData(filtered, "../Resources");

    return 0;
    /*for (int i = 0; i < res->DataSize; ++i) {
        std::cout << unsigned(res->Data[i]) << " ";
    }*/
    
    return 0;



    // set new file name:
    res->Name = res->Name + "_n";

    jpgFormat.SaveImageData(*res, "../Resources");

    /*UserMenu userMenu;
    userMenu.Update();*/

    return 0;
}