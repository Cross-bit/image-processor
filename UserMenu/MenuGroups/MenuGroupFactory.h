//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUGROUPFACTORY_H
#define IMAGEPROCESSOR_MENUGROUPFACTORY_H

#include "MainMenuGroup/MainMenuGroup.h"
#include "LibraryMenuGroup/LibraryMenuGroup.h"


#include "../../ImageLibrary/ImagesLibrary.h"
#include <queue>
#include <unordered_set>

//#include <unordered_set>
class MenuGroupFactory {
public:
    MenuGroupFactory(ImagesLibrary& imageLibrary);
    /**
     * Creates new instance of main menu group.
     * @return
     */
    std::unique_ptr<MenuGroup> CreateMainMenuGroup();

    /**
     * Creates new instance of filters menu group.
     * @return
     */
    std::unique_ptr<MenuGroup> CreateFiltersMenuGroup(std::unordered_set<int> &&libraryIndexesToWorkWith);

    /**
     * Creates new instance of library menu group.
     * @return
     */
    std::unique_ptr<MenuGroup> CreateLibraryMenuGroup();


    ImagesLibrary& ImageLibrary;
};

#endif //IMAGEPROCESSOR_MENUGROUPFACTORY_H
