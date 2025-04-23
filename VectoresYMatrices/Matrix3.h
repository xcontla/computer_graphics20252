#ifndef MATRIX3_H
#define MATRIX3_H

#include "Vector3.h"

class Matrix3 {
public:
    Matrix3()
    {
        a00 = 1.0f, a01 = 0.0f, a02 = 0.0f;
        a10 = 0.0f, a11 = 1.0f, a12 = 0.0f;
        a20 = 0.0f, a21 = 0.0f, a22 = 1.0f;

    }
    Matrix3(float m00, float m01, float m02,
            float m10, float m11, float m12,
            float m20, float m21, float m22);
    Matrix3(const Matrix3& m);
     ~Matrix3(){}
     Matrix3 add(const Matrix3& m);
     Matrix3 subtract(const Matrix3& m);
     Matrix3 multiply(const Matrix3& m);
     Matrix3 multiplyScalar(float c);
     Vector3 multiplyVector(const Vector3& v) ;
     Matrix3 transpose() ;
     float determinant() ;
     void set(  float m00, float m01, float m02,
                float m10, float m11, float m12,
                float m20, float m21, float m22) ;
     void set(const Matrix3& m);

    void rotate(float alfa);
    void scale(float sx, float sy);
    void translate(float tx, float ty);


    float a00, a01, a02;
    float a10, a11, a12;
    float a20, a21, a22;

    friend Matrix3& operator +(const Matrix3 &m1, const Matrix3 &m2);
    friend Matrix3& operator -(const Matrix3 &m1, const Matrix3 &m2);
    friend Matrix3& operator *(const Matrix3 &m1, const Matrix3 &m2);
    friend Vector3& operator *(const Matrix3 &m, const Vector3 &v1);
    friend Matrix3& operator *(const Matrix3 &m, float c);
    friend Matrix3& operator *( float c, const Matrix3 &m);
    friend std::ostream& operator <<(std::ostream &o, const Matrix3 &m);

};

#endif // MATRIX3_H
