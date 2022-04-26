//
// Created by kriz on 06.03.2022.
//

#include "MenuGroupFactory.h"

#include "../MenuCommands/GoSecondMenuOption.h"
#include "../MenuCommands/GoIdleMenuOption.h"


#include "LibraryMenuGroup/Commands/ListAllImagesOption.h"

MenuGroupFactory::MenuGroupFactory(ImagesLibrary& imageLib) : _imageLibrary(imageLib) { }

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateIdleMenuGroup() {
    auto newIdleMenuGroup = std::make_unique<IdleMenuGroup>();
    newIdleMenuGroup->AddMenuOption("a", std::make_unique<GoSecondMenuOption>());

    return std::move(newIdleMenuGroup);
}

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateSecondMenuGroup() {
    auto newSecondMenuGroup = std::make_unique<SecondMenuGroup>();
    newSecondMenuGroup->AddMenuOption("1", std::make_unique<GoIdleMenuOption>());

    return std::move(newSecondMenuGroup);
}

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateLibraryMenuGroup() {
    auto newLibraryMenuGroup = std::make_unique<LibraryMenuGroup>();
    
    newLibraryMenuGroup->AddMenuOption("1", std::make_unique<ListAllImagesOption>(_imageLibrary));

    return std::move(newLibraryMenuGroup);
}