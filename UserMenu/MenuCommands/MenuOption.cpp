//
// Created by kriz on 06.03.2022.
//

#include "MenuOption.h"

void MenuOption::Render(){
    std::cout << _itemContent;
}

void MenuOption::Execute() { }

void MenuOption::PrintError(const std::string& callbackMessage) {
    std::cout << "Error: " << callbackMessage << std::endl;
}

void MenuOption::PrintWarning(const std::string& callbackMessage) {
    std::cout << "Warning: " << callbackMessage << std::endl;
}

template<typename T>
void MenuOption::PrintInputFallback(const T & fallbackValue) {

    //if (!std::is_same<T, int>::value && !std::is_same<T, float>::value && !std::is_same<T, double>::value && !std::is_same<T, std::string>::value)
    if (!std::is_convertible<T, std::string>::value) {
        return;
    }

    std::cout << "No input provided. Default value will be used instead. (" << fallbackValue << std::to_string(fallbackValue) << ")" << std::endl;
}

std::string MenuOption::ReadUserInput() const {
    std::string input;
    getline(std::cin, input);

    return std::move(input);
}

MenuOption::~MenuOption(){ }
