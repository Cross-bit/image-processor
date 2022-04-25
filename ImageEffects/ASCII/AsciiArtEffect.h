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

    /**
     * Sets tile width (how many pixels in width)
     * @param tileWidth
     */
    void SetTileWidth(int tileWidth);

    /**
     * Sets tile height (how many pixels in height)
     * @param tileHeight
     */
    void SetTileHeight(int tileHeight);

    /**
     * Sets tile width by: "how many chars per line should be printed".
     * @param numOfCharsPerLine
     */
    void SetTileWidthByRowLen(int numOfCharsPerLine);

    /**
     * Sets tile height proportionally to the tile width. (which needs to be set first)
     * @param scalingFactor is value between (0, 1]
     */
    void SetTileHeightByScalingFactor(float scalingFactor);

    /**
     * Puts characters into output stream.
     * @param outputLetter Letter to put to the output stream.
     * @param isEnd Wheter to put end of line symbol.
     */
    void PutCharacterToOutput(char outputLetter, bool isEnd);

    /**
     * Sets output stream where should the characters should be printed.
     * @param _outputTarget
     */
    void SetOutputTarget(const std::ostream& _outputTarget);

private:
    ImageData& _imageData;
    std::string& _inputAlphabet;
    int _valuesPerLine;
    int _alphabetSize;
    int _tileWidth;
    std::ostream _outputTarget;

    /**
     * Height of tile(or matrix) of pixels thats values are averadged.
     */
    int _tileHeight;

    /**
     * Sets internal size of alphabet.
     */
    void SetAlphabetSize();

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
