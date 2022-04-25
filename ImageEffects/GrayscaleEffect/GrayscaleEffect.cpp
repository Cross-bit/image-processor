//
// Created by kriz on 19.04.2022.
//

#include "GrayscaleEffect.h"

GrayscaleEffect::GrayscaleEffect(ImageData& imageData, std::unique_ptr<GrayscaleStrategyBase>&& grayscaleStrategy )
: ImageEffect(imageData),
_effectStrategy(std::move(grayscaleStrategy))
{}

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
    _effectStrategy->TransformToGrayscale(_imageData);
}
