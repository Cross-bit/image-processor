//
// Created by kriz on 20.04.2022.
//

#ifndef MAIN_CPP_LINEARGRAYSCALESTRATEGY_H
#define MAIN_CPP_LINEARGRAYSCALESTRATEGY_H

#include "GrayscaleStrategyBase.h"


class LinearGrayscaleStrategy : public GrayscaleStrategyBase
{
public:
    LinearGrayscaleStrategy();

    virtual void TransformToGrayscale(ImageData& inputData) const = 0;
    void SetLinearParameters(float red, float green, float blue);
private:
    float _redCoef;
    float _greenCoef;
    float _blueCoef;
};


#endif //MAIN_CPP_LINEARGRAYSCALESTRATEGY_H
