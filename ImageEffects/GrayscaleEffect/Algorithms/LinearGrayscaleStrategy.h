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
    LinearGrayscaleStrategy(float redCoef, float greenCoef, float blueCoef);

    void TransformToGrayscale(ImageData& inputData) const override;
    void SetLinearParameters(float red, float green, float blue);
private:
    float _redCoef;
    float _greenCoef;
    float _blueCoef;
};


#endif //MAIN_CPP_LINEARGRAYSCALESTRATEGY_H
