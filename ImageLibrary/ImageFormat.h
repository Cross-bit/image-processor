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
    virtual bool SaveImageData(const ImageData &dataToSave, const std::string &outFileName) const = 0;

    static std::string RemoveExstention(const std::string &inpFileName);
    static std::string ParseFileName(const std::string &inpFileName);

    explicit ImageFormat() = default;
    virtual ~ImageFormat() = default;

protected:
    virtual std::string AddExstention(const std::string &fileName) const = 0;

    //virtual std::string GetFormatExstention() const = 0;
};


#endif //MAIN_CPP_IMAGEFORMAT_H
