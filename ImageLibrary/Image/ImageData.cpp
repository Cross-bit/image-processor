//
// Created by kriz on 12.03.2022.
//

#include "ImageData.h"
#include <memory>
#include <string>
#include <algorithm>
#include <string.h>
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

ImageData::ImageData(const ImageData& other) :
Name(other.Name),
Width(other.Width),
Height(other.Height),
Channels(other.Channels),
DataSize(other.DataSize),
ColorSpace(other.ColorSpace)
{
    if(this == &other)
        return;

    Data = std::make_unique<uint8_t[]>(other.DataSize);

    std::copy(&other.Data[0], &other.Data[0] + other.DataSize, &Data[0]);
}

ImageData::ImageData(ImageData&& other) :
        Name(std::move(other.Name)),
        Width(std::move(other.Width)),
        Height(std::move(other.Height)),
        Channels(std::move(other.Channels)),
        DataSize(std::move(other.DataSize)),
        Data(std::move(other.Data)),
        ColorSpace(std::move(other.ColorSpace))
{ }

ImageData& ImageData::operator=(ImageData&& other){
    this->Name = std::move(other.Name);
    this->Width = std::move(other.Width);
    this->Height = std::move(other.Height);
    this->Channels = std::move(other.Channels);
    this->DataSize = std::move(other.DataSize);
    this->Data = std::move(other.Data);
    this->ColorSpace = std::move(other.ColorSpace);

    return *this;
}


ImageData& ImageData::operator=(const ImageData& other){
    if(this == &other)
        return *this;

    this->Name = other.Name;
    this->Width = other.Width;
    this->Height = other.Height;
    this->Channels = other.Channels;
    this->DataSize = other.DataSize;
    this->ColorSpace = other.ColorSpace;

    Data = std::make_unique<uint8_t[]>(other.DataSize);

    std::copy(&other.Data[0], &other.Data[0] + other.DataSize, &Data[0]);

    return *this;
}



const int ImageData::ColorChannels = 3;


// todo: if further exspantion, it would be better to move colorSpaces and its methods to separate classes...

double ImageData::sRGBGammaExspansion(double value_srgb){
    if(value_srgb <= 0.04045)
        return value_srgb / 12.92;
    else
        return pow(((value_srgb+0.055)/1.055), 2.4);
}

double ImageData::sRGBGammaCompression(double value_srgb){
    if(value_srgb <= 0.0031308)
        return value_srgb * 12.92;
    else
        return ((pow(value_srgb, 1/2.4)*1.055) - 0.055);
}


