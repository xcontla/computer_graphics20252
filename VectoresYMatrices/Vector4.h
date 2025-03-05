#ifndef VECTOR4_H
#define VECTOR4_H

class Vector4 {
public:
    virtual ~Vector4() = default;
    virtual Vector4 add(const Vector4& v) const = 0;
    virtual Vector4 subtract(const Vector4& v) const = 0;
    virtual float dot(const Vector4& v) const = 0;
    virtual Vector4 normalize() const = 0;
    virtual void set(float x, float y, float z, float w) = 0;
protected:
    float x, y, z, w;
};

#endif // VECTOR4_H
