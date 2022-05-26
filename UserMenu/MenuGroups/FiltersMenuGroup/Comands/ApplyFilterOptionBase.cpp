//
// Created by kriz on 27.04.2022.
//

#include "ApplyFilterOptionBase.h"


#include "../../../UserMenu.h"
#include "../../../GlobalMenuCommands/StoreImageDataOption.h"
#include "../../MenuGroupFactory.h"
#include "thread"
#include "future"

ApplyFilterOptionBase::ApplyFilterOptionBase(std::unordered_set<int> libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary) :
_libraryIndexesToWorkWith(std::move(libraryIndexesToWorkWith)),
_imagesLibrary(imagesLibrary)
{ }


void ApplyFilterOptionBase::StartProcessingImageData(int imageLibraryIndex) {

    auto imageRecord = _imagesLibrary.GetRecordByIndex(imageLibraryIndex);

    Print("-> ");
    PrintLine(imageRecord->Data->Name);

    if (imageRecord == nullptr) {
        PrintWarning("Index " + std::to_string(imageLibraryIndex) + " couldn't be found in library...");
        return;
    }

    _asyncFilters.emplace_back(std::async(&ApplyFilterOptionBase::ApplyFilterOnImage, this, std::ref(*(imageRecord->Data))));
}

void ApplyFilterOptionBase::WaitForParallelImageComputation() {
    for (auto & t : _asyncFilters) {
        t.wait();
    }
}

void ApplyFilterOptionBase::FinalizeParallelImageProcessing() {
    for (auto & t : _asyncFilters) {
        _processedImageIndexes.emplace_back(t.get());
    }
}

void ApplyFilterOptionBase::PerformImageParallelProcessing() {

    for (auto libIndex : _libraryIndexesToWorkWith) {
        StartProcessingImageData(libIndex);
    }

    WaitForParallelImageComputation();

    FinalizeParallelImageProcessing();
}


void ApplyFilterOptionBase::Execute() {

    if (!InitializeFilterProperties())
        return;

    PrintLine("Processing images data(this may take a while)...");

    PerformImageParallelProcessing();

    PrintLine("Done!");

    // call image store command
    StoreProcessedImageData();
}


std::unique_ptr<MenuGroup> ApplyFilterOptionBase::CreateNextGroup(UserMenu & userMenu) {
    return userMenu.GroupsFac.CreateMainMenuGroup();
}

bool ApplyFilterOptionBase::InitializeFilterProperties() {
    return true;
}
void ApplyFilterOptionBase::StoreProcessedImageData() {
    (StoreImageDataOption (_processedImageIndexes)).Execute();
}