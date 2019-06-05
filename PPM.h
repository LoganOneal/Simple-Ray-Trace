#ifndef PPM_H
#define PPM_H

#include <iostream>
#include <vector>
#include "RGB.h"

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

#endif