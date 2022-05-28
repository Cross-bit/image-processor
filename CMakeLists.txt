cmake_minimum_required(VERSION 2.4)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(
        ImageProcessor
        main.cpp
        UserMenu/MenuGroups/MenuGroup.h
        UserMenu/OtherMenuCommands/MenuOption.h
        UserMenu/UserMenu.h
        UserMenu/UserMenu.cpp
        UserMenu/MenuGroups/MenuGroup.cpp
        UserMenu/OtherMenuCommands/MenuOption.cpp
        UserMenu/MenuGroups/MainMenuGroup/Commands/GoMainMenuOption.cpp
        UserMenu/MenuGroups/MainMenuGroup/Commands/GoMainMenuOption.h
        UserMenu/MenuGroups/MainMenuGroup/MainMenuGroup.cpp
        UserMenu/MenuGroups/MainMenuGroup/MainMenuGroup.h
        UserMenu/MenuGroups/FiltersMenuGroup/FiltersMenuGroup.cpp
        UserMenu/MenuGroups/FiltersMenuGroup/FiltersMenuGroup.h
        UserMenu/MenuGroups/MainMenuGroup/Commands/GoFiltersMenuGroup.cpp
        UserMenu/MenuGroups/MainMenuGroup/Commands/GoFiltersMenuGroup.h
        UserMenu/MenuGroups/MenuGroupFactory.cpp UserMenu/MenuGroups/MenuGroupFactory.h
        ImageLibrary/ImagesLibrary.cpp
        ImageLibrary/ImagesLibrary.h
        ImageLibrary/ImageFormat.cpp
        ImageLibrary/ImageFormat.h
        ImageLibrary/ImageFormat/ImageJPG.cpp
        ImageLibrary/ImageFormat/ImageJPG.h
        ImageLibrary/ImageFormatFactory.cpp
        ImageLibrary/ImageFormatFactory.h
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
        UserMenu/MenuGroups/MainMenuGroup/Commands/GoLibraryMenuGroup.cpp
        UserMenu/MenuGroups/MainMenuGroup/Commands/GoLibraryMenuGroup.h
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddImageToLibrary.cpp
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddImageToLibrary.h
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddAllImagesFromDirOption.cpp
        UserMenu/MenuGroups/LibraryMenuGroup/Commands/AddAllImagesFromDirOption.h
        UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyFilterOptionBase.cpp
        UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyFilterOptionBase.h
        UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplySobelOption.cpp
        UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplySobelOption.h
        UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyLinearGrayscaleOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyLinearGrayscaleOption.h UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyGaussianBlurOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyGaussianBlurOption.h UserMenu/OtherMenuCommands/StoreImageDataOption.cpp UserMenu/OtherMenuCommands/StoreImageDataOption.h UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyBoxBlurOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyBoxBlurOption.h UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyNegativeOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyNegativeOption.h UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyFlipTransformOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyFlipTransformOption.h UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyAverageGrayscaleOption.cpp UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyAverageGrayscaleOption.h UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyASCIIArtEffect.cpp UserMenu/MenuGroups/FiltersMenuGroup/Commands/ApplyASCIIArtEffect.h Services/ConfigurationLoader.cpp Services/ConfigurationLoader.h Services/yamlConfigurationLoader.cpp Services/yamlConfigurationLoader.h UserMenu/OtherMenuCommands/EndApplicationOption.h)


target_link_libraries(ImageProcessor ${CMAKE_SOURCE_DIR}/External/lib/libyaml-cpp.a)
target_link_libraries(ImageProcessor ${CMAKE_SOURCE_DIR}/External/lib/libjpeg.a)



