//
// Created by kriz on 12.03.2022.
//

#include "ImageData.h"

ImageData::ImageData() :
    Name( "" ),
    Width( 0 ),
    Height( 0 ),
    Channels( 0 ),
    Data( nullptr ),
    DataSize( 0 ),
    ColorSpace ( ImageData::sRGB )
{ }


ImageData::ImageData(std::string imageName, int width, int height, int numOfChannels, int dataSize, ImageData::ColorSpaces colorSpace) :
Name ( move ( imageName ) ),
Width ( width ),
Height ( height ),
Channels ( numOfChannels ),
Data ( std::make_unique<uint8_t[]>(dataSize) ),
DataSize ( dataSize ),
ColorSpace(colorSpace)
{ }

const int ImageData::ColorChannels = 3;



