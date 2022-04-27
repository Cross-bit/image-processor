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

class ApplyFilterOptionBase : public MenuOption {
public:
    ApplyFilterOptionBase(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

    void Execute() override;

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu & userMenu) override;
protected:
    ImagesLibrary& _imagesLibrary;
    std::queue<int>& _libraryIndexesToWorkWith;

    /**
     * Implementation of other users input values needed for filter computation.
     * @return
     */
    virtual bool InitializeFilterProperties();

    /**
     * Stores index of processed image data in library.
     */
    std::vector<std::unique_ptr<ImageData>> _processedImageIndexes;

    /**
     * Adds filtered data to image library and returns pointer to the data.
     */
    void AddFilteredDataToLibrary();

    virtual std::unique_ptr<ImageData> ApplyFilterOnImage(ImageData& inputImage) =0;

 //   bool _executionSucceded = false;
};


#endif //MAIN_CPP_APPLYFILTEROPTIONBASE_H
