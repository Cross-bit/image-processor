//
// Created by kriz on 27.04.2022.
//

#include "ApplyFilterOptionBase.h"


#include "../../../UserMenu.h"
#include "../../../GlobalMenuCommands/StoreImageDataOption.h"

#include <thread>
#include <future>

ApplyFilterOptionBase::ApplyFilterOptionBase(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
_libraryIndexesToWorkWith(libraryIndexesToWorkWith),
_imagesLibrary(imagesLibrary)
{ }

void ApplyFilterOptionBase::Execute() {

    std::vector<std::future<std::unique_ptr<ImageData>>> asyncFilters;

    if(!InitializeFilterProperties())
        return;

    std::cout << "Processing images data..." << std::endl;

    while(!_libraryIndexesToWorkWith.empty()){

        int index = _libraryIndexesToWorkWith.front();
        _libraryIndexesToWorkWith.pop();

        auto imageRecord = _imagesLibrary.GetRecordByIndex(index);

        if(imageRecord == nullptr) {
            PrintWarning("Index " + std::to_string(index) + " couldn't be found in library...");
            continue;
        }

        // todo: what about error handling??

        asyncFilters.emplace_back(std::async(&ApplyFilterOptionBase::ApplyFilterOnImage, this, std::ref(*(imageRecord->Data))));
    }

    for (auto & t : asyncFilters) {
        t.wait();
    }

    for (auto & t : asyncFilters) {
        _processedImageIndexes.emplace_back(t.get());
        //std::cout << a->Name << "againg" << std::endl;
    }

    std::cout << "Done!" << std::endl;

    // call image store command
    (StoreImageDataOption (_processedImageIndexes)).Execute();
}


std::unique_ptr<MenuGroup> ApplyFilterOptionBase::CreateNextGroup(UserMenu & userMenu) {
    return nullptr;
}

bool ApplyFilterOptionBase::InitializeFilterProperties() {
    return true;
}