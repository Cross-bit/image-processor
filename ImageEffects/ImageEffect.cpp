//
// Created by kriz on 19.04.2022.
//

#include "ImageEffect.h"

#include "cassert"

ImageEffect::ImageEffect(ImageData &imageData) :
_imageData(imageData),
_redCoef(1),
_greenCoef(1),
_blueCoef(1)
{ }

ImageEffect::ImageEffect(ImageData &imageData, float redCoef, float greenCoef, float blueCoef)
        : _imageData(imageData) {
    SetRedCoef(redCoef);
    SetGreenCoef(greenCoef);
    SetBlueCoef(blueCoef);
}

ImageData& ImageEffect::GetProcessedImageDataReference() const {
    return *_processedImage;
}

std::unique_ptr<ImageData> ImageEffect::GetProcessedImageData() {
    return std::move(_processedImage);
}

void ImageEffect::SetRedCoef(float value){
    assert(("Red coef value is out of range [0,1]", !CheckCoef(value)));
    _redCoef = value;
}

void ImageEffect::SetGreenCoef(float value) {
    assert(("Green coef value is out of range [0,1]", !CheckCoef(value)));
    _greenCoef = value;
}

void ImageEffect::SetBlueCoef(float value) {
    assert(("Blue coef value is out of range [0,1]", !CheckCoef(value)));
    _blueCoef = value;
}

bool ImageEffect::CheckCoef(float value) {
    return value >= 0 && value <= 1;
}