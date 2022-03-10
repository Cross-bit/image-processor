//
// Created by kriz on 10.03.2022.
//

#ifndef MAIN_CPP_IMAGEFORMATFACTORY_H
#define MAIN_CPP_IMAGEFORMATFACTORY_H

#include "ImageFormat.h"

class ImageFormatFactory {
public:
    ImageFormatFactory() noexcept;

    std::unique_ptr<ImageFormat> CreateImageFormat(const std::string &fileName);

    ImageFormatFactory(const ImageFormatFactory&) = delete;
    ImageFormatFactory(const ImageFormatFactory&&) = delete;

private:
    template<typename  TFormat>
    void RegisterFormat(std::string formatType);

    std::unordered_map<std::string, std::function<std::unique_ptr<ImageFormat>()>> _imageFormatClassMapping;

};
#endif //MAIN_CPP_IMAGEFORMATFACTORY_H
