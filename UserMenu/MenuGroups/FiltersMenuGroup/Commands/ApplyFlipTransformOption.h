//
// Created by kriz on 14.05.2022.
//

#ifndef MAIN_CPP_APPLYFLIPTRANSFORMOPTION_H
#define MAIN_CPP_APPLYFLIPTRANSFORMOPTION_H


#include <unordered_set>
#include "ApplyFilterOptionBase.h"
#include "../../../../ImageEffects/Transformations/FlipTransform.h"

class ApplyFlipTransformOption : public ApplyFilterOptionBase
{
public:
    ApplyFlipTransformOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData &imageToProcess) override;

    bool InitializeFilterProperties(UserMenu &userMenu) override;

    std::string GetNewFileNameAppendix() const override;
private:
    FlipTransform::Direction _flipDirection;

    char _flipChar = '.';
};


#endif //MAIN_CPP_APPLYFLIPTRANSFORMOPTION_H
