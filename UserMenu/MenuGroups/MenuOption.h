//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUOPTION_H
#define IMAGEPROCESSOR_MENUOPTION_H

#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

class MenuGroup;

class MenuOption {
public:

    void Render();

    void Execute();

	virtual std::unique_ptr<MenuGroup> CreateNextGroup() = 0;

protected:

    std::string _itemContent = "bla bla cool";
};

#endif //IMAGEPROCESSOR_MENUOPTION_H