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

std::string MenuOption::ReadUserInput() const {
    std::string input;
    getline(std::cin, input);

    return std::move(input);
}

MenuOption::~MenuOption(){ }
