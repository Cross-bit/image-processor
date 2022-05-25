//
// Created by kriz on 19.04.2022.
//

#include "ImageEffectFactory.h"

/*
 *  Ascii art effect.
 */
ImageEffectFactory::ImageEffectFactory(ImageData& imageData) : _imageData(imageData) { }

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateAsciiArtEffectByScale(std::string& inputAlphabet, int colsX, float scale, std::ostream &outputStream) {
    return std::move(std::make_unique<AsciiArtEffect>(_imageData, inputAlphabet, colsX, scale, outputStream));
}

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateAsciiArtEffectFixedTileSize(std::string& inputAlphabet, int tileWidth, int tileHeight, std::ostream &outputStream) {
    return std::move(std::make_unique<AsciiArtEffect>(_imageData, inputAlphabet, tileWidth, tileHeight, outputStream));
}

/*
 *  Convolutions.
 */

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateGaussianBlurConvolution(int kernelSize, double standardDeviation) {
    auto gaussianImageKernel = std::make_unique<GaussianBlurImageKernel>(kernelSize, standardDeviation);
    return std::move(std::make_unique<ConvolutionProcessor>(_imageData, std::move(gaussianImageKernel), true));
}

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateBoxBlurConvolution() {
    auto boxBlurImageKernel = std::make_unique<BoxBlurImageKernel>();
    return std::move(std::make_unique<ConvolutionProcessor>(_imageData, std::move(boxBlurImageKernel), true));
}

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateSobelConvolution(SobelImageKernel::Direction direction){
    auto sobelImageKernel = std::make_unique<SobelImageKernel>(direction);
    return std::move(std::make_unique<ConvolutionProcessor>(_imageData, std::move(sobelImageKernel), false));
}

/*
 *  Grayscale effect
 */

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateAveragedGrayScale() {
    auto algorithm = std::make_unique<AverageGrayscaleStrategy>();
    return std::move(std::make_unique<GrayscaleEffect>(_imageData, std::move(algorithm)));
}

std::unique_ptr<GrayscaleEffect> ImageEffectFactory::CreateLinearGrayScale() {
    auto algorithm = std::make_unique<LinearGrayscaleStrategy>();
    return std::move(std::make_unique<GrayscaleEffect>(_imageData,std::move(algorithm)));
}

/*
 *  Negative effect.
 */

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateColorInversion(float intensity) {
    return std::move(std::make_unique<NegativeEffect>(_imageData, intensity));
}

/*
 * Transformations
 */

std::unique_ptr<ImageEffect> ImageEffectFactory::CreateFlipTransform(FlipTransform::Direction direction) {
    return std::move(std::make_unique<FlipTransform>(_imageData, direction));
}
