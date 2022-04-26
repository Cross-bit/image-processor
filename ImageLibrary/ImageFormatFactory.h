//
// Created by kriz on 10.03.2022.
//

#ifndef MAIN_CPP_IMAGEFORMATFACTORY_H
#define MAIN_CPP_IMAGEFORMATFACTORY_H

#include "ImageFormat.h"
#include "ImageFormat/ImageJPG.h"

class ImageFormatFactory {
public:
    ImageFormatFactory() noexcept;

    std::unique_ptr<ImageFormat> CreateImageFormat(std::string imgExtension);

    ImageFormatFactory(const ImageFormatFactory&) = delete;
    ImageFormatFactory(const ImageFormatFactory&&) = delete;


private:

    template<typename  TFormat>
    void RegisterFormat(std::string formatType) {
        static_assert(!std::is_same<ImageFormat, TFormat>::value, "Invalid image format type!");
        _imageFormatClassMapping.insert({formatType, std::make_unique<TFormat>});
    }

    std::unordered_map<std::string, std::function<std::unique_ptr<ImageFormat>()>> _imageFormatClassMapping;

};
#endif //MAIN_CPP_IMAGEFORMATFACTORY_H
