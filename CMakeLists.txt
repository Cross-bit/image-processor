cmake_minimum_required(VERSION 2.4)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_STATIC_LINKER_FLAGS "-ljpeglib")
#set(CMAKE_LIBRARY_PATH  /usr/local/lib)
#include_directories(/usr/local/lib)
#find_library(JPEG_LIB libjpeg.so.9)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#if(NOT ${JPEG_LIB})
 #   message(FATAL_ERROR "libjpeg library not found")
#endif()

add_executable(
        ImageProcessor
        main.cpp
        UserMenu/MenuGroups/MenuGroup.h
        UserMenu/MenuCommands/MenuOption.h
        UserMenu/UserMenu.h
        UserMenu/UserMenu.cpp
        UserMenu/MenuGroups/MenuGroup.cpp
        UserMenu/MenuCommands/MenuOption.cpp
        UserMenu/MenuCommands/GoMainMenuOption.cpp
        UserMenu/MenuCommands/GoMainMenuOption.h
        UserMenu/MenuGroups/MainMenuGroup/MainMenuGroup.cpp
        UserMenu/MenuGroups/MainMenuGroup/MainMenuGroup.h
        UserMenu/MenuGroups/FiltersMenuGroup/FiltersMenuGroup.cpp
        UserMenu/MenuGroups/FiltersMenuGroup/FiltersMenuGroup.h
        UserMenu/MenuCommands/GoFiltersMenuGroup.cpp
        UserMenu/MenuCommands/GoFiltersMenuGroup.h
        UserMenu/MenuGroups/MenuGroupFactory.cpp UserMenu/MenuGroups/MenuGroupFactory.h
        ImageLibrary/ImagesLibrary.cpp
        ImageLibrary/ImagesLibrary.h
        ImageLibrary/ImageFormat.cpp
        ImageLibrary/ImageFormat.h
        ImageLibrary/ImageFormat/ImageJPG.cpp
        ImageLibrary/ImageFormat/ImageJPG.h
        ImageLibrary/ImageFormatFactory.cpp
        ImageLibrary/ImageFormatFactory.h ImageLibrary/ImageFormat/ImagePNG.cpp
        ImageLibrary/ImageFormat/ImagePNG.h
        ImageLibrary/Image/ImageData.cpp
        ImageLibrary/Image/ImageData.h
        ImageEffects/GrayscaleEffect/GrayscaleEffect.cpp
        ImageEffects/GrayscaleEffect/GrayscaleEffect.h
        ImageEffects/ImageEffect.cpp ImageEffects/ImageEffect.h
        ImageEffects/ImageEffectFactory.cpp
        ImageEffects/ImageEffectFactory.h
        ImageEffects/GrayscaleEffect/Algorithms/GrayscaleStrategyBase.h
        ImageEffects/GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.cpp
        ImageEffects/GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.h
        ImageEffects/GrayscaleEffect/Algorithms/LinearGrayscaleStrategy.cpp
        ImageEffects/GrayscaleEffect/Algorithms/LinearGrayscaleStrategy.h
        ImageEffects/NegativeEffect/NegativeEffect.cpp
        ImageEffects/NegativeEffect/NegativeEffect.h
        ImageEffects/Convolution/ConvolutionKernels/ImageKernel.cpp
        ImageEffects/Convolution/ConvolutionKernels/ImageKernel.h
        ImageEffects/ASCII/AsciiArtEffect.cpp
        ImageEffects/ASCII/AsciiArtEffect.h
        ImageEffects/Convolution/ConvolutionProcessor.cpp
        ImageEffects/Convolution/ConvolutionProcessor.h
        ImageEffects/Convolution/ConvolutionKernels/Blur/BoxBlurImageKernel.cpp
        ImageEffects/Convolution/ConvolutionKernels/Blur/BoxBlurImageKernel.h
        ImageEffects/Convolution/ConvolutionKernels/Blur/GaussianBlurImageKernel.cpp
        ImageEffects/Convolution/ConvolutionKernels/Blur/GaussianBlurImageKernel.h
        ImageEffects/Convolution/ConvolutionKernels/Sobel/SobelImageKernel.cpp
        ImageEffects/Convolution/ConvolutionKernels/Sobel/SobelImageKernel.h
        ImageEffects/Transformations/RegularRotation.cpp
        ImageEffects/Transformations/RegularRotation.h
        ImageEffects/Transformations/FlipTransform.cpp
        ImageEffects/Transformations/FlipTransform.h
        UserMenu/MenuGroups/LibraryMenuGroup/LibraryMenuGroup.cpp
        UserMenu/MenuGroups/LibraryMenuGroup/LibraryMenuGroup.h
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/ListAllImagesOption.cpp
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/ListAllImagesOption.h
        UserMenu/MenuCommands/GoLibraryMenuGroup.cpp
        UserMenu/MenuCommands/GoLibraryMenuGroup.h
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddImageToLibrary.cpp
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddImageToLibrary.h
        UserMenu/MenuGroups/OptionsMenuGroup/OptionsMenuGroup.cpp
        UserMenu/MenuGroups/OptionsMenuGroup/OptionsMenuGroup.h
        UserMenu/MenuGroups/OptionsMenuGroup/Commands/SetDefaultInputDirectory.cpp
        UserMenu/MenuGroups/OptionsMenuGroup/Commands/SetDefaultInputDirectory.h
        Configuration/ApplicationConfiguration.cpp
        Configuration/ApplicationConfiguration.h
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddAllImagesFromDirOption.cpp
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddAllImagesFromDirOption.h
        UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyFilterOptionBase.cpp
        UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyFilterOptionBase.h
        UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplySobelOption.cpp
        UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplySobelOption.h
        UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyLinearGrayscaleOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyLinearGrayscaleOption.h UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyGaussianBlurOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyGaussianBlurOption.h UserMenu/GlobalMenuCommands/StoreImageDataOption.cpp UserMenu/GlobalMenuCommands/StoreImageDataOption.h UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyBoxBlurOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyBoxBlurOption.h UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyNegativeOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyNegativeOption.h UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyFlipTransformOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyFlipTransformOption.h UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyAverageGrayscaleOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyAverageGrayscaleOption.h UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyASCIIArtEffect.cpp UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplyASCIIArtEffect.h)

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
#target_link_libraries(ImageProcessor ${CMAKE_SOURCE_DIR}/External/lib/libturbojpeg.a)

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



