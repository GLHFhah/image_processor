#include "bmp_utils.h"
#include "imageclass.h"

<<<<<<< HEAD
#include <cstdint>
=======
>>>>>>> cc50007 (First try)
#include <stdexcept>
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

<<<<<<< HEAD
const double MAX_RGB = 255.0;

const int NUM_FOR_ROUND = 31;
const int FOUR_BYTES = 32;
=======

const double MAX_RGB = 255.0;
>>>>>>> cc50007 (First try)

BMPReaderWriter::~BMPReaderWriter() {
    Close();
}

<<<<<<< HEAD
void BMPReaderWriter::OpenToRead(const std::string &filename) {
=======
void BMPReaderWriter::OpenToRead(const std::string& filename) {
>>>>>>> cc50007 (First try)
    if (file_.is_open()) {
        throw std::logic_error("File is already opened.");
    }
    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty.");
    }

    filename_ = filename;
    file_.open(filename, std::ios_base::in);

    if (!file_.is_open()) {
        throw std::runtime_error("File can't be opened.");
    }
}
void BMPReaderWriter::Close() {
    file_.close();
    filename_.clear();
}

void BMPReaderWriter::ReadBmp() {
    if (!IsOpen()) {
        throw std::logic_error("File is not opened.");
    }

    // Всегда читаем с начала файла
    file_.seekg(0);

    ReadBMPHeader();
    ReadDIBHeader();
    //Переходим на позицию чтения пикселей цветов
    file_.seekg(bmp_header_.offset);
    return ReadRGBPixels();
}
void BMPReaderWriter::ReadBMPHeader() {
    if (!file_) {
        throw std::logic_error("Something wrong with file stream before read.");
    }
    file_.read(reinterpret_cast<char *>(&bmp_header_), sizeof(BMPHeader));
    if (!file_) {
        throw std::runtime_error("Something wrong with file stream after read.");
    }
    // Проверка корректности bmp_header_ прямо здесь
    if (bmp_header_.signature != BMP_SIGNATURE) {
        throw std::runtime_error("BMP file is not correct.");
    }
}
void BMPReaderWriter::ReadDIBHeader() {
    if (!file_) {
        throw std::logic_error("Something wrong with file stream before DIB read.");
    }
    file_.read(reinterpret_cast<char *>(&dib_header_), sizeof(DIBHeader));
    if (!file_) {
        throw std::runtime_error("Something wrong with file stream after DIB read.");
    }
    // Проверка корректности dib_header_ прямо здесь(bits_per_pixel==24?, color planes == 1?)
    if (dib_header_.bits_per_pixel != DIB_BITS_PER_PIXEL) {
        throw std::logic_error("The number of bits per pixel isn't equal to 24.");
    }
    if (dib_header_.color_planes_num != DIB_COLOR_PLANES_NUM) {
        throw std::logic_error("The number of color planes isn't equal to 1.");
    }
}

