//
// Created by kriz on 12.03.2022.
//

#ifndef MAIN_CPP_IMAGEDATA_H
#define MAIN_CPP_IMAGEDATA_H

#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

class ImageData {
public:

    enum ColorSpaces { sRGB, GRAYSCALE }; // todo: fill in other spaces

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
    std::unique_ptr<uint8_t[]> Data; // todo: if time do it generic => more than 8-bits color

    int MaxChannelValue = 255; // constant for now

    int MinChannelValue = 0; // constant for now todo:

    /**
     * Total number of pixels, typically width * height * #channels. (i. e. data array len)
     */
    int DataSize;
    /**
     * In which color space the data are stored.
     */
    ColorSpaces ColorSpace;

    explicit ImageData();

    explicit ImageData(std::string imageName, int width, int height, int numOfChannels, int dataSize, ImageData::ColorSpaces colorSpace);

    ImageData(ImageData &&other);

    ~ImageData() = default;

    ImageData(const ImageData &other);

    ImageData& operator=(const ImageData &other);

    ImageData& operator=(ImageData&& other);

    /**
     * Gets data at index after gamma exspansion (based on the color model).
     * @param index Index of data to get;
     * @return Gamme exspanded data.
     */
    double GetGammaExspanded(int index) const;

    /**
     * Sets dat at index with gamma compression (based on the color model). Modifies the data!(it is up to user to take care about data coherience and consistivity)
     * @param index Index of data to set.
     * @param value Data to set.
     */
    void SetGammaCompressed(int index, double value);

    /**
     * Real number of channels representing color (e.g. RGB).
     */
    static const int ColorChannels;

    static double sRGBGammaExspansion(double value_srgb);

    static double sRGBGammaCompression(double value_srgb);

};


#endif //MAIN_CPP_IMAGEDATA_H
