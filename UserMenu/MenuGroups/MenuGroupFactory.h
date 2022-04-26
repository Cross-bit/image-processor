//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUGROUPFACTORY_H
#define IMAGEPROCESSOR_MENUGROUPFACTORY_H

#include "IdleMenuGroup/IdleMenuGroup.h"
#include "SecondMenuGroup/SecondMenuGroup.h"
#include "LibraryMenuGroup/LibraryMenuGroup.h"


#include "../../ImageLibrary/ImagesLibrary.h"
class MenuGroupFactory {
public:
    MenuGroupFactory(ImagesLibrary& imageLibrary);
    /**
     * Creates new instance of idle menu group.
     * @return
     */
    std::unique_ptr<MenuGroup> CreateIdleMenuGroup();

    /**
     * Creates new instance of second menu group.
     * @return
     */
    std::unique_ptr<MenuGroup> CreateSecondMenuGroup();

    std::unique_ptr<MenuGroup> CreateLibraryMenuGroup();
private:
    ImageLibrary& _imageLibrary;
};

#endif //IMAGEPROCESSOR_MENUGROUPFACTORY_H