void BMPReaderWriter::ReadRGBPixels() {
    if (!file_) {
        throw std::logic_error("Something wrong with file stream before pixels read.");
    }
    photo_.SetHeight(dib_header_.height);
    photo_.SetWidth(dib_header_.width);
<<<<<<< HEAD
    photo_.SetRowSize((photo_.GetWidth() * dib_header_.bits_per_pixel + NUM_FOR_ROUND) / FOUR_BYTES * 4);
=======
    photo_.SetRowSize((photo_.GetWidth() * dib_header_.bits_per_pixel + 31) / 32 * 4);
>>>>>>> cc50007 (First try)
    photo_.SetRowSizeWithoutPadding();
    photo_.SetImageSize();
    for (int32_t ind_of_row = 0; ind_of_row < photo_.GetHeight(); ++ind_of_row) {
        std::vector<BMPReaderWriter::RGB> row_of_pixels;
<<<<<<< HEAD
        for (int32_t ind_of_pixel = 0; ind_of_pixel < photo_.GetWidth(); ++ind_of_pixel) {
=======
        for (int32_t ind_of_pixel = 0; ind_of_pixel < photo_.GetWidth();
             ++ind_of_pixel) {
>>>>>>> cc50007 (First try)
            uint8_t pixel_rgb_el = 0;
            file_.read(reinterpret_cast<char *>(&pixel_rgb_el), sizeof(uint8_t));
            pixel.b = static_cast<double>(pixel_rgb_el) / MAX_RGB;
            file_.read(reinterpret_cast<char *>(&pixel_rgb_el), sizeof(uint8_t));
            pixel.g = static_cast<double>(pixel_rgb_el) / MAX_RGB;
            file_.read(reinterpret_cast<char *>(&pixel_rgb_el), sizeof(uint8_t));
            pixel.r = static_cast<double>(pixel_rgb_el) / MAX_RGB;
            if (!file_) {
<<<<<<< HEAD
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row) + " " +
                                         std::to_string(ind_of_pixel) + "pixel read.");
=======
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row)
                                         + " " + std::to_string(ind_of_pixel) + "pixel read.");
>>>>>>> cc50007 (First try)
            }
            row_of_pixels.emplace_back(pixel);
        }
        for (int32_t ind_of_pixel = 0; ind_of_pixel < photo_.GetRowSize() - photo_.GetWidth() * 3; ++ind_of_pixel) {
            file_.read(reinterpret_cast<char *>(&unused), sizeof(Padding));
            if (!file_) {
<<<<<<< HEAD
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row) + " " +
                                         std::to_string(ind_of_pixel) + "padding read.");
=======
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row) +
                                         " " + std::to_string(ind_of_pixel) + "padding read.");
>>>>>>> cc50007 (First try)
            }
        }
        photo_.AddRow(row_of_pixels);
        if (row_of_pixels.size() != photo_.GetWidth()) {
<<<<<<< HEAD
            throw std::runtime_error("Something wrong with width of " + std::to_string(ind_of_row) + " row of pixel");
=======
            throw std::runtime_error("Something wrong with width of " + std::to_string(ind_of_row) +
                                     " row of pixel");
>>>>>>> cc50007 (First try)
        }
    }
}

void BMPReaderWriter::WriteBmp(BMPReaderWriter &photo_to_write) {
    if (!IsOpen()) {
        throw std::logic_error("File is not opened.");
    }

    // Всегда пишем с начала файла
    file_.seekg(0);

    WriteBMPHeader(photo_to_write);
    WriteDIBHeader(photo_to_write);

    //Переходим на позицию чтения пикселей цветов
    for (int i = 0; i < photo_to_write.bmp_header_.offset - DEFAULT_OFFSET; i++) {
        unused.a = 0;
        file_.write(reinterpret_cast<char *>(&unused), sizeof(Padding));
    }
    WriteRGBPixels(photo_to_write);
}

void BMPReaderWriter::WriteBMPHeader(BMPReaderWriter &photo_to_write) {
    if (!file_) {
        throw std::logic_error("Something wrong with file stream before write.");
    }
    file_.write(reinterpret_cast<char *>(&photo_to_write.bmp_header_), sizeof(BMPHeader));

    if (!file_) {
        throw std::runtime_error("Something wrong with file stream after write.");
    }
}

void BMPReaderWriter::WriteDIBHeader(BMPReaderWriter &photo_to_write) {
    if (!file_) {
        throw std::logic_error("Something wrong with file stream before DIB write.");
    }
    file_.write(reinterpret_cast<char *>(&photo_to_write.dib_header_), sizeof(DIBHeader));
    if (!file_) {
        throw std::runtime_error("Something wrong with file stream after DIB write.");
    }
}

