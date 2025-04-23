#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>


class Vector3 {
public:

    Vector3(const float x1,const float y1,const float z1) : x(x1), y(y1), z(1.0f) {}
    ~Vector3(){}
    Vector3 add(const Vector3& v);
    Vector3 subtract(const Vector3& v);
    Vector3 porEscalar(float s);
    float length();
    float dot(const Vector3& v);
    
    Vector3 normalize();

    void set(float x, float y, float z) ;
    void divZ();

    friend Vector3& operator +(const Vector3 &v1, const Vector3 &v2);
    friend Vector3& operator -(const Vector3 &v1, const Vector3 &v2);
    friend Vector3& operator *(const Vector3 &v1, float s);
    friend Vector3& operator *(float s, const Vector3 &v1);
    friend Vector3& operator /(const Vector3 &v1, float s);
    friend std::ostream& operator <<(std::ostream &o, const Vector3 &v);


    float x, y, z;
};

#endif // VECTOR3_H
