#include "Vector4.h"
#include <cmath>

Vector4 Vector4::add(const Vector4& mv) {
    return Vector4( this->x + mv.x,  this->y + mv.y, this->z + mv.z, fmin(this->z + mv.z, 1.0f));
}

Vector4 Vector4::subtract(const Vector4& mv){
    return Vector4( this->x - mv.x,  this->y - mv.y, this->z - mv.z, abs( this->z - mv.z ));
}

Vector4 Vector4::porEscalar(float s){
    return Vector4( this->x * s,  this->y * s, this->z * s, this ->w);
}

float Vector4::dotxyz(const Vector4& mv){
    return this->x * mv.x +  this->y * mv.y + this->z * mv.z;
}

float Vector4::dot(const Vector4& mv){
    return this->x * mv.x +  this->y * mv.y + this->z * mv.z + this->w * mv.w;
}

Vector4 Vector4::cross(const Vector4& v)
{
    return Vector4(
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x,
        0.0
    );
}

float Vector4::length()
{
    return sqrtf(this->x * this->x +  this->y * this->y + this->z * this->z);
}

Vector4 Vector4::normalize()
{

    return *this/this->length();
}

void Vector4::set(float x1, float y1, float z1, float w1) {
    this->x = x1;
    this->y = y1;
    this->z = z1;
    this->w = w1;
}

void Vector4::divW(){
    this->set(this->x / this->w,this->y / this->w,this->z/ this->w,this->w / this->w);
}

/**
 * 
 *  OPERADORES
 * 
 * ***/

Vector4& operator +(const Vector4 &v1, const Vector4 &v2)
{
    return  *(new Vector4( v1.x + v2.x,  v1.y + v2.y, v1.z + v2.z, fmin(v1.z +v2.z, 1.0f)));
}

Vector4& operator -(const Vector4 &v1, const Vector4 &v2)
{
    return  *(new Vector4( v1.x - v2.x,  v1.y - v2.y, v1.z - v2.z, abs( v1.z - v2.z )));
}

Vector4& operator *(const Vector4 &v1, float s)
{
    return  *(new Vector4( v1.x * s,  v1.y * s, v1.z * s, v1.w));
}

Vector4& operator *(float s, const Vector4 &v1)
{
    return  *(new Vector4( v1.x * s,  v1.y * s, v1.z * s, v1.w));
}

Vector4& operator /(const Vector4 &v1, float s)
{
    return  *(new Vector4( v1.x / s,  v1.y / s, v1.z / s, v1.w));
}

std::ostream& operator <<(std::ostream &o, const Vector4 &v)
{
    o << "( "  << v.x << ", " << v.y << ", " << v.z << ", " << v.w <<")";
    return  o;
}