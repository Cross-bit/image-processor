//
// Created by kriz on 27.04.2022.
//

#include "ApplyFilterOptionBase.h"


#include "../../../UserMenu.h"

ApplyFilterOptionBase::ApplyFilterOptionBase(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
_libraryIndexesToWorkWith(libraryIndexesToWorkWith),
_imagesLibrary(imagesLibrary)
{ }

void ApplyFilterOptionBase::Execute() {

    while(!_libraryIndexesToWorkWith.empty()){

        int index = _libraryIndexesToWorkWith.front();
        _libraryIndexesToWorkWith.pop();

        auto imageRecord = _imagesLibrary.GetRecordByIndex(index);

        if(imageRecord == nullptr) {
            PrintWarning("Index " + std::to_string(index) + " couldn't be found in library...");
            continue;
        }

        std::cout << "Processing image data..." << std::endl;

        ApplyFilterOnImage((*imageRecord->Data));
        // todo: probably it we could return some status code if operation fails...
        std::cout << "Done!" << std::endl;



    }
}


std::unique_ptr<MenuGroup> ApplyFilterOptionBase::CreateNextGroup(UserMenu & userMenu) {
    return nullptr;
}