//
// Created by kriz on 10.03.2022.
//

#include "ImageFormatFactory.h"
#include "ImageFormat/ImageJPG.h"

#include <cctype>
ImageFormatFactory::ImageFormatFactory() noexcept {
    RegisterFormat<ImageJPG>("jpg");
    RegisterFormat<ImageJPG>("jpeg");
}

std::unique_ptr<ImageFormat> ImageFormatFactory::CreateImageFormat(std::string imgExtension) {

    for (auto & c : imgExtension)
        c = std::tolower(c);
    
    auto record = _imageFormatClassMapping.find(imgExtension);

    if(record != _imageFormatClassMapping.end())
        return std::move(record->second());

    return nullptr;
}