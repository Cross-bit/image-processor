//
// Created by kriz on 14.05.2022.
//

#include "ApplyNegativeOption.h"

ApplyNegativeOption::ApplyNegativeOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
        ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary)
{
    _itemContent = "Negative";
}

bool ApplyNegativeOption::InitializeFilterProperties() {

    std::cout << "Enter \"intensity\" constant (def.: 1):" << std::endl;

    auto repetitionsInput = ReadUserInput();

    if (CheckStringIsEmpty(repetitionsInput) || // todo: abstract double/float check somewhere
        repetitionsInput.find_first_not_of("0123456789.") != std::string::npos
        || std::count(repetitionsInput.begin(), repetitionsInput.end(), '.') > 1) {
        _intensityConst = 1.0f;
        PrintInputFallback<float>(_intensityConst);
        return true;
    }

    _intensityConst = std::stod(repetitionsInput);

    return true;
}

std::unique_ptr<ImageData> ApplyNegativeOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    std::cout << imageToProcess.Name << std::endl; // todo: move out

    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateColorInversion(_intensityConst);
    effect->ProcessImageData();

    return std::move(effect->GetProcessedImageData());
}