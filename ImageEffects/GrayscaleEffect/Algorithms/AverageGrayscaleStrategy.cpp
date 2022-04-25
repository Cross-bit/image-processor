//
// Created by kriz on 20.04.2022.
//

#include "AverageGrayscaleStrategy.h"

#include <cstring>

void AverageGrayscaleStrategy::TransformToGrayscale(ImageData& imageData) const {
    // simply takes average of R+G+B and sets all the channels to it.

    for (int i = 0; i < imageData.DataSize; i += imageData.ColorChannels) {

        int avgPixelValue = 0;

        for (int j = i; j < i + imageData.ColorChannels; ++j) {
            avgPixelValue += imageData.Data[j];
        }

        avgPixelValue /= imageData.ColorChannels;

        std::memset(&imageData.Data[i], avgPixelValue, imageData.ColorChannels);
    }
}