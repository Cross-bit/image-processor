//
// Created by kriz on 21.04.2022.
//

#include "ImageKernel.h"
#include <cassert>
#include <string>

ImageKernel::ImageKernel(int dimension) : _dimension(dimension) { }

int ImageKernel::GetDimension() const {
    return this->_dimension;
}


/**
 * Default implementation of image kernel is identity.
 * @param x
 * @param y
 * @return
 */
double ImageKernel::GetKernelValueOnCoords(int x, int y) const {
    assert(CheckCoordsInDims(x, y));
    return  _dimension / 2 == x && _dimension / 2 == y ? 1 : 0;
}

bool ImageKernel::CheckCoordsInDims(int x, int y) const{
    return x < _dimension && y < _dimension && x >= 0 && y >= 0;
}
