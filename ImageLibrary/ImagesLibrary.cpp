//
// Created by kriz on 08.03.2022.
//

#include "ImagesLibrary.h"
#include <filesystem>
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

std::unordered_map<std::string, std::unique_ptr<ImageData>>::iterator ImagesLibrary::GetAllImages() {
    return _loadedImages.begin();
}

void ImagesLibrary::UpdateRecords() {

    for (auto it = _loadedImages.begin(); it != _loadedImages.end() ; ++it) {
        if (!std::filesystem::exists(it->first))
            _loadedImages.erase(it);
    }
}


