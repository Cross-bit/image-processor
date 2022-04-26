//
// Created by kriz on 25.04.2022.
//

#include "RegularRotation.h"
#include "FlipTransform.h"
#include <cassert>

RegularRotation::RegularRotation(ImageData &imageData, int rotationAngle) :
ImageEffect(imageData),
_rotationAngle(rotationAngle)
{
    _rotatedImage = std::make_unique<ImageData>(
            imageData.Name,
            imageData.Width,
            imageData.Height,
            imageData.Channels,
            imageData.Width * imageData.Height * imageData.Channels,
            imageData.ColorSpace );

}

void RegularRotation::ProcessImageData() {

    if(_rotationAngle / 360 == 0)
        return; // nothing to do

    /* for (int i = 0; i < ; ++i) {

    }*/
}

void RegularRotation::RotateImageRightAngle() {
}

std::string RegularRotation::GenerateImageName() const{
    return _imageData.Name + std::to_string(_rotationAngle);
}

ImageData& RegularRotation::GetProcessedImageData() const {
    return _rotationAngle % 360 == 0 ? _imageData : *_rotatedImage; //
}

void RegularRotation::SetRotationAngle(int inputRotation){
    assert(("Ivalid rotation!", inputRotation % 90 == 0));

    _rotationAngle = inputRotation / 90;
}

