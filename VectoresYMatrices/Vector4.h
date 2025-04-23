#ifndef VECTOR4_H
#define VECTOR4_H


#include <iostream>


class Vector4 {
public:

    Vector4(const float x1,const float y1,const float z1, const float w1) : x(x1), y(y1), z(z1), w(w1) {}
    ~Vector4(){}
    Vector4 add(const Vector4& v);
    Vector4 subtract(const Vector4& v);
    Vector4 porEscalar(float s);
    float dotxyz(const Vector4& mv);
    float dot(const Vector4& v);

    Vector4 cross(const Vector4& v);
    float length();
    Vector4 normalize();
    void set(float x, float y, float z, float w) ;
    void divW();


    friend Vector4& operator +(const Vector4 &v1, const Vector4 &v2);

    friend Vector4& operator -(const Vector4 &v1, const Vector4 &v2);

    friend Vector4& operator *(const Vector4 &v1, float s);

    friend Vector4& operator *(float s, const Vector4 &v1);

    friend Vector4& operator /(const Vector4 &v1, float s);

    friend std::ostream& operator <<(std::ostream &o, const Vector4 &v);


    float x, y, z, w;
};


#endif // VECTOR4_H
