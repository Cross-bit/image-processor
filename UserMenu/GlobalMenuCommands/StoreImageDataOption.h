//
// Created by kriz on 27.04.2022.
//

#ifndef MAIN_CPP_STOREIMAGEDATAOPTION_H
#define MAIN_CPP_STOREIMAGEDATAOPTION_H


#include "../MenuCommands/MenuOption.h"
#include "../../ImageLibrary/Image/ImageData.h"

#include <vector>
class StoreImageDataOption : public MenuOption {
public:
    StoreImageDataOption(std::vector<std::unique_ptr<ImageData>>& imagesToStore);

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu &groupFactory) override;

    void Execute(UserMenu& userMenu) override;
private:
    std::vector<std::unique_ptr<ImageData>>& _imagesToStore;
};


#endif //MAIN_CPP_STOREIMAGEDATAOPTION_H
