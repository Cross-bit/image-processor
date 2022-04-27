//
// Created by kriz on 25.04.2022.
//

#include "FlipTransform.h"


FlipTransform::FlipTransform(ImageData &imageData, Direction flipDirection) :
ImageEffect(imageData),
_flipDirection(flipDirection)
{
    _processedImage = std::make_unique<ImageData>(
            imageData.Name,
            imageData.Width,
            imageData.Height,
            imageData.Channels,
            imageData.Width * imageData.Height * imageData.Channels,
            imageData.ColorSpace );
}

void FlipTransform::ProcessImageData() {

    switch (_flipDirection) {
        case HORIZONTAL:
            FlipHorizontally(_imageData);
            break;
        case VERTICAL:
            FlipVertically(_imageData);
            break;
        default:
            FlipHorizontally(_imageData);
            break;
    }
    
}

void FlipTransform::FlipHorizontally(ImageData &imageData) {

    int valuesPerRow = imageData.Channels * imageData.Width;

    for (int y = 0; y < imageData.Height; ++y) {
        for (int x = imageData.Channels; x <= valuesPerRow; x += imageData.Channels) {
            // process the pixel
            for (int i = 0; i < imageData.Channels; ++i) {
                _processedImage->Data[y * valuesPerRow + x - imageData.Channels + i] =
                        imageData.Data[(y+1) * valuesPerRow - x + i];
            }
        }
    }
}

void FlipTransform::FlipVertically(ImageData &imageData) {
    int valuesPerRow = imageData.Channels * imageData.Width;

    for (int y = 0; y < imageData.Height; ++y) {
        for (int x = 0; x < valuesPerRow; ++x) {
            _processedImage->Data[x + y * valuesPerRow] =
                    imageData.Data[x + (imageData.Height-1) * valuesPerRow -  y * valuesPerRow];
        }
    }
}

ImageData& FlipTransform::GetProcessedImageData() const {
    return *_processedImage;
}
