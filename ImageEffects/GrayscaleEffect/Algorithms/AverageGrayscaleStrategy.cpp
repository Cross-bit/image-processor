//
// Created by kriz on 20.04.2022.
//

#include "AverageGrayscaleStrategy.h"


void AverageGrayscaleStrategy::TransformToGrayscale(ImageData& imageData) const {
    for (int i = 0; i < imageData.DataSize; i += imageData.ColorChannels) {

        int avgPixelValue;

        for (int j = i; j < i + imageData.ColorChannels; ++j) {
            avgPixelValue += imageData.Data[j];
        }

        avgPixelValue /= imageData.ColorChannels;

        for (int j = i; j < i + imageData.ColorChannels; ++j) {
            imageData.Data[j] = avgPixelValue;
        }
    }
}