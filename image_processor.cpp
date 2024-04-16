#include <iostream>
#include <cassert>
<<<<<<< HEAD
#include <cstdint>
=======
>>>>>>> cc50007 (First try)

#include "parser.h"
#include "crop.h"
#include "bmp_utils.h"
#include "gs.h"
#include "neg.h"
#include "sharp.h"
#include "edge.h"
#include "pipeline.h"

<<<<<<< HEAD
const std::string LENNA_FILENAME =
    "/Users/Gosha/Library/Mobile Documents/com~apple~CloudDocs/HSE C++ /pmi-235-2-George-"
    "Lupiltsev-GLHF/tasks/image_processor/test_script/data/lenna.bmp";

const std::string DOPTEST_FILENAME =
    "/Users/Gosha/Library/Mobile Documents/com~apple~CloudDocs/HSE C++ /pmi-235-2-George-"
    "Lupiltsev-GLHF/tasks/image_processor/test_script/data/doptest.bmp";

int main(int argc, char** argv) {
=======
const std::string LENNA_FILENAME = "/Users/Gosha/Library/Mobile Documents/com~apple~CloudDocs/HSE C++ /pmi-235-2-George-"
    "Lupiltsev-GLHF/tasks/image_processor/test_script/data/flag.bmp";

const std::string DOPTEST_FILENAME = "/Users/Gosha/Library/Mobile Documents/com~apple~CloudDocs/HSE C++ /pmi-235-2-George-"
    "Lupiltsev-GLHF/tasks/image_processor/test_script/data/doptest.bmp";

void test001() {
    BMPReaderWriter bmp_rw;

    try {
        bmp_rw.OpenToRead(LENNA_FILENAME);
    }
    catch (std::exception& e){
        std::cerr << "TEST001 Excpetion: " << e.what() << "\n";
    }
    catch(...){
        std::cerr << "TEST001 Unknown Excpetion" << "\n";
    }

    assert(bmp_rw.IsOpen());

}

void test002() {
    BMPReaderWriter bmp_rw;

    bmp_rw.OpenToRead(LENNA_FILENAME);
    bmp_rw.ReadBmp();

    bmp_rw.Close();

    BMPReaderWriter bmp_wr;
    bmp_wr.OpenToWrite(DOPTEST_FILENAME);
    Edge filter_crop_second;
    filter_crop_second.AddParam("0.1");
    filter_crop_second.ChangePhoto(bmp_rw);
    bmp_wr.WriteBmp(bmp_rw);
    bmp_wr.Close();
}

int main(int argc, char** argv) {
    try {
        test001();
        test002();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    catch (...){
        std::cerr << "Unknown Excpetion" << "\n";
        return 1;
    }
>>>>>>> cc50007 (First try)
    Parser cmd_line;
    cmd_line.CmdLineParser(argc, argv);
    const std::string input_filename = cmd_line.GetInputFileName();
    const std::string output_filename = cmd_line.GetOutputFileName();
    BMPReaderWriter bmp_rw;

    bmp_rw.OpenToRead(input_filename);
    bmp_rw.ReadBmp();

    bmp_rw.Close();
<<<<<<< HEAD
    Pipeline mainfunc;

=======

    Pipeline mainfunc;
>>>>>>> cc50007 (First try)
    mainfunc.ApplyFilters(cmd_line, bmp_rw);

    BMPReaderWriter bmp_wr;
    bmp_wr.OpenToWrite(output_filename);
    bmp_wr.WriteBmp(bmp_rw);
    bmp_wr.Close();
}
