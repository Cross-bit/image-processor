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

    /**
     * Updates internal convolution pixel buffer.
     * @param pixelX
     * @param pixelY
     * @param pixelNumber
     */
    void UpdateConvolutedPixelBuffer(int pixelX, int pixelY, int pixelNumber);

    /**
     * Transforms recived x coord so that it always corresponds to pixel in the image.
     * @param x coord to transform.
     * @return X coord that always lies in the image.
     */
    int GetValidXCoord(int x);

    /**
     * Transforms recived y coord so that it always corresponds to pixel in the image.
     * @param y coord to transform.
     * @return coord that always lies in the image.
     */
    int GetValidYCoord(int y);

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
     * Holds channel values for currently convoluted pixel.
     */
    std::vector<double> _convolutedPixelBuffer;

    int _valuesPerLine;
};


#endif //MAIN_CPP_CONVOLUTIONPROCESSOR_H
