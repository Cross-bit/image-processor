//
// Created by kriz on 19.04.2022.
//

#ifndef MAIN_CPP_IMAGEEFFECTFACTORY_H
#define MAIN_CPP_IMAGEEFFECTFACTORY_H

#include <iostream>
#include <memory>
#include <string>

#include "ImageEffect.h"
#include "ASCII/AsciiArtEffect.h"
#include "Convolution/ConvolutionProcessor.h"

#include "Convolution/ConvolutionKernels/Blur/BoxBlurImageKernel.h"
#include "Convolution/ConvolutionKernels/Blur/GaussianBlurImageKernel.h"

#include "Convolution/ConvolutionKernels/Sobel/SobelImageKernel.h"

#include "GrayscaleEffect/GrayscaleEffect.h"
#include "GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.h"
#include "GrayscaleEffect/Algorithms/LinearGrayscaleStrategy.h"
#include "NegativeEffect/NegativeEffect.h"

class ImageEffectFactory {

public:
    ImageEffectFactory(ImageData& imageData);

    /*
     *  Ascii art effect.
     */

    std::unique_ptr<ImageEffect> CreateAsciiArtEffectByScale(std::string& inputAlphabet, int colsX, float scale, std::ostream &outputStream);

    std::unique_ptr<ImageEffect> CreateAsciiArtEffectFixedTileSize(std::string& inputAlphabet, int tileWidth, int tileHeight, std::ostream &outputStream);

    /*
     *  Convolutions.
     */

    std::unique_ptr<ImageEffect> CreateGaussianBlurConvolution(int kernelSize, double standardDeviasion);

    std::unique_ptr<ImageEffect> CreateBoxBlurConvolution(int kernelSize, double standardDeviasion);

    std::unique_ptr<ImageEffect> CreateSobelConvolution(SobelImageKernel::Direction direction);

    /*
     *  Grayscale effect
     */

    std::unique_ptr<ImageEffect> CreateAveragedGrayScale();

    std::unique_ptr<ImageEffect> LinearGrayScale();

    /*
     *  Negative effect.
     */

    std::unique_ptr<ImageEffect> CreateColorInversion(float intensity);

private:
    ImageData& _imageData;

};


#endif //MAIN_CPP_IMAGEEFFECTFACTORY_H
