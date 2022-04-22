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
     * Getter for kernel dimension
     */
    int GetDimension();

    /**
     *  Gets value from kernel matrix on specific coords.
     * @return
     */
    float GetKernelValueOnCoords(int x, int y);

private:
    int _dimension;
};


#endif //MAIN_CPP_IMAGEKERNEL_H
