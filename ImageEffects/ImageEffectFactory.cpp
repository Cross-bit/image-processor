//
// Created by kriz on 19.04.2022.
//

#include "ImageEffectFactory.h"

/*
 *  Ascii art effect.
 */
ImageEffectFactory::ImageEffectFactory(ImageData& imageData) : _imageData(imageData) {}

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateAsciiArtEffectByScale(std::string& inputAlphabet, int colsX, float scale, std::ostream &outputStream) {
    return std::move(std::make_unique<AsciiArtEffect>(_imageData, inputAlphabet, colsX, scale, outputStream));
}

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateAsciiArtEffectFixedTileSize(std::string& inputAlphabet, int tileWidth, int tileHeight, std::ostream &outputStream) {
    return std::move(std::make_unique<AsciiArtEffect>(_imageData, inputAlphabet, tileWidth, tileHeight, outputStream));
}

/*
 *  Convolutions.
 */

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateGaussianBlurConvolution(int kernelSize, double standardDeviasion){
    GaussianBlurImageKernel gaussianImageKernel(kernelSize, standardDeviasion);
    return std::move(std::make_unique<ConvolutionProcessor>(_imageData, std::move(gaussianImageKernel), true));
}

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateBoxBlurConvolution(int kernelSize, double standardDeviasion){
    BoxBlurImageKernel boxBlurImageKernel;
    return std::move(std::make_unique<ConvolutionProcessor>(_imageData, std::move(boxBlurImageKernel), true));
}

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateSobelConvolution(SobelImageKernel::Direction direction){
    SobelImageKernel sobelImageKernel(direction);
    return std::move(std::make_unique<ConvolutionProcessor>(_imageData, false));
}

/*
 *  Grayscale effect
 */

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateAveragedGrayScale() {
    auto algorithm = AverageGrayscaleStrategy();
    return std::move(std::make_unique<GrayscaleEffect>(_imageData, std::move(algorithm)));
}

std::unique_ptr<ImageEffect> ImageEffectFactory::LinearGrayScale() {
    auto algorithm = LinearGrayscaleStrategy();
    return std::move(std::make_unique<GrayscaleEffect>(_imageData,std::move(algorithm)));
}

/*
 *  Negative effect.
 */

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateColorInversion(float intensity) {
    return std::move(std::make_unique<NegativeEffect>(_imageData, intensity));
}