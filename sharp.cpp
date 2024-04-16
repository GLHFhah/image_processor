#include "sharp.h"
#include <algorithm>
#include <vector>
<<<<<<< HEAD
#include <cstdint>
=======

>>>>>>> cc50007 (First try)

void Sharp::ChangePhoto(BMPReaderWriter &photo) {
    Image previous_photo = photo.photo_;
    for (int i = 0; i < photo.photo_.GetHeight(); ++i) {
        for (int j = 0; j < photo.photo_.GetWidth(); ++j) {
            int max_height = photo.photo_.GetHeight();
            int max_width = photo.photo_.GetWidth();
<<<<<<< HEAD
            std::vector<std::vector<double>> matrix_of_b = {
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j - 1, max_width)).b,
                 previous_photo.GetPixel(RI(i, max_height), RI(j - 1, max_width)).b,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j - 1, max_width)).b},
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j, max_width)).b,
                 previous_photo.GetPixel(RI(i, max_height), RI(j, max_width)).b,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j, max_width)).b},
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j + 1, max_width)).b,
                 previous_photo.GetPixel(RI(i, max_height), RI(j + 1, max_width)).b,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j + 1, max_width)).b}};

            std::vector<std::vector<double>> matrix_of_g = {
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j - 1, max_width)).g,
                 previous_photo.GetPixel(RI(i, max_height), RI(j - 1, max_width)).g,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j - 1, max_width)).g},
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j, max_width)).g,
                 previous_photo.GetPixel(RI(i, max_height), RI(j, max_width)).g,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j, max_width)).g},
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j + 1, max_width)).g,
                 previous_photo.GetPixel(RI(i, max_height), RI(j + 1, max_width)).g,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j + 1, max_width)).g}};

            std::vector<std::vector<double>> matrix_of_r = {
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j - 1, max_width)).r,
                 previous_photo.GetPixel(RI(i, max_height), RI(j - 1, max_width)).r,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j - 1, max_width)).r},
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j, max_width)).r,
                 previous_photo.GetPixel(RI(i, max_height), RI(j, max_width)).r,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j, max_width)).r},
                {previous_photo.GetPixel(RI(i - 1, max_height), RI(j + 1, max_width)).r,
                 previous_photo.GetPixel(RI(i, max_height), RI(j + 1, max_width)).r,
                 previous_photo.GetPixel(RI(i + 1, max_height), RI(j + 1, max_width)).r}};
=======
            std::vector <std::vector <double>> matrix_of_b =
                {{previous_photo.GetPixel(RI(i - 1, max_height), RI(j - 1, max_width)).b,
                  previous_photo.GetPixel(RI(i, max_height), RI(j - 1, max_width)).b,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j - 1, max_width)).b},
              {previous_photo.GetPixel(RI(i - 1, max_height), RI(j, max_width)).b,
                  previous_photo.GetPixel(RI(i, max_height), RI(j, max_width)).b,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j, max_width)).b},
              {previous_photo.GetPixel(RI(i - 1, max_height), RI(j + 1, max_width)).b,
                  previous_photo.GetPixel(RI(i, max_height), RI(j + 1, max_width)).b,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j + 1, max_width)).b}};

            std::vector <std::vector <double>> matrix_of_g =
                {{previous_photo.GetPixel(RI(i - 1, max_height), RI(j - 1, max_width)).g,
                  previous_photo.GetPixel(RI(i, max_height), RI(j - 1, max_width)).g,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j - 1, max_width)).g},
                 {previous_photo.GetPixel(RI(i - 1, max_height), RI(j, max_width)).g,
                  previous_photo.GetPixel(RI(i, max_height), RI(j, max_width)).g,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j, max_width)).g},
                 {previous_photo.GetPixel(RI(i - 1, max_height), RI(j + 1, max_width)).g,
                  previous_photo.GetPixel(RI(i, max_height), RI(j + 1, max_width)).g,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j + 1, max_width)).g}};

            std::vector <std::vector <double>> matrix_of_r =
                {{previous_photo.GetPixel(RI(i - 1, max_height), RI(j - 1, max_width)).r,
                  previous_photo.GetPixel(RI(i, max_height), RI(j - 1, max_width)).r,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j - 1, max_width)).r},
                 {previous_photo.GetPixel(RI(i - 1, max_height), RI(j, max_width)).r,
                  previous_photo.GetPixel(RI(i, max_height), RI(j, max_width)).r,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j, max_width)).r},
                 {previous_photo.GetPixel(RI(i - 1, max_height), RI(j + 1, max_width)).r,
                  previous_photo.GetPixel(RI(i, max_height), RI(j + 1, max_width)).r,
                  previous_photo.GetPixel(RI(i + 1, max_height), RI(j + 1, max_width)).r}};
>>>>>>> cc50007 (First try)

            double new_rgb_b = Func(matrix_, matrix_of_b);
            double new_rgb_g = Func(matrix_, matrix_of_g);
            double new_rgb_r = Func(matrix_, matrix_of_r);

            Image::RGB new_pixel = {new_rgb_b, new_rgb_g, new_rgb_r};
            photo.photo_.SetPixel(i, j, new_pixel);
        }
    }
    photo.SetBMPHeaderWithImage();
    photo.SetDHeaderDerWithImage();
}
<<<<<<< HEAD
Sharp::Sharp() {
    SetRequiredParametersNum(0);
    SetParams({});
}
=======
>>>>>>> cc50007 (First try)
