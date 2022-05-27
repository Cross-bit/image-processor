//
// Created by kriz on 27.05.2022.
//

#ifndef MAIN_CPP_CONFIGURATIONLOADER_H
#define MAIN_CPP_CONFIGURATIONLOADER_H

#include <iostream>
#include <string>

/**
 * Configuration context, containing data parsed from the input file.
 */
struct ConfigurationContext
{
public:
    int a = 45;
    std::string PathToConfigurationFile;
    std::string DefaultInputDir;
    std::string DefaultOutputDir;
};

class ConfigurationLoader {
public:
    ConfigurationLoader(const std::string& configurationFilePath);

     /**
      * Loads configuration from file.
      * @return
      */
    virtual bool TryLoadConfiguration()=0;

    /**
     * Getter for configuration context containing data parsed from input.
     * @return Copy of configuration context.
     */
    virtual ConfigurationContext GetConfigurationContext()=0;

protected:
    const std::string& _configFilePath;
    ConfigurationContext _configurationContext;
};


#endif //MAIN_CPP_CONFIGURATIONLOADER_H
