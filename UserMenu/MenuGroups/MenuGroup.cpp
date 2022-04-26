//
// Created by kriz on 06.03.2022.
//

#include "MenuGroup.h"

#include "../UserMenu.h"
//public

void MenuGroup::AddMenuOption(std::string indentificator, std::unique_ptr<MenuOption> option) {
    //auto valueTuple = std::make_tuple(std::move(option), std::move(groupToTransitionIn));
    _menuOptions.insert(std::make_pair(indentificator, std::move(option)));
}


void MenuGroup::Render() {
    RenderHeader();
    RenderMenuItems();
}

void MenuGroup::OnUserChoice(UserMenu& userMenu, std::string choice) {
    auto optionSearched = _menuOptions.find(choice);
    if (optionSearched != _menuOptions.end()) {
        optionSearched->second->Execute();

        userMenu.SetNewMenuItem(std::move(optionSearched->second->CreateNextGroup(userMenu)));
    }
    else {
        std::cout << "Choice \"" << choice << "\" not found" << std::endl;
    }
}

// private
void ChangeMenuGroup(UserMenu& userMenu, std::unique_ptr<MenuGroup> groupToChangeTo) {
   // userMenu.SetNewMenuItem(std::move(groupToChangeTo));
}



// protected

void MenuGroup::RenderHeader() {
    std::cout << "-- " << _headerData << " --" << std::endl;
}

void MenuGroup::RenderBulletPoint(std::string innerText) {
    std::cout << innerText << _bulletPointEnd;
}

void MenuGroup::RenderMenuItems(){
    for (auto& menuOption : _menuOptions) {
        RenderBulletPoint(menuOption.first);
        menuOption.second->Render();
        std::cout << std::endl;
    }
}

