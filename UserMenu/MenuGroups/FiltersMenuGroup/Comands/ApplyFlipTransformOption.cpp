//
// Created by kriz on 14.05.2022.
//

#include "ApplyFlipTransformOption.h"


ApplyFlipTransformOption::ApplyFlipTransformOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
        ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary)
{
    _itemContent = "Flip transform";
}

bool ApplyFlipTransformOption::InitializeFilterProperties() {

    PrintLine("Write \"h\"(for horizontal), or \"v\"(vertical) for the specific transformation.");

    auto userInput = ReadUserInput();

    if(userInput.length() > 1 || userInput.length() <= 0){
        PrintError("Invalid input given!");
        return false;
    }

    switch (userInput.c_str()[0]) {
        case 'h':
            _flipDirection = FlipTransform::HORIZONTAL; break;
        case 'v':
            _flipDirection = FlipTransform::VERTICAL;
            break;
        default:
            PrintError("Invalid input given!");
            return false;

    }
    return true;
}

std::unique_ptr<ImageData> ApplyFlipTransformOption::ApplyFilterOnImage(ImageData& imageToProcess) {

    ImageEffectFactory imageFactory(imageToProcess);
    auto effect = imageFactory.CreateFlipTransform(_flipDirection);
    effect->ProcessImageData();

    return std::move(effect->GetProcessedImageData());
}