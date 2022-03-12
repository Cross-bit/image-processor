//
// Created by kriz on 10.03.2022.
//

#ifndef MAIN_CPP_IMAGEJPG_H
#define MAIN_CPP_IMAGEJPG_H


#include "../ImageFormat.h"
#include <jpeglib.h>
#include <setjmp.h>

class ImageJPG : public ImageFormat {
public:
    std::unique_ptr<ImageData> LoadImageData(const std::string &inpFileName) const override;
    bool SaveImageData(const ImageData &dataToSave, const std::string &outFileName) const override;

    virtual ~ImageJPG() = default;
private:

    struct ErrorManager {
        jpeg_error_mgr defaultErrorManager;
        jmp_buf jumpBuffer;
    };

    static void ErrorExit(j_common_ptr cinfo);
    static void OutputMessage(j_common_ptr cinfo);
};


#endif //MAIN_CPP_IMAGEJPG_H
