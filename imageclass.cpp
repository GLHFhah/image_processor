#include "imageclass.h"

#include <iostream>
<<<<<<< HEAD
#include <cstdint>
=======
>>>>>>> cc50007 (First try)

void Image::SetWidth(int32_t value) {
    width_ = value;
}
void Image::SetHeight(int32_t value) {
    height_ = value;
}
void Image::SetRowSize(int32_t value) {
    row_size_ = value;
}
int32_t Image::GetRowSize() const {
    return row_size_;
}
int32_t Image::GetWidth() const {
    return width_;
}
int32_t Image::GetHeight() const {
    return height_;
}
uint32_t Image::GetImageSize() const {
    return image_size_;
}
void Image::AddRow(std::vector<RGB> &pixels) {
    pixel_array_.emplace_back(pixels);
}
int32_t Image::GetRowSizeWithoutPadding() const {
    return row_size_without_padding_;
}
Image::RGB Image::GetPixel(int32_t row, int32_t column) const {
    return pixel_array_[row][column];
}
std::deque<std::vector<Image::RGB>> Image::GetPixelArray() const {
    return pixel_array_;
}
void Image::DeleteLastRow() {
    pixel_array_.pop_front();
}
void Image::DeleteLastColumn() {
    for (size_t i = 0; i < pixel_array_.size(); i++) {
        pixel_array_[i].pop_back();
    }
}
void Image::SetPixel(int32_t row, int32_t column, RGB new_pixel) {
    pixel_array_[row][column] = new_pixel;
}
