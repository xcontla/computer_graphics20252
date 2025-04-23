#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vector4.h"

class Matrix4 {
public:
    Matrix4()
    {
        a00 = 1.0f, a01 = 0.0f, a02 = 0.0f, a03 = 0.0f;
        a10 = 0.0f, a11 = 1.0f, a12 = 0.0f, a13 = 0.0f;
        a20 = 0.0f, a21 = 0.0f, a22 = 1.0f, a23 = 0.0f;
        a30 = 0.0f, a31 = 0.0f, a32 = 0.0f, a33 = 1.0f;

    }
    Matrix4(    float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33);

    Matrix4(const Matrix4& m);
     ~Matrix4(){}
     Matrix4 add(const Matrix4& m);
     Matrix4 subtract(const Matrix4& m);
     Matrix4 multiply(const Matrix4& m);
     Matrix4 multiplyScalar(float c);
     Vector4 multiplyVector(const Vector4& v) ;
     Matrix4 transpose() ;
     float determinant() ;
     void set(  float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33) ;
     void set(const Matrix4& m);

    void rotateX(float alfa);
    void rotateY(float beta);
    void rotateZ(float gamma);
    void rotate(float alfa, float beta, float gamma);
    void scale(float sx, float sy, float sz);
    void translate(float tx, float ty, float tz);

    Matrix4 lookAt(const Vector4& eye, const Vector4& center, const Vector4& up);
    Matrix4 perspective(float fov, float near, float far, float aspectRatio);

    float a00, a01, a02, a03;
    float a10, a11, a12, a13;
    float a20, a21, a22, a23;
    float a30, a31, a32, a33;

    friend Matrix4& operator +(const Matrix4 &m1, const Matrix4 &m2);
    friend Matrix4& operator -(const Matrix4 &m1, const Matrix4 &m2);
    friend Matrix4& operator *(const Matrix4 &m1, const Matrix4 &m2);
    friend Vector4& operator *(const Matrix4 &m, const Vector4 &v1);
    friend Matrix4& operator *(const Matrix4 &m, float c);
    friend Matrix4& operator *( float c, const Matrix4 &m);
    friend std::ostream& operator <<(std::ostream &o, const Matrix4 &m);

};

#endif // MATRIX4_H
