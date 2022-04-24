//
// Created by kriz on 24.04.2022.
//

#include "LeftSobelImageKernel.h"


LeftSobelImageKernel::LeftSobelImageKernel() : ImageKernel(3) {}

double LeftSobelImageKernel::GetKernelValueOnCoords(int x, int y) const {
    return _kernelBuffer[y][x];
}