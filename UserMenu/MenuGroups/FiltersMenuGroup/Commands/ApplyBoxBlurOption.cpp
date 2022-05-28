//
// Created by kriz on 29.04.2022.
//

#include "ApplyBoxBlurOption.h"

ApplyBoxBlurOption::ApplyBoxBlurOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary) {
    _itemContent = "Box blur";
}

bool ApplyBoxBlurOption::InitializeFilterProperties(UserMenu &userMenu) {
    PrintLine("Enter number of cycles in range 1 to n (def.: 1):");

    if (!ReadUserInputNaturalNum(_repetitions)) {
        _repetitions = 1;
        PrintInputFallback<int>(_repetitions);
    }

    return true;
}

std::unique_ptr<ImageData> ApplyBoxBlurOption::ApplyFilterOnImage(ImageData& imageToProcess) {
    std::unique_ptr<ImageData> result = std::make_unique<ImageData>(imageToProcess);

    for (int i = 0; i < _repetitions; ++i) {
        ImageEffectFactory imageFactory(*result);
        auto effect = imageFactory.CreateBoxBlurConvolution();
        effect->ProcessImageData();
        result = std::move(effect->GetProcessedImageData());
    }


    return std::move(result);
}

std::string ApplyBoxBlurOption::GetNewFileNameAppendix() const {
    return "_box_blur";
}
