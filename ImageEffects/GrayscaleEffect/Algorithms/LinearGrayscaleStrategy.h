//
// Created by kriz on 20.04.2022.
//

#ifndef MAIN_CPP_LINEARGRAYSCALESTRATEGY_H
#define MAIN_CPP_LINEARGRAYSCALESTRATEGY_H

#include "GrayscaleStrategyBase.h"


class LinearGrayscaleStrategy : GrayscaleStrategyBase
{
public:
    LinearGrayscaleStrategy();

    virtual void TransformToGrayscale(ImageData& inputData) const = 0;
    void SetLinearParameters(float red, float green, float blue);
private:
    float _red;
    float _green;
    float _blue;
};


#endif //MAIN_CPP_LINEARGRAYSCALESTRATEGY_H
