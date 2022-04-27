//
// Created by kriz on 25.04.2022.
//

#ifndef MAIN_CPP_FLIPTRANSFORM_H
#define MAIN_CPP_FLIPTRANSFORM_H


#include <iostream>
#include <memory>

#include "../ImageEffect.h"
#include "../../ImageLibrary/Image/ImageData.h"

/**
 * Transformation filter for fliping image along x and y axis.
 */
class FlipTransform : public ImageEffect
{
public:

    enum Direction { HORIZONTAL, VERTICAL };

    FlipTransform(ImageData& imageData, Direction flipDirection);

    void ProcessImageData() override;

    ImageData& GetProcessedImageDataReference() const override;

private:
    /**
     * Flips provided data horizontally.
     * @param imageData
     */
    void FlipHorizontally(ImageData& imageData);

    /**
     * Flips provided data vertically.
     * @param imageData
     */
    void FlipVertically(ImageData& imageData);

    Direction _flipDirection;
};


#endif //MAIN_CPP_FLIPTRANSFORM_H
