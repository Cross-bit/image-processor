//
// Created by kriz on 26.04.2022.
//

#ifndef MAIN_CPP_SETDEFAULTINPUTDIRECTORY_H
#define MAIN_CPP_SETDEFAULTINPUTDIRECTORY_H


#include "../../../MenuCommands/MenuOption.h"

class SetDefaultInputDirectory : MenuOption
{
public:
    SetDefaultInputDirectory();

    void Execute(UserMenu& userMenu) override;
};


#endif //MAIN_CPP_SETDEFAULTINPUTDIRECTORY_H
