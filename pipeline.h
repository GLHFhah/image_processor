<<<<<<< HEAD
#pragma once
#include "filter.h"
#include "parser.h"
#include <map>
#include <cstdint>
=======
#include "filter.h"
#include "parser.h"
#include <map>
>>>>>>> cc50007 (First try)

class Pipeline {
public:
    Pipeline();

    void ApplyFilters(const Parser &cmd_line, BMPReaderWriter &photo);
<<<<<<< HEAD

private:
    std::map<std::string, Filter *> filters_map_;
=======
private:
    std::map<std::string, Filter*> filters_;
>>>>>>> cc50007 (First try)
};
