//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_USERMENU_H
#define IMAGEPROCESSOR_USERMENU_H

#include "MenuGroups/MenuGroup.h"
#include "../Services/ConfigurationLoader.h"

/**
 * Main class representing user menu.
 */
class UserMenu {
public:
    /**
     * Constructor of UserMenu
     * @param groupsFac Reference to groups menu factory, for menus creation.
     * @param configurationContext Configuration context.
     */
    UserMenu(MenuGroupFactory &groupsFac, ConfigurationContext configurationContext);

    void SetNewMenuItem(std::unique_ptr<MenuGroup> menuItemToSet);

    void Initialize();

    void Update();

    MenuGroupFactory &GroupsFac;

    std::unique_ptr<MenuGroup> GetCurrentMenuGroup();

    ConfigurationContext ConfigurationCtx;

private:
	std::unique_ptr<MenuGroup> _currentMenuGroup;

	bool _isAppRunning = true;
};

#endif //IMAGEPROCESSOR_USERMENU_H