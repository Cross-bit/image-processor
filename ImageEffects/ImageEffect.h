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

    virtual void ApplyEffect() =0;

    void SetRedCoef(int value);

    void SetGreenCoef(int value);

    void SetBlueCoef(int value);
private:
    bool CheckCoef(int value);

protected:
    ImageData& _imageData;

    float _redCoef;
    float _greenCoef;
    float _blueCoef;
};


#endif //MAIN_CPP_IMAGEEFFECT_H
