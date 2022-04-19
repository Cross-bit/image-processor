//
// Created by kriz on 08.03.2022.
//

#include "ImageFormat.h"

std::string ImageFormat::RemoveExstention(const std::string &fileName){
    auto dotIndex = fileName.find_last_of( '.' );
    return fileName.substr ( 0, dotIndex );
}

std::string ImageFormat::ParseFileName(const std::string &fileName) {

    auto indexOfName = fileName.find_last_of("/\\");
    return RemoveExstention(fileName.substr(indexOfName + 1 ));
}

ImageData::ColorSpaces ImageFormat::DecodeColorSpaceMapping(int index) const {
    return ImageData::ColorSpaces::sRGB;
}

int ImageFormat::EncodeColorSpaceMapping(ImageData::ColorSpaces colorSpace) const {
    return 0;
}


