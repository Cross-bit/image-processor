//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUGROUP_H
#define IMAGEPROCESSOR_MENUGROUP_H

#include "MenuOption.h"

class UserMenu;

class MenuGroup{
public:
    void AddMenuOption(
            std::string indentificator,
            std::unique_ptr<MenuOption> option
    );

    void Render();

    void OnUserChoice(UserMenu& userMenu, std::string choice);

protected:
    std::string _headerData = "";
    std::string _bulletPointEnd = ") ";
    std::unordered_map<std::string, std::unique_ptr<MenuOption>> _menuOptions;

    virtual void RenderHeader();

    virtual void RenderBulletPoint(std::string innerText);

    virtual void RenderMenuItems();
};

#endif //IMAGEPROCESSOR_MENUGROUP_H