//
// Created by kriz on 06.03.2022.
//

#include "MenuGroupFactory.h"

#include "../MenuCommands/GoSecondMenuOption.h"
#include "../MenuCommands/GoIdleMenuOption.h"

std::unique_ptr<IdleMenuGroup> MenuGroupFactory::CreateIdleMenuGroup() {
    auto newIdleMenuGroup = std::make_unique<IdleMenuGroup>();
    newIdleMenuGroup->AddMenuOption("a", std::make_unique<GoSecondMenuOption>());

    return std::move(newIdleMenuGroup);
}

std::unique_ptr<SecondMenuGroup> MenuGroupFactory::CreateSecondMenuGroup() {
    auto newSecondMenuGroup = std::make_unique<SecondMenuGroup>();
    newSecondMenuGroup->AddMenuOption("1", std::make_unique<GoIdleMenuOption>());

    return std::move(newSecondMenuGroup);
}