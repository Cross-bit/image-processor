//
// Created by kriz on 08.03.2022.
//

#ifndef MAIN_CPP_IMAGEFORMAT_H
#define MAIN_CPP_IMAGEFORMAT_H

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <functional>

#include "Image/ImageData.h"


class ImageFormat {
public:
    virtual std::unique_ptr<ImageData> LoadImageData(const std::string &inpFileName) const = 0;
    virtual bool SaveImageData(const ImageData &dataToSave, const std::string &outFileDir) const = 0;

    static std::string RemoveExstention(const std::string &inpFileName);
    static std::string ParseFileName(const std::string &inpFileName);

    explicit ImageFormat() = default;
    virtual ~ImageFormat() = default;

protected:
    virtual std::string AddExstention(const std::string &fileName) const = 0;

    /**
     * Converts 3-rd party library colorspace indexing to ours ColorSpaces enum.
     * @param index
     * @return
     */
    virtual ImageData::ColorSpaces DecodeColorSpaceMapping(int index) const;

    /**
     * Converts ours colorSpace enums to 3-rd party library int representation.
     * @param colorSpace
     * @return
     */
    virtual int EncodeColorSpaceMapping(ImageData::ColorSpaces colorSpace) const;
};


#endif //MAIN_CPP_IMAGEFORMAT_H
