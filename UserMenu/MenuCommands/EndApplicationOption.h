//
// Created by kriz on 28.05.2022.
//

#ifndef MAIN_CPP_ENDAPPLICATIONOPTION_H
#define MAIN_CPP_ENDAPPLICATIONOPTION_H

#include "MenuOption.h"

class EndApplicationOption : public MenuOption {
public:
    EndApplicationOption();

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu &userMenu) override;

    void Execute(UserMenu& userMenu) override;

};

#endif //MAIN_CPP_ENDAPPLICATIONOPTION_H
