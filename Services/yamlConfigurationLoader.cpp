//
// Created by kriz on 27.05.2022.
//

#include "yamlConfigurationLoader.h"
#include <filesystem>
#include "../External/includes/yaml-cpp/yaml.h"

yamlConfigurationLoader::yamlConfigurationLoader(const std::string& configurationFilePath) :
ConfigurationLoader(configurationFilePath) { }


bool yamlConfigurationLoader::TryLoadConfiguration() {

    if (!IsValidYamlFileProvided())
        return false;

    _configurationContext.PathToConfigurationFile = _configFilePath;

    YAML::Node config = YAML::LoadFile(_configFilePath);

    if (config[_inputDirectoryKey])
        _configurationContext.DefaultInputDir = config[_inputDirectoryKey].as<std::string>();
    else
        std::cout << "Default input directory status: not provided" << std::endl;

    if (config[_outputDirectoryKey])
        _configurationContext.DefaultOutputDir = config[_outputDirectoryKey].as<std::string>();
    else
        std::cout << "Default output directory status: not provided" << std::endl;

    return true;
}

bool yamlConfigurationLoader::IsValidYamlFileProvided() {
    std::filesystem::path configFile(_configFilePath);
    return configFile.has_filename() && configFile.extension() == yamlExstention && std::filesystem::exists(_configFilePath);
}

ConfigurationContext  yamlConfigurationLoader::GetConfigurationContext() {
    return _configurationContext;
}

