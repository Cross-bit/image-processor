//
// Created by kriz on 08.03.2022.
//

#include "ImagesLibrary.h"

void ImagesLibrary::AddRecord(std::string filePath, std::unique_ptr<ImageData> imageData)
{
    if (_loadedImages.find(filePath) == _loadedImages.end())
        _loadedImages.insert({filePath, std::move(imageData)});
}

void ImagesLibrary::RemoveRecord(std::string filePath) {
    auto res = _loadedImages.find(filePath);
    if (res != _loadedImages.end())
        _loadedImages.erase(res);
}

void ImagesLibrary::ClearLibrary() {
    _loadedImages.clear();
}


