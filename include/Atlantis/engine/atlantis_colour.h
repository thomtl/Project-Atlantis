#ifndef ATLANTIS_COLOUR
#define ATLANTIS_COLOUR

#include <Atlantis/atlantis_common.h>

class atlantis_colour {
    public:
        double r, g, b, a;
        atlantis_colour(double R, double G, double B, double A){this->a = A;this->r = R;this->g = G;this->b = B;}
        atlantis_colour(double R, double G, double B){this->r = R;this->g = G;this->b = B;this->a = 1;}
        std::string to_string(){std::ostringstream oss; oss << "[" << r << ", " << g << ", " << b << "]"; return oss.str();}
        atlantis_colour operator -(atlantis_colour b) {return atlantis_colour((this->r - b.r), (this->g - b.g), (this->b - b.b), (this->a - b.a));}
        atlantis_colour operator +(atlantis_colour b) {return atlantis_colour((this->r + b.r), (this->g + b.g), (this->b + b.b), (this->a + b.a));}
        atlantis_colour operator *(atlantis_colour b) {return atlantis_colour((this->r * b.r), (this->g * b.g), (this->b * b.b), (this->a * b.a));}
        atlantis_colour operator /(atlantis_colour b) {return atlantis_colour((this->r / b.r), (this->g / b.g), (this->b / b.b), (this->a / b.a));}
};

#endif