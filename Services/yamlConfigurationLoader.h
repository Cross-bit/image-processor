//
// Created by kriz on 27.05.2022.
//

#ifndef MAIN_CPP_YAMLCONFIGURATIONLOADER_H
#define MAIN_CPP_YAMLCONFIGURATIONLOADER_H

#include "./ConfigurationLoader.h"

class yamlConfigurationLoader : public ConfigurationLoader {
public:
    yamlConfigurationLoader(const std::string& configurationFilePath);

    bool TryLoadConfiguration() override;

    ConfigurationContext GetConfigurationContext() override;

private:

    const std::string yamlExstention = ".yaml";

    bool IsValidYamlFileProvided();

    /**
     * Default keys to search for in yaml file.
     */
    const std::string _inputDirectoryKey = "default_input_directory";
    const std::string _outputDirectoryKey = "default_output_directory";
};


#endif //MAIN_CPP_YAMLCONFIGURATIONLOADER_H
