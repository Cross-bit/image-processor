//
// Created by kriz on 27.04.2022.
//

#include <unordered_set>
#include "ApplyLinearGrayscaleOption.h"
ApplyLinearGrayscaleOption::ApplyLinearGrayscaleOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary) {
    _itemContent = "Linear grayscale";
}

std::unique_ptr<ImageData> ApplyLinearGrayscaleOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateLinearGrayScale();
    effect->ProcessImageData();
    return std::move(effect->GetProcessedImageData());
}

std::string ApplyLinearGrayscaleOption::GetNewFileNameAppendix() const {
    return "_grayscale_l";
}