<<<<<<< HEAD
#pragma once
#include "filter.h"
#include <cstdint>

const double MIDMAT = 5.0;

class Sharp : public Filter {
public:
    void ChangePhoto(BMPReaderWriter &photo) override;
    Sharp();

private:
    std::vector<std::vector<double>> matrix_ = {{0, -1, 0}, {-1, MIDMAT, -1}, {0, -1, 0}};
};
=======
//
// Created by Gosha on 29.10.2023.
//

#ifndef CPP_HSE_SHARP_H
#define CPP_HSE_SHARP_H



class sharp {

};



#endif //CPP_HSE_SHARP_H
>>>>>>> cc50007 (First try)
