//
// Created by kriz on 27.04.2022.
//

#ifndef MAIN_CPP_APPLYLINEARGRAYSCALEOPTION_H
#define MAIN_CPP_APPLYLINEARGRAYSCALEOPTION_H

#include "ApplyFilterOptionBase.h"


class ApplyLinearGrayscaleOption : public ApplyFilterOptionBase
{
public:
    ApplyLinearGrayscaleOption(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    void ApplyFilterOnImage(ImageData &imageToProcess) override;
};


#endif //MAIN_CPP_APPLYLINEARGRAYSCALEOPTION_H
