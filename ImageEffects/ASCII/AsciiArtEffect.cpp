//
// Created by kriz on 22.04.2022.
//

#include "AsciiArtEffect.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

AsciiArtEffect::AsciiArtEffect(ImageData& imageData, std::string &inputAlphabet, int colsX, float scale) :
_imageData(imageData),
_inputAlphabet(inputAlphabet),
_alphabetSize(inputAlphabet.size()-1),
_valuesPerLine(imageData.Width * imageData.Channels)
{
    SetTileWidthByRowLen(colsX);
    SetTileHeightByScalingFactor(scale);
}

AsciiArtEffect::AsciiArtEffect(ImageData& imageData, std::string &inputAlphabet, int tileWidth, int tileHeight) :
        _imageData(imageData),
        _inputAlphabet(inputAlphabet),
        _alphabetSize(inputAlphabet.size()-1),
        _valuesPerLine(imageData.Width * imageData.Channels) {
    SetTileWidth(tileWidth);
    SetTileHeight(tileHeight);
}

void AsciiArtEffect::SetTileWidthByRowLen(int numOfCharsPerLine) {
    assert(("Too large number of letters per row!", numOfCharsPerLine <= _imageData.Width));
    _tileWidth = (_imageData.Width - 1) / (numOfCharsPerLine + 1);
}

void AsciiArtEffect::SetTileHeightByScalingFactor(float scalingFactor) {
    assert(("Given scaling factor is not allowed!", scalingFactor > 0 && scalingFactor <= 1));
    _tileHeight = _tileWidth / scalingFactor;
}

void AsciiArtEffect::SetTileHeight(int tileHeight) {
    assert(("Tile height is not valid!", tileHeight > 0 && tileHeight <= _imageData.Height));
    _tileHeight = tileHeight;
}

void AsciiArtEffect::SetTileWidth(int tileWidth) {
    assert(("Tile width is not valid!", tileWidth > 0 && tileWidth <= _imageData.Height));
    _tileHeight = tileWidth;
}

void AsciiArtEffect::ProcessImageData() {

    for (int i = 0; i < _imageData.Height; i += _tileHeight) {
        // per img line
        for (int j = 0; j < _valuesPerLine; j += _tileWidth * _imageData.Channels) {
            // convolute data of matrix starting(top left value is) at j, i
            ProcessTile(j, i);
        }
    }
}


void AsciiArtEffect::ProcessTile(int tileLeftX, int tileTopY) {
    // average the tiles pixel value and find letter in alphabet
    int sum = 0;

    int lastTilePixelY = tileTopY + _tileHeight;
    int lastTilePixelX = tileLeftX +  _tileWidth * _imageData.Channels;

    int offsetPosition = 0;
    for (int y = tileTopY; y < lastTilePixelY; ++y) {
        for (int x = tileLeftX; x < lastTilePixelX; x += _imageData.Channels) {
            offsetPosition = tileTopY * _valuesPerLine + x;

            sum += _imageData.Data[offsetPosition];
        }
    }
    int tileAverage = sum /(double) (_tileHeight * _tileWidth);

   PutCharacterToOutput(tileAverage, lastTilePixelX >= _valuesPerLine);

}

void AsciiArtEffect::PutCharacterToOutput(int averagedTileValue, bool isEnd) {

    std::cout << _inputAlphabet[(int)((averagedTileValue * _alphabetSize) /(double) _imageData.MaxChannelValue)];

    if (isEnd)
        std::cout << std::endl;

}