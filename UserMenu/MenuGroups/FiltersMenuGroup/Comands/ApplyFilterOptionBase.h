//
// Created by kriz on 27.04.2022.
//

#ifndef MAIN_CPP_APPLYFILTEROPTIONBASE_H
#define MAIN_CPP_APPLYFILTEROPTIONBASE_H

#include "../../../MenuCommands/MenuOption.h"
#include "../../../../ImageLibrary/Image/ImageData.h"
#include "../../../../ImageLibrary/ImagesLibrary.h"
#include "../../../../ImageEffects/ImageEffectFactory.h"

#include <queue>
#include <unordered_set>
#include <thread>
#include <future>

class ApplyFilterOptionBase : public MenuOption {
public:
    ApplyFilterOptionBase(std::unordered_set<int> libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

    void Execute() override;

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu & userMenu) override;

protected:
    ImagesLibrary& _imagesLibrary;
    std::unordered_set<int> _libraryIndexesToWorkWith;

    /**
     * Stores index of processed image data in library.
     */
    std::vector<std::unique_ptr<ImageData>> _processedImageIndexes;

    /**
     * Adds filtered data to image library and returns pointer to the data.
     */
    void AddFilteredDataToLibrary();

    /**
     * Implementation of other users input values needed for filter computation.
     * @return
     */
    virtual bool InitializeFilterProperties();
    /**
     * Applies provided image effect on data.
     * @param inputImage
     * @return Copy of input data filtered.
     */
    virtual std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData& inputImage) =0;

    /**
     * Processes all images in parallel.
     */
    void PerformImageParallelProcessing();

private:
    std::vector<std::future<std::unique_ptr<ImageData>>> _asyncFilters;

    /**
     * Starts async image processing.
     * @param imageLibraryIndex
     */
    void StartProcessingImageData(int imageLibraryIndex);

    /**
     * Ads processed images into output list
     * @param imageLibraryIndex
     */
    void FinalizeParallelImageProcessing();

    /**
     * Waits until all async computations finishes image processing and joins them into main thread.
     */
    void WaitForParallelImageComputation();
};


#endif //MAIN_CPP_APPLYFILTEROPTIONBASE_H
