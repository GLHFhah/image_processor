#pragma once
#include <string>
#include <vector>
<<<<<<< HEAD
#include <memory>
#include <cstdint>
#include <map>
=======
>>>>>>> cc50007 (First try)
#include "bmp_utils.h"

class Filter {
public:
<<<<<<< HEAD
    virtual ~Filter() = default;
    void AddParam(char *param);
    void SetParams(std::vector<char *> params);
    void SetName(char *&name);
    void SetRequiredParametersNum(int value);
    int RI(int ind, int max_size);
    double Func(const std::vector<std::vector<double>> &c, const std::vector<std::vector<double>> &matrix);

    std::vector<char *> GetParams() const;
    char *GetName() const;
    int GetRequiredParametersNum() const;
    int GetParametersNum() const;

    void Clear();

    virtual void ChangePhoto(BMPReaderWriter &photo) = 0;

private:
    std::vector<char *> parameters_ = {};
    char *name_;
    int required_parameters_num_ = 0;
=======
    void AddParam(std::string param);
    void SetParams(std::vector<std::string> params);
    void SetName(std::string &name);
    void SetRequiredParametersNum(int value);
    int RI(int ind, int max_size);
    double Func(const std::vector <std::vector<double>> &c, const std::vector <std::vector<double>> &matrix);

    std::vector<std::string> GetParams() const;
    std::string GetName() const ;
    int GetRequiredParametersNum() const;
    int GetParametersNum() const;

    virtual void ChangePhoto(BMPReaderWriter& photo) = 0;

    void Clear();
private:
    std::vector<std::string> parameters_;
    std::string name_;
    int required_parameters_num_;
>>>>>>> cc50007 (First try)
};