//
// Created by kriz on 19.04.2022.
//

#ifndef MAIN_CPP_IMAGEEFFECT_H
#define MAIN_CPP_IMAGEEFFECT_H

#include "../ImageLibrary/Image/ImageData.h"

class ImageEffect {
public:
    ImageEffect(ImageData& imageData);

    virtual void ApplyEffect() =0;

protected:
    ImageData& _imageData;
};


#endif //MAIN_CPP_IMAGEEFFECT_H
