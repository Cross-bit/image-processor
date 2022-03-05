#include "MenuItemGroup.h"

void MenuItemGroup::AddMenuOption(std::string indentificator, std::unique_ptr<MenuOption> option) {
	_menuOptions.insert(std::make_pair(indentificator, std::move(option)));
}

void MenuItemGroup::Render() {
	RenderHeader();
	RenderMenuItems();
}

void MenuItemGroup::OnUserChoice(std::string choice) {
	auto optionSearched = _menuOptions.find(choice);
	if (optionSearched != _menuOptions.end()) {
		optionSearched->second->Execute();
	}
	else {
		std::cout << "Choice \"" << choice << "\" not found" << std::endl;
	}
}

void MenuItemGroup::RenderHeader() {
	std::cout << _headerData << std::endl;
}

void MenuItemGroup::RenderBulletPoint(std::string innerText) {
	std::cout << innerText << _bulletPointEnd;
}

void MenuItemGroup::RenderMenuItems() {
	int ctr = 1;
	for (auto& menuOption : _menuOptions) {
		RenderBulletPoint(menuOption.first);
		menuOption.second->Render();
		std::cout << std::endl;
	}
}