//
// Created by kriz on 23.04.2022.
//

#include "BoxBlurImageKernel.h"
#include "math.h"

BoxBlurImageKernel::BoxBlurImageKernel() : ImageKernel(3) { }; // box blur operates with kernel size 3 (otherwise we get unwanted effects)

double BoxBlurImageKernel::GetKernelValueOnCoords(int x, int y) const {
    // box blur
    return 1 / (float) pow(_dimension, 2);
}
