//
// Created by kriz on 29.04.2022.
//

#ifndef MAIN_CPP_APPLYBOXBLUROPTION_H
#define MAIN_CPP_APPLYBOXBLUROPTION_H



#include <unordered_set>
#include "ApplyFilterOptionBase.h"

class ApplyBoxBlurOption : public ApplyFilterOptionBase
{
public:
    ApplyBoxBlurOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData &imageToProcess) override;

    bool InitializeFilterProperties() override;
private:
    int _repetitions = 1;
};


#endif //MAIN_CPP_APPLYBOXBLUROPTION_H
