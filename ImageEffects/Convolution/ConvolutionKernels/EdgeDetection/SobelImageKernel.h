//
// Created by kriz on 24.04.2022.
//

#ifndef MAIN_CPP_SOBELIMAGEKERNEL_H
#define MAIN_CPP_SOBELIMAGEKERNEL_H


#include "../ImageKernel.h"

class SobelImageKernel : public ImageKernel // todo: make it generic
{
public:
    enum Direction {LEFT, TOP, RIGHT, BOTTOM};

    SobelImageKernel(Direction _direction);

    double GetKernelValueOnCoords(int x, int y) const override;

private:

    void PopulateKernelBufferValues();

    Direction _direction;
    /**
     * Kernel buffer matrix.
     */
   // std::vector<std::vector<double>>  _kernelBuffer = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};//;{{1, 0, -1}, {2, 0, -2}, {1, 0, -1}};*/
   std::vector<std::vector<int>> _kernelBuffer;


};


#endif //MAIN_CPP_SOBELIMAGEKERNEL_H
