//
// Created by kriz on 06.03.2022.
//

#include "UserMenu.h"
#include <iostream>
#include <filesystem>

#include "MenuGroups/MenuGroupFactory.h"
#include "MenuGroups/LibraryMenuGroup/Commands/AddAllImagesFromDirOption.h"

UserMenu::UserMenu(MenuGroupFactory &groupsFac, ConfigurationContext configurationCtx) :
GroupsFac(groupsFac), ConfigurationCtx(configurationCtx)
{
    _currentMenuGroup = GroupsFac.CreateMainMenuGroup();
}

void UserMenu::SetNewMenuItem(std::unique_ptr<MenuGroup> menuItemToSet) {

    if (menuItemToSet == nullptr)
        return; // do nothing (e.g. we want to keep current menu)

	_currentMenuGroup = std::move(menuItemToSet);
}

std::unique_ptr<MenuGroup> UserMenu::GetCurrentMenuGroup() {
    return std::move(_currentMenuGroup);
}

void UserMenu::Initialize() {

    std::cout << "Initializing data..." << std::endl;

    std::cout.setstate(std::ios_base::failbit); // turns off images

    if (!std::filesystem::exists(ConfigurationCtx.DefaultInputDir)){
        std::cout << "Invalid input directory in configuration provided." << std::endl;
        std::cout.clear();
        return;
    }

    AddAllImagesFromDirOption allImagesFromDirCommand(GroupsFac.ImageLibrary, ConfigurationCtx.DefaultInputDir);
    allImagesFromDirCommand.Execute(*this);

    std::cout.clear();
    std::cout << "Done!" << std::endl;
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