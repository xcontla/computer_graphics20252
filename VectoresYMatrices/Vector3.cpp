#include "Vector3.h"
#include <cmath>

Vector3 Vector3::add(const Vector3& mv) {
    return Vector3( this->x + mv.x,  this->y + mv.y, fmin(mv.z + mv.z, 1.0f));
}

Vector3 Vector3::subtract(const Vector3& mv){
    return Vector3( this->x - mv.x,  this->y - mv.y, fmax(mv.z - mv.z, 0.0f));
}

Vector3 Vector3::porEscalar(float s){
    return Vector3( this->x * s,  this->y * s, this->z);
}

float Vector3::dot(const Vector3& mv){
    return this->x * mv.x +  this->y * mv.y;
}

float Vector3::length()
{

    return sqrtf( this->x * this->x + this->y * this->y );
}

Vector3 Vector3::normalize()
{
    return *this/this->length();
}

void Vector3::set(float x1, float y1, float z1) {
    this->x = x1;
    this->y = y1;
    this->z = z1;
}

void Vector3::divZ(){
     this->set(this->x / this->z,this->y / this->z,this->z/ this->z);
}

/**
 * 
 *  OPERADORES
 * 
 * ***/

Vector3& operator +(const Vector3 &v1, const Vector3 &v2)
{
    return  *(new Vector3( v1.x + v2.x,  v1.y + v2.y, fmin(v1.z +v2.z, 1.0f)));
}

Vector3& operator -(const Vector3 &v1, const Vector3 &v2)
{
    return  *(new Vector3( v1.x - v2.x,  v1.y - v2.y, abs(v1.z -v2.z)));
}

Vector3& operator *(const Vector3 &v1, float s)
{
    return  *(new Vector3( v1.x * s,  v1.y * s, v1.z));
}

Vector3& operator *(float s, const Vector3 &v1)
{
    return  *(new Vector3( v1.x * s,  v1.y * s, v1.z));
}

Vector3& operator /(const Vector3 &v1, float s)
{
    return  *(new Vector3( v1.x / s,  v1.y / s, v1.z));
}

std::ostream& operator <<(std::ostream &o, const Vector3 &v)
{
    o << "( "  << v.x << ", " << v.y << ", " << v.z << ")";
    return  o;
}