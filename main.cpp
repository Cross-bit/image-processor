#include <iostream>

#include "UserMenu/UserMenu.h"

#include "UserMenu/MenuCommands/GoMainMenuOption.h"

#include "ImageLibrary/ImageFormatFactory.h"

#include "ImageLibrary/ImageFormat/ImageJPG.h"

#include "ImageEffects/ImageEffect.h"
#include "ImageEffects/GrayscaleEffect/GrayscaleEffect.h"

#include "ImageEffects/GrayscaleEffect/Algorithms/AverageGrayscaleStrategy.h"
#include "ImageEffects/GrayscaleEffect/Algorithms/LinearGrayscaleStrategy.h"
#include "ImageEffects/NegativeEffect/NegativeEffect.h"

#include "ImageEffects/Convolution/ConvolutionKernels/ImageKernel.h"
#include "ImageEffects/Convolution/ConvolutionProcessor.h"

#include "ImageEffects/Convolution/ConvolutionKernels/Blur/BoxBlurImageKernel.h"
#include "ImageEffects/Convolution/ConvolutionKernels/Blur/GaussianBlurImageKernel.h"
#include "ImageEffects/Convolution/ConvolutionKernels/Sobel/SobelImageKernel.h"

#include "ImageEffects/ASCII/AsciiArtEffect.h"

#include "ImageEffects/ImageEffectFactory.h"

#include "ImageLibrary/ImagesLibrary.h"
#include "UserMenu/MenuGroups/MenuGroupFactory.h"

#include "UserMenu/MenuGroups/FiltersMenuGroup/Comands/ApplySobelOption.h"

#include <cstdio>
#include <filesystem>
#include <unistd.h>

#include <string>
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include <limits.h>

#include <iostream>
#include <fstream>

#include "Services/ConfigurationLoader.h"
#include "Services/yamlConfigurationLoader.h"

int main() {

    // -- configuration loading --
    std::string currentDir = std::filesystem::current_path();
    std::string pathToConfig = currentDir + "/config.yaml";

    yamlConfigurationLoader configurationLoader(pathToConfig);

    ConfigurationContext config;

    if (configurationLoader.TryLoadConfiguration()){
        config = configurationLoader.GetConfigurationContext();
    }

    // -- user menu initialisation --
    ImagesLibrary imagesLibrary;

    MenuGroupFactory menuGroupsFactory(imagesLibrary);

    UserMenu userMenu(menuGroupsFactory, config);

    userMenu.Initialize();
    userMenu.Update();

    return 0;
}