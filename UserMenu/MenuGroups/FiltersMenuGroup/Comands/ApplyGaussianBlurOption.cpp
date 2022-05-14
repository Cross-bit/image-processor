//
// Created by kriz on 27.04.2022.
//

#include "ApplyGaussianBlurOption.h"
#include <sstream>

ApplyGaussianBlurOption::ApplyGaussianBlurOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary)
{
    _itemContent = "Gaussian blur";
}

bool ApplyGaussianBlurOption::ReadKernelSize(){
    std::cout << "Please enter odd positive integer representing Gaussian kernel size(def.: 3):" << std::endl;
    auto kernelInput = ReadUserInput();

    if (CheckStringIsEmpty(kernelInput)) {
        _kernelSize = 3;
        PrintInputFallback<int>(_kernelSize);
        return true;
    }

    if (kernelInput.find_first_not_of("0123456789") != std::string::npos || (stoi(kernelInput) & 1) == 0) {
        PrintError("Gaussian kernel size must be positive odd integer!");
        return false;
    }

    _kernelSize = stoi(kernelInput);
    return true;
}

bool ApplyGaussianBlurOption::ReadStandardDeviation(){
    std::cout << "Please enter standard deviation(positive double, def.: 1):" << std::endl;

    auto stdDeviation = ReadUserInput();

    if(stdDeviation == "" || !stdDeviation.find_first_not_of(" ") == std::string::npos) {
        _standardDeviation = 1;
        PrintInputFallback<int>(_standardDeviation);
        return true;
    }

    if(stdDeviation.find_first_not_of("0123456789.") != std::string::npos || std::count(stdDeviation.begin(), stdDeviation.end(), '.') > 1) {
        PrintError("Gaussian kernel size must be positive odd integer!");
        return false;
    }

    _standardDeviation = stod(stdDeviation);
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

