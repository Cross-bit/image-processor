//
// Created by kriz on 10.03.2022.
//

#ifndef MAIN_CPP_IMAGEJPG_H
#define MAIN_CPP_IMAGEJPG_H


#include "../ImageFormat.h"

class ImageJPG : public ImageFormat {
public:
    ImageData LoadImageData(const std::string &inpFileName) const override;
    bool SaveImageData(const ImageData &dataToSave, const std::string &outFileName) const override;
};


#endif //MAIN_CPP_IMAGEJPG_H
