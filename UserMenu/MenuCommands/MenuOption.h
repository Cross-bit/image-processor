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
#include <float.h>
#include <limits.h>

class MenuGroup;
class MenuGroupFactory;

class UserMenu;

// basic text foreground colors
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

/**
 * Base class for menu option command.
 */
class MenuOption {
public:
    virtual void Render();

    virtual ~MenuOption();

    virtual void Execute(UserMenu& userMenu);

	virtual std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu & groupFactory)= 0;

    static const std::string WHITESPACE;
protected:
    std::string _itemContent = "Item content is not filled";

    virtual void PrintError(const std::string& callbackMessage);
    virtual void PrintWarning(const std::string& callbackMessage);

    virtual void Print(const std::string& messageToPrint);
    virtual void PrintLine(const std::string& messageToPrint);
    virtual void PrintList(const std::vector<std::string>& messagesToPrint, std::string optionalBullet = "->");
    virtual void PrintSuccess(const std::string& messageToPrint);


    template <typename T>
    void PrintInputFallback(const T& fallbackValue) const;

    void PrintInputFallback(const char& fallbackValue) const;

    void PrintInputFallback(const std::string& fallbackValue) const;

    static bool CheckStringIsEmpty(const std::string& inputToCheck);

    static bool CheckIfStringIsNaturalNumber(std::string& stringToCheck);

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

     /**
      * Tries to read users input and convert it to natural number.
      * @param userInput Converted input. If not possible sets to -1
      * @param min Minimal possible value def.: 0
      * @param max Maximal possible value def.: 2147483647 (int max)
      * @return true if conversion succeeded, false otherwise
      */
    bool ReadUserInputNaturalNum(int& userInput, const unsigned int min = 0, const unsigned int max = INT_MAX) const;

    /**
     * Tries to read users input and convert it to real number.
     * @param userInput Converted input. If not possible sets to 0
     * @param min Minimal possible value def.: DBL_MIN
     * @param max Maximal possible value def.: DBL_MAX
     * @return true if conversion succeeded, false otherwise
     */
    bool ReadUserInputDecimal(double& userInput, const double min = DBL_MIN, const double max = DBL_MAX) const;

    std::string GetFallbackMessage(const std::string& defValue) const;
};

#endif //IMAGEPROCESSOR_MENUOPTION_H