//
// Created by kriz on 23.04.2022.
//

#ifndef MAIN_CPP_BOXBLURIMAGEKERNEL_H
#define MAIN_CPP_BOXBLURIMAGEKERNEL_H

#include "../ImageKernel.h"

class BoxBlurImageKernel : public ImageKernel
{
public:
    BoxBlurImageKernel();
    double GetKernelValueOnCoords(int x, int y) const override;

};


#endif //MAIN_CPP_BOXBLURIMAGEKERNEL_H
