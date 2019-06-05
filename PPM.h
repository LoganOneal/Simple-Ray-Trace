#ifndef PPM_H
#define PPM_H

#include <string>
#include <vector>
#include "RGB.h"


class PPM {
    private:
        unsigned int width;
        unsigned int height; 
        std::vector<RGB> pixels;
    public:
        PPM(int width, int height);
        void open(const std::string&);
        RGB& get(unsigned int, unsigned int);
        unsigned int getWidth();
        unsigned int getHeight();

};

#endif