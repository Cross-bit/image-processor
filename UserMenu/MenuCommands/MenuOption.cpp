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

template <typename T>
void MenuOption::PrintInputFallback(const T& fallbackValue) {
    // it is up to user to specify all value types convertible to string(by to_string) in fallback arg, in ff declaration below
    std::cout << "No input provided. Default value will be used instead. (" << fallbackValue << std::to_string(fallbackValue) << ")" << std::endl;
}

// ff declaration for fallback prints (add if some more needed in the future)
template void MenuOption::PrintInputFallback<int>(const int&);
template void MenuOption::PrintInputFallback<double>(const double&);


MenuOption::~MenuOption(){ }
