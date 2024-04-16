<<<<<<< HEAD
#pragma once
#include "filter.h"
#include <cstdint>
class Gs : public Filter {
public:
    void ChangePhoto(BMPReaderWriter &photo) override;
    Gs();
=======
#include "filter.h"
class Gs : public Filter{
public:
    void ChangePhoto(BMPReaderWriter &photo) override;
>>>>>>> cc50007 (First try)
};
