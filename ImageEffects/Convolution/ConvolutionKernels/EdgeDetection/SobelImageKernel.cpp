//
// Created by kriz on 24.04.2022.
//

#include "SobelImageKernel.h"


SobelImageKernel::SobelImageKernel(Direction direction) : ImageKernel(3) {
    PopulateKernelBufferValues();
}

double SobelImageKernel::GetKernelValueOnCoords(int x, int y) const {
    return _kernelBuffer[y][x];
}

void SobelImageKernel::PopulateKernelBufferValues() {

    switch (_direction) {
        case LEFT:
            _kernelBuffer = {{1, 0, -1}, {2, 0, -2}, {1, 0, -1}};
            break;
        case TOP:
            _kernelBuffer = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};
            break;
        case RIGHT:
            _kernelBuffer = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            break;
        case BOTTOM:
            _kernelBuffer = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
            break;
    }
}