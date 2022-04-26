//
// Created by kriz on 26.04.2022.
//

#ifndef MAIN_CPP_ADDIMAGETOLIBRARY_H
#define MAIN_CPP_ADDIMAGETOLIBRARY_H

#include "../../../MenuCommands/MenuOption.h"

#include "../../../../ImageLibrary/ImagesLibrary.h"

class AddImageToLibrary : public MenuOption {
public:
    AddImageToLibrary(ImagesLibrary& imagesLibrary);

    std::unique_ptr<MenuGroup> CreateNextGroup(MenuGroupFactory & groupFactory) override;

    void Execute() override;
private:
    ImagesLibrary& _imagesLibrary;
};


#endif //MAIN_CPP_ADDIMAGETOLIBRARY_H
