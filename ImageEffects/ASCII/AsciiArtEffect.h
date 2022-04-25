//
// Created by kriz on 22.04.2022.
//

#ifndef MAIN_CPP_ASCIIARTEFFECT_H
#define MAIN_CPP_ASCIIARTEFFECT_H

#include <iostream>
#include <string>

#include "../../ImageLibrary/Image/ImageData.h"
#include "../ImageEffect.h"


/**
 * Filter converts image to ascii art and prints it to provided output.
 */
class AsciiArtEffect : public ImageEffect {
public:
    AsciiArtEffect(ImageData &imageData, std::string &inputAlphabet, int colsX, float scale,
                   std::ostream &outputStream);
    AsciiArtEffect(ImageData &imageData, std::string &inputAlphabet, int tileWidth, int tileHeight,
                   std::ostream &outputStream);
    /**
     * Calling this method will convert given image to ascii art and print the data to given output stream.
     */
    void ProcessImageData() override;

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
     * @param _outputStream
     */
    void SetOutputTarget(const std::ostream& _outputStream);

private:
    std::string& _inputAlphabet;
    int _valuesPerLine;
    int _alphabetSize;
    int _tileWidth;
    std::ostream& _outputStream;

    /**
     * Height of tile(or matrix) of pixels thats values are averadged.
     */
    int _tileHeight;

    /**
     * Sets internal size of alphabet.
     */
    void SetAlphabetSize();

    /**
     * Averages value of given tile.
     * @param x
     * @param y
     */
    virtual int ProcessTile(int x, int y);

    /**
     * Gets value from given alphabet.
     * @param value
     * @return
     */
    virtual char GetOutputCharMapping(int value);

};


#endif //MAIN_CPP_ASCIIARTEFFECT_H
