//
// Created by kriz on 06.03.2022.
//

#include "MenuGroup.h"

#include "../UserMenu.h"
//public

void MenuGroup::AddMenuOption(std::string indentificator, std::unique_ptr<MenuOption> option) {
    _menuOptions.insert(std::make_pair(indentificator, std::move(option)));
}

std::string MenuGroup::FindOptionAlphaName(int index) {
    // basically excel column like mapping

    std::string result;

    while (index > 0) {
        int rem = index % 26;

        if (rem == 0) {
            result += 'Z';
            index = (index / 26) - 1;
        }
        else {
            result += (rem - 1) + 'A';
            index /= 26;
        }
    }

    return result;
}

void MenuGroup::AddMenuOptions(std::vector<std::unique_ptr<MenuOption>> &options, MenuGroup::BulletPointType bulletType) {

    switch (bulletType) {
        case NUMERIC:

            break;

        default:
        case ALPHABET:
            for(auto it = options.begin(); it != options.end(); ++it){
                _menuOptions.insert(std::make_pair(FindOptionAlphaName(1 + std::distance(options.begin(),it)), std::move(*it)));
            }
            break;
    }
}


void MenuGroup::Render() {
    RenderHeader();
    RenderMenuItems();
}

void MenuGroup::OnUserChoice(UserMenu& userMenu, std::string choice) {
    auto optionSearched = _menuOptions.find(choice);
    if (optionSearched != _menuOptions.end()) {
        // 1) execute command
        optionSearched->second->Execute();

        // 2) navigate to next menu group
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


MenuGroup::~MenuGroup() {}
