//
// Created by kriz on 22.04.2022.
//

#ifndef MAIN_CPP_CONVOLUTIONPROCESSOR_H
#define MAIN_CPP_CONVOLUTIONPROCESSOR_H

#include "ConvolutionKernels/ImageKernel.h"

class ConvolutionProcessor {
public:
    ConvolutionProcessor(ImageData& imageData, ImageKernel& imageKernel);

    void ProcessImageData();

    ImageData& GetConvolutedImageData();

private:
    void ProcessImageKernel(int kernelLeftX, int kernelTopY);

    void UpdateConvolutedBuffer(int pixelX, int pixelY, int pixelNumber);

    /**
     * Updates the final image data corresponding to the current kernel position with newly calculated data.
     * @param kernelLeftX
     * @param kernelTopY
     */
  // void UpdateFinalImageData(int kernelLeftX, int kernelTopY);

    /**
     * Determines for how many pixels the kernel matrix shifts in each step horizontally. (Default set to 1)
     */
    int _kernelStepHorizontal;

    /**
     * Determines for how many pixels the kernel matrix shifts in each step vertically. (Default set to 1)
     */
    int _kernelStepVertically;

    ImageData& _imageData;

    std::unique_ptr<ImageData> _convolutedImageData;

    ImageKernel& _imageKernel;

    /**
     * Currently convoluted pixel buffer
     */
    std::vector<int> _convolutedPixelBuffer;
    std::vector<uint8_t> _convolutedData;

    int _valuesPerLine;
};


#endif //MAIN_CPP_CONVOLUTIONPROCESSOR_H
