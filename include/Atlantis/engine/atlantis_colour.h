#ifndef ATLANTIS_COLOUR
#define ATLANTIS_COLOUR

#include <Atlantis/atlantis_common.h>

class colour {
    public:
        double r, g, b, a;
        colour(double R, double G, double B, double A){this->a = A;this->r = R;this->g = G;this->b = B;}
        colour(double R, double G, double B){this->r = R;this->g = G;this->b = B;}
        std::string to_string(){std::ostringstream oss; oss << "[" << r << ", " << g << ", " << b << "]"; return oss.str();}
        colour operator -(colour b) {return colour((this->r - b.r), (this->g - b.g), (this->b - b.b), (this->a - b.a));}
        colour operator +(colour b) {return colour((this->r + b.r), (this->g + b.g), (this->b + b.b), (this->a + b.a));}
        colour operator *(colour b) {return colour((this->r * b.r), (this->g * b.g), (this->b * b.b), (this->a * b.a));}
        colour operator /(colour b) {return colour((this->r / b.r), (this->g / b.g), (this->b / b.b), (this->a / b.a));}
};

#endif