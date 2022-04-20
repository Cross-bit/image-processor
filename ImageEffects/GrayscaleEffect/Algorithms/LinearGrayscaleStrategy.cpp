//
// Created by kriz on 20.04.2022.
//

#include "LinearGrayscaleStrategy.h"

LinearGrayscaleStrategy::LinearGrayscaleStrategy() :
        _redCoef(1),
        _greenCoef(1),
        _blueCoef(1) { }

void LinearGrayscaleStrategy::SetLinearParameters(float red, float green, float blue) {
    _redCoef = red;
    _greenCoef = green;
    _blueCoef = blue;
}

void LinearGrayscaleStrategy::TransformToGrayscale(ImageData &inputData) const {

    for (int i = 0; i < inputData.DataSize; ++i) {

    }
}