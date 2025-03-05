#ifndef MATRIX3_H
#define MATRIX3_H

#include "Vector3.h"

class Matrix3 {
public:
    virtual ~Matrix3() = default;
    virtual Matrix3 add(const Matrix3& m) const = 0;
    virtual Matrix3 subtract(const Matrix3& m) const = 0;
    virtual Matrix3 multiply(const Matrix3& m) const = 0;
    virtual Matrix3 multiplyScalar(float c) const = 0;
    virtual Vector3 multiplyVector(const Vector3& v) const = 0;
    virtual Matrix3 invert() const = 0;
    virtual Matrix3 transpose() const = 0;
    virtual float determinant() const = 0;
    virtual void set(float a00, float a01, float a02,
                     float a10, float a11, float a12,
                     float a20, float a21, float a22) = 0;
protected:
    float a00, a01, a02;
    float a10, a11, a12;
    float a20, a21, a22;
};

#endif // MATRIX3_H
