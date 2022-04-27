//
// Created by kriz on 27.04.2022.
//

#include "ApplyLinearGrayscaleOption.h"
ApplyLinearGrayscaleOption::ApplyLinearGrayscaleOption(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary) {
    _itemContent = "Linear grayscale";
}

std::unique_ptr<ImageData> ApplyLinearGrayscaleOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateLinearGrayScale();
    std::cout << imageToProcess.Name << std::endl;
    effect->ProcessImageData();
    return std::move(effect->GetProcessedImageData());
}
