//
// Created by kriz on 23.04.2022.
//

#include "GaussianBlurImageKernel.h"
#include <cassert>
GaussianBlurImageKernel::GaussianBlurImageKernel(int kernelDimension) : ImageKernel(kernelDimension)
{
    SetStandardDeviation(1);
    PopulateKernelBufferWithValues();
}

GaussianBlurImageKernel::GaussianBlurImageKernel(int kernelDimension, double standardDiviation) : ImageKernel(kernelDimension) {
    SetStandardDeviation(standardDiviation);
    PopulateKernelBufferWithValues();
}

void GaussianBlurImageKernel::SetStandardDeviation(double value) {
    _stdDeviation = value;
    _precomputedDeviationCoef = 2 * pow(_stdDeviation, 2);
}

void GaussianBlurImageKernel::PopulateKernelBufferWithValues() {
    // note: this algorithm works, but is far from optimal
    // g. blur can be done in O(n) (or O(n*log(n)) using FFT)
    // for example: http://blog.ivank.net/fastest-gaussian-blur.html

    _kernelBuffer.clear();
    double sum = 0;
    for (int i = 0; i < _dimension; ++i) {
        std::vector<double> bufferRow(_dimension);
        for (int j = 0; j < _dimension; ++j) {
            int x = i - (_dimension / 2);
            int y = j - (_dimension / 2);

            bufferRow[j] = Get2DGaussianValueOnCoords(x, y);
            sum += bufferRow[j];
        }
        _kernelBuffer.emplace_back(std::move(bufferRow));
    }

    NormalizeKernelData(sum);
}

void GaussianBlurImageKernel::NormalizeKernelData(double sum){
    // normalizes the kernel (so all values sum up to 1)
    for (int y = 0; y < _dimension; y++){
        for (int x = 0; x < _dimension; x++){
            _kernelBuffer[y][x] /= sum;
        }
    }
}

double GaussianBlurImageKernel::Get2DGaussianValueOnCoords(int x, int y) const{
    // source: https://en.wikipedia.org/wiki/Gaussian_blur

    double coordsComb = pow(x, 2) + pow(y, 2);

    return 1/(exp(coordsComb/_precomputedDeviationCoef) * (M_PI*_precomputedDeviationCoef));
}

double GaussianBlurImageKernel::GetKernelValueOnCoords(int x, int y) const {
    assert(("Given dimensions are out of image kernel!", CheckCoordsInDims(x, y)));

    // return the corresponding kernel value
   return _kernelBuffer[y][x];
}
