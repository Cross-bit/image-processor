//
// Created by kriz on 06.03.2022.
//

#ifndef IMAGEPROCESSOR_GOSECONDMENUOPTION_H
#define IMAGEPROCESSOR_GOSECONDMENUOPTION_H


#include "MenuOption.h"
#include "../../ImageLibrary/ImagesLibrary.h"
#include <queue>
#include <unordered_set>


class GoFiltersMenuGroup : public MenuOption {
public:
    GoFiltersMenuGroup(ImagesLibrary& imagesLibrary);

    std::unique_ptr<MenuGroup> CreateNextGroup(UserMenu &userMenu) override;

    void Execute() override;

private:
    ImagesLibrary& _imagesLibrary;
    std::unordered_set<int> _imagesToFilter;
};




#endif //IMAGEPROCESSOR_GOSECONDMENUOPTION_H
