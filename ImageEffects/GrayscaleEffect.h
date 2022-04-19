//
// Created by kriz on 19.04.2022.
//

#ifndef MAIN_CPP_GRAYSCALEEFFECT_H
#define MAIN_CPP_GRAYSCALEEFFECT_H

#include "ImageEffect.h"


class GrayscaleEffect : public ImageEffect{
public:
    GrayscaleEffect();

    void ApplyEffect() override;


};


#endif //MAIN_CPP_GRAYSCALEEFFECT_H
