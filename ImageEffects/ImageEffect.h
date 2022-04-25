//
// Created by kriz on 19.04.2022.
//

#ifndef MAIN_CPP_IMAGEEFFECT_H
#define MAIN_CPP_IMAGEEFFECT_H

#include "../ImageLibrary/Image/ImageData.h"

#include <iostream>

class ImageEffect {
public:
    ImageEffect(ImageData& imageData);

    ImageEffect(ImageData& imageData, float r, float g, float b);

    /**
     * Applies the effect on the image data.
     */
    virtual void ProcessImageData() =0;

    /**
     * Returns data after processing is done.
     * @return
     */
    virtual ImageData& GetProcessedImageData() const;

    void SetRedCoef(float value);

    void SetGreenCoef(float value);

    void SetBlueCoef(float value);

private:
    bool CheckCoef(float value);

protected:
    ImageData& _imageData;

    float _redCoef; // todo: probably move to specific algoritm, but we will see if it makes sense here...
    float _greenCoef;
    float _blueCoef;
};


#endif //MAIN_CPP_IMAGEEFFECT_H
