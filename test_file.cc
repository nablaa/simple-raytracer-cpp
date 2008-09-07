#include <iostream>
#include <fstream>
#include <sstream>
#include "file.hh"
#include "common.hh"
#include "tests.hh"

const Color RED_COLOR    = { 1.0f, 0.0f, 0.0f };
const Color GREEN_COLOR  = { 0.0f, 1.0f, 0.0f };
const Color BLUE_COLOR   = { 0.0f, 0.0f, 1.0f };
const Color YELLOW_COLOR = { 1.0f, 1.0f, 0.0f };
const Color WHITE_COLOR  = { 1.0f, 1.0f, 1.0f };
const Color BLACK_COLOR  = { 0.0f, 0.0f, 0.0f };


int main()
{
	BEGIN_TESTS("File");

	{
	ImageData data(2);
	data.at(0) = std::vector<Color>(3);
	data.at(1) = std::vector<Color>(3);

	data.at(0).at(0) = RED_COLOR;
	data.at(0).at(1) = GREEN_COLOR;
	data.at(0).at(2) = BLUE_COLOR;
	data.at(1).at(0) = YELLOW_COLOR;
	data.at(1).at(1) = WHITE_COLOR;
	data.at(1).at(2) = BLACK_COLOR;

	const std::string& str = "test_file_ppm_01.ppm";
	save_ppm(str, data);

	std::ifstream file(str.c_str());
	std::ostringstream oss;
	std::string line;
	while (std::getline(file, line)) {
		oss << line << std::endl;
	}

	TEST(true, "save_ppm(), check image");
	}

}
