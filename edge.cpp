#include "edge.h"
#include "gs.h"
#include <algorithm>
#include <vector>
#include <iostream>
<<<<<<< HEAD
#include <cstdint>
=======
>>>>>>> cc50007 (First try)

const double ONE_FOR_RGB = 1.0;

void Checkthreshold(double &color1, double &color2, double &color3, double threshold) {
    if (color1 > threshold) {
        color1 = ONE_FOR_RGB;
        color2 = ONE_FOR_RGB;
        color3 = ONE_FOR_RGB;
        return;
    }
    color1 = 0.0;
    color2 = 0.0;
    color3 = 0.0;
}

<<<<<<< HEAD
void Edge::ChangePhoto(BMPReaderWriter &photo) {
=======
void Edge::ChangePhoto(BMPReaderWriter& photo) {
>>>>>>> cc50007 (First try)
    Gs to_gray;
    to_gray.ChangePhoto(photo);
    Image previous_photo = photo.photo_;
    int max_height = photo.photo_.GetHeight();
    int max_width = photo.photo_.GetWidth();
    for (int i = 0; i < photo.photo_.GetHeight(); ++i) {
        for (int j = 0; j < photo.photo_.GetWidth(); ++j) {
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

            double threshold = std::stod(GetParams()[0]);

            double new_rgb_b = Func(matrix_, matrix_of_b);
            double new_rgb_g = Func(matrix_, matrix_of_g);
            double new_rgb_r = Func(matrix_, matrix_of_r);

            Checkthreshold(new_rgb_b, new_rgb_g, new_rgb_r, threshold);

            Image::RGB new_pixel = {new_rgb_b, new_rgb_g, new_rgb_r};
            photo.photo_.SetPixel(i, j, new_pixel);
        }
    }
    photo.SetBMPHeaderWithImage();
    photo.SetDHeaderDerWithImage();
}
<<<<<<< HEAD
Edge::Edge() {
    SetRequiredParametersNum(1);
    SetParams({});
}
=======
>>>>>>> cc50007 (First try)
