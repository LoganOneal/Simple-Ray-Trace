#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include "RGB.h"
#include "PPM.h"


	
	PPM::PPM() {
		int width = 0;
		int height = 0;
	};

int main() {

	PPM img{};
	img.open("6colour_ppma.ppm");

	unsigned int size = img.getWidth() * img.getHeight();
	for (unsigned int b = 0; b < img.getHeight(); b++) {
		for (unsigned int a = 0; a < img.getWidth(); a++) {
			RGB& ref_colour = img.get(a, b);
			std::cout << "RGB {" << (int)ref_colour.R << ", " << (int)ref_colour.G << ", " << (int)ref_colour.B << "}" << std::endl;		
		}
	}
	return 0;
}