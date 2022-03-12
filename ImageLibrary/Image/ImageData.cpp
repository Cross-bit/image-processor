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
    DataSize( 0 )
{ }

ImageData::ImageData ( std::string fileName, int width, int height, int numOfChannels, int dataSize ):
    Name ( move ( fileName ) ),
    Width ( width ),
    Height ( height ),
    Channels ( numOfChannels ),
    Data ( std::make_unique<uint8_t[]>(dataSize) ),
    DataSize ( dataSize )
{ }




