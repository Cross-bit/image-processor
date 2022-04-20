cmake_minimum_required(VERSION 2.4)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_STATIC_LINKER_FLAGS "-ljpeglib")
#set(CMAKE_LIBRARY_PATH  /usr/local/lib)
#include_directories(/usr/local/lib)
#find_library(JPEG_LIB libjpeg.so.9)

#if(NOT ${JPEG_LIB})
 #   message(FATAL_ERROR "libjpeg library not found")
#endif()

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
        UserMenu/MenuGroups/MenuGroupFactory.cpp UserMenu/MenuGroups/MenuGroupFactory.h ImageLibrary/ImagesLibrary.cpp ImageLibrary/ImagesLibrary.h ImageLibrary/ImageFormat.cpp ImageLibrary/ImageFormat.h ImageLibrary/ImageFormat/ImageJPG.cpp ImageLibrary/ImageFormat/ImageJPG.h ImageLibrary/ImageFormatFactory.cpp ImageLibrary/ImageFormatFactory.h ImageLibrary/ImageFormat/ImagePNG.cpp ImageLibrary/ImageFormat/ImagePNG.h
        ImageLibrary/Image/ImageData.cpp ImageLibrary/Image/ImageData.h ImageEffects/GrayscaleEffect/GrayscaleEffect.cpp ImageEffects/GrayscaleEffect/GrayscaleEffect.h ImageEffects/ImageEffect.cpp ImageEffects/ImageEffect.h ImageEffects/ImageEffectFactory.cpp ImageEffects/ImageEffectFactory.h ImageEffects/GrayscaleEffect/Algorithms/GrayscaleStrategyBase.h ImageEffects/GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.cpp ImageEffects/GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.h ImageEffects/GrayscaleEffect/Algorithms/LinearGrayscaleStrategy.cpp ImageEffects/GrayscaleEffect/Algorithms/LinearGrayscaleStrategy.h)

#find_package (jpeg REQUIRED)

#find_package(libjpeg REQUIRED)
#find_library(JPEG_LIB libjpeg)
#target_link_libraries(ImageProcessor ${CMAKE_SOURCE_DIR}/External/lib/libjpeg.a)
#set(LIB_AA C:/Users/kriz/CLionProjects/ImageProcessor/External/)
#find_path(LIB_HEAD jpeglib.h PATH_SUFFIXES includes PATHS ${LIB_AA})
#target_link_libraries(ImageProcessor C:/Users/kriz/CLionProjects/ImageProcessor/External/lib/libjpeg.a)

 #link_directories(${CMAKE_BINARY_DIR}/res)

#find_library(JPEG_LIB External/lib/)
#${JPEG_LIB}
target_link_libraries(ImageProcessor ${CMAKE_SOURCE_DIR}/External/lib/libturbojpeg.a)

#target_link_libraries(ImageProcessor  /mnt/c/Users/kriz/CLionProjects/ImageProcessor/External/lib/libjpeg.a)
target_link_libraries(ImageProcessor ${JPEG_LIB})


#find_library(JPEG_LIB jpeg62)
#target_link_libraries(ImageProcessor /External/lib/jpeg62.dll)
#if(NOT ${JPEG_LIB})
#    message(FATAL_ERROR "libjpeg library not found")
#endif()
#find_package (jpeg REQUIRED)
#target_link_libraries(ImageProcessor jpeg::jpeg)
#link_directories(${CMAKE_BINARY_DIR}/../External/lib)
#target_link_libraries(ImageProcessor External/lib/libjpeg)
#${JPEG_LIB}



