//
// Created by kriz on 22.04.2022.
//

#include "ConvolutionProcessor.h"



ConvolutionProcessor::ConvolutionProcessor(ImageData &imageData, ImageKernel &imageKernel) :
_imageData(imageData),
_imageKernel(imageKernel)
{ }

void ConvolutionProcessor::ProcessImageData() {

    int step = 1; // image kernel size

    int componentsOnLine = _imageData.Width * _imageData.Channels;

    for (int i = 0; i < _imageData.Height; i += step) {

        for (int j = 0; j < componentsOnLine; j += step*_imageData.Channels) {
            ProcessImageKernel(j, i);
            //printf("\n");
        }
        return;
    }
}

void ConvolutionProcessor::ProcessImageKernel(int kernelLeftX, int kernelTopY) {
    int step = 3; // image kernel size

    for (int y = kernelTopY; y < kernelTopY + step; ++y) {
        for (int x = kernelLeftX; x < kernelLeftX + step * _imageData.Channels; x += _imageData.Channels) {

            // per pixel
            for (int k = _imageData.Width * _imageData.Channels * y + x; k < _imageData.Width * _imageData.Channels * y + x + _imageData.Channels; ++k) {
                printf("%d ", _imageData.Data[k]);
            }
        //    printf(" ");
        }
        printf("\n");
    }
}
