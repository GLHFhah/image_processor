#pragma once
#include <vector>
#include <deque>
<<<<<<< HEAD
#include <cstdint>

class Image {
public:
    struct RGB {
        double b;
        double g;
        double r;
    } __attribute__((packed));
=======

class Image {
public:
    struct RGB{
        double b;
        double g;
        double r;
    }__attribute__((packed));
>>>>>>> cc50007 (First try)

public:
    void SetWidth(int32_t value);
    void SetHeight(int32_t value);
    void SetRowSize(int32_t value);
<<<<<<< HEAD
    void SetImageSize() {
        image_size_ = row_size_ * height_;
    }
    void SetRowSizeWithoutPadding() {
        row_size_without_padding_ = row_size_ - width_ * 3;
    }
=======
    void SetImageSize() {image_size_ = row_size_ * height_;}
    void SetRowSizeWithoutPadding() {row_size_without_padding_ = row_size_ - width_ * 3;}
>>>>>>> cc50007 (First try)
    void SetPixel(int32_t row, int32_t column, RGB new_pixel);
    int32_t GetWidth() const;
    int32_t GetHeight() const;
    int32_t GetRowSize() const;
    uint32_t GetImageSize() const;
    RGB GetPixel(int32_t row, int32_t column) const;
    int32_t GetRowSizeWithoutPadding() const;
    std::deque<std::vector<RGB>> GetPixelArray() const;

    void AddRow(std::vector<RGB> &pixel);
    void DeleteLastRow();
    void DeleteLastColumn();
<<<<<<< HEAD

=======
>>>>>>> cc50007 (First try)
private:
    uint32_t image_size_;
    int32_t width_;
    int32_t height_;
    int32_t row_size_;
    int32_t row_size_without_padding_;
    std::deque<std::vector<RGB>> pixel_array_;
};