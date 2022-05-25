//
// Created by kriz on 25.05.2022.
//

#include "ApplyASCIIArtEffect.h"

ApplyASCIIArtEffect::ApplyASCIIArtEffect(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
ApplyFilterOptionBase(libraryIndexesToWorkWith, imagesLibrary)
{
    _itemContent = "ASCII-art";
}

std::unique_ptr<ImageData> ApplyASCIIArtEffect::ApplyFilterOnImage(ImageData &imageToProcess) {

    ImageEffectFactory imageFactoryGrayScale(imageToProcess);
    auto grayScale = imageFactoryGrayScale.CreateLinearGrayScale();
    grayScale->ProcessImageData();

    auto grayScaled = grayScale->GetProcessedImageData();
    ImageEffectFactory imageFactoryASCII(*grayScaled);

    auto effect = imageFactoryASCII.CreateAsciiArtEffectByScale(_inputAlphabet, 1, 1 / (double)100, std::cout);
    effect->ProcessImageData();

    return std::move(effect->GetProcessedImageData());
}

bool ApplyASCIIArtEffect::InitializeFilterProperties() {

    PrintLine("Select alphabet you want to use:");
    PrintLine("a) " + Alphabet1);
    PrintLine("b) " + Alphabet2);
    PrintLine("c) Custom");

    std::string userChoice;
    if(!ReadUserChoices(std::vector<std::string>{"a", "b", "c"},  userChoice)){
        _inputAlphabet = Alphabet1;
        PrintInputFallback(Alphabet1);
    }
    else {
        switch (userChoice[0]) {
            case 'a':
                _inputAlphabet = Alphabet1;
                break;
            case 'b':
                _inputAlphabet = Alphabet2;
                break;
            case 'c':
                _inputAlphabet = ReadUserInput();
                if(_inputAlphabet == ""){
                    _inputAlphabet = Alphabet1;
                    PrintInputFallback(Alphabet1);
                }
                break;
        }
    }

    PrintLine("Enter number of columns[1, img_width]:");

    if (!ReadUserInputNaturalNum(_tileWidth)){
        PrintInputFallback("img_width");
    }

    PrintLine("Enter height scaling factor:");

    if (!ReadUserInputNaturalNum(_)){
        PrintInputFallback("image_width");
    }


    return true;
}