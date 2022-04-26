//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUOPTION_H
#define IMAGEPROCESSOR_MENUOPTION_H

#include <string>
#include <memory>
#include <iostream>
#include <map>

class MenuGroup;
class MenuGroupFactory;

/**
 * Base class for menu option command.
 */
class MenuOption {
public:

    virtual void Render();

    virtual void Execute();

	virtual std::unique_ptr<MenuGroup> CreateNextGroup(MenuGroupFactory & groupFactory)= 0;

protected:
    std::string _itemContent = "Item content is not filled";
};

#endif //IMAGEPROCESSOR_MENUOPTION_H