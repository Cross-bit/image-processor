//
// Created by kriz on 25.04.2022.
//

#include "RegularRotation.h"
#include <cassert>

RegularRotation::RegularRotation(ImageData &imageData, int rotationAngle) :
ImageEffect(imageData),
_rotationAngle(rotationAngle)
{
    /*explicit ImageData(std::string imageName, int width, int height, int numOfChannels, int dataSize, ImageData::ColorSpaces colorSpace);
    _rotatedImage = std::make_unique<ImageData>(
            imageData.Name,
            );*/
}

void RegularRotation::ProcessImageData() {

    if(_rotationAngle / 360 == 0)
        return;

/*    for (int i = 0; i < ; ++i) {
        
    }*/
    
}

std::string RegularRotation::GenerateImageName() const{
    return _imageData.Name + std::to_string(_rotationAngle);
}

ImageData& RegularRotation::GetProcessedImageData() const
{
    return _rotationAngle / 360 == 0 ? _imageData : *_rotatedImage;
}

void RegularRotation::SetRotationAngle(int inputRotation){
    assert(("Ivalid rotation!", inputRotation % 90 == 0));

    _rotationAngle = inputRotation / 90;
}

