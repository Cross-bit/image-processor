//
// Created by kriz on 08.03.2022.
//

#include "ImagesLibrary.h"
#include <filesystem>
void ImagesLibrary::AddRecord(const std::string& filePath, std::unique_ptr<ImageData> imageData)
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

std::unordered_map<std::string, std::unique_ptr<ImageData>>::const_iterator ImagesLibrary::Begin() const {
    return _loadedImages.begin();
}

std::unordered_map<std::string, std::unique_ptr<ImageData>>::const_iterator ImagesLibrary::End() const {
    return _loadedImages.end();
}

bool ImagesLibrary::CheckIfRecordExists(const std::string& recordKey) const {
    return _loadedImages.find(recordKey) == _loadedImages.end();
}

void ImagesLibrary::UpdateRecords() {

    for (auto it = _loadedImages.begin(); it != _loadedImages.end() ; ++it) {
        if (!std::filesystem::exists(it->first))
            _loadedImages.erase(it);
    }
}


std::string ImagesLibrary::ParseFileExstention(const std::string& filePath){
    return filePath.substr(filePath.find_last_of(".") + 1);
}

