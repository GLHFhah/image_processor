#pragma once
<<<<<<< HEAD
=======
#include <cstdint>
>>>>>>> cc50007 (First try)
#include <string>
#include <fstream>
#include <vector>
#include "imageclass.h"

<<<<<<< HEAD
class BMPReaderWriter : public Image::RGB {
=======
class BMPReaderWriter : public Image::RGB{
>>>>>>> cc50007 (First try)
public:
    // static const char BMP_SIGNATURE = {0x42, 0x4D}; // B M
    static const uint16_t BMP_SIGNATURE = 0x4D42;
    static const uint32_t ALL_HEADERS_SIZE = 54;
    static const uint16_t DIB_COLOR_PLANES_NUM = 1;
    static const uint16_t DIB_BITS_PER_PIXEL = 24;
    static const uint16_t DEFAULT_OFFSET = 54;
    static const uint32_t HEADER_SIZE = 40;

<<<<<<< HEAD
    struct BMPHeader {
=======
    struct BMPHeader{
>>>>>>> cc50007 (First try)
        uint16_t signature;
        uint32_t size;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset;
<<<<<<< HEAD
    } __attribute__((packed));

    struct DIBHeader {
=======
    }__attribute__((packed));

    struct DIBHeader{
>>>>>>> cc50007 (First try)
        uint32_t header_size;
        int32_t width;
        int32_t height;
        uint16_t color_planes_num;
        uint16_t bits_per_pixel;
        uint32_t compression;
        uint32_t img_size;
        int32_t hor_res;
        int32_t ver_res;
        uint32_t colors_num;
        uint32_t important_colors_num;
<<<<<<< HEAD
    } __attribute__((packed));

    struct Padding {
        uint8_t a;
    } __attribute__((packed));
=======
    }__attribute__((packed));

    struct Padding{
        uint8_t a;
    }__attribute__((packed));
>>>>>>> cc50007 (First try)

    Image photo_;

public:
<<<<<<< HEAD
    BMPReaderWriter() {
    }

    ~BMPReaderWriter();

    const std::string &ReturnFileName() const {
        return filename_;
    }

    // Открывает файл с переданным именем файла для чтения
    void OpenToRead(const std::string &filename);

    // Открывает файл с переданным именем файла для написания
    void OpenToWrite(const std::string &filename);
=======
    BMPReaderWriter() {}

    ~BMPReaderWriter();

    const std::string& ReturnFileName() const { return filename_; }

    // Открывает файл с переданным именем файла для чтения
    void OpenToRead(const std::string& filename);

    // Открывает файл с переданным именем файла для написания
    void OpenToWrite(const std::string& filename);
>>>>>>> cc50007 (First try)

    // Закрывает файл
    void Close();

    //Считывает bmp файл
    void ReadBmp();

    //Записывает bmp файл
    void WriteBmp(BMPReaderWriter &photo_to_write);

    // Провереяет, открыт ли файл с переданным именем файла
<<<<<<< HEAD
    bool IsOpen() {
        return file_.is_open();
    }
=======
    bool IsOpen() { return file_.is_open(); }
>>>>>>> cc50007 (First try)

    void SetBMPHeaderWithImage();
    void SetDHeaderDerWithImage();

protected:
    // Читает bmp заголовок, не задавая текущую позицию чтения, не выполняет лишних проверок на открытие файла и тд
    void ReadBMPHeader();

    void ReadDIBHeader();

    void ReadRGBPixels();

    void WriteBMPHeader(BMPReaderWriter &photo_to_write);

    void WriteDIBHeader(BMPReaderWriter &photo_to_write);

    void WriteRGBPixels(BMPReaderWriter &photo_to_write);

protected:
    std::string filename_;
    std::fstream file_;
    BMPHeader bmp_header_;
    DIBHeader dib_header_;

protected:
    RGB pixel;
    Padding unused;
};