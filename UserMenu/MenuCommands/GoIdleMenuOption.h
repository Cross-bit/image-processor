//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_GOIDLEMENUOPTION_H
#define IMAGEPROCESSOR_GOIDLEMENUOPTION_H

#include "../MenuGroups/MenuOption.h"



class GoIdleMenuOption : public MenuOption {
public:
    GoIdleMenuOption();

    std::unique_ptr<MenuGroup> CreateNextGroup() override;
};

#endif //IMAGEPROCESSOR_GOIDLEMENUOPTION_H