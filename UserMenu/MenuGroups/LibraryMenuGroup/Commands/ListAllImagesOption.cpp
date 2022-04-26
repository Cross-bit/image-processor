//
// Created by kriz on 26.04.2022.
//

#include "ListAllImagesOption.h"
#include "../../MenuGroupFactory.h"

ListAllImagesOption::ListAllImagesOption(ImagesLibrary& imagesLibrary) : _imagesLibrary(imagesLibrary) {
    _itemContent = "List all images";
}

std::unique_ptr<MenuGroup> ListAllImagesOption::CreateNextGroup(MenuGroupFactory & groupFactory) {
    std::cin;
    return std::move(groupFactory.CreateLibraryMenuGroup());
}

void ListAllImagesOption::Execute() {

    _imagesLibrary.UpdateRecords();

    std::cout << "/----------------------------------------------------------/" << std::endl;

    if(_imagesLibrary.Begin() == _imagesLibrary.End())
        std::cout << "Nothing here... " << std::endl;

    int ctr = 0;
    for (auto it = _imagesLibrary.Begin(); it != _imagesLibrary.End(); ++it) {
        std::cout << std::to_string(ctr) << " " << it->first << std::endl;
        ctr++;
    }

    std::cout << "/----------------------------------------------------------/" << std::endl;
}