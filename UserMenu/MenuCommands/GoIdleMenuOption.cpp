//
// Created by kriz on 06.03.2022.
//

#include "GoIdleMenuOption.h"

#include "../MenuGroups/MenuGroupFactory.h"

GoIdleMenuOption::GoIdleMenuOption() {
    _itemContent = "Go to first menu";
}

std::unique_ptr<MenuGroup> GoIdleMenuOption::CreateNextGroup(){
    MenuGroupFactory groupsFac;
    return std::move(groupsFac.CreateIdleMenuGroup());
}