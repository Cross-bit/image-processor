//
// Created by kriz on 10.03.2022.
//

#include "ImageFormatFactory.h"
#include "ImageFormat/ImageJPG.h"


ImageFormatFactory::ImageFormatFactory() noexcept {
    // todo dynamically formatType type (from the concrete type)
    RegisterFormat<ImageJPG>("jpg");
    //src: https://stackoverflow.com/questions/69947237/best-way-of-creating-polymorphic-c-objects-with-types-based-on-a-string
}

template<typename  TFormat>
void ImageFormatFactory::RegisterFormat(std::string formatType) {

    //static_assert(std::is_base_of<ImageFormatFactory, TFormat>);
    //_imageFormatClassMapping.insert(std::make_pair(formatType, std::make_unique<TFormat>()))

}


