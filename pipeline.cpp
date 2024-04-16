#include "pipeline.h"

#include "crop.h"
#include "edge.h"
#include "neg.h"
#include "gs.h"
#include "sharp.h"

<<<<<<< HEAD
#include <cstdint>
#include <iostream>
#include <locale>
#include <memory>
Pipeline::Pipeline() {
    filters_map_["-crop"] = new Crop();
    filters_map_["-edge"] = new Edge();
    filters_map_["-neg"] = new Neg();
    filters_map_["-gs"] = new Gs();
    filters_map_["-sharp"] = new Sharp();
}
void Pipeline::ApplyFilters(const Parser& cmd_line, BMPReaderWriter& photo) {
    for (size_t i = 0; i < cmd_line.filters_.size(); ++i) {
        if (filters_map_.find(cmd_line.filters_[i]->GetName()) == filters_map_.end()) {
            throw std::logic_error("There is no such a filter.");
        }
        Filter* type_of_cur_filter = filters_map_[cmd_line.filters_[i]->GetName()];
        for (char*& element : cmd_line.filters_[i]->GetParams()) {
            type_of_cur_filter->AddParam(element);
        }
=======
Pipeline::Pipeline() {
    Crop crop;
    crop.SetRequiredParametersNum(2);
    filters_["-crop"] = &crop;
    Edge edge;
    edge.SetRequiredParametersNum(1);
    filters_["-edge"] = &edge;
    Neg neg;
    neg.SetRequiredParametersNum(0);
    filters_["-neg"] = &neg;
    Edge gs;
    gs.SetRequiredParametersNum(0);
    filters_["-gs"] = &gs;
    Edge sharp;
    sharp.SetRequiredParametersNum(0);
    filters_["-sharp"] = &sharp;
}
void Pipeline::ApplyFilters(const Parser& cmd_line, BMPReaderWriter &photo) {
    for (const Filter* cur_filter : cmd_line.Parser::filters_) {
        if (filters_.find(cur_filter->GetName()) == filters_.end()) {
            throw std::logic_error("There is no such a filter.");
        }
        Filter* type_of_cur_filter = filters_[cur_filter->GetName()];
>>>>>>> cc50007 (First try)
        if (type_of_cur_filter->GetParametersNum() != type_of_cur_filter->GetRequiredParametersNum()) {
            throw std::logic_error("There is incorrect amount of params for filter.");
        }
        type_of_cur_filter->ChangePhoto(photo);
<<<<<<< HEAD
        type_of_cur_filter->Clear();
    }
    delete filters_map_["-crop"];
    delete filters_map_["-edge"];
    delete filters_map_["-neg"];
    delete filters_map_["-gs"];
    delete filters_map_["-sharp"];
=======
    }
>>>>>>> cc50007 (First try)
}
