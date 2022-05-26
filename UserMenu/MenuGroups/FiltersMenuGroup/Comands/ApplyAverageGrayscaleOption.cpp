//
// Created by kriz on 14.05.2022.
//

#include "ApplyAverageGrayscaleOption.h"
ApplyAverageGrayscaleOption::ApplyAverageGrayscaleOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary)
{
    _itemContent = "Average grayscale";
}

std::unique_ptr<ImageData> ApplyAverageGrayscaleOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateAveragedGrayScale();
    effect->ProcessImageData();
    return std::move(effect->GetProcessedImageData());
}

std::string ApplyAverageGrayscaleOption::GetNewFileNameAppendix() const {
    return "_grayscale_avg";
}