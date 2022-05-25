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
    void PrintInputFallback(const T& fallbackValue) const;

    static bool CheckStringIsEmpty(const std::string& inputToCheck);
    static std::string TrimInputWhiteSpaces(const std::string& inputToTrim);
    static std::string TrimInputWhiteSpacesFront(const std::string& inputToTrim);
    static std::string TrimInputWhiteSpacesBack(const std::string& inputToTrim);

    /**
     * Reads user input.
     * @return Input provided by user.
     */
    virtual std::string ReadUserInput() const;

    /**
     * Reads user input and checks if matches provided pattern.
     * @param possibleInputs Input that is expected.
     * @param inputValue Actual input user provided.
     * @return Whether value provided by user equals expected pattern.
     */
    virtual bool ReadUserChoice(const std::string& possibleInputs, std::string& inputValue) const;

    /**
     * Reads user input and checks if given input is valid based on provided input patterns.
     * @param possibleInputs Valid inputs.
     * @param inputValue Actual input user provided.
     * @return Whether the value provided is in the possible expected patterns.
     */
    virtual bool ReadUserChoices(const std::vector<std::string>& possibleInputs, std::string& inputValue) const;

    /**
     * Reads user yes no input.
     * @param inputValue Actual input user provided.
     * @return y/n based on user input. If input is invalid returns false and sets input value to "".
     */
    bool ReadUserYesNo(bool& result) const;
};

#endif //IMAGEPROCESSOR_MENUOPTION_H