//
// Created by kriz on 14.05.2022.
//

#include "ApplyNegativeOption.h"

ApplyNegativeOption::ApplyNegativeOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
        ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary)
{
    _itemContent = "Negative";
}

std::unique_ptr<ImageData> ApplyNegativeOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateColorInversion(1.0f);
    effect->ProcessImageData();

    return std::move(effect->GetProcessedImageData());
}

std::string  ApplyNegativeOption::GetNewFileNameAppendix() const {
    return "_negative";
}