#include "Matrix3.h"
#include <cmath>


Matrix3::Matrix3(float m00, float m01, float m02,
               float m10, float m11, float m12,
               float m20, float m21, float m22) 
{
    a00 = m00, a01 = m01, a02 = m02;
    a10 = m10, a11 = m11, a12 = m12;
    a20 = m20, a21 = m21, a22 = m22;
}

Matrix3::Matrix3(const Matrix3& m) 
{
    a00 = m.a00, a01 = m.a01, a02 = m.a02;
    a10 = m.a10, a11 = m.a11, a12 = m.a12;
    a20 = m.a20, a21 = m.a21, a22 = m.a22;
}

Matrix3 Matrix3::add(const Matrix3& m)
{
    return Matrix3( this->a00 + m.a00, this->a01 + m.a01, this->a02 + m.a02,
                    this->a10 + m.a10, this->a11 + m.a11, this->a12 + m.a12,
                    this->a20 + m.a20, this->a21 + m.a21, this->a22 + m.a22

    );
}
Matrix3 Matrix3::subtract(const Matrix3& m)
{
    return Matrix3( this->a00 - m.a00, this->a01 - m.a01, this->a02 - m.a02,
        this->a10 - m.a10, this->a11 - m.a11, this->a12 - m.a12,
        this->a20 - m.a20, this->a21 - m.a21, this->a22 - m.a22

);
}

Vector3 Matrix3::multiplyVector(const Vector3& v)
{
    return Vector3(
        (Vector3(this->a00, this->a01, this->a02)).dot(v),
        (Vector3(this->a10, this->a11, this->a12)).dot(v),
        (Vector3(this->a20, this->a21, this->a22)).dot(v)
    );
}

Matrix3 Matrix3::multiply(const Matrix3& m)
{
    return Matrix3(
        Vector3(this->a00, this->a01, this->a02).dot(Vector3(m.a00,m.a10,m.a20)), //a00
        Vector3(this->a00, this->a01, this->a02).dot(Vector3(m.a01,m.a11,m.a21)), //a01
        Vector3(this->a00, this->a01, this->a02).dot(Vector3(m.a02,m.a12,m.a22)), //a02

        Vector3(this->a10, this->a11, this->a12).dot(Vector3(m.a00,m.a10,m.a20)), //a10
        Vector3(this->a10, this->a11, this->a12).dot(Vector3(m.a01,m.a11,m.a21)), //a11
        Vector3(this->a10, this->a11, this->a12).dot(Vector3(m.a02,m.a12,m.a22)), //a12

        Vector3(this->a20, this->a21, this->a22).dot(Vector3(m.a00,m.a10,m.a20)), //a20
        Vector3(this->a20, this->a21, this->a22).dot(Vector3(m.a01,m.a11,m.a21)), //a21
        Vector3(this->a20, this->a21, this->a22).dot(Vector3(m.a02,m.a12,m.a22)) //a22


    );
}


Matrix3 Matrix3::multiplyScalar(float c)
{
    return Matrix3( this->a00 * c, this->a01 * c, this->a02  * c,
                    this->a10 * c, this->a11 * c, this->a12  * c,
                    this->a20 * c, this->a21 * c, this->a22  * c

    );
}

Matrix3 Matrix3::transpose()
{
    return Matrix3( this->a00, this->a10, this->a20,
                    this->a01 , this->a11, this->a21,
                    this->a02 , this->a12, this->a22

    );   
}
float Matrix3::determinant()
{
    /*
        a00  a10  a20  a00  a10,
        a01  a11  a21  a01  a11, 
        a02  a12  a22  a02  a12,
    */

    return  this->a00 * this->a11 * this->a22 
        +   this->a10 * this->a21 * this->a02 
        +   this->a20 * this->a01 * this->a12 
        -   this->a20 * this->a11 * this->a02 
        -   this->a00 * this->a21 * this->a12 
        -   this->a10 * this->a01 * this->a22 ;
        
}



void Matrix3::set(  float m00, float m01, float m02,
                    float m10, float m11, float m12,
                    float m20, float m21, float m22)
{

        this->a00 = m00; this->a01 = m01; this->a02 = m02;
        this->a10 = m10; this->a11 = m11; this->a12 = m12;
        this->a20 = m20; this->a21 = m21; this->a22 = m22;

     
}

void Matrix3::set(const Matrix3& m)
{

this->a00 = m.a00; this->a01 = m.a01; this->a02 = m.a02;
this->a10 = m.a10; this->a11 = m.a11; this->a12 = m.a12;
this->a20 = m.a20; this->a21 = m.a21; this->a22 = m.a22;


}

