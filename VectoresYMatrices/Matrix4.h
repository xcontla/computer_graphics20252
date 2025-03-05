#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vector3.h"
#include "Vector4.h"

class Matrix4 {
public:
    virtual ~Matrix4() = default;
    virtual Matrix4 add(const Matrix4& m) const = 0;
    virtual Matrix4 subtract(const Matrix4& m) const = 0;
    virtual Matrix4 multiply(const Matrix4& m) const = 0;
    virtual Matrix4 multiplyScalar(float c) const = 0;
    virtual Vector4 multiplyVector(const Vector4& v) const = 0;
    virtual Matrix4 invert() const = 0;
    virtual Matrix4 transpose() const = 0;
    virtual float determinant() const = 0;
    virtual void set(float a00, float a01, float a02, float a03,
                     float a10, float a11, float a12, float a13,
                     float a20, float a21, float a22, float a23,
                     float a30, float a31, float a32, float a33) = 0;
protected:
    float a00, a01, a02, a03;
    float a10, a11, a12, a13;
    float a20, a21, a22, a23;
    float a30, a31, a32, a33;
};

#endif // MATRIX4_H
