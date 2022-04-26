//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_GOSECONDMENUOPTION_H
#define IMAGEPROCESSOR_GOSECONDMENUOPTION_H


#include "MenuOption.h"

class GoFiltersMenuGroup : public MenuOption {
public:
    GoFiltersMenuGroup();

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu &userMenu) override;
};




#endif //IMAGEPROCESSOR_GOSECONDMENUOPTION_H
