//
// Created by kriz on 19.04.2022.
//

#include "GrayscaleEffect.h"

GrayscaleEffect::GrayscaleEffect(ImageData& imageData, const GrayscaleStrategyBase& grayscaleStrategy )
: ImageEffect(imageData),
_effectStrategy(grayscaleStrategy)
{}

GrayscaleEffect::GrayscaleEffect(ImageData &imageData,
                                 const GrayscaleStrategyBase& grayscaleStrategy,
                                 float redCoef, float greenCoef, float blueCoef)
: ImageEffect(imageData), _effectStrategy(grayscaleStrategy)
{
    SetRedCoef(redCoef);
    SetBlueCoef(greenCoef);
    SetGreenCoef(blueCoef);
}

void GrayscaleEffect::ProcessImageData() {
    if(_imageData.DataSize == 0)
        return;
    _effectStrategy.TransformToGrayscale(_imageData);
}
