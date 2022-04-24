//
// Created by kriz on 24.04.2022.
//

#ifndef MAIN_CPP_LEFTSOBELIMAGEKERNEL_H
#define MAIN_CPP_LEFTSOBELIMAGEKERNEL_H


#include "../ImageKernel.h"

class LeftSobelImageKernel : public ImageKernel // todo: make it generic
{
public:
    LeftSobelImageKernel();

    double GetKernelValueOnCoords(int x, int y) const override;
private:
    /**
     * Kernel buffer matrix.
     */
    std::vector<std::vector<double>>  _kernelBuffer = {{1, 2, 1}, {0, 0, 0}, {-1, 2, -1}};//;{{1, 0, -1}, {2, 0, -2}, {1, 0, -1}};
};


#endif //MAIN_CPP_LEFTSOBELIMAGEKERNEL_H
