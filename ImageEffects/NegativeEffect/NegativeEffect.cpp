//
// Created by kriz on 21.04.2022.
//

#include "NegativeEffect.h"

#include "cassert"
#include "math.h"

NegativeEffect::NegativeEffect(ImageData& imageData) :
ImageEffect(imageData) {
SetIntensityCoef(1);
}

NegativeEffect::NegativeEffect(ImageData &imageData, float intensityCoef) : ImageEffect(imageData)
{
    SetIntensityCoef(intensityCoef);
}

void NegativeEffect::SetIntensityCoef(float value){
    if(value < 0 || value > 1)
        assert("Intensity of negativity must be in interval [0, 1]!");

    _intensityCoef = value;
}

void NegativeEffect::ProcessImageData() {

    if(_imageData.DataSize == 0)
        return;

    for (int i = 0; i < _imageData.DataSize; ++i) {
        int dataTmp = _imageData.Data[i];
        _imageData.Data[i] = dataTmp - _intensityCoef*(2*dataTmp - 255);
                //_imageData.Data[i]*(1-2*_intensityCoef) + _intensityCoef*255; // alternative
                //((255 - _imageData.Data[i])  + (2*dataTmp - 255) * (1 - _intensityCoef)); original formula // todo: do not lose the paper with math, and put it into the documentation!
    }

}