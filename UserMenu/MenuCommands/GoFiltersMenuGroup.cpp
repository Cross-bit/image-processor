//
// Created by kriz on 06.03.2022.
//

#include <sstream>
#include <iostream>
#include <string>
#include "GoFiltersMenuGroup.h"

#include "../MenuGroups/MenuGroupFactory.h"
#include "../UserMenu.h"

#include "../MenuGroups/LibraryMenuGroup/Commands/ListAllImagesOption.h"

GoFiltersMenuGroup::GoFiltersMenuGroup(ImagesLibrary& imagesLibrary) :
_imagesLibrary(imagesLibrary)
{
    _itemContent = "Go to filters menu";
}

std::unique_ptr<MenuGroup> GoFiltersMenuGroup::CreateNextGroup(UserMenu &userMenu) {
    return std::move(userMenu.GroupsFac.CreateFiltersMenuGroup(std::move(_imagesToFilter)));
}


void GoFiltersMenuGroup::Execute() {

    // first list all available images
    ListAllImagesOption listAllImagesCommand(_imagesLibrary);
    listAllImagesCommand.Execute();

    std::cout << "Enter numbers of images that you wish to modify(separated by space):" << std::endl;

    auto dataToModify = ReadUserInput();

    if(dataToModify.find_first_not_of("0123456789 ") != std::string::npos){
        PrintError("Invalid input!");
        return;
    }


    std::istringstream stringStream( dataToModify );

    int n;
    while ( stringStream >> n ) {

        if (!_imagesLibrary.CheckIfIndexIsValid(n)) {
            PrintWarning("Index " + std::to_string(n) + " is invalid and effect will be not applied!");
        }

        // add to the queue
        _imagesToFilter.emplace(n);
    }
}
