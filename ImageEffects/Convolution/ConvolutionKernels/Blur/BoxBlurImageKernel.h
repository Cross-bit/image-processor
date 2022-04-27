//
// Created by kriz on 23.04.2022.
//

#ifndef MAIN_CPP_BOXBLURIMAGEKERNEL_H
#define MAIN_CPP_BOXBLURIMAGEKERNEL_H

#include "../ImageKernel.h"

/**
 * Simple box blur image kernel (3x3). (very simple low pass filter)
 */
class BoxBlurImageKernel : public ImageKernel
{
public:
    BoxBlurImageKernel();
    double GetKernelValueOnCoords(int x, int y) const override;

};


#endif //MAIN_CPP_BOXBLURIMAGEKERNEL_H
