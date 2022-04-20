//
// Created by kriz on 19.04.2022.
//

#include "GrayscaleEffect.h"

GrayscaleEffect::GrayscaleEffect(ImageData& _imageData, GrayscaleStrategyBase& grayscaleStrategy )
: ImageEffect(_imageData),
_effectStrategy(grayscaleStrategy)
{}

GrayscaleEffect::GrayscaleEffect(ImageData &_imageData,
                                 GrayscaleStrategyBase& grayscaleStrategy,
                                 float redCoef, float greenCoef, float blueCoef)
: ImageEffect(_imageData), _effectStrategy(grayscaleStrategy)
{
    SetRedCoef(redCoef);
    SetBlueCoef(greenCoef);
    SetGreenCoef(blueCoef);
}

void GrayscaleEffect::ApplyEffect() {

    if(_imageData.DataSize == 0)
        return; //nothing to do todo: throw probably

    _effectStrategy.TransformToGrayscale(_imageData);
}
