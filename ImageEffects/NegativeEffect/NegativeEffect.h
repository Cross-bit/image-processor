//
// Created by kriz on 21.04.2022.
//

#ifndef MAIN_CPP_NEGATIVEEFFECT_H
#define MAIN_CPP_NEGATIVEEFFECT_H

#include "../ImageEffect.h"


class NegativeEffect : public ImageEffect{
public:
    void ApplyEffect() override;

    NegativeEffect(ImageData& imageData);

    NegativeEffect(ImageData& imageData, float intensityCoef);

    void SetIntensityCoef(float value);

private:
    float _intensityCoef = 1;
};


#endif //MAIN_CPP_NEGATIVEEFFECT_H