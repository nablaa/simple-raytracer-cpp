#include "file.hh"

void save_ppm(const std::string& filename, const ImageData& data)
{
	std::ofstream file(filename.c_str(),
	                   std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);

	if (!file.is_open()) {
		throw std::runtime_error("could not write file: " + filename);
	}

	const size_t w = data.at(1).size();
	const size_t h = data.size();

	// PPM header
	// type: P6, width: w, height: h, max color: 255
	file << "P6" << std::endl << w << " " << h << std::endl << "255" << std::endl;

	static unsigned char color[3];
	for (size_t j = 0; j < h; ++j) {
		for (size_t i = 0; i < w; ++i) {
			color[0] = static_cast<int>(data.at(j).at(i).r * 255) % 256;
			color[1] = static_cast<int>(data.at(j).at(i).g * 255) % 256;
			color[2] = static_cast<int>(data.at(j).at(i).b * 255) % 256;
			file << (char)color[0] << (char)color[1] << (char)color[2];
			// TODO check failbit
		}
	}
}
