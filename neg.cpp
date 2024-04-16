#include "neg.h"
<<<<<<< HEAD
#include <cstdint>
=======
>>>>>>> cc50007 (First try)

const double ONE_FOR_RGB = 1.0;

void Neg::ChangePhoto(BMPReaderWriter& photo) {
    for (int i = 0; i < photo.photo_.GetHeight(); ++i) {
        for (int j = 0; j < photo.photo_.GetWidth(); ++j) {
            Image::RGB now_pixel = photo.photo_.GetPixel(i, j);
<<<<<<< HEAD
            Image::RGB new_pixel = {ONE_FOR_RGB - now_pixel.b, ONE_FOR_RGB - now_pixel.g, ONE_FOR_RGB - now_pixel.r};
            photo.photo_.SetPixel(i, j, new_pixel);
        }
    }
    photo.SetBMPHeaderWithImage();
    photo.SetDHeaderDerWithImage();
}
Neg::Neg() {
    SetRequiredParametersNum(0);
    SetParams({});
=======
            Image::RGB new_pixel = {ONE_FOR_RGB - now_pixel.b, ONE_FOR_RGB - now_pixel.g,
                                    ONE_FOR_RGB - now_pixel.r};
            photo.photo_.SetPixel(i, j, new_pixel);
        }
        photo.SetBMPHeaderWithImage();
        photo.SetDHeaderDerWithImage();
    }
>>>>>>> cc50007 (First try)
}