void Matrix3::rotate(float alfa)
{
    this->a00 = cosf(alfa); this->a01 = -sinf(alfa);    this->a02 = 0.0f;
    this->a10 = sinf(alfa); this->a11 = cosf(alfa);     this->a12 = 0.0f;
    this->a20 = 0.0f;       this->a21 = 0.0f;           this->a22 = 1.0f;
    
}

void Matrix3::scale(float sx, float sy)
{
    this->a00 = sx;     this->a01 = 0.0f;   this->a02 = 0.0f;
    this->a10 = 0.0f;   this->a11 = sy;     this->a12 = 0.0f;
    this->a20 = 0.0f;   this->a21 = 0.0f;   this->a22 = 1.0f;
    
}

void Matrix3::translate(float tx, float ty)
{
    this->a00 = 1.0f; this->a01 = 0.0f; this->a02 = tx;
    this->a10 = 0.0f; this->a11 = 1.0f; this->a12 = ty;
    this->a20 = 0.0f; this->a21 = 0.0f; this->a22 = 1.0f;
    
}


Matrix3& operator +(const Matrix3 &m1, const Matrix3 &m2)
{
    return *(new Matrix3( 
        m1.a00 + m2.a00, m1.a01 + m2.a01, m1.a02 + m2.a02,
        m1.a10 + m2.a10, m1.a11 + m2.a11, m1.a12 + m2.a12,
        m1.a20 + m2.a20, m1.a21 + m2.a21, m1.a22 + m2.a22));

};

Matrix3& operator -(const Matrix3 &m1, const Matrix3 &m2)
{
    return *(new Matrix3( 
        m1.a00 - m2.a00, m1.a01 - m2.a01, m1.a02 - m2.a02,
        m1.a10 - m2.a10, m1.a11 - m2.a11, m1.a12 - m2.a12,
        m1.a20 - m2.a20, m1.a21 - m2.a21, m1.a22 - m2.a22));
}

Matrix3& operator *(const Matrix3 &m1, const Matrix3 &m2)
{
    return *(new Matrix3(
        Vector3(m1.a00, m1.a01, m1.a02).dot(Vector3(m2.a00,m2.a10,m2.a20)), //a00
        Vector3(m1.a00, m1.a01, m1.a02).dot(Vector3(m2.a01,m2.a11,m2.a21)), //a01
        Vector3(m1.a00, m1.a01, m1.a02).dot(Vector3(m2.a02,m2.a12,m2.a22)), //a02
        Vector3(m1.a10, m1.a11, m1.a12).dot(Vector3(m2.a00,m2.a10,m2.a20)), //a10
        Vector3(m1.a10, m1.a11, m1.a12).dot(Vector3(m2.a01,m2.a11,m2.a21)), //a11
        Vector3(m1.a10, m1.a11, m1.a12).dot(Vector3(m2.a02,m2.a12,m2.a22)), //a12
        Vector3(m1.a20, m1.a21, m1.a22).dot(Vector3(m2.a00,m2.a10,m2.a20)), //a20
        Vector3(m1.a20, m1.a21, m1.a22).dot(Vector3(m2.a01,m2.a11,m2.a21)), //a21
        Vector3(m1.a20, m1.a21, m1.a22).dot(Vector3(m2.a02,m2.a12,m2.a22)) )//a22


    );
}

Vector3& operator *(const Matrix3 &m, const Vector3 &v)
{
    return *(new Vector3(
        (Vector3(m.a00, m.a01, m.a02)).dot(v),
        (Vector3(m.a10, m.a11, m.a12)).dot(v),
        (Vector3(m.a20, m.a21, m.a22)).dot(v))
    );

}

Matrix3& operator *(const Matrix3 &m, float c)
{
    return *(  new Matrix3( m.a00 * c, m.a01 * c, m.a02  * c,
        m.a10 * c, m.a11 * c, m.a12  * c,
        m.a20 * c, m.a21 * c, m.a22  * c)

);
}

Matrix3& operator *( float c, const Matrix3 &m)
{
    return *(new  Matrix3( m.a00 * c, m.a01 * c, m.a02  * c,
        m.a10 * c, m.a11 * c, m.a12  * c,
        m.a20 * c, m.a21 * c, m.a22  * c)

);
}

std::ostream& operator <<(std::ostream &o, const Matrix3 &m)
{
    o << "[ "  << m.a00 << " " << m.a01 << " " << m.a02 << "" << std::endl;
    o << "  "  << m.a10 << " " << m.a11 << " " << m.a12 << "" << std::endl;
    o << "  "  << m.a20 << " " << m.a21 << " " << m.a22 << "]";
    return  o;
}