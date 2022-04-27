//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUGROUPFACTORY_H
#define IMAGEPROCESSOR_MENUGROUPFACTORY_H

#include "MainMenuGroup/MainMenuGroup.h"
#include "LibraryMenuGroup/LibraryMenuGroup.h"


#include "../../ImageLibrary/ImagesLibrary.h"
#include <queue>
class MenuGroupFactory {
public:
    MenuGroupFactory(ImagesLibrary& imageLibrary);
    /**
     * Creates new instance of idle menu group.
     * @return
     */
    std::unique_ptr<MenuGroup> CreateMainMenuGroup();

    /**
     * Creates new instance of second menu group.
     * @return
     */
    std::unique_ptr<MenuGroup> CreateFiltersMenuGroup(std::queue<int>& libraryIndexesToWorkWith);

    std::unique_ptr<MenuGroup> CreateLibraryMenuGroup();

    ImagesLibrary& ImageLibrary;
};

#endif //IMAGEPROCESSOR_MENUGROUPFACTORY_H
