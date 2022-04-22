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

private:
    void ProcessImageKernel(int kernelLeftX, int kernelTopY);

    /**
     * Determines for how many pixels the kernel matrix shifts in each step horizontally. (Default set to 1)
     */
    int _kernelStepHorizontal;

    /**
     * Determines for how many pixels the kernel matrix shifts in each step vertically. (Default set to 1)
     */
    int _kernelStepVertically;

    ImageData& _imageData;

    ImageKernel _imageKernel;
};


#endif //MAIN_CPP_CONVOLUTIONPROCESSOR_H
