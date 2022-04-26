//
// Created by kriz on 26.04.2022.
//

#include "AddImageToLibrary.h"

#include "../../MenuGroupFactory.h"

AddImageToLibrary::AddImageToLibrary(ImagesLibrary& imagesLibrary) : _imagesLibrary(imagesLibrary) {
    _itemContent = "List all images";
}

std::unique_ptr<MenuGroup> AddImageToLibrary::CreateNextGroup(MenuGroupFactory & groupFactory) {
    std::cin;
    return std::move(groupFactory.CreateLibraryMenuGroup());
}

void AddImageToLibrary::Execute()
{
}