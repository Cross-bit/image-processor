//
// Created by kriz on 10.03.2022.
//

#include "ImageFormatFactory.h"

ImageFormatFactory::ImageFormatFactory() noexcept {
    RegisterFormat<ImageJPG>("jpg");
}