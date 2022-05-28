//
// Created by kriz on 06.03.2022.
//

#include "GoMainMenuOption.h"

#include "../../MenuGroupFactory.h"
#include "../../../UserMenu.h"

GoMainMenuOption::GoMainMenuOption() {
    _itemContent = "Go to main menu";
}

std::unique_ptr<MenuGroup> GoMainMenuOption::CreateNextGroup(UserMenu &userMenu) {
    return std::move(userMenu.GroupsFac.CreateMainMenuGroup());
}