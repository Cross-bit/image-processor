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

    PrintLine("Enter format you wish to be used.");
    auto formatExtension = ReadUserInput();

    imageFormat = formatFactory.CreateImageFormat(formatExtension);

    if(imageFormat == nullptr) {
        PrintWarning("Unfortunately your format is not supported. jpg will be used instead ...");
        imageFormat = formatFactory.CreateImageFormat("jpg");
    }

    PrintLine("Enter full path to output directory(leave blank for default).");
    auto outputDirectory = ReadUserInput();

    if(CheckStringIsEmpty(outputDirectory))
        outputDirectory = _defaultOutputDir;

    if(!std::filesystem::exists(outputDirectory)){
        PrintWarning("Provided dir does not exist! Default directory will be used instead ...");
        outputDirectory = _defaultOutputDir;
    }

    // save image data
    for (auto & img : _imagesToStore) {
        imageFormat->SaveImageData(*img, outputDirectory);
    }

    PrintLine("Images successfully saved!");
}


std::unique_ptr<MenuGroup> StoreImageDataOption::CreateNextGroup(UserMenu &userMenu) {
    return nullptr;
}
