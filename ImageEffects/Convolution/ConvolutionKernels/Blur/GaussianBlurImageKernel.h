//
// Created by kriz on 23.04.2022.
//

#ifndef MAIN_CPP_GAUSSIANBLURIMAGEKERNEL_H
#define MAIN_CPP_GAUSSIANBLURIMAGEKERNEL_H

#include "../ImageKernel.h"
#include <vector>
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

    void NormalizeKernelData(double sum);
    /**
     * Kernel buffer matrix.
     */
    std::vector<std::vector<double>>  _kernelBuffer;

    /**
     * Gaussian distribution standard diviation.
     */
    double _stdDiviation;
    /**
     * Coefitient based on standard diviation used in the formula. (Is recalculated with setting std diviation)
     */
    double _precomputedDeviationCoef;

};


#endif //MAIN_CPP_GAUSSIANBLURIMAGEKERNEL_H
