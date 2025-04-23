#include "Matrix4.h"
#include <cmath>

#define PI 3.141592



Matrix4::Matrix4(float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33) 
{
    a00 = m00, a01 = m01, a02 = m02, a03 = m03;
    a10 = m10, a11 = m11, a12 = m12, a13 = m13;
    a20 = m20, a21 = m21, a22 = m22, a23 = m23;
    a30 = m30, a31 = m32, a32 = m32, a33 = m33;
}

Matrix4::Matrix4(const Matrix4& m) 
{
    a00 = m.a00, a01 = m.a01, a02 = m.a02, a03 = m.a03;
    a10 = m.a10, a11 = m.a11, a12 = m.a12, a13 = m.a13;
    a20 = m.a20, a21 = m.a21, a22 = m.a22, a23 = m.a23;
    a30 = m.a30, a31 = m.a31, a32 = m.a32, a33 = m.a33;
}

Matrix4 Matrix4::add(const Matrix4& m)
{
    return Matrix4( this->a00 + m.a00, this->a01 + m.a01, this->a02 + m.a02, this->a03 + m.a03,
                    this->a10 + m.a10, this->a11 + m.a11, this->a12 + m.a12, this->a13 + m.a13,
                    this->a20 + m.a20, this->a21 + m.a21, this->a22 + m.a22, this->a23 + m.a23,
                    this->a30 + m.a30, this->a31 + m.a31, this->a32 + m.a32, this->a33 + m.a33

    );
}
Matrix4 Matrix4::subtract(const Matrix4& m)
{
    return Matrix4( 
        this->a00 - m.a00, this->a01 - m.a01, this->a02 - m.a02, this->a03 - m.a03,
        this->a10 - m.a10, this->a11 - m.a11, this->a12 - m.a12, this->a13 - m.a13,
        this->a20 - m.a20, this->a21 - m.a21, this->a22 - m.a22, this->a23 - m.a23,
        this->a20 - m.a20, this->a21 - m.a21, this->a22 - m.a22, this->a33 - m.a33

);
}

Vector4 Matrix4::multiplyVector(const Vector4& v)
{
    return Vector4(
        (Vector4(this->a00, this->a01, this->a02, this->a03)).dot(v),
        (Vector4(this->a10, this->a11, this->a12, this->a13)).dot(v),
        (Vector4(this->a20, this->a21, this->a22, this->a23)).dot(v),
        (Vector4(this->a30, this->a31, this->a32, this->a33)).dot(v)
    );
}

Matrix4 Matrix4::multiply(const Matrix4& m)
{
    return Matrix4(
        Vector4(this->a00, this->a01, this->a02, this->a03).dot(Vector4(m.a00,m.a10,m.a20,m.a30)), //a00
        Vector4(this->a00, this->a01, this->a02, this->a03).dot(Vector4(m.a01,m.a11,m.a21,m.a31)), //a01
        Vector4(this->a00, this->a01, this->a02, this->a03).dot(Vector4(m.a02,m.a12,m.a22,m.a32)), //a02
        Vector4(this->a00, this->a01, this->a02, this->a03).dot(Vector4(m.a03,m.a13,m.a23,m.a33)), //a03

        Vector4(this->a10, this->a11, this->a12, this->a13).dot(Vector4(m.a00,m.a10,m.a20,m.a30)), //a10
        Vector4(this->a10, this->a11, this->a12, this->a13).dot(Vector4(m.a01,m.a11,m.a21,m.a31)), //a11
        Vector4(this->a10, this->a11, this->a12, this->a13).dot(Vector4(m.a02,m.a12,m.a22,m.a32)), //a12
        Vector4(this->a10, this->a11, this->a12, this->a13).dot(Vector4(m.a03,m.a13,m.a23,m.a33)), //a13

        Vector4(this->a20, this->a21, this->a22, this->a23).dot(Vector4(m.a00,m.a10,m.a20,m.a30)), //a20
        Vector4(this->a20, this->a21, this->a22, this->a23).dot(Vector4(m.a01,m.a11,m.a21,m.a31)), //a21
        Vector4(this->a20, this->a21, this->a22, this->a23).dot(Vector4(m.a02,m.a12,m.a22,m.a32)), //a22
        Vector4(this->a20, this->a21, this->a22, this->a23).dot(Vector4(m.a03,m.a13,m.a23,m.a33)), //a23

        Vector4(this->a30, this->a31, this->a32, this->a33).dot(Vector4(m.a00,m.a10,m.a20,m.a30)), //a20
        Vector4(this->a30, this->a31, this->a32, this->a33).dot(Vector4(m.a01,m.a11,m.a21,m.a31)), //a21
        Vector4(this->a30, this->a31, this->a32, this->a33).dot(Vector4(m.a02,m.a12,m.a22,m.a32)), //a22
        Vector4(this->a30, this->a31, this->a32, this->a33).dot(Vector4(m.a03,m.a13,m.a23,m.a33))  //a23


    );
}


