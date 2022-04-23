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
        _kernelStepHorizontal(1),
        _kernelStepVertically(2)
    {
        _convolutedImageData = std::make_unique<ImageData>(
                    imageData.Name + "_conv",
                    imageData.Width,
                    imageData.Height,
                    imageData.Channels,
                    imageData.Width * imageData.Height * imageData.Channels,
                    imageData.ColorSpace );

    }

void ConvolutionProcessor::ProcessImageData() {

    int step = 1; // how many pixels kernel slides at once ...
    int totalDataCtr = 0;

    // per rows
    for (int i = 0; i < _imageData.Height; i += step) {
        // per line
        for (int j = 0; j < _valuesPerLine; j += step*_imageData.Channels) {
            ProcessImageKernel(j, i);

            for (auto & channelData : _convolutedPixelBuffer) {
                _convolutedImageData->Data[totalDataCtr] = ImageData::sRGBGammaCompression(channelData) * 255;
                totalDataCtr++;
            }
        }
    }
}

void ConvolutionProcessor::ProcessImageKernel(int kernelLeftX, int kernelTopY) {

    // clear the buffer first...
    std::fill(_convolutedPixelBuffer.begin(), _convolutedPixelBuffer.end(), 0);

    int lastPixelY = kernelTopY + _imageKernel.GetDimension();
    int lastPixelX = kernelLeftX +  _imageKernel.GetDimension() * _imageData.Channels;


    int pixelNumber = 0;
    for (int y = kernelTopY; y < lastPixelY; ++y) {
        for (int x = kernelLeftX; x < lastPixelX; x += _imageData.Channels) {

            if(y > _imageData.Width) {
                // todo: :) handling of going out of the image bounds + vertically too todo:
                std::cout << "jsme venku";
            }

            UpdateConvolutedBuffer(x, y, pixelNumber);
            pixelNumber++;
        }
    }
}

void ConvolutionProcessor::UpdateConvolutedBuffer(int pixelX, int pixelY, int pixelNumber) {

    int pixelOffset = _valuesPerLine * pixelY + pixelX; // which value is the starting value of this pixel
    int pixelEndPosition = pixelOffset + _imageData.ColorChannels; // len of the pixel == # color channels

    int kernel_x = (pixelNumber) % (_imageKernel.GetDimension());
    int kernel_y = pixelNumber / _imageKernel.GetDimension();

    // Do convolution per each color channel separately, k - real offset of channel
    for (int k = pixelOffset; k < pixelEndPosition; ++k) {

        _convolutedPixelBuffer[k % _imageData.ColorChannels] +=
                _imageKernel.GetKernelValueOnCoords(kernel_x, kernel_y) * ImageData::sRGBGammaExspansion(_imageData.Data[k]/(float) 255);
    }
}

ImageData& ConvolutionProcessor::GetConvolutedImageData() {
    return *_convolutedImageData;
}
