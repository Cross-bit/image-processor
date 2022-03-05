#pragma once

#include "MenuItemGroup.h"

class UserMenu {
public:
	UserMenu() {}
	~UserMenu() {}

	void SetNewMenuItem(std::unique_ptr<MenuItemGroup> menuItemToSet);

	void Update();

private:
	std::unique_ptr<MenuItemGroup> _currentMenuGroup;
	bool _isAppRunning = true;
};