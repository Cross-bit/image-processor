//
// Created by kriz on 15.05.2022.
//

#include "ApplySobelOption.h"

ApplySobelOption::ApplySobelOption(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary) {
    _itemContent = "Sobel";
}

bool ApplySobelOption::InitializeFilterProperties(UserMenu &userMenu) {

    PrintLine("Enter direction:");
    PrintLine("t - top, b - bottom, l - left, r - right:");

    std::string userInput;
    if (!ReadUserChoices(std::vector<std::string> {"t", "b", "l", "r"}, userInput)){
        PrintInputFallback('b');
        userInput = "b";
    }

    _sobelDirectionChar = userInput[0];

    switch (_sobelDirectionChar) {
        case 't': _sobelDirection = SobelImageKernel::Direction::TOP; break;
        case 'b': _sobelDirection = SobelImageKernel::Direction::BOTTOM; break;
        case 'l': _sobelDirection = SobelImageKernel::Direction::LEFT; break;
        case 'r': _sobelDirection = SobelImageKernel::Direction::RIGHT; break;
    }

    PrintLine("Colored? (y/n): ");
    bool isColored;
    if (!ReadUserYesNo(isColored)){
        PrintInputFallback('n');
        _isColored = false;
    }
    else
        _isColored = isColored;

    return true;
}

std::unique_ptr<ImageData> ApplySobelOption::ApplyFilterOnImage(ImageData& imageToProcess) {

    // if not colored, first convert to grayscale
    auto imageData = _isColored ? imageToProcess : std::move(*ApplyGrayScale(imageToProcess))  ;

    ImageEffectFactory imageFactory(imageData);
    auto effect = imageFactory.CreateSobelConvolution(_sobelDirection);
    effect->ProcessImageData();
    return std::move(effect->GetProcessedImageData());
}

std::unique_ptr<ImageData> ApplySobelOption::ApplyGrayScale(ImageData &inputImage) {
    ImageEffectFactory imageFactory(inputImage);
    auto grayScale = imageFactory.CreateLinearGrayScale();
    grayScale->ProcessImageData();
    return std::move(grayScale->GetProcessedImageData());
}

std::string ApplySobelOption::GetNewFileNameAppendix() const {

    std::string newFileName = "_sobel_";
    newFileName += (_isColored ? "colored_" : "_");
    newFileName += _sobelDirectionChar;
    return newFileName;
}
