#ifndef ATLANTIS_VEC
#define ATLANTIS_VEC

#include <Atlantis/atlantis_common.h>

namespace math {

    template<typename T>
    class vec4 {
        public:
            T x, y, z, w;
            vec4(T x, T y, T z, T w): x(x), y(y), z(z), w(w){}
            vec4(): x(0), y(0), z(0), w(0){}

            vec4 operator +(T b) {return vec4(this->x + b, this->y + b, this->z + b, this->w + b);}
            vec4 operator -(T b) {return vec4(this->x - b, this->y - b, this->z - b, this->w - b);}
            vec4 operator /(T b) {return vec4(this->x / b, this->y / b, this->z / b, this->w / b);}
            vec4 operator *(T b) {return vec4(this->x * b, this->y * b, this->z * b, this->w * b);}

            vec4 operator +(vec4 b) {return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);}
            vec4 operator -(vec4 b) {return vec4(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);}

            T operator *(vec4 b) {return T((this->x * b.x) + (this->y * b.y) + (this->z * b.z) + (this->w * b.w));}
    };

    template<typename T>
    class vec3 {
        public:
            T x, y, z;
            vec3(T x, T y, T z): x(x), y(y), z(z){}
            vec3(): x(0), y(0), z(0){}

            vec3 operator +(T b) {return vec3(this->x + b, this->y + b, this->z + b);}
            vec3 operator -(T b) {return vec3(this->x - b, this->y - b, this->z - b);}
            vec3 operator /(T b) {return vec3(this->x / b, this->y / b, this->z / b);}
            vec3 operator *(T b) {return vec3(this->x * b, this->y * b, this->z * b);}

            vec3 operator +(vec3 b) {return vec3(this->x + b.x, this->y + b.y, this->z + b.z);}
            vec3 operator -(vec3 b) {return vec3(this->x - b.x, this->y - b.y, this->z - b.z);}

            T operator *(vec3 b) {return T((this->x * b.x) + (this->y * b.y) + (this->z * b.z));}
    };


    template<typename T>
    class vec2 {
        public:
            T x, y;
            vec2(T x, T y): x(x), y(y){}
            vec2(): x(0), y(0){}

            vec2 operator +(T b) {return vec2(this->x + b, this->y + b);}
            vec2 operator -(T b) {return vec2(this->x - b, this->y - b);}
            vec2 operator /(T b) {return vec2(this->x / b, this->y / b);}
            vec2 operator *(T b) {return vec2(this->x * b, this->y * b);}

            vec2 operator +(vec2 b) {return vec2(this->x + b.x, this->y + b.y);}
            vec2 operator -(vec2 b) {return vec2(this->x - b.x, this->y - b.y);}

            T operator *(vec2 b) {return T((this->x * b.x) + (this->y * b.y));}
    };

    typedef vec4<int> vec4i;
    typedef vec4<float> vec4f;
    typedef vec4<double> vec4d;
    typedef vec3<int> vec3i;
    typedef vec3<float> vec3f;
    typedef vec3<double> vec3d;
    typedef vec2<int> vec2i;
    typedef vec2<float> vec2f;
    typedef vec2<double> vec2d;
}



#endif