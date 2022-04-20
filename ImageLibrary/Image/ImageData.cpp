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


// todo: if further exspantion, it would be better to move colorSpaces and its methods to separate classes...

float ImageData::sRGBGammaExspansion(float value_srgb){
    if(value_srgb <= 0.04045)
        return value_srgb / 12.92;
    else
        return pow(((value_srgb+0.055)/1.055), 2.4);
}

float ImageData::sRGBGammaCompression(float value_srgb){
    if(value_srgb <= 0.0031308)
        return value_srgb * 12.92;
    else
        return ((pow(value_srgb, 1/2.4)*1.055) - 0.055);
}


