//
// Created by kriz on 08.03.2022.
//

#include "ImagesLibrary.h"
#include <filesystem>
void ImagesLibrary::AddRecord(const std::string& filePath, std::unique_ptr<ImageData> imageData)
{
    for (auto & record : _loadedImages) {
        if(record->FilePath == filePath)
            return;
    }

    _loadedImages.push_back(std::make_shared<LibraryRecord>(filePath, std::move(imageData)));
}

void ImagesLibrary::RemoveRecord(std::string filePath) {

    for (auto it = _loadedImages.begin(); it != _loadedImages.end() ; ++it) {
        if((*it)->FilePath == filePath)
            _loadedImages.erase(it);
    }
}

void ImagesLibrary::ClearLibrary() {
    _loadedImages.clear();
}

std::vector<std::shared_ptr<LibraryRecord>>::const_iterator ImagesLibrary::Begin() const {
    return _loadedImages.cbegin();
}

std::vector<std::shared_ptr<LibraryRecord>>::const_iterator  ImagesLibrary::End() const {
    return _loadedImages.cend();
}

bool ImagesLibrary::CheckIfRecordExists(const std::string& recordPath) const {

    for (auto & record : _loadedImages) {
        if(record->FilePath == recordPath)
            return true;
    }
    return false;
}

bool ImagesLibrary::CheckIfIndexIsValid(int index) const {
    return index < _loadedImages.size() && index >= 0;
}

#include <vector>
void ImagesLibrary::UpdateRecords() {
    std::vector<std::shared_ptr<LibraryRecord>>::iterator it = _loadedImages.begin();
    while (it != _loadedImages.end()) {
        if (!std::filesystem::exists((*it)->FilePath)) {
            it = _loadedImages.erase(it);
        } else {
            ++it;
        }
    }
}

std::shared_ptr<LibraryRecord> ImagesLibrary::GetRecordByIndex(int index) const{

    if(!CheckIfIndexIsValid(index))
        return nullptr;

    return _loadedImages[index];
}

std::string ImagesLibrary::ParseFileExstention(const std::string& filePath){
    return filePath.substr(filePath.find_last_of(".") + 1);
}

int ImagesLibrary::GetLastInsertRecordId(){
    return _loadedImages.size() - 1;
}
