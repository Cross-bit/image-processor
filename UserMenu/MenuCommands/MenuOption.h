//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUOPTION_H
#define IMAGEPROCESSOR_MENUOPTION_H

#include <string>
#include <memory>
#include <iostream>
#include <map>
#include <vector>

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

    static const std::string WHITESPACE;
protected:
    std::string _itemContent = "Item content is not filled";

    virtual void PrintError(const std::string& callbackMessage);
    virtual void PrintWarning(const std::string& callbackMessage);

    virtual void Print(const std::string& messageToPrint);
    virtual void PrintLine(const std::string& messageToPrint);
    virtual void PrintList(const std::vector<std::string>& messagesToPrint, std::string optionalBullet = "->");

    template <typename T>
    void PrintInputFallback(const T& fallbackValue);

    static bool CheckStringIsEmpty(const std::string& inputToCheck);
    static std::string TrimInputWhiteSpaces(const std::string& inputToTrim);
    static std::string TrimInputWhiteSpacesFront(const std::string& inputToTrim);
    static std::string TrimInputWhiteSpacesBack(const std::string& inputToTrim);

    virtual std::string ReadUserInput() const;
};

#endif //IMAGEPROCESSOR_MENUOPTION_H