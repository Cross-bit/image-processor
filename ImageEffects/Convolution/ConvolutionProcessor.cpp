//
// Created by kriz on 22.04.2022.
//

#include "ConvolutionProcessor.h"
#include "vector"

ConvolutionProcessor::ConvolutionProcessor(ImageData& imageData, ImageKernel &imageKernel, bool useGammaExspantion) :
        _imageData(imageData),
        _imageKernel(imageKernel),
        _useGammaExspantion(useGammaExspantion),
        _convolutedPixelBuffer(imageData.ColorChannels),
        _valuesPerLine(_imageData.Width * _imageData.Channels),
        _kernelStepHorizontal(1),
        _kernelStepVertically(1)
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

    int totalDataCtr = 0; //

    // per img rows
    for (int i = 0; i < _imageData.Height; i += _kernelStepVertically) {
        // per img line
        for (int j = 0; j < _valuesPerLine; j += _kernelStepHorizontal * _imageData.Channels) {

            // convolute data of matrix starting(top left value is) at j, i
            ProcessImageKernel(j, i);

            // store convoluted data
            StoreConvolutedPixelBuffer(totalDataCtr);

            totalDataCtr += _convolutedPixelBuffer.size();
        }
    }
}

void ConvolutionProcessor::StoreConvolutedPixelBuffer(int outDataOffset) {

    int scalingConst = _useGammaExspantion ? _convolutedImageData->MaxChannelValue : 1;
    // maan i do not like this! todo: !!

    for (auto & channelData : _convolutedPixelBuffer) {

        if ((channelData * scalingConst) <= 0) {
            _convolutedImageData->Data[outDataOffset] = 0;
        }
        else if((channelData * scalingConst) >= _convolutedImageData->MaxChannelValue) {
            _convolutedImageData->Data[outDataOffset] = _convolutedImageData->MaxChannelValue;
        }
        else {
            if(_useGammaExspantion)
                _convolutedImageData->SetGammaCompressed(outDataOffset, channelData);
            else
                _convolutedImageData->Data[outDataOffset] = channelData;
        }

        outDataOffset++;
    }
}

void ConvolutionProcessor::ProcessImageKernel(int kernelLeftX, int kernelTopY) {

    // clear the buffer first...
    std::fill(_convolutedPixelBuffer.begin(), _convolutedPixelBuffer.end(), 0);

    int lastPixelY = kernelTopY + _imageKernel.GetDimension(); // only to know where to end
    int lastPixelX = kernelLeftX +  _imageKernel.GetDimension() * _imageData.Channels;

    int pixelNumber = 0;
    for (int y = kernelTopY; y < lastPixelY; ++y) {
        for (int x = kernelLeftX; x < lastPixelX; x += _imageData.Channels) {
            // Update currently convoluted pixel data with value on x, y
            UpdateConvolutedPixelBuffer(GetValidXCoord(x), GetValidYCoord(y), pixelNumber);

            pixelNumber++;
        }
    }
}

void ConvolutionProcessor::UpdateConvolutedPixelBuffer(int pixelX, int pixelY, int pixelNumber) {

    int pixelOffset = _valuesPerLine * pixelY + pixelX; // which value is the starting value of this pixel
    int pixelEndPosition = pixelOffset + _imageData.ColorChannels; // len of the pixel == # color channels

    int kernel_x = (pixelNumber) % (_imageKernel.GetDimension());
    int kernel_y = pixelNumber / _imageKernel.GetDimension();

    // Do convolution per each color channel separately, k - real offset of channel
    for (int k = pixelOffset; k < pixelEndPosition; ++k) {
        int tmp = k % _imageData.ColorChannels;

        _convolutedPixelBuffer[tmp] +=
                _imageKernel.GetKernelValueOnCoords(kernel_x, kernel_y) *
                   (_useGammaExspantion ? _imageData.GetGammaExspanded(k) : _imageData.Data[k]);
    }
}

ImageData& ConvolutionProcessor::GetConvolutedImageData() {
    return *_convolutedImageData;
}

int ConvolutionProcessor::GetValidXCoord(int x) const{
    // if out of bounds return boundary pixel
    return x <= _imageData.Width*_imageData.Channels-6 ? x : _imageData.Width*_imageData.Channels-6;
}


int ConvolutionProcessor::GetValidYCoord(int y) const{
    // if out of bounds return boundary pixel
    return y <= _imageData.Height-1 ? y : _imageData.Height-1;
}

