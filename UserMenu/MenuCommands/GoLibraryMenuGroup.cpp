//
// Created by kriz on 26.04.2022.
//

#include "GoLibraryMenuGroup.h"

#include "../MenuGroups/MenuGroupFactory.h"

GoLibraryMenuGroup::GoLibraryMenuGroup() {
    _itemContent = "Go image library";
}

std::unique_ptr<MenuGroup> GoLibraryMenuGroup::CreateNextGroup(MenuGroupFactory & groupFactory) {
    return std::move(groupFactory.CreateLibraryMenuGroup());
}