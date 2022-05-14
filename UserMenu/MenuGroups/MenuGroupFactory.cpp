//
// Created by kriz on 06.03.2022.
//

#include <unordered_set>
#include "MenuGroupFactory.h"

#include "../MenuCommands/GoFiltersMenuGroup.h"
#include "../MenuCommands/GoMainMenuOption.h"
#include "../MenuCommands/GoLibraryMenuGroup.h"

#include "FiltersMenuGroup/FiltersMenuGroup.h"
#include "FiltersMenuGroup/Comands/ApplyLinearGrayscaleOption.h"
#include "FiltersMenuGroup/Comands/ApplyGaussianBlurOption.h"
#include "FiltersMenuGroup/Comands/ApplyBoxBlurOption.h"
#include "FiltersMenuGroup/Comands/ApplyNegativeOption.h"

#include "LibraryMenuGroup/Commands/ListAllImagesOption.h"
#include "LibraryMenuGroup/Commands/AddImageToLibrary.h"
#include "LibraryMenuGroup/Commands/AddAllImagesFromDirOption.h"


#include "queue"

MenuGroupFactory::MenuGroupFactory(ImagesLibrary& imageLib) : ImageLibrary(imageLib) { }

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateMainMenuGroup() {
    auto newMainMenuGroup = std::make_unique<MainMenuGroup>();
    newMainMenuGroup->AddMenuOption("a", std::make_unique<GoLibraryMenuGroup>());
    newMainMenuGroup->AddMenuOption("b", std::make_unique<GoFiltersMenuGroup>(ImageLibrary));

    return std::move(newMainMenuGroup);
}

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateFiltersMenuGroup(std::unordered_set<int> &&libraryIndexesToWorkWith) {
    auto newFiltersMenuGroup = std::make_unique<FiltersMenuGroup>();
    newFiltersMenuGroup->AddMenuOption("a", std::make_unique<ApplyLinearGrayscaleOption>(libraryIndexesToWorkWith, ImageLibrary));
    newFiltersMenuGroup->AddMenuOption("b", std::make_unique<ApplyGaussianBlurOption>(libraryIndexesToWorkWith, ImageLibrary));
    newFiltersMenuGroup->AddMenuOption("c", std::make_unique<ApplyBoxBlurOption>(libraryIndexesToWorkWith, ImageLibrary));
    newFiltersMenuGroup->AddMenuOption("d", std::make_unique<ApplyNegativeOption>(libraryIndexesToWorkWith, ImageLibrary));
    newFiltersMenuGroup->AddMenuOption("e", std::make_unique<GoMainMenuOption>());

    return std::move(newFiltersMenuGroup);
}

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateLibraryMenuGroup() {
    auto newLibraryMenuGroup = std::make_unique<LibraryMenuGroup>();
    newLibraryMenuGroup->AddMenuOption("a", std::make_unique<ListAllImagesOption>(ImageLibrary));
    newLibraryMenuGroup->AddMenuOption("b", std::make_unique<AddImageToLibrary>(ImageLibrary));
    newLibraryMenuGroup->AddMenuOption("c", std::make_unique<AddAllImagesFromDirOption>(ImageLibrary));
    newLibraryMenuGroup->AddMenuOption("d", std::make_unique<GoMainMenuOption>());
    return std::move(newLibraryMenuGroup);
}