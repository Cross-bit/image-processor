cmake_minimum_required(VERSION 3.21)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ImageProcessor
        main.cpp
        UserMenu/MenuGroups/MenuGroup.h
        UserMenu/MenuGroups/MenuOption.h
        UserMenu/UserMenu.h
        UserMenu/UserMenu.cpp
        UserMenu/MenuGroups/MenuGroup.cpp
        UserMenu/MenuGroups/MenuOption.cpp
        UserMenu/MenuCommands/GoIdleMenuOption.cpp
        UserMenu/MenuCommands/GoIdleMenuOption.h
        UserMenu/MenuGroups/IdleMenuGroup/IdleMenuGroup.cpp
        UserMenu/MenuGroups/IdleMenuGroup/IdleMenuGroup.h
        UserMenu/MenuGroups/SecondMenuGroup/SecondMenuGroup.cpp
        UserMenu/MenuGroups/SecondMenuGroup/SecondMenuGroup.h
        UserMenu/MenuCommands/GoSecondMenuOption.cpp
        UserMenu/MenuCommands/GoSecondMenuOption.h
        UserMenu/MenuGroups/MenuGroupFactory.cpp UserMenu/MenuGroups/MenuGroupFactory.h ImageLibrary/ImagesLibrary.cpp ImageLibrary/ImagesLibrary.h ImageLibrary/ImageFormat.cpp ImageLibrary/ImageFormat.h ImageLibrary/ImageFormat/ImageJPG.cpp ImageLibrary/ImageFormat/ImageJPG.h ImageLibrary/ImageFormatFactory.cpp ImageLibrary/ImageFormatFactory.h)
