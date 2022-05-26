//
// Created by kriz on 25.05.2022.
//

#include "ApplyASCIIArtEffect.h"
#include "../../../UserMenu.h"
#include "../../MenuGroupFactory.h"

#include <iostream>
#include <fstream>
#include <filesystem>
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

    std::ofstream outputFile;
    outputFile.open(GetFullFileDirName(imageToProcess.Name));// todo:

    auto effect = imageFactoryASCII.CreateAsciiArtEffectByScale(_inputAlphabet, (_colsCount < 0 ? imageToProcess.Width : _colsCount), _scalingFactor, outputFile);
    effect->ProcessImageData();

    outputFile.close();
    return std::move(effect->GetProcessedImageData());
}

std::string ApplyASCIIArtEffect::GetNewFileNameAppendix() const{
    return "_ascii";
}

std::string ApplyASCIIArtEffect::GetFullFileDirName(const std::string& fileName) const{
    std::string res = _outputDir;
    res += _outputDir[_outputDir.length() - 1] == '/' ? "" : "/";

    return res + fileName + GetNewFileNameAppendix() + ".txt";
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
                if (_inputAlphabet == ""){
                    _inputAlphabet = Alphabet1;
                    PrintInputFallback(Alphabet1);
                }
                break;
        }
    }

    PrintLine("Enter number of columns [1, img_width]:");

    if (!ReadUserInputNaturalNum(_colsCount)){
        std::string message = "img_width";
        PrintInputFallback(message);
    }

    PrintLine("Enter height scaling factor [0, 1]:");

    if (!ReadUserInputDecimal(_scalingFactor, 0, 1)){
        _scalingFactor = 1;
        PrintInputFallback<double>(_scalingFactor);
    }

    PrintLine("Enter output file path:");

    std::string outputPath = ReadUserInput();

    // if provided dir does not exsist use default
    if (!std::filesystem::exists(outputPath)) {
        // todo: refactor:
        _outputDir = "/mnt/c/Users/kriz/CLionProjects/ImageProcessor/DefaultOutput";
        PrintInputFallback(_outputDir);
    }
    else {
        _outputDir = outputPath;
    }

    return true;
}

void ApplyASCIIArtEffect::StoreProcessedImageData() {
    std::cout << "done!";
}
