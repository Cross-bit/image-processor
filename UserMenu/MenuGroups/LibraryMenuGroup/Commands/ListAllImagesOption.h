//
// Created by kriz on 26.04.2022.
//

#ifndef MAIN_CPP_LISTALLIMAGESOPTION_H
#define MAIN_CPP_LISTALLIMAGESOPTION_H


#include "../../../MenuCommands/MenuOption.h"

#include "../../../../ImageLibrary/ImagesLibrary.h"

class ListAllImagesOption : public MenuOption {
public:
    ListAllImagesOption(ImagesLibrary& imagesLibrary);

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu &userMenu) override;

    void Execute() override;
private:
    ImagesLibrary& _imagesLibrary;
};


#endif //MAIN_CPP_LISTALLIMAGESOPTION_H
