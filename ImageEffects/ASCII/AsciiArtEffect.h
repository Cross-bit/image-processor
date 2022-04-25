//
// Created by kriz on 22.04.2022.
//

#ifndef MAIN_CPP_ASCIIARTEFFECT_H
#define MAIN_CPP_ASCIIARTEFFECT_H

#include <iostream>
#include <string>

#include "../../ImageLibrary/Image/ImageData.h"

class AsciiArtEffect {
public:
    AsciiArtEffect(ImageData& imageData, std::string& inputAlphabet, int cols, float scale);
    AsciiArtEffect(ImageData& imageData, std::string& inputAlphabet, int tileHeight, int tileWidth);

    void ProcessImageData();

private:
    ImageData& _imageData;
    std::string& _inputAlphabet;
    int _valuesPerLine;
    int _alphabetSize;
    int _tileWidth;
    int _tileHeight;


    void SetAlphabetSize();

    void SetTileWidth(int tileWidth);
    void SetTileHeight(int tileHeight);

    /**
     * Sets
     * @param numOfCharsPerLine
     */
    void SetTileWidthByRowLen(int numOfCharsPerLine);

    /**
     * Sets tile height proportionally to the tile width. (which needs to be set first)
     * @param scalingFactor is value between (0, 1]
     */
    void SetTileHeightByScalingFactor(float scalingFactor);

    void ProcessTile(int x, int y);

    void PutCharacterToOutput(int averagedTileValue, bool isEnd);

};


#endif //MAIN_CPP_ASCIIARTEFFECT_H
