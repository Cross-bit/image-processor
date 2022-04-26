//
// Created by kriz on 26.04.2022.
//

#include "ListAllImagesOption.h"


ListAllImagesOption::ListAllImagesOption(ImagesLibrary& imagesLibrary) : _imagesLibrary(imagesLibrary) { }

std::unique_ptr<MenuGroup> ListAllImagesOption::CreateNextGroup(MenuGroupFactory & groupFactory) {
    std::cin;

    return std::move(groupFactory.CreateLibraryMenuGroup());
}