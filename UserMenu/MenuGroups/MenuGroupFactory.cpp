//
// Created by kriz on 06.03.2022.
//

#include "MenuGroupFactory.h"

#include "../MenuCommands/GoFiltersMenuGroup.h"
#include "../MenuCommands/GoMainMenuOption.h"
#include "../MenuCommands/GoLibraryMenuGroup.h"
#include "LibraryMenuGroup/Commands/ListAllImagesOption.h"

MenuGroupFactory::MenuGroupFactory(ImagesLibrary& imageLib) : _imageLibrary(imageLib) { }

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateMainMenuGroup() {
    auto newMainMenuGroup = std::make_unique<MainMenuGroup>();
    newMainMenuGroup->AddMenuOption("a", std::make_unique<GoLibraryMenuGroup>());
    newMainMenuGroup->AddMenuOption("b", std::make_unique<GoFiltersMenuGroup>());

    return std::move(newMainMenuGroup);
}

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateFiltersMenuGroup() {
    auto newFiltersMenuGroup = std::make_unique<SecondMenuGroup>();
    newFiltersMenuGroup->AddMenuOption("a", std::make_unique<GoMainMenuOption>());

    return std::move(newFiltersMenuGroup);
}

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateLibraryMenuGroup() {
    auto newLibraryMenuGroup = std::make_unique<LibraryMenuGroup>();
    newLibraryMenuGroup->AddMenuOption("a", std::make_unique<ListAllImagesOption>(_imageLibrary));
    newLibraryMenuGroup->AddMenuOption("b", std::make_unique<GoMainMenuOption>());
    return std::move(newLibraryMenuGroup);
}