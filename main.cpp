#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoIdleMenuOption.h"

#include "ImageLibrary/ImageFormatFactory.h"

int main() {

    UserMenu userMenu;
    userMenu.Update();

    /*ImageFormatFactory ahoj;
    ahoj.RegisterFormat<ImageJPG>("jpg");*/

    return 0;
}
