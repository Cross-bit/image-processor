//
// Created by kriz on 06.03.2022.
//

#include "GoFiltersMenuGroup.h"

#include "../MenuGroups/MenuGroupFactory.h"
#include "../UserMenu.h"
GoFiltersMenuGroup::GoFiltersMenuGroup() {
    _itemContent = "Go to filters menu";
}

std::unique_ptr<MenuGroup> GoFiltersMenuGroup::CreateNextGroup(UserMenu &userMenu) {
    return std::move(userMenu.GroupsFac.CreateFiltersMenuGroup());
}