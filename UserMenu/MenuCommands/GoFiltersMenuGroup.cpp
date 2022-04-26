//
// Created by kriz on 06.03.2022.
//

#include "GoFiltersMenuGroup.h"

#include "../MenuGroups/MenuGroupFactory.h"

GoFiltersMenuGroup::GoFiltersMenuGroup() {
    _itemContent = "Go to filters menu";
}

std::unique_ptr<MenuGroup> GoFiltersMenuGroup::CreateNextGroup(MenuGroupFactory & groupFactory) {
    return std::move(groupFactory.CreateFiltersMenuGroup());
}