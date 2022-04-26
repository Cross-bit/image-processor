//
// Created by kriz on 26.04.2022.
//

#ifndef MAIN_CPP_GOLIBRARYMENUGROUP_H
#define MAIN_CPP_GOLIBRARYMENUGROUP_H


#include "MenuOption.h"

class GoLibraryMenuGroup : public MenuOption {
public:
    GoLibraryMenuGroup();

    std::unique_ptr<MenuGroup> CreateNextGroup(MenuGroupFactory & groupFactory) override;
};



#endif //MAIN_CPP_GOLIBRARYMENUGROUP_H
