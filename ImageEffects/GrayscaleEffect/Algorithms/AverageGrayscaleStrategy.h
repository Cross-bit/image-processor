//
// Created by kriz on 20.04.2022.
//

#ifndef MAIN_CPP_AVERAGEGRAYSCALESTRATEGY_H
#define MAIN_CPP_AVERAGEGRAYSCALESTRATEGY_H

#include "GrayscaleStrategyBase.h"


class AverageGrayscaleStrategy : public GrayscaleStrategyBase {
public:
    void TransformToGrayscale(ImageData& inputData) const override;
};


#endif //MAIN_CPP_AVERAGEGRAYSCALESTRATEGY_H
