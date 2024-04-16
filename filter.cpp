#include "filter.h"
<<<<<<< HEAD
#include <cstdint>

const double ONE_FOR_RGB = 1.0;
void Filter::AddParam(char *param) {
    parameters_.emplace_back(param);
}
void Filter::SetName(char *&name) {
=======

const double ONE_FOR_RGB = 1.0;
void Filter::AddParam(std::string param) {
    parameters_.emplace_back(param);
}
void Filter::SetName(std::string &name) {
>>>>>>> cc50007 (First try)
    name_ = name;
}
void Filter::SetRequiredParametersNum(int value) {
    required_parameters_num_ = value;
}
<<<<<<< HEAD
std::vector<char *> Filter::GetParams() const {
    return parameters_;
}
char *Filter::GetName() const {
=======
std::vector<std::string> Filter::GetParams() const{
    return parameters_;
}
std::string Filter::GetName() const {
>>>>>>> cc50007 (First try)
    return name_;
}
int Filter::GetRequiredParametersNum() const {
    return required_parameters_num_;
}
int Filter::RI(int ind, int max_size) {
    return std::min(std::max(0, ind), max_size - 1);
}
double Filter::Func(const std::vector<std::vector<double>> &c, const std::vector<std::vector<double>> &matrix) {
<<<<<<< HEAD
    return std::min(ONE_FOR_RGB,
                    std::max(0.0, c[0][0] * matrix[0][0] + c[0][1] * matrix[0][1] + c[0][2] * matrix[0][2] +
                                      c[1][0] * matrix[1][0] + c[1][1] * matrix[1][1] + c[1][2] * matrix[1][2] +
                                      c[2][0] * matrix[2][0] + c[2][1] * matrix[2][1] + c[2][2] * matrix[2][2]));
}
void Filter::Clear() {
    parameters_.clear();
}
void Filter::SetParams(std::vector<char *> params) {
=======
    return std::min(ONE_FOR_RGB, std::max(0.0, c[0][0] * matrix[0][0] + c[0][1] * matrix[0][1] + c[0][2] * matrix[0][2] +
                                                   c[1][0] * matrix[1][0] + c[1][1] * matrix[1][1] + c[1][2] * matrix[1][2] +
                                                   c[2][0] * matrix[2][0] + c[2][1] * matrix[2][1] + c[2][2] * matrix[2][2]));
}
void Filter::Clear() {
    parameters_.clear();
    required_parameters_num_ = 0;
    name_ = "";
}
void Filter::SetParams(std::vector<std::string> params) {
>>>>>>> cc50007 (First try)
    parameters_ = params;
}
int Filter::GetParametersNum() const {
    return static_cast<int>(parameters_.size());
<<<<<<< HEAD
}
=======
}
>>>>>>> cc50007 (First try)