void BMPReaderWriter::WriteRGBPixels(BMPReaderWriter &photo_to_write) {
    if (!file_) {
        throw std::logic_error("Something wrong with file stream before pixels write.");
    }

    for (int32_t ind_of_row = 0; ind_of_row < photo_to_write.photo_.GetHeight(); ++ind_of_row) {
        for (int32_t ind_of_pixel = 0; ind_of_pixel < photo_to_write.photo_.GetWidth(); ++ind_of_pixel) {
            pixel = photo_to_write.photo_.GetPixel(ind_of_row, ind_of_pixel);
            uint8_t pixel_rgb_el = static_cast<uint8_t>(std::round(pixel.b * MAX_RGB));
            file_.write(reinterpret_cast<char *>(&pixel_rgb_el), sizeof(uint8_t));
            pixel_rgb_el = static_cast<uint8_t>(std::round(pixel.g * MAX_RGB));
            file_.write(reinterpret_cast<char *>(&pixel_rgb_el), sizeof(uint8_t));
            pixel_rgb_el = static_cast<uint8_t>(std::round(pixel.r * MAX_RGB));
            file_.write(reinterpret_cast<char *>(&pixel_rgb_el), sizeof(uint8_t));
            if (!file_) {
<<<<<<< HEAD
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row) + " " +
                                         std::to_string(ind_of_pixel) + "pixel write.");
=======
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row)
                                         + " " + std::to_string(ind_of_pixel) + "pixel write.");
>>>>>>> cc50007 (First try)
            }
        }
        for (int32_t ind_of_pixel = 0;
             ind_of_pixel < photo_to_write.photo_.GetRowSize() - photo_to_write.photo_.GetWidth() * 3; ++ind_of_pixel) {
            unused.a = 0;
            file_.write(reinterpret_cast<char *>(&unused), sizeof(Padding));
            if (!file_) {
<<<<<<< HEAD
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row) + " " +
                                         std::to_string(ind_of_pixel) + "padding write.");
=======
                throw std::runtime_error("Something wrong with file stream after " + std::to_string(ind_of_row)
                                         + " " + std::to_string(ind_of_pixel) + "padding write.");
>>>>>>> cc50007 (First try)
            }
        }
    }
}
void BMPReaderWriter::OpenToWrite(const std::string &filename) {
    if (file_.is_open()) {
        throw std::logic_error("File is already opened.");
    }
    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty.");
    }

    filename_ = filename;
    file_.open(filename, std::ios_base::out);

    if (!file_.is_open()) {
        throw std::runtime_error("File can't be opened.");
    }
}
void BMPReaderWriter::SetBMPHeaderWithImage() {
<<<<<<< HEAD
    bmp_header_.size =
        ((photo_.GetWidth() * DIB_BITS_PER_PIXEL + NUM_FOR_ROUND) / FOUR_BYTES * 4) * photo_.GetHeight() +
        bmp_header_.offset;
=======
    bmp_header_.size = ((photo_.GetWidth() * DIB_BITS_PER_PIXEL + 31) / 32 * 4) * photo_.GetHeight() + bmp_header_.offset;
>>>>>>> cc50007 (First try)
}

void BMPReaderWriter::SetDHeaderDerWithImage() {
    dib_header_.header_size = HEADER_SIZE;
    dib_header_.width = photo_.GetWidth();
    dib_header_.height = photo_.GetHeight();
    dib_header_.color_planes_num = 1;
    dib_header_.bits_per_pixel = DIB_BITS_PER_PIXEL;
    dib_header_.compression = 0;
    dib_header_.img_size = 0;
    dib_header_.hor_res = 0;
    dib_header_.ver_res = 0;
    dib_header_.colors_num = 0;
    dib_header_.important_colors_num = 0;
    photo_.SetHeight(dib_header_.height);
    photo_.SetWidth(dib_header_.width);
<<<<<<< HEAD
    photo_.SetRowSize((photo_.GetWidth() * dib_header_.bits_per_pixel + NUM_FOR_ROUND) / FOUR_BYTES * 4);
=======
    photo_.SetRowSize((photo_.GetWidth() * dib_header_.bits_per_pixel + 31) / 32 * 4);
>>>>>>> cc50007 (First try)
    photo_.SetRowSizeWithoutPadding();
    photo_.SetImageSize();
}
