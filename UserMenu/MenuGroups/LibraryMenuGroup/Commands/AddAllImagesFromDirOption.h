//
// Created by kriz on 26.04.2022.
//

#ifndef MAIN_CPP_ADDALLIMAGESFROMDIROPTION_H
#define MAIN_CPP_ADDALLIMAGESFROMDIROPTION_H

#include "../../../MenuCommands/MenuOption.h"
#include "../../../../ImageLibrary/ImagesLibrary.h"
#include "../../../../ImageLibrary/ImageFormatFactory.h"

class AddAllImagesFromDirOption : public MenuOption
{
public:
    AddAllImagesFromDirOption(ImagesLibrary& imagesLibrary);

    void Execute() override;

    std::unique_ptr<MenuGroup> CreateNextGroup(MenuGroupFactory &groupFactory) override;
private:
    ImageFormatFactory _formatFactory;

    ImagesLibrary& _imagesLibrary;
};


#endif //MAIN_CPP_ADDALLIMAGESFROMDIROPTION_H
