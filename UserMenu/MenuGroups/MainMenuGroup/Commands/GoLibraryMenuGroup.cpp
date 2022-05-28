//
// Created by kriz on 26.04.2022.
//

#include "GoLibraryMenuGroup.h"

#include "../../MenuGroupFactory.h"
#include "../../../UserMenu.h"
GoLibraryMenuGroup::GoLibraryMenuGroup() {
    _itemContent = "Go to image library";
}

std::unique_ptr<MenuGroup> GoLibraryMenuGroup::CreateNextGroup(UserMenu &userMenu) {
    return std::move(userMenu.GroupsFac.CreateLibraryMenuGroup());
}