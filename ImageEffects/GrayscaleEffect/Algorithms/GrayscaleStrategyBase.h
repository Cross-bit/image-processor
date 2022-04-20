//
// Created by kriz on 20.04.2022.
//

#ifndef MAIN_CPP_GRAYSCALESTRATEGYBASE_H
#define MAIN_CPP_GRAYSCALESTRATEGYBASE_H

#include "../../../ImageLibrary/Image/ImageData.h"

class GrayscaleStrategyBase {
public:
    virtual ~GrayscaleStrategyBase() {}
    virtual void TransformToGrayscale(ImageData& inputData) const = 0;
};


#endif //MAIN_CPP_GRAYSCALESTRATEGYBASE_H
