//
// Created by kriz on 06.03.2022.
//

#include "UserMenu.h"
#include <iostream>

#include "MenuGroups/MenuGroupFactory.h"
#include "MenuGroups/LibraryMenuGroup/Commands/AddAllImagesFromDirOption.h"


UserMenu::UserMenu(MenuGroupFactory &groupsFac) : GroupsFac(groupsFac)
{
    _currentMenuGroup = GroupsFac.CreateMainMenuGroup();
}

void UserMenu::SetNewMenuItem(std::unique_ptr<MenuGroup> menuItemToSet) {

    if(menuItemToSet == nullptr)
        return; // do nothing (e.g. we want to keep current menu)

	_currentMenuGroup = std::move(menuItemToSet);
}

std::unique_ptr<MenuGroup> UserMenu::GetCurrentMenuGroup() {
    return std::move(_currentMenuGroup);
}

void UserMenu::Initialize(const std::string& inputImageFolder) {

    std::cout << "Initializing data..." << std::endl;

    std::cout.setstate(std::ios_base::failbit);

    // todo: abstract ass initial list of commands to execute?
    AddAllImagesFromDirOption allImagesFromDirCommand(GroupsFac.ImageLibrary, inputImageFolder);
    allImagesFromDirCommand.Execute();

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