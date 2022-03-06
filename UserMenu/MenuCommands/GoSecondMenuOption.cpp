//
// Created by kriz on 06.03.2022.
//

#include "GoSecondMenuOption.h"

#include "../MenuGroups/MenuGroupFactory.h"

GoSecondMenuOption::GoSecondMenuOption() {
    _itemContent = "Go to second menu...";
}

std::unique_ptr<MenuGroup> GoSecondMenuOption::CreateNextGroup() {
    MenuGroupFactory groupsFac;
    return std::move(groupsFac.CreateSecondMenuGroup());
}