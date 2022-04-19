//
// Created by kriz on 12.03.2022.
//

#ifndef MAIN_CPP_IMAGEDATA_H
#define MAIN_CPP_IMAGEDATA_H

#include <iostream>
#include <memory>
#include <vector>

class ImageData {
public:

    std::string Name;
    int Width;
    int Height;
    int Channels;
    std::unique_ptr<uint8_t[]> Data;
    int DataSize; // total number of pixels, typically width * height * #channels

    ImageData();

    explicit ImageData(std::string imageName, int width, int height, int numOfChannels, int dataSize);
};


#endif //MAIN_CPP_IMAGEDATA_H
