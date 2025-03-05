#include <iostream>
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

using namespace std;

int main() {
    cout << "Pruebas para Vector3:" << endl;
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);
    cout << "Producto punto de v1 y v2: " << Vector3::dot(v1, v2) << endl;

    cout << "\nPruebas para Matrix3:" << endl;
    Matrix3 m1;
    Matrix3 m2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    Matrix3 m3 = Matrix3::add(m1, m2);
    cout << "Suma de m1 y m2: " << m3.a00 << " " << m3.a01 << " " << m3.a02 << endl;

    cout << "\nPruebas para Matrix4:" << endl;
    Matrix4 mat1, mat2;
    Matrix4 result = Matrix4::add(mat1, mat2);
    cout << "Suma de Matrix4: " << result.a00 << " " << result.a01 << " " << result.a02 << endl;

    return 0;
}
