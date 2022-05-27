//
// Created by kriz on 27.04.2022.
//

#include "ApplyGaussianBlurOption.h"
#include <sstream>

ApplyGaussianBlurOption::ApplyGaussianBlurOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary) {
    _itemContent = "Gaussian blur";
}

bool ApplyGaussianBlurOption::ReadKernelSize() {
    PrintLine("Please enter odd positive integer representing Gaussian kernel size(def.: 3):");

    if (!ReadUserInputNaturalNum(_kernelSize, 2) || (_kernelSize & 1) == 0) {
        _kernelSize = 3;
        PrintInputFallback<int>(_kernelSize);
        return true;
    }
    return true;
}

bool ApplyGaussianBlurOption::ReadStandardDeviation() {
    PrintLine("Please enter standard deviation(positive double >= 0.1, def.: 1.0):");

    if (!ReadUserInputDecimal(_standardDeviation, 0.1)) {
        _standardDeviation = 1.0;
        PrintInputFallback<double>(_standardDeviation);
    }
    return true;
}

bool ApplyGaussianBlurOption::InitializeFilterProperties() {
    return ReadKernelSize() && ReadStandardDeviation();
}

std::unique_ptr<ImageData> ApplyGaussianBlurOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateGaussianBlurConvolution(_kernelSize, _standardDeviation);
    effect->ProcessImageData();

    return std::move(effect->GetProcessedImageData());
}

std::string ApplyGaussianBlurOption::GetNewFileNameAppendix() const {
    return "_gauss_blur";
}
