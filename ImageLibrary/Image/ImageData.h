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

    /**
     * Image name.
     */
    std::string Name;
    /**
     * Image (pixel) widht.
     */
    int Width;
    /**
     * Image (pixel) height.
     */
    int Height;
    /**
     * All loaded channels.
     */
    int Channels;
    /**
     * All Image data buffer.
     */
    std::unique_ptr<uint8_t[]> Data;
    /**
     * Total number of pixels, typically width * height * #channels. (i. e. data array len)
     */
    int DataSize;

    ImageData();

    explicit ImageData(std::string imageName, int width, int height, int numOfChannels, int dataSize);

    /**
     * Real number of channels representing color (e.g. RGB).
     */
    static const int ColorChannels;
};


#endif //MAIN_CPP_IMAGEDATA_H
