<<<<<<< HEAD
#pragma once
#include "filter.h"
#include "bmp_utils.h"
#include <cstdint>
class Crop : public Filter {
public:
    Crop();
=======
#include "filter.h"
#include "bmp_utils.h"
class Crop: public Filter{
public:
>>>>>>> cc50007 (First try)
    void ChangePhoto(BMPReaderWriter &photo) override;
};