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

class ImageFormat {
public:
    const int Width;
    const int Height;
    const int Size;

    ImageFormat(std::string fileName);
    ImageFormat(const ImageFormat& other);
    ~ImageFormat();

    std::string GetFormat() const;

private:
    void LoadImageData();
    void WriteImageData();
};


#endif //MAIN_CPP_IMAGEFORMAT_H
