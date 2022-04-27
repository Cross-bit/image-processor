//
// Created by kriz on 27.04.2022.
//

#ifndef MAIN_CPP_APPLYGAUSSIANBLUROPTION_H
#define MAIN_CPP_APPLYGAUSSIANBLUROPTION_H

#include "ApplyFilterOptionBase.h"

class ApplyGaussianBlurOption : public ApplyFilterOptionBase
{
public:
    ApplyGaussianBlurOption(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData &imageToProcess) override;
    bool InitializeFilterProperties() override;
private:
    int _kernelSize;
    double _standardDeviation;

    bool ReadKernelSize();
    bool ReadStandardDeviation();
};



#endif //MAIN_CPP_APPLYGAUSSIANBLUROPTION_H
