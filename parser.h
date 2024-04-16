#pragma once
#include <string>
#include "filter.h"
#include <vector>
<<<<<<< HEAD
#include <memory>
#include <cstdint>

class Parser {
public:
    void CmdLineParser(int argc, char **&argv);
=======

class Parser {
public:
    void CmdLineParser(int argc, char** &argv);
>>>>>>> cc50007 (First try)
    void SetInputFileName(std::string &name);
    void SetOutputFileName(std::string &name);

    std::string GetInputFileName();
    std::string GetOutputFileName();

<<<<<<< HEAD
    std::vector<std::unique_ptr<Filter>> filters_;

=======
    std::vector<Filter*> filters_;
>>>>>>> cc50007 (First try)
private:
    std::string input_file_name_;
    std::string output_file_name_;
};