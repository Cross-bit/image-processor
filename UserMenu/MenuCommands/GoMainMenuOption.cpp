//
// Created by kriz on 06.03.2022.
//

#include "GoMainMenuOption.h"

#include "../MenuGroups/MenuGroupFactory.h"

GoMainMenuOption::GoMainMenuOption() {
    _itemContent = "Go to main menu";
}

std::unique_ptr<MenuGroup> GoMainMenuOption::CreateNextGroup(MenuGroupFactory & groupFactory) {
    return std::move(groupFactory.CreateMainMenuGroup());
}