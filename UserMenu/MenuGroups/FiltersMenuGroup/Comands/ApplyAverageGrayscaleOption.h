//
// Created by kriz on 14.05.2022.
//

#ifndef MAIN_CPP_APPLYAVERAGEGRAYSCALEOPTION_H
#define MAIN_CPP_APPLYAVERAGEGRAYSCALEOPTION_H


#include <unordered_set>
#include "ApplyFilterOptionBase.h"

class ApplyAverageGrayscaleOption : public ApplyFilterOptionBase
{
public:
    ApplyAverageGrayscaleOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData &imageToProcess) override;
private:
    int _repetitions = 1;
};


#endif //MAIN_CPP_APPLYAVERAGEGRAYSCALEOPTION_H
