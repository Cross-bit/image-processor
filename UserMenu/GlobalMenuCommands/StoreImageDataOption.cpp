//
// Created by kriz on 27.04.2022.
//

#include "StoreImageDataOption.h"

#include "../../UserMenu/UserMenu.h"
#include "../MenuGroups/MenuGroupFactory.h"
#include "../../ImageLibrary/ImageFormat.h"
#include "../../ImageLibrary/ImageFormatFactory.h"

#include <filesystem>

StoreImageDataOption::StoreImageDataOption(std::vector<std::unique_ptr<ImageData>>& imagesToStore) :
_imagesToStore(imagesToStore)
{
    _itemContent = "Save image data.";
}

void StoreImageDataOption::Execute() {

    ImageFormatFactory formatFactory;

    std::unique_ptr<ImageFormat> imageFormat;

    std::cout << "Enter format you wish to be used." << std::endl; // todo: add as selection menu...
    auto formatExtension = ReadUserInput();

    imageFormat = formatFactory.CreateImageFormat(formatExtension);

    if(imageFormat == nullptr) {
        PrintWarning("Unfortunately your format is not supported. jpg will be used instead ...");
        imageFormat = formatFactory.CreateImageFormat("jpg");
    }

    std::cout << "Enter full path to output directory(leave blank for default)." << std::endl;
    auto outputDirectory = ReadUserInput();

    if(outputDirectory == "")
        outputDirectory = _defaultOutputDir;

    if(!std::filesystem::exists(outputDirectory)){
        PrintWarning("Provided dir does not exist! Default directory will be used instead ...");
        outputDirectory = _defaultOutputDir;
    }

    // save image data
    for (auto & img : _imagesToStore) {
        imageFormat->SaveImageData(*img, outputDirectory);
    }

    std::cout << "Images successfully saved!" << std::endl;
}


std::unique_ptr<MenuGroup> StoreImageDataOption::CreateNextGroup(UserMenu &userMenu) {
    return nullptr;
}
