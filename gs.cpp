#include "gs.h"
#include "cmath"
<<<<<<< HEAD
#include <cstdint>
=======
>>>>>>> cc50007 (First try)

const double GS_FOR_R = 0.299;
const double GS_FOR_G = 0.587;
const double GS_FOR_B = 0.114;

<<<<<<< HEAD
void Gs::ChangePhoto(BMPReaderWriter &photo) {
=======
void Gs::ChangePhoto(BMPReaderWriter &photo){
>>>>>>> cc50007 (First try)
    for (int i = 0; i < photo.photo_.GetHeight(); ++i) {
        for (int j = 0; j < photo.photo_.GetWidth(); ++j) {
            Image::RGB now_pixel = photo.photo_.GetPixel(i, j);
            double new_rgb = GS_FOR_R * static_cast<double>(now_pixel.r) + GS_FOR_G * static_cast<double>(now_pixel.g) +
<<<<<<< HEAD
                             GS_FOR_B * static_cast<double>(now_pixel.b);
=======
                              GS_FOR_B * static_cast<double>(now_pixel.b);
>>>>>>> cc50007 (First try)
            Image::RGB new_pixel = {new_rgb, new_rgb, new_rgb};
            photo.photo_.SetPixel(i, j, new_pixel);
        }
    }
    photo.SetBMPHeaderWithImage();
    photo.SetDHeaderDerWithImage();
<<<<<<< HEAD
}
Gs::Gs() {
    SetRequiredParametersNum(0);
    SetParams({});
}
=======
}
>>>>>>> cc50007 (First try)
