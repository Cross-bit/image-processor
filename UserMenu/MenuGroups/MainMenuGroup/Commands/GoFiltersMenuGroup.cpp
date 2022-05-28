//
// Created by kriz on 06.03.2022.
//

#include <sstream>
#include <iostream>
#include <string>
#include "GoFiltersMenuGroup.h"

#include "../../MenuGroupFactory.h"
#include "../../../UserMenu.h"

#include "../../LibraryMenuGroup/Commands/ListAllImagesOption.h"

GoFiltersMenuGroup::GoFiltersMenuGroup(ImagesLibrary& imagesLibrary) :
_imagesLibrary(imagesLibrary)
{
    _itemContent = "Go to filters menu";
}

std::unique_ptr<MenuGroup> GoFiltersMenuGroup::CreateNextGroup(UserMenu &userMenu) {
    return _executionSucceeded ? std::move(userMenu.GroupsFac.CreateFiltersMenuGroup(std::move(_imagesToFilter))) : nullptr;
}


void GoFiltersMenuGroup::Execute(UserMenu& userMenu) {

    // first list all available images
    ListAllImagesOption listAllImagesCommand(_imagesLibrary);
    listAllImagesCommand.Execute(userMenu);

    PrintLine("Enter indexes of images that you wish to modify(separated by space):");

    auto rawImgIndexes = ReadUserInput();

    // special value
    if (rawImgIndexes == allIndexesSpecial){
        AddAllIndexes();
        _executionSucceeded = !_imagesToFilter.empty();
        return;
    }

    if (rawImgIndexes.find_first_not_of("0123456789" + WHITESPACE) != std::string::npos){
        PrintError("Invalid input!");
        _executionSucceeded = false;
        return;
    }

    if (CheckStringIsEmpty(rawImgIndexes)) {
        _executionSucceeded = false;
        PrintError("Input provided is empty!");
        return;
    }

    ParseIndexes(rawImgIndexes);

    if (_imagesToFilter.empty()) {
        PrintError("All provided inputs are invalid!");
        return;
    }

    _executionSucceeded = true;
}

void GoFiltersMenuGroup::AddAllIndexes() {
    auto beginIterator = _imagesLibrary.Begin();
    for (auto it = beginIterator; it != _imagesLibrary.End(); ++it) {
        int indexVal = std::distance(_imagesLibrary.Begin(), it);
        _imagesToFilter.emplace(indexVal);
    }
}

void GoFiltersMenuGroup::ParseIndexes(std::string toParseFrom) {
    size_t pos = 0;
    while (!CheckStringIsEmpty(toParseFrom)) {

        size_t tmpPos = toParseFrom.find_first_of(WHITESPACE);
        pos = (tmpPos == std::string::npos ? toParseFrom.length() : tmpPos);

        std::string imgIndex = toParseFrom.substr(0, pos);
        toParseFrom.erase(0, pos + 1);

        if (CheckStringIsEmpty(imgIndex))
            continue;
        else {
            if (!CheckIfStringIsNaturalNumber(imgIndex)) {
                PrintWarning("Index " + imgIndex + " is invalid and value will be ignored!");
                continue;
            }

            int indexValue = std::stoi(imgIndex);

            if (indexValue <= std::distance(_imagesLibrary.Begin(), _imagesLibrary.End()))
                _imagesToFilter.emplace(indexValue);
            else
                PrintWarning("Index " + imgIndex + " is invalid and value will be ignored!");
        }
    }
}
