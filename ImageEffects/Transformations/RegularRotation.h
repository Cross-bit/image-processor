//
// Created by kriz on 25.04.2022.
//

#ifndef MAIN_CPP_REGULARROTATION_H
#define MAIN_CPP_REGULARROTATION_H

#include <iostream>
#include <memory>

#include "../ImageEffect.h"
#include "../../ImageLibrary/Image/ImageData.h"


/**
 * Performs image rotation by multiples of 90 degree.
 */
class RegularRotation : ImageEffect {

public:
    RegularRotation(ImageData& imageData, int rotationAngle);

    void ProcessImageData() override;

    ImageData& GetProcessedImageData() const override;

    virtual std::string GenerateImageName() const;


private:
    std::unique_ptr<ImageData> _rotatedImage;
    int _rotationAngle;

    void SetRotationAngle(int inputAngle);

};


#endif //MAIN_CPP_REGULARROTATION_H
