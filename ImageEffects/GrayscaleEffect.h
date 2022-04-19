//
// Created by kriz on 19.04.2022.
//

#ifndef MAIN_CPP_GRAYSCALEEFFECT_H
#define MAIN_CPP_GRAYSCALEEFFECT_H

#include "ImageEffect.h"


class GrayscaleEffect : public ImageEffect{
public:
    GrayscaleEffect(ImageData& _imageData);

    GrayscaleEffect(ImageData& _imageData, float r, float g, float b);

    void ApplyEffect() override;
};


#endif //MAIN_CPP_GRAYSCALEEFFECT_H
