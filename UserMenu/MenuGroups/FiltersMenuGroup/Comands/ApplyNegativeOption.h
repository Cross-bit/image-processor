//
// Created by kriz on 14.05.2022.
//

#ifndef MAIN_CPP_APPLYNEGATIVEOPTION_H
#define MAIN_CPP_APPLYNEGATIVEOPTION_H

#include <unordered_set>
#include "ApplyFilterOptionBase.h"

class ApplyNegativeOption : public ApplyFilterOptionBase {
public:
    ApplyNegativeOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData &imageToProcess) override;

    bool InitializeFilterProperties() override;

private:
    float _intensityConst = 1.0f;


};


#endif //MAIN_CPP_APPLYNEGATIVEOPTION_H
