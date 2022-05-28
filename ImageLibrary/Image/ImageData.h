//
// Created by kriz on 12.03.2022.
//

#ifndef MAIN_CPP_IMAGEDATA_H
#define MAIN_CPP_IMAGEDATA_H

#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

/**
 * Represents image data.
 */
class ImageData {
public:

    // add other spaces here if needed
    enum ColorSpaces { sRGB, GRAYSCALE };

    /**
     * Image name.
     */
    std::string Name;

    /**
     * Image (pixel) width.
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
    std::unique_ptr<uint8_t[]> Data; // note: would be nice to make it generic, not only 8-bit

    /**
     * Maximal value per channel(depends on depth).
     */
    const int MaxChannelValue = 255;

    /**
     * Minimal value per channel(typically zero)
     */
    const int MinChannelValue = 0;

    /**
     * Total number of pixels, typically width * height * #channels. (i. e. data array len)
     */
    int DataSize;

    /**
     * In which color space the data are stored.
     */
    ColorSpaces ColorSpace;

    /**
     * Real number of channels that represents the color (e.g. RGB).
     */
    static const int ColorChannels; // for example for PNG, this value will be still 3

    explicit ImageData();

    explicit ImageData(std::string imageName, int width, int height, int numOfChannels, int dataSize, ImageData::ColorSpaces colorSpace);

    ImageData(ImageData &&other);

    ~ImageData() = default;

    ImageData(const ImageData &other);

    ImageData& operator=(const ImageData &other);

    ImageData& operator=(ImageData&& other);

    /**
     * Gets data at index after gamma expansion (based on the color model).
     * @param index Index of data to get;
     * @return Gamme exspanded data.
     */
    double GetGammaExpanded(int index) const;

    /**
     * Sets dat at index with gamma compression (based on the color model). Modifies the data!(it is up to user to take care about data coherience and consistivity)
     * @param index Index of data to set.
     * @param value Data to set.
     */
    void SetGammaCompressed(int index, double value);

    /**
     * Performs gamma expansion in sRGB.
     * @param value_srgb
     * @return
     */
    static double sRGBGammaExpansion(double value_srgb);

    /**
     * Performs gamma compression in sRGB.
     * @param value_srgb
     * @return
     */
    static double sRGBGammaCompression(double value_srgb);

};

#endif //MAIN_CPP_IMAGEDATA_H
