//
// Created by kriz on 23.04.2022.
//

#ifndef MAIN_CPP_GAUSSIANBLURIMAGEKERNEL_H
#define MAIN_CPP_GAUSSIANBLURIMAGEKERNEL_H

#include "../ImageKernel.h"
#include <vector>
/**
 * Gaussian blur convolution image kernel. (low pass filter)
 */
class GaussianBlurImageKernel : public ImageKernel
{

public:
    GaussianBlurImageKernel(int kernelDimension);
    GaussianBlurImageKernel(int kernelDimension, double standardDiviation);

    double GetKernelValueOnCoords(int x, int y) const override;

    /**
     * Calculates kernel matrix values and sets internal buffer.
     * @return
     */
    void PopulateKernelBufferWithValues();

    /**
     * Setter for standard deviation.
     */
    void SetStandardDeviation(double value);

private:

    double Get2DGaussianValueOnCoords(int x, int y) const;

    /**
     * Normalizes kernel data, so all values sum up to 1.
     * @param sum sum of all matrix values.
     */
    void NormalizeKernelData(double sum);

    /**
     * Kernel buffer matrix.
     */
    std::vector<std::vector<double>>  _kernelBuffer;

    /**
     * Standard deviation for gaussian distribution.
     */
    double _stdDeviation;

    /**
     * Coefitient based on standard diviation used in the formula. (Is recalculated with setting std diviation).
     */
    double _precomputedDeviationCoef;

};


#endif //MAIN_CPP_GAUSSIANBLURIMAGEKERNEL_H
