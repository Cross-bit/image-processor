//
// Created by kriz on 08.03.2022.
//

#ifndef MAIN_CPP_IMAGESLIBRARY_H
#define MAIN_CPP_IMAGESLIBRARY_H

#include <iostream>
#include <vector>
#include <unordered_map>

#include "Image/ImageData.h"
#include "ImageFormat.h"

class ImagesLibrary {
public:
    /**
     * Adds new data to the library.
     * @param filePath
     * @param imageData
     */
    void AddRecord(std::string filePath, std::unique_ptr<ImageData> imageData);

    /**
     * Removes record from the library. If doesn't exists, does nothing.
     * @param filePath
     */
    void RemoveRecord(std::string filePath);

    /**
     * Removes all records from the library.
     */
    void ClearLibrary();

    /**
     * Returns all records.
     */
    std::unordered_map<std::string, std::unique_ptr<ImageData>>::iterator GetAllImages();

    /**
     * Goes through all records and checks if image file exists at given key. If not it deletes the record.
     */
    void UpdateRecords();

private:
    std::unordered_map<std::string, std::unique_ptr<ImageData>> _loadedImages;
};


#endif //MAIN_CPP_IMAGESLIBRARY_H

