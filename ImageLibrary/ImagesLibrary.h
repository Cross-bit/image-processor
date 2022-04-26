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

struct LibraryRecord
{
    LibraryRecord(std::string filePath, std::unique_ptr<ImageData> imageData):
    FilePath(filePath),
    Data(std::move(imageData)) {}

    std::string FilePath;
    std::unique_ptr<ImageData> Data;
};

class ImagesLibrary {
public:
    /**
     * Adds new data to the library.
     * @param filePath
     * @param imageData
     */
    void AddRecord(const std::string& filePath, std::unique_ptr<ImageData> imageData);

    /**
     * Returns img record base on the index.
     * @param index
     * @return
     */
    std::shared_ptr<LibraryRecord> GetRecordByIndex(int index) const;

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
     * Checks if record exists in library.
     * @return
     */
    bool CheckIfRecordExists(const std::string& recordKey) const;

    /*
     * Gets begin iterator of data.
     */
    std::vector<std::shared_ptr<LibraryRecord>>::const_iterator Begin() const;

    /**
     * Gets end iterator of the data.
     * @return
     */
    std::vector<std::shared_ptr<LibraryRecord>>::const_iterator End() const;

    static std::string ParseFileExstention(const std::string& filePath);

    /**
     * Goes through all records and checks if image file exists at given key. If not it deletes the record.
     */
    void UpdateRecords();

    /**
     * Check if index is in the library data range.
     * @param index
     * @return
     */
    bool CheckIfIndexIsValid(int index) const;


private:
    //std::unordered_map<std::string, std::unique_ptr<ImageData>> _loadedImages;
    std::vector<std::shared_ptr<LibraryRecord>> _loadedImages;

};


#endif //MAIN_CPP_IMAGESLIBRARY_H

