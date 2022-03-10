//
// Created by kriz on 08.03.2022.
//

#ifndef MAIN_CPP_IMAGESLIBRARY_H
#define MAIN_CPP_IMAGESLIBRARY_H

#include <iostream>
#include <vector>
#include <vector>


class ImagesLibrary {
public:

    void AddNewPathToLibrary();
    void RemovePathFromLibrary();

    void ClearLibrary();
    void GetAllImages();

private:
    std::vector<std::string> loadedImagesPaths;
};


#endif //MAIN_CPP_IMAGESLIBRARY_H

