//
// Created by kriz on 06.03.2022.
//

#include <sstream>
#include <iostream>
#include <string>


#include "MenuOption.h"
#include "../../ImageLibrary/ImagesLibrary.h"
#include <queue>
#include <unordered_set>

#include "EndApplicationOption.h"

#include "../MenuGroups/MenuGroupFactory.h"
#include "../UserMenu.h"

#include "../MenuGroups/LibraryMenuGroup/Commands/ListAllImagesOption.h"

EndApplicationOption::EndApplicationOption() {
    _itemContent = "End";
}

std::unique_ptr<MenuGroup> EndApplicationOption::CreateNextGroup(UserMenu &userMenu) {
    return nullptr;
}

void EndApplicationOption::Execute(UserMenu& userMenu) {
    std::cout << "Application is ending...";
    userMenu._isAppRunning = false;
}
