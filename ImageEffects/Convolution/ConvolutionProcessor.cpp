//
// Created by kriz on 22.04.2022.
//

#include "ConvolutionProcessor.h"
#include "vector"

ConvolutionProcessor::ConvolutionProcessor(ImageData& imageData, ImageKernel &imageKernel) :
        _imageData(imageData),
        _imageKernel(imageKernel),
        _convolutedPixelBuffer(imageData.ColorChannels),
        _valuesPerLine(_imageData.Width * _imageData.Channels),
        _imageDataCopy(imageData) { }

void ConvolutionProcessor::ProcessImageData() {

    int step = 1; // image kernel size

    for (int i = 0; i < _imageData.Height; i += step) {

        for (int j = 0; j < _valuesPerLine; j += step*_imageData.Channels) {
            ProcessImageKernel(j, i);
            //printf("\n");
        }
        return;
    }
}

void ConvolutionProcessor::ProcessImageKernel(int kernelLeftX, int kernelTopY) {

    // clear the buffer first...
    std::fill(_convolutedPixelBuffer.begin(), _convolutedPixelBuffer.end(), 0);

    int lastPixelY = kernelTopY + _imageKernel.GetDimension();
    int lastPixelX = kernelLeftX +  _imageKernel.GetDimension() * _imageData.Channels;

    for (int y = kernelTopY; y < lastPixelY; ++y) {
        for (int x = kernelLeftX; x < lastPixelX; x += _imageData.Channels) {

            if(y > _imageData.Width){
                // todo: :) handling of going out of the image bounds + vertically todo:
            }

            UpdateConvolutedBuffer(x, y);

        }
        printf("\n");
    }
}

void ConvolutionProcessor::UpdateConvolutedBuffer(int x, int y) {

    int pixelStartPos = _valuesPerLine * y + x;
    int pixelEndPos = pixelStartPos + _imageData.ColorChannels;

    // per each pixel do convolution for each color channel
    for (int k = pixelStartPos; k < pixelEndPos; ++k) {
        //printf("%d ", _imageData.Data[k]);
        _convolutedPixelBuffer[k] += _imageKernel.GetKernelValueOnCoords(x, y);
    }
}