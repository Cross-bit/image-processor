//
// Created by kriz on 15.05.2022.
//

#ifndef MAIN_CPP_APPLYSOBELOPTION_H
#define MAIN_CPP_APPLYSOBELOPTION_H

#include <unordered_set>
#include "ApplyFilterOptionBase.h"

//SobelImageKernel;
//#include "../../../../ImageEffects/Convolution/ConvolutionKernels/Sobel/SobelImageKernel.h"

class ApplySobelOption : public ApplyFilterOptionBase
{
public:
    ApplySobelOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData& inputImage) override;

    bool InitializeFilterProperties() override;

    std::string GetNewFileNameAppendix() const override;
private:
    /**
     * Direction of sobel.
     */
    SobelImageKernel::Direction _sobelDirection = SobelImageKernel::BOTTOM;
    bool _isColored = false;

    /**
     * Coverts image first to grayscale.
     * @param inputImage
     * @return
     */
    std::unique_ptr<ImageData> ApplyGrayScale(ImageData& inputImage);
};


#endif //MAIN_CPP_APPLYSOBELOPTION_H
