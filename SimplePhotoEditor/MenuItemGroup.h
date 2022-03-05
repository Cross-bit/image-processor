#pragma once

#include "MenuOption.h"

class MenuItemGroup {
public:
	void AddMenuOption(std::string indentificator, std::unique_ptr<MenuOption> option);

	void Render();

	void OnUserChoice(std::string choice);

protected:
	std::string _headerData = "";
	std::string _bulletPointEnd = ") ";
	std::unordered_map<std::string, std::unique_ptr<MenuOption>> _menuOptions;

	virtual void RenderHeader();

	virtual void RenderBulletPoint(std::string innerText);

	virtual void RenderMenuItems();
};
