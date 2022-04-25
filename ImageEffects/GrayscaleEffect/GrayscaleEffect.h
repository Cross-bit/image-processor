//
// Created by kriz on 19.04.2022.
//

#ifndef MAIN_CPP_GRAYSCALEEFFECT_H
#define MAIN_CPP_GRAYSCALEEFFECT_H

#include "../ImageEffect.h"

#include "Algorithms/GrayscaleStrategyBase.h"

/**
 * Filter converting image to grayscale based on provided strategy algorithm.
 */
class GrayscaleEffect : public ImageEffect {
public:
    GrayscaleEffect(ImageData& imageData, const GrayscaleStrategyBase& grayscaleStrategy);

    GrayscaleEffect(ImageData& imageData, const GrayscaleStrategyBase& grayscaleStrategy, float r, float g, float b);

    void ProcessImageData() override;

private:
    /**
     *
     */
    const GrayscaleStrategyBase& _effectStrategy;
};


#endif //MAIN_CPP_GRAYSCALEEFFECT_H
