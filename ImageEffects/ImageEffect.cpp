//
// Created by kriz on 19.04.2022.
//

#include "ImageEffect.h"

#include "cassert"

ImageEffect::ImageEffect(ImageData &imageData) :
_imageData(imageData)
{ }

ImageData& ImageEffect::GetProcessedImageDataReference() {
    return *_processedImage;
}

std::unique_ptr<ImageData> ImageEffect::GetProcessedImageData() {
    return std::move(_processedImage);
}