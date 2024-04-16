<<<<<<< HEAD
#pragma once
#include "filter.h"
#include <cstdint>
class Neg : public Filter {
public:
    void ChangePhoto(BMPReaderWriter &photo) override;
    Neg();
};
=======
#include "filter.h"
class Neg : public Filter {
public:
    void ChangePhoto(BMPReaderWriter &photo) override;
};

>>>>>>> cc50007 (First try)
