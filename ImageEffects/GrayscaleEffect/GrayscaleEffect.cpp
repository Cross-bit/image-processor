//
// Created by kriz on 19.04.2022.
//

#include "GrayscaleEffect.h"
#include <cassert>

GrayscaleEffect::GrayscaleEffect(ImageData& imageData, std::unique_ptr<GrayscaleStrategyBase>&& grayscaleStrategy )
: ImageEffect(imageData),
_effectStrategy(std::move(grayscaleStrategy))
{ }

void GrayscaleEffect::SetRedCoef(float value){
    assert(("Red coef value is out of range [0,1]", !CheckCoef(value)));
    _redCoef = value;
}

void GrayscaleEffect::SetGreenCoef(float value) {
    assert(("Green coef value is out of range [0,1]", !CheckCoef(value)));
    _greenCoef = value;
}

void GrayscaleEffect::SetBlueCoef(float value) {
    assert(("Blue coef value is out of range [0,1]", !CheckCoef(value)));
    _blueCoef = value;
}

bool GrayscaleEffect::CheckCoef(float value) {
    return value >= 0 && value <= 1;
}

GrayscaleEffect::GrayscaleEffect(ImageData &imageData,
                                 std::unique_ptr<GrayscaleStrategyBase>&& grayscaleStrategy,
                                 float redCoef, float greenCoef, float blueCoef)
: ImageEffect(imageData), _effectStrategy(std::move(grayscaleStrategy))
{
    SetRedCoef(redCoef);
    SetBlueCoef(greenCoef);
    SetGreenCoef(blueCoef);
}

void GrayscaleEffect::ProcessImageData() {
    if(_imageData.DataSize == 0)
        return;

    // copy the data to output:
    _processedImage = std::move(_effectStrategy->TransformToGrayscale(_imageData));
}