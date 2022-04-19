//
// Created by kriz on 19.04.2022.
//

#include "GrayscaleEffect.h"

GrayscaleEffect::GrayscaleEffect(ImageData &_imageData)
: ImageEffect(_imageData) { }

GrayscaleEffect::GrayscaleEffect(ImageData &_imageData, float redCoef, float greenCoef, float blueCoef)
: ImageEffect(_imageData)
{
    SetRedCoef(redCoef);
    SetBlueCoef(greenCoef);
    SetGreenCoef(blueCoef);
}


void GrayscaleEffect::ApplyEffect() {

    if(_imageData.DataSize == 0)
        return; //nothing to do

    for (int i = 0; i < _imageData.DataSize; i += _imageData.Channels) {

        int avgPixelValue;
        for (int j = i; j < i + _imageData.Channels; ++j) {
            avgPixelValue += _imageData.Data[j];
        }

        avgPixelValue /= _imageData.Channels;

        for (int j = i; j < i + _imageData.Channels; ++j) {
            _imageData.Data[j] = avgPixelValue;
        }
    }
}
