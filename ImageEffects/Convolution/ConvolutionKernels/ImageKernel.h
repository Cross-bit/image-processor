//
// Created by kriz on 21.04.2022.
//

#ifndef MAIN_CPP_IMAGEKERNEL_H
#define MAIN_CPP_IMAGEKERNEL_H

#include "../../../ImageLibrary/Image/ImageData.h"

/**
 * Base class for image kernel.
 */
class ImageKernel {
public:
    ImageKernel(int dimension);

    /**
     * Setter for kernel dimension.
     */
    void SetDimension(int value);

    /**
     * Getter for kernel dimension
     */
    void GetDimension();

private:
    int _dimension;
};


#endif //MAIN_CPP_IMAGEKERNEL_H
