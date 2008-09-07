#ifndef FILE_HH
#define FILE_HH

#include <fstream>
#include <stdexcept>
#include "common.hh"

void save_ppm(const std::string& filename, const ImageData& data);


#endif // FILE_HH
