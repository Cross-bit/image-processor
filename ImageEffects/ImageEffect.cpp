//
// Created by kriz on 19.04.2022.
//

#include "ImageEffect.h"

#include "cassert"
/*ImageEffect::ImageEffect(ImageData &imageData) : _redCoef(1), _greenCoef(1), _blueCoef(1) {

}*/


ImageEffect::ImageEffect(ImageData &imageData) :
_imageData(imageData),
_redCoef(1),
_greenCoef(1),
_blueCoef(1)
{ }


void ImageEffect::SetRedCoef(int value){
    assert(("Red coef value is out of range [0,1]", !CheckCoef(value)));
    _redCoef = value;
}

void ImageEffect::SetGreenCoef(int value) {
    assert(("Green coef value is out of range [0,1]", !CheckCoef(value)));
    _greenCoef = value;
}

void ImageEffect::SetBlueCoef(int value) {
    assert(("Blue coef value is out of range [0,1]", !CheckCoef(value)));
    _blueCoef = value;
}

bool ImageEffect::CheckCoef(int value) {
    return value >= 0 && value <= 1;
}