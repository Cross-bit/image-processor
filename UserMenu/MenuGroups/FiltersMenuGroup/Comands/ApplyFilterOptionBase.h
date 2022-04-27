//
// Created by kriz on 27.04.2022.
//

#ifndef MAIN_CPP_APPLYFILTEROPTIONBASE_H
#define MAIN_CPP_APPLYFILTEROPTIONBASE_H

#include "../../../MenuCommands/MenuOption.h"
#include "../../../../ImageLibrary/Image/ImageData.h"
#include "../../../../ImageLibrary/ImagesLibrary.h"
#include "../../../../ImageEffects/ImageEffectFactory.h"
//#include "../../../"

#include <queue>

class ApplyFilterOptionBase : public MenuOption {
public:
    ApplyFilterOptionBase(std::queue<int>& libraryIndexesToWorkWith, ImagesLibrary& imagesLibrary);

    void Execute() override;

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu & userMenu) override;
protected:
    ImagesLibrary& _imagesLibrary;
    std::queue<int>& _libraryIndexesToWorkWith;

    virtual void ApplyFilterOnImage(ImageData& inputImage) =0;
};


#endif //MAIN_CPP_APPLYFILTEROPTIONBASE_H
