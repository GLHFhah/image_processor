#include "parser.h"
<<<<<<< HEAD
#include "crop.h"
#include <iostream>
#include <locale>
#include <memory>
#include <cstdint>

void Parser::CmdLineParser(int argc, char**& argv) {
=======
#include "iostream"

void Parser::CmdLineParser(int argc, char** &argv) {
>>>>>>> cc50007 (First try)
    if (argc == 1) {
        throw std::logic_error("No input filename in arguments.");
    }
    input_file_name_ = argv[1];
    if (argc == 2) {
        throw std::logic_error("No output filename in arguments.");
    }
    output_file_name_ = argv[2];
<<<<<<< HEAD
    std::unique_ptr<Filter> cur_filter = std::make_unique<Crop>(Crop());
=======
    Filter* cur_filter = nullptr;
>>>>>>> cc50007 (First try)
    if (argc == 3) {
        return;
    }
    if (argv[3][0] != '-') {
        throw std::logic_error("Filtername must start with -, filter parameters should go after filter name.");
    }
<<<<<<< HEAD
    for (int i = 3; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (i != 3) {
                filters_.emplace_back(std::move(cur_filter));
            }
            cur_filter = std::make_unique<Crop>(Crop());
            cur_filter->SetName(argv[i]);
        } else {
            cur_filter->AddParam(argv[i]);
        }
    }
    filters_.emplace_back(std::move(cur_filter));
=======
    for (int i = 3; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (i != 3) {
                filters_.emplace_back(cur_filter);
            }
            cur_filter->Clear();
            cur_filter->SetName(reinterpret_cast<std::string&>(argv[i]));
        }
        else {
            cur_filter->AddParam(reinterpret_cast<std::string&>(argv[i]));
        }
    }
    filters_.emplace_back(cur_filter);
>>>>>>> cc50007 (First try)
}
void Parser::SetOutputFileName(std::string& name) {
    output_file_name_ = name;
}
void Parser::SetInputFileName(std::string& name) {
    input_file_name_ = name;
}
std::string Parser::GetInputFileName() {
    return input_file_name_;
}
std::string Parser::GetOutputFileName() {
    return output_file_name_;
}
