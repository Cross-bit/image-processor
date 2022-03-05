#include "UserMenu.h";

void UserMenu::SetNewMenuItem(std::unique_ptr<MenuItemGroup> menuItemToSet) {
	_currentMenuGroup = std::move(menuItemToSet);
}

void UserMenu::Update(){
	while (_isAppRunning) {
		_currentMenuGroup->Render();

		std::string userInput;
		std::getline(std::cin, userInput);

		_currentMenuGroup->OnUserChoice(userInput);
	}
}