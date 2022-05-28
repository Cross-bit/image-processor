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
    GrayscaleEffect(ImageData& imageData, std::unique_ptr<GrayscaleStrategyBase>&& grayscaleStrategy);

    GrayscaleEffect(ImageData& imageData, std::unique_ptr<GrayscaleStrategyBase>&& grayscaleStrategy, float r, float g, float b);

    void ProcessImageData() override;

private:
    /**
     *
     */
    std::unique_ptr<GrayscaleStrategyBase> _effectStrategy;

    float _redCoef;
    float _greenCoef;
    float _blueCoef;

    void SetRedCoef(float value);

    void SetGreenCoef(float value);

    void SetBlueCoef(float value);

    bool CheckCoef(float value);
};


#endif //MAIN_CPP_GRAYSCALEEFFECT_H
