//
// Created by kriz on 27.04.2022.
//

#include "ApplyLinearGrayscaleOption.h"
ApplyLinearGrayscaleOption::ApplyLinearGrayscaleOption(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary) {
    _itemContent = "Linear grayscale";
}

void ApplyLinearGrayscaleOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateLinearGrayScale();

    effect->ProcessImageData();
}