Matrix4 Matrix4::multiplyScalar(float c)
{
    return Matrix4( this->a00 * c, this->a01 * c, this->a02  * c, this->a03  * c,
                    this->a10 * c, this->a11 * c, this->a12  * c, this->a13  * c,
                    this->a20 * c, this->a21 * c, this->a22  * c, this->a23  * c,
                    this->a30 * c, this->a31 * c, this->a32  * c, this->a33  * c

    );
}

Matrix4 Matrix4::transpose()
{
    return Matrix4( this->a00, this->a10, this->a20, this->a30,
                    this->a01 , this->a11, this->a21, this->a31,
                    this->a02 , this->a12, this->a22, this->a32,
                    this->a03 , this->a13, this->a23, this->a33

    );   
}
float Matrix4::determinant()
{
    return a00 * (a11 * (a22 * a33 - a23 * a32) - a12 * (a21 * a33 - a23 * a31) + a13 * (a21 * a32 - a22 * a31))
         - a01 * (a10 * (a22 * a33 - a23 * a32) - a12 * (a20 * a33 - a23 * a30) + a13 * (a20 * a32 - a22 * a30))
         + a02 * (a10 * (a21 * a33 - a23 * a31) - a11 * (a20 * a33 - a23 * a30) + a13 * (a20 * a31 - a21 * a30))
         - a03 * (a10 * (a21 * a32 - a22 * a31) - a11 * (a20 * a32 - a22 * a30) + a12 * (a20 * a31 - a21 * a30));

        
}



