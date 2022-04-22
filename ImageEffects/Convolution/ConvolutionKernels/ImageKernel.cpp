//
// Created by kriz on 21.04.2022.
//

#include "ImageKernel.h"

ImageKernel::ImageKernel(int dimension) : _dimension(dimension) { }

int ImageKernel::GetDimension() const {
    return this->_dimension;
}