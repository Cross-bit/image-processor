#include <iostream>
#include <filesystem>

#include "UserMenu/UserMenu.h"
#include "ImageLibrary/ImagesLibrary.h"
#include "UserMenu/MenuGroups/MenuGroupFactory.h"

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