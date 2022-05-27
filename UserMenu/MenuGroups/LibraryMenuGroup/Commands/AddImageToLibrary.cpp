//
// Created by kriz on 26.04.2022.
//

#include "AddImageToLibrary.h"

#include "../../MenuGroupFactory.h"
#include "../../../UserMenu.h"

#include <filesystem>
#include <string>
#include <unistd.h>

AddImageToLibrary::AddImageToLibrary(ImagesLibrary& imagesLibrary) : _imagesLibrary(imagesLibrary) {
    _itemContent = "Add image to library";
}

std::unique_ptr<MenuGroup> AddImageToLibrary::CreateNextGroup(UserMenu & userMenu) {
    return std::move(userMenu.GroupsFac.CreateLibraryMenuGroup());
}

void AddImageToLibrary::Execute(UserMenu& userMenu)
{
    _imagesLibrary.UpdateRecords();

    std::string imageFilePath;

    std::cout << "Enter file path:" << std::endl;

    imageFilePath = ReadUserInput();

    if(imageFilePath == ""){
        PrintError("Invalid input!");
        return;
    }

    if (!TryToFindImage(imageFilePath)) {
        PrintError("File does not exist!");
        return;
    }

    auto imageFormat = GetImageFormat(imageFilePath);

    if(imageFormat == nullptr) {
        PrintError("Invalid file format!");
        return;
    }

    std::cout << "Loading img data..." << std::endl;

    auto imageData = imageFormat->LoadImageData(imageFilePath);

    std::cout << "Reading done!" << std::endl;

    _imagesLibrary.AddRecord(std::move(imageFilePath), std::move(imageData));

    std::cout << "Image successfully added to the library!" << std::endl;
}

bool AddImageToLibrary::TryToFindImage(std::string &imagePath) const {
    if(std::filesystem::exists(imagePath))
        return true;

     // try to use relative path to working directory:
    char workingDir[256];
    getcwd(workingDir, 256);
    imagePath = std::string(workingDir)  + "/" + imagePath;

    return std::filesystem::exists(imagePath);
}

std::unique_ptr<ImageFormat> AddImageToLibrary::GetImageFormat(const std::string& filePath){

    std::string fileExtension = ImagesLibrary::ParseFileExstention(filePath);

    return std::move(_formatFactory.CreateImageFormat(fileExtension));
}
