//
// Created by kriz on 27.04.2022.
//

#ifndef MAIN_CPP_APPLYLINEARGRAYSCALEOPTION_H
#define MAIN_CPP_APPLYLINEARGRAYSCALEOPTION_H

#include <unordered_set>
#include "ApplyFilterOptionBase.h"


class ApplyLinearGrayscaleOption : public ApplyFilterOptionBase
{
public:
    ApplyLinearGrayscaleOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData &imageToProcess) override;
};


#endif //MAIN_CPP_APPLYLINEARGRAYSCALEOPTION_H
