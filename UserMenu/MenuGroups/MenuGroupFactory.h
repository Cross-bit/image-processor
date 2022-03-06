//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_MENUGROUPFACTORY_H
#define IMAGEPROCESSOR_MENUGROUPFACTORY_H

#include "IdleMenuGroup/IdleMenuGroup.h"
#include "SecondMenuGroup/SecondMenuGroup.h"

class MenuGroupFactory {
public:
    /**
     * Creates new instance of idle menu group.
     * @return
     */
    std::unique_ptr<IdleMenuGroup> CreateIdleMenuGroup();

    /**
     * Creates new instance of second menu group.
     * @return
     */
    std::unique_ptr<SecondMenuGroup> CreateSecondMenuGroup();

};

#endif //IMAGEPROCESSOR_MENUGROUPFACTORY_H
