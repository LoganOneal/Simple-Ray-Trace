#include <iostream>
#include <string>
#include <vector> 
#include <fstream>

//Declare RBG constructor
struct RGB {
	RGB() : R(0), G(0), B(0) {};
	unsigned char R, G, B;
};

//Declare PPM Class
class PPM {
    public:
        PPM();
        void open(const std::string&);
        RGB& get(unsigned int, unsigned int);
        unsigned int getWidth();
        unsigned int getHeight();

    private:
        unsigned int width, height;
        std::vector<RGB> pixels;
};

void PPM::open(const std::string& path){ 
	//test out
	std::cout << path.c_str() << "the c str thing";
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



PPM::PPM() {
		width = 0;
		height = 0;
	}
	
int main() {
	PPM img;
	img.open("test.ppm");

	unsigned int size = img.getWidth() * img.getHeight();
	for (unsigned int b = 0; b < img.getHeight(); b++) {
		for (unsigned int a = 0; a < img.getWidth(); a++) {
			RGB& ref_colour = img.get(a, b);
			std::cout << "RGB {" << (int)ref_colour.R << ", " << (int)ref_colour.G << ", " << (int)ref_colour.B << "}" << std::endl;		
		}
	}
	return 0;
}