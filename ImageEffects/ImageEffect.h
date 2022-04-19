//
// Created by kriz on 19.04.2022.
//

#ifndef MAIN_CPP_IMAGEEFFECT_H
#define MAIN_CPP_IMAGEEFFECT_H

#include "../ImageLibrary/Image/ImageData.h"

#include <iostream>

class ImageEffect {
public:
    ImageEffect(ImageData& imageData);

    ImageEffect(ImageData& imageData, float r, float g, float b);

    virtual void ApplyEffect() =0;

    void SetRedCoef(float value);

    void SetGreenCoef(float value);

    void SetBlueCoef(float value);

private:
    bool CheckCoef(float value);

protected:
    ImageData& _imageData;

    float _redCoef;
    float _greenCoef;
    float _blueCoef;
};


#endif //MAIN_CPP_IMAGEEFFECT_H
