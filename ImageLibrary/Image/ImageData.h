//
// Created by kriz on 12.03.2022.
//

#ifndef MAIN_CPP_IMAGEDATA_H
#define MAIN_CPP_IMAGEDATA_H

#include <iostream>

class ImageData {
public:
    int Width;
    int Height;
    int Size;
    uint8_t* Data;

    //ImageFormat() = default;
    /*ImageFormat(std::string fileName);
    ImageFormat(const ImageFormat& other);
    ~ImageFormat();*/

    //std::string GetFormat() const;
};


#endif //MAIN_CPP_IMAGEDATA_H
