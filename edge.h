<<<<<<< HEAD
#pragma once
#include "filter.h"
#include <cstdint>

class Edge : public Filter {
public:
    void ChangePhoto(BMPReaderWriter &photo) override;
    Edge();

private:
    std::vector<std::vector<double>> matrix_ = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
=======
#include "filter.h"

class Edge : public Filter{
public:
    void ChangePhoto(BMPReaderWriter &photo) override;
private:
    std::vector<std::vector <double>> matrix_ = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
>>>>>>> cc50007 (First try)
};
