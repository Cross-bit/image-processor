//
// Created by kriz on 29.04.2022.
//

#include "ApplyBoxBlurOption.h"

ApplyBoxBlurOption::ApplyBoxBlurOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary)
{
    _itemContent = "Box blur";
}

bool ApplyBoxBlurOption::InitializeFilterProperties() {
    PrintLine("Enter number of cycles in range 1 to n (def.: 1):");

    auto repetitionsInput = ReadUserInput();

    if (CheckStringIsEmpty(repetitionsInput) ||
    repetitionsInput.find_first_not_of("123456789") != std::string::npos) {
        _repetitions = 1;
        PrintInputFallback<int>(_repetitions);
        return true;
    }

    _repetitions = std::stoi(repetitionsInput);

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