void Matrix4::set(  
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{

        this->a00 = m00; this->a01 = m01; this->a02 = m02; this->a03 = m03;
        this->a10 = m10; this->a11 = m11; this->a12 = m12; this->a13 = m13;
        this->a20 = m20; this->a21 = m21; this->a22 = m22; this->a23 = m23;
        this->a30 = m30; this->a31 = m31; this->a32 = m32; this->a33 = m33;

     
}

void Matrix4::set(const Matrix4& m) 
{
    a00 = m.a00; a01 = m.a01; a02 = m.a02; a03 = m.a03;
    a10 = m.a10; a11 = m.a11; a12 = m.a12; a13 = m.a13;
    a20 = m.a20; a21 = m.a21; a22 = m.a22; a23 = m.a23;
    a30 = m.a30; a31 = m.a31; a32 = m.a32; a33 = m.a33;
}

void Matrix4::rotateX(float alfa) 
{
    alfa = alfa * PI * 0.0055555f;
    float c = cosf(alfa);
    float s = sinf(alfa);
    this->set(1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, c, -s, 0.0f,
            0.0f, s, c, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix4::rotateY(float beta) 
{
    beta = beta * PI * 0.005555f;
    float c = cosf(beta);
    float s = sinf(beta);
    this->set(c, 0.0f, s, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            -s, 0.0f, c, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix4::rotateZ(float gamma) 
{
    gamma = gamma * PI * 0.005555f;
    float c = cosf(gamma);
    float s = sinf(gamma);
    this->set(c, -s, 0.0f, 0.0f,
            s, c, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix4::rotate(float alfa, float beta, float gamma) 
{
    rotateX(alfa);
    rotateY(beta);
    rotateZ(gamma);
}

void Matrix4::scale(float sx, float sy, float sz) 
{
    this->set(sx, 0.0f, 0.0f,  0.0f,
              0.0f, sy,  0.0f, 0.0f,
              0.0f, 0.0f, sz,  0.0f,
              0.0f, 0.0f, 0.0f, 1.0f);
                    
}

void Matrix4::translate(float tx, float ty, float tz) 
{
    this->set(1.0f, 0.0f, 0.0f, tx,
              0.0f, 1.0f, 0.0f, ty,
              0.0f, 0.0f, 1.0f, tz,
              0.0f, 0.0f, 0.0f, 1.0f);
}


Matrix4 Matrix4::lookAt(const Vector4& eye, const Vector4& center, const Vector4& up) {
    Vector4 forward = eye - center;
    forward.normalize();
    Vector4 right = forward.cross(up);
    right.normalize();
    Vector4 upNormalized = right.cross(forward);
    upNormalized.normalize();
    Matrix4 viewMatrix;

    std::cout << "u: " << right << std::endl;
    std::cout << "v: " << upNormalized << std::endl;
    std::cout << "w: " << forward << std::endl;
    std::cout << "-w: " << forward * -1.0f << std::endl;

    viewMatrix.set(right.x, upNormalized.x, -forward.x, -right.dot(eye),
                   right.y, upNormalized.y, -forward.y, -upNormalized.dot(eye),
                   right.z, upNormalized.z, -forward.z, -forward.dot(eye),
                   0.0f, 0.0f, 0.0f, 1.0f);
                   // -right.dot(eye), -upNormalized.dot(eye), -    forward.dot(eye), 1.0f);
    return viewMatrix;
}

Matrix4 Matrix4::perspective(float fov, float near, float far, float aspectRatio) {
    float tanHalfFov = tanf((fov  * 0.5) * PI * 0.00555f);
    
    Matrix4 proj;
    proj.set(1.0f / (tanHalfFov * aspectRatio), 0.0f, 0.0f, 0.0f,
             0.0f, 1.0f / tanHalfFov, 0.0f, 0.0f,
             0.0f, 0.0f, -(far + near) / (far - near), -(2 * far * near) / (far - near),
             0.0f, 0.0f, -1.0f, 0.0f);
    return proj;
}



Matrix4& operator +(const Matrix4 &m1, const Matrix4 &m2)
{
    return *(new Matrix4( 
        m1.a00 + m2.a00, m1.a01 + m2.a01, m1.a02 + m2.a02, m1.a03 + m2.a03,
        m1.a10 + m2.a10, m1.a11 + m2.a11, m1.a12 + m2.a12, m1.a13 + m2.a13,
        m1.a20 + m2.a20, m1.a21 + m2.a21, m1.a22 + m2.a22, m1.a23 + m2.a23,
        m1.a30 + m2.a30, m1.a31 + m2.a31, m1.a32 + m2.a32, m1.a33 + m2.a33));

};

Matrix4& operator -(const Matrix4 &m1, const Matrix4 &m2)
{
    return *(new Matrix4( 
        m1.a00 - m2.a00, m1.a01 - m2.a01, m1.a02 - m2.a02, m1.a03 - m2.a03,
        m1.a10 - m2.a10, m1.a11 - m2.a11, m1.a12 - m2.a12, m1.a13 - m2.a13,
        m1.a20 - m2.a20, m1.a21 - m2.a21, m1.a22 - m2.a22, m1.a23 - m2.a23,
        m1.a30 - m2.a30, m1.a31 - m2.a31, m1.a32 - m2.a32, m1.a33 - m2.a33));
}

Matrix4& operator *(const Matrix4 &m1, const Matrix4 &m2)
{

    return *(new Matrix4(
        Vector4(m1.a00, m1.a01, m1.a02, m1.a03).dot(Vector4(m2.a00,m2.a10,m2.a20,m2.a30)), //a00
        Vector4(m1.a00, m1.a01, m1.a02, m1.a03).dot(Vector4(m2.a01,m2.a11,m2.a21,m2.a31)), //a01
        Vector4(m1.a00, m1.a01, m1.a02, m1.a03).dot(Vector4(m2.a02,m2.a12,m2.a22,m2.a32)), //a02
        Vector4(m1.a00, m1.a01, m1.a02, m1.a03).dot(Vector4(m2.a03,m2.a13,m2.a23,m2.a33)), //a03

        Vector4(m1.a10, m1.a11, m1.a12, m1.a13).dot(Vector4(m2.a00,m2.a10,m2.a20,m2.a30)), //a10
        Vector4(m1.a10, m1.a11, m1.a12, m1.a13).dot(Vector4(m2.a01,m2.a11,m2.a21,m2.a31)), //a11
        Vector4(m1.a10, m1.a11, m1.a12, m1.a13).dot(Vector4(m2.a02,m2.a12,m2.a22,m2.a32)), //a12
        Vector4(m1.a10, m1.a11, m1.a12, m1.a13).dot(Vector4(m2.a03,m2.a13,m2.a23,m2.a33)), //a13

        Vector4(m1.a20, m1.a21, m1.a22, m1.a23).dot(Vector4(m2.a00,m2.a10,m2.a20,m2.a30)), //a20
        Vector4(m1.a20, m1.a21, m1.a22, m1.a23).dot(Vector4(m2.a01,m2.a11,m2.a21,m2.a31)), //a21
        Vector4(m1.a20, m1.a21, m1.a22, m1.a23).dot(Vector4(m2.a02,m2.a12,m2.a22,m2.a32)), //a22
        Vector4(m1.a20, m1.a21, m1.a22, m1.a23).dot(Vector4(m2.a03,m2.a13,m2.a23,m2.a33)), //a23

        Vector4(m1.a30, m1.a31, m1.a32, m1.a33).dot(Vector4(m2.a00,m2.a10,m2.a20,m2.a30)), //a30
        Vector4(m1.a30, m1.a31, m1.a32, m1.a33).dot(Vector4(m2.a01,m2.a11,m2.a21,m2.a31)), //a31
        Vector4(m1.a30, m1.a31, m1.a32, m1.a33).dot(Vector4(m2.a02,m2.a12,m2.a22,m2.a32)), //a32
        Vector4(m1.a30, m1.a31, m1.a32, m1.a33).dot(Vector4(m2.a03,m2.a13,m2.a23,m2.a33)) //a33
    
    )


    );
}

Vector4& operator *(const Matrix4 &m, const Vector4 &v)
{
    return *(new Vector4(
        (Vector4(m.a00, m.a01, m.a02, m.a03)).dot(v),
        (Vector4(m.a10, m.a11, m.a12, m.a13)).dot(v),
        (Vector4(m.a20, m.a21, m.a22, m.a23)).dot(v),
        (Vector4(m.a30, m.a31, m.a32, m.a33)).dot(v))
    );

}

Matrix4& operator *(const Matrix4 &m, float c)
{
    return *(  
        new Matrix4( 
        m.a00 * c, m.a01 * c, m.a02  * c, m.a03  * c,
        m.a10 * c, m.a11 * c, m.a12  * c, m.a13  * c,
        m.a20 * c, m.a21 * c, m.a22  * c, m.a23  * c,
        m.a30 * c, m.a31 * c, m.a32  * c, m.a33  * c)

);
}

Matrix4& operator *( float c, const Matrix4 &m)
{
    return *( 
        new Matrix4( 
        m.a00 * c, m.a01 * c, m.a02  * c, m.a03  * c,
        m.a10 * c, m.a11 * c, m.a12  * c, m.a13  * c,
        m.a20 * c, m.a21 * c, m.a22  * c, m.a23  * c,
        m.a30 * c, m.a31 * c, m.a32  * c, m.a33  * c)

    );
}

std::ostream& operator <<(std::ostream &o, const Matrix4 &m) 
{
    o << "[" << m.a00 << " " << m.a01 << " " << m.a02 << " " << m.a03 << " \n"
      << " " << m.a10 << " " << m.a11 << " " << m.a12 << " " << m.a13 << " \n"
      << " " << m.a20 << " " << m.a21 << " " << m.a22 << " " << m.a23 << " \n"
      << " " << m.a30 << " " << m.a31 << " " << m.a32 << " " << m.a33 << "]\n";
    return o;
}