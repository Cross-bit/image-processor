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
     * Returns reference to processed data.
     * @return
     */
    virtual ImageData& GetProcessedImageDataReference();

    /**
     * Passes ownership of processed image data to caller.
     * @return
     */
    virtual std::unique_ptr<ImageData> GetProcessedImageData();

protected:
    ImageData& _imageData;
    std::unique_ptr<ImageData> _processedImage;
};


#endif //MAIN_CPP_IMAGEEFFECT_H
