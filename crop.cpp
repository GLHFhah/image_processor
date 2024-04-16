#include "crop.h"
#include <iostream>
<<<<<<< HEAD
#include <cstdint>

void Crop::ChangePhoto(BMPReaderWriter &photo) {
    std::vector<char *> width_height = GetParams();
=======

void Crop::ChangePhoto(BMPReaderWriter &photo){
    std::vector <std::string> width_height = GetParams();
>>>>>>> cc50007 (First try)
    int now_height = photo.photo_.GetHeight();
    int now_width = photo.photo_.GetWidth();
    int need_width = std::stoi(width_height[0]);
    int need_height = std::stoi(width_height[1]);
    int rows_to_delete = now_height - need_height;
    int columns_to_delete = now_width - need_width;
    for (int i = 0; i < rows_to_delete; i++) {
        photo.photo_.DeleteLastRow();
        --now_height;
    }
    for (int i = 0; i < columns_to_delete; i++) {
        photo.photo_.DeleteLastColumn();
        --now_width;
    }
    photo.photo_.SetWidth(now_width);
    photo.photo_.SetHeight(now_height);
    photo.SetBMPHeaderWithImage();
    photo.SetDHeaderDerWithImage();
}
<<<<<<< HEAD
Crop::Crop() {
    SetRequiredParametersNum(2);
    SetParams({});
}
=======
>>>>>>> cc50007 (First try)
