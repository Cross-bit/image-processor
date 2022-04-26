//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_USERMENU_H
#define IMAGEPROCESSOR_USERMENU_H

#include "MenuGroups/MenuGroup.h"

class UserMenu {
public:
    UserMenu(MenuGroupFactory &groupsFac);

    void SetNewMenuItem(std::unique_ptr<MenuGroup> menuItemToSet);

    void Update();

    MenuGroupFactory &GroupsFac;

private:
	std::unique_ptr<MenuGroup> _currentMenuGroup;

	bool _isAppRunning = true;
};

#endif //IMAGEPROCESSOR_USERMENU_H