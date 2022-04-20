//
// Created by kriz on 20.04.2022.
//

#include "LinearGrayscaleStrategy.h"
#include <cstring>
#include <math.h>
LinearGrayscaleStrategy::LinearGrayscaleStrategy() :
    _redCoef(0.2126),
    _greenCoef(0.7152),
    _blueCoef(0.0722) { }

LinearGrayscaleStrategy::LinearGrayscaleStrategy(float redCoef, float greenCoef, float blueCoef) :
    _redCoef(redCoef),
    _greenCoef(greenCoef),
    _blueCoef(blueCoef) { }

void LinearGrayscaleStrategy::SetLinearParameters(float red, float green, float blue) {
    _redCoef = red;
    _greenCoef = green;
    _blueCoef = blue;
}

float sRGBGammaExspansion(float value_srgb){
    if(value_srgb <= 0.04045)
        return value_srgb / 12.92;
    else
        return pow(((value_srgb+0.055)/1.055), 2.4);
}

float sRGBGammaCompression(float value_srgb){
    if(value_srgb <= 0.0031308)
        return value_srgb * 12.92;
    else
        return ((pow(value_srgb, 1/2.4)*1.055) - 0.055);
}

void LinearGrayscaleStrategy::TransformToGrayscale(ImageData &inputData) const {

    for (int i = 0; i < inputData.DataSize; i += inputData.ColorChannels) {


        /*inputData.Data[i] = sRGBGammaCompression(inputData.Data[i] / (float) 255) * 255;
        continue;*/
        float res;
        res = _redCoef * sRGBGammaExspansion(inputData.Data[i] / (float) 255);
        res += _greenCoef * sRGBGammaExspansion(inputData.Data[i + 1] / (float) 255);
        res += _blueCoef * sRGBGammaExspansion(inputData.Data[i + 2] / (float) 255);

        /*res = 0.2126 * inputData.Data[i];
        res += 0.7152 * inputData.Data[i+1];
        res += 0.0722 * inputData.Data[i+2];*/

        //std::memset(&inputData.Data[i], res, inputData.ColorChannels);
        std::memset(&inputData.Data[i], sRGBGammaCompression(res) * 255, inputData.ColorChannels);
    }
}