//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_GOIDLEMENUOPTION_H
#define IMAGEPROCESSOR_GOIDLEMENUOPTION_H

#include "MenuOption.h"

class GoMainMenuOption : public MenuOption {
public:
    GoMainMenuOption();

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu &userMenu) override;
};

#endif //IMAGEPROCESSOR_GOIDLEMENUOPTION_H