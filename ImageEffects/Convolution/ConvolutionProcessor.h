//
// Created by kriz on 22.04.2022.
//

#ifndef MAIN_CPP_CONVOLUTIONPROCESSOR_H
#define MAIN_CPP_CONVOLUTIONPROCESSOR_H

#include "ConvolutionKernels/ImageKernel.h"
#include "../ImageEffect.h"


/**
 * Filter converting applying convolution based on the given image kernel.
 */
class ConvolutionProcessor : public ImageEffect
{
public:
    ConvolutionProcessor(ImageData& imageData,std::unique_ptr<ImageKernel> imageKernel, bool useGammaExspantion = true); // todo remove this bool...

    void ProcessImageData() override;

    ImageData& GetProcessedImageData() const override;

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
    int GetValidXCoord(int x) const;

    /**
     * Transforms recived y coord so that it always corresponds to pixel in the image.
     * @param y coord to transform.
     * @return coord that always lies in the image.
     */
    int GetValidYCoord(int y) const;

    /**
     * Procedur storing convoluted pixel data in buffer.
     */
    void StoreConvolutedPixelBuffer(int outDataOffset);

    /**
     * Determines for how many pixels the kernel matrix shifts in each step horizontally. (Default set to 1)
     */
    int _kernelStepHorizontal;

    /**
     * Determines for how many pixels the kernel matrix shifts in each step vertically. (Default set to 1)
     */
    int _kernelStepVertically;

    std::unique_ptr<ImageData> _convolutedImageData;

    std::unique_ptr<ImageKernel> _imageKernel;

    /**
     * Holds channel values for currently convoluted pixel.
     */
    std::vector<double> _convolutedPixelBuffer;

    int _valuesPerLine;

    bool _useGammaExspantion; // do not like this approach but i will leave it for now...
};


#endif //MAIN_CPP_CONVOLUTIONPROCESSOR_H
