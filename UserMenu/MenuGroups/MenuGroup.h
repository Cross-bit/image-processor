//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUGROUP_H
#define IMAGEPROCESSOR_MENUGROUP_H

#include "../MenuCommands/MenuOption.h"
class UserMenu;

class MenuGroup {
public:

    enum BulletPointType { ALPHABET_LOWER, NUMERIC };

    BulletPointType bulletType = MenuGroup::ALPHABET_LOWER;

    /**
     * Adds new menu option to the menu group.
     * @param bulletPoint
     * @param option
     */
    void AddMenuOption(
        const std::string& indentificator,
        std::unique_ptr<MenuOption> option
    );

    /**
     * Adds new menu options to the menu group, with automatically generated bullet points(based on the bullet type enum).
     * @param options
     */
    void AddMenuOptions(
            std::vector<std::unique_ptr<MenuOption>> &options,
            BulletPointType bulletType = BulletPointType::ALPHABET_LOWER
    );

    void Render();

    void OnUserChoice(UserMenu& userMenu, std::string choice);

    virtual ~MenuGroup();
protected:
    std::string _headerData = "";
    std::string _bulletPointEnd = ") ";
    std::map<std::string, std::unique_ptr<MenuOption>> _menuOptions;

    virtual void RenderHeader();

    virtual void RenderBulletPoint(std::string innerText);

    virtual void RenderMenuItems();
private:
    std::string FindOptionAlphaName(int index, bool capital = false);

};

#endif //IMAGEPROCESSOR_MENUGROUP_H