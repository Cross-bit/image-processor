//
// Created by kriz on 06.03.2022.
//

#include <unordered_set>
#include "MenuGroupFactory.h"

#include "MainMenuGroup/Commands/GoFiltersMenuGroup.h"
#include "MainMenuGroup/Commands/GoMainMenuOption.h"
#include "MainMenuGroup/Commands/GoLibraryMenuGroup.h"
#include "../OtherMenuCommands/EndApplicationOption.cpp"

#include "FiltersMenuGroup/FiltersMenuGroup.h"
#include "FiltersMenuGroup/Commands/ApplyLinearGrayscaleOption.h"
#include "FiltersMenuGroup/Commands/ApplyAverageGrayscaleOption.h"
#include "FiltersMenuGroup/Commands/ApplyGaussianBlurOption.h"
#include "FiltersMenuGroup/Commands/ApplyBoxBlurOption.h"
#include "FiltersMenuGroup/Commands/ApplyNegativeOption.h"
#include "FiltersMenuGroup/Commands/ApplyFlipTransformOption.h"
#include "FiltersMenuGroup/Commands/ApplySobelOption.h"
#include "FiltersMenuGroup/Commands/ApplyASCIIArtEffect.h"


#include "LibraryMenuGroup/Commands/ListAllImagesOption.h"
#include "LibraryMenuGroup/Commands/AddImageToLibrary.h"
#include "LibraryMenuGroup/Commands/AddAllImagesFromDirOption.h"


#include "queue"

MenuGroupFactory::MenuGroupFactory(ImagesLibrary& imageLib) : ImageLibrary(imageLib) { }

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateMainMenuGroup() {
    auto newMainMenuGroup = std::make_unique<MainMenuGroup>();
    newMainMenuGroup->AddMenuOption("a", std::make_unique<GoLibraryMenuGroup>());
    newMainMenuGroup->AddMenuOption("b", std::make_unique<GoFiltersMenuGroup>(ImageLibrary));
    newMainMenuGroup->AddMenuOption("c", std::make_unique<EndApplicationOption>());
    return std::move(newMainMenuGroup);
}

std::unique_ptr<MenuGroup> MenuGroupFactory::CreateFiltersMenuGroup(std::unordered_set<int> &&libraryIndexesToWorkWith) {
    std::vector<std::unique_ptr<MenuOption>> options;

    options.emplace_back(std::make_unique<ApplyLinearGrayscaleOption>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<ApplyAverageGrayscaleOption>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<ApplyGaussianBlurOption>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<ApplyBoxBlurOption>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<ApplySobelOption>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<ApplyNegativeOption>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<ApplyFlipTransformOption>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<ApplyASCIIArtEffect>(libraryIndexesToWorkWith, ImageLibrary));
    options.emplace_back(std::make_unique<GoMainMenuOption>());

    auto newFiltersMenuGroup = std::make_unique<FiltersMenuGroup>();

    newFiltersMenuGroup->AddMenuOptions(options, MenuGroup::ALPHABET_LOWER);
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