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

class UserMenu;
/**
 * Base class for menu option command.
 */
class MenuOption {
public:
    virtual void Render();

    virtual ~MenuOption();

    virtual void Execute();

	virtual std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu & groupFactory)= 0;

protected:
    std::string _itemContent = "Item content is not filled";

    virtual void PrintError(const std::string& callbackMessage);
    virtual void PrintWarning(const std::string& callbackMessage);

    template <typename T>
    void PrintInputFallback(const T& fallbackValue);

    virtual std::string ReadUserInput() const;

};

#endif //IMAGEPROCESSOR_MENUOPTION_H