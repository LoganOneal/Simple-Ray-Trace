#include "RGB.h"
#include "PPM.h"
#include <fstream>

RGB& PPM::get(unsigned int a, unsigned int b) {
    return pixels[(b * width) + a];
}

unsigned int PPM::getWidth() {
    return width;
}

unsigned int PPM::getHeight() {
    return height;
}

void PPM::open(const std::string& path){ 
	std::ifstream fp(path.c_str());
	if (fp.fail()) {
		return; //failed
	}
	//read MajNum
	std::string mg_num, width_str, height_str,  range_str;
	fp >> mg_num;

	if (mg_num != "P3") {
		fp.close();
		return; //file is not ASCII PPM
	}

	fp >> width_str >> height_str >> range_str;
	width = atoi(width_str.c_str()); //takes tring and convert to int
	height = atoi(height_str.c_str());

	//kill vector
	pixels.clear();

	//read vals into vector 
	RGB tmp;
	std::string _R, _G, _B;
	for (unsigned int i = 0; i < width * height; i++) {
		fp >> _R >> _G >> _B;
		tmp.R = atoi(_R.c_str());
		tmp.G = atoi(_G.c_str());
		tmp.B = atoi(_B.c_str());

		pixels.push_back(tmp);
	}
	fp.close();
}