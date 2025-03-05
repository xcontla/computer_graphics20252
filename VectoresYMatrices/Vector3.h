#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
    virtual ~Vector3() = default;
    virtual Vector3 add(const Vector3& v) const = 0;
    virtual Vector3 subtract(const Vector3& v) const = 0;
    virtual float dot(const Vector3& v) const = 0;
    virtual Vector3 normalize() const = 0;
    virtual void set(float x, float y, float z) = 0;
protected:
    float x, y, z;
};

#endif // VECTOR3_H
