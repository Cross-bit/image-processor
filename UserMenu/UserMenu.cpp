//
// Created by kriz on 06.03.2022.
//

#include "UserMenu.h"
#include <iostream>

#include "MenuGroups/MenuGroupFactory.h"

UserMenu::UserMenu(){
    MenuGroupFactory groupsFac;
    _currentMenuGroup = groupsFac.CreateIdleMenuGroup();
}

void UserMenu::SetNewMenuItem(std::unique_ptr<MenuGroup> menuItemToSet) {
	_currentMenuGroup = std::move(menuItemToSet);
}

void UserMenu::Update(){
	while (_isAppRunning) {
		_currentMenuGroup->Render();

        // todo: handling of global commands/options

		std::string userInput;
		std::getline(std::cin, userInput);

	    _currentMenuGroup->OnUserChoice(*this, userInput);
	}
}