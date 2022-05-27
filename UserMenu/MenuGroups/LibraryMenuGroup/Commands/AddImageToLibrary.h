//
// Created by kriz on 26.04.2022.
//

#ifndef MAIN_CPP_ADDIMAGETOLIBRARY_H
#define MAIN_CPP_ADDIMAGETOLIBRARY_H

#include "../../../MenuCommands/MenuOption.h"

#include "../../../../ImageLibrary/ImagesLibrary.h"
#include "../../../../ImageLibrary/ImageFormatFactory.h"

class AddImageToLibrary : public MenuOption {
public:
    AddImageToLibrary(ImagesLibrary& imagesLibrary);

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu & userMenu) override;

    void Execute(UserMenu& userMenu) override;
private:
    ImagesLibrary& _imagesLibrary;

    ImageFormatFactory _formatFactory;

    std::unique_ptr<ImageFormat> GetImageFormat(const std::string& filePath);

    bool TryToFindImage(std::string& imagePath) const;

};


#endif //MAIN_CPP_ADDIMAGETOLIBRARY_H
