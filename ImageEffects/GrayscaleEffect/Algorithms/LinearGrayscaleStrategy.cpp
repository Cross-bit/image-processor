//
// Created by kriz on 20.04.2022.
//

#include "LinearGrayscaleStrategy.h"

LinearGrayscaleStrategy::LinearGrayscaleStrategy() :
_red(1),
_green(1),
_blue(1) { }

void LinearGrayscaleStrategy::SetLinearParameters(float red, float green, float blue) {
    _red = red;
    _green = green;
    _blue = blue;
}

void LinearGrayscaleStrategy::TransformToGrayscale(ImageData &inputData) const {

    for (int i = 0; i < inputData.DataSize; ++i) {

    }
}