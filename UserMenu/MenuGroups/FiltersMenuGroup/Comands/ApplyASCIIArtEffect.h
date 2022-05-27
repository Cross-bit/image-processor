//
// Created by kriz on 25.05.2022.
//

#ifndef MAIN_CPP_APPLYASCIIARTEFFECT_H
#define MAIN_CPP_APPLYASCIIARTEFFECT_H

#include <unordered_set>
#include "ApplyFilterOptionBase.h"


class ApplyASCIIArtEffect : public ApplyFilterOptionBase
{
public:
    ApplyASCIIArtEffect(std::unordered_set<int> &libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

protected:
    std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData &imageToProcess) override;

    bool InitializeFilterProperties() override;

    void StoreProcessedImageData(UserMenu& userMenu) override;

    std::string GetNewFileNameAppendix() const override;

private:

    std::string GetFullFileDirName(const std::string& filename) const;

    const std::string Alphabet1 = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,¨^`'. ";
    const std::string Alphabet2 = "$@B%8&WM#;:,¨^`'. ";

    int _colsCount = 1;
    double _scalingFactor = 1;
    std::string _inputAlphabet;
    std::string _outputDir;

};

#endif //MAIN_CPP_APPLYASCIIARTEFFECT_H
