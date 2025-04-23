#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

// Dimensiones de la imagen
const int width = 400;
const int height = 400;
    
std::vector<uint8_t> pixels;

void pinta(int x, int y, uint32_t color)
{
    int index = (y * width + x) * 4;
    pixels[index + 0] = (color >> 24) & 0xFF;
    pixels[index + 1] = (color >> 16) & 0xFF;
    pixels[index + 2] = (color >> 8) & 0xFF;
    pixels[index + 3] = color & 0xFF;
}

void initPixels(uint32_t color)
{

pixels.reserve(width * height * 4);
std::cout << "Inicializando" << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
           // uint32_t pixel = image[y][x];
            uint32_t pixel = color;
            int index = (y * width + x) * 4;
            pixels[index + 0] = (pixel >> 24) & 0xFF; // R
            pixels[index + 1] = (pixel >> 16) & 0xFF; // G
            pixels[index + 2] = (pixel >> 8) & 0xFF;  // B
            pixels[index + 3] = pixel & 0xFF;         // A
        }
    }

}

void clearPixels(uint32_t color){
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
           // uint32_t pixel = image[y][x];
            uint32_t pixel = color;
            int index = (y * width + x) * 4;
            pixels[index + 0] = (pixel >> 24) & 0xFF; // R
            pixels[index + 1] = (pixel >> 16) & 0xFF; // G
            pixels[index + 2] = (pixel >> 8) & 0xFF;  // B
            pixels[index + 3] = pixel & 0xFF;         // A
        }
    }
}

int main() {

    initPixels(0x000000FF);
    std::vector<Vector4> vertices;

    vertices.push_back(Vector4( 1.0,  0.35,  1.0, 1.0));
    vertices.push_back(Vector4( 1.0,  0.35, -1.0, 1.0));
    vertices.push_back(Vector4( 1.0,  0.0,  1.0, 1.0));
    vertices.push_back(Vector4( 1.0,  0.0, -1.0, 1.0));
    vertices.push_back(Vector4( -1.0, 0.35, 1.0, 1.0));
    vertices.push_back(Vector4( -1.0, 0.35, -1.0, 1.0));
    vertices.push_back(Vector4( -1.0, 0.0,  1.0, 1.0));
    vertices.push_back(Vector4( -1.0, 0.0, -1.0, 1.0));
 

    // Crear una textura y un sprite para mostrar la imagen
    sf::Texture texture;
    texture.create(width, height);

    // texture.update(pixels.data());
    //sf::Sprite sprite(texture);

    std::cout << "Crear una ventana" << std::endl;
    sf::RenderWindow window(sf::VideoMode(width, height), "Display Image from Array");


    // Matrices y vectores  
    Matrix4 rotacionY, camara, perspectiva, MVP, escalamiento;
    


    camara = camara.lookAt(Vector4(0.0f,5.0f,-10.0f,1.0), Vector4(0.0f,0.0f,0.0f,1.0), Vector4(0.0f,1.0f,0.0f,0.0));
    
    std::cout << "Camara: " << std::endl;
    std::cout << camara << std::endl;
    
    perspectiva = perspectiva.perspective(40.0f, 1.0f, 50.0f, (float)width/(float)height);
    
    std::cout << "Perspectiva: " << std::endl;
    std::cout << perspectiva << std::endl;

    
    float alfa = 0.0f;

    rotacionY.rotateY(alfa);
    escalamiento.scale(0.5,0.5,0.5);
    
    std::cout << "Rotacion: " << std::endl;
    std::cout << rotacionY << std::endl;

    
    // Bucle principal de la ventana
    while (window.isOpen()) {
        sf::Event event;

        rotacionY.rotateY(alfa);
        MVP = perspectiva * camara * rotacionY * escalamiento;
        
        for(Vector4 vertex : vertices){

            Vector4 nuevo = MVP * vertex;
    
            nuevo.divW();

    
            int px = (nuevo.x + 1.0f) * 0.5f * (float)width; 
            int py = (nuevo.y + 1.0f) * 0.5f * (float)height; 

            py = height - py;
            
    //        std::cout << "[ " << px << "," << py << " ], ";
            if( (px >= 0  && px < width) && ( py >= 0 && py < height )  )
            pinta(px,py,0xFFFF00FF);
    
        }
        
        //std::cout << std::endl;

        texture.update(pixels.data());
        sf::Sprite sprite2(texture);
        window.clear();   
        clearPixels(0x000000FF);
        window.draw(sprite2);
        window.display();


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        alfa = alfa + 0.5f;
    }

    return 0;
}


/*
int main() {
    Vector3 v1(1.0f, 0.0f, 1.0f);
    Vector3 v2(0.0f, 1.0f, 1.0f);
    
    //Vector3 resultAdd = v1 + v2;
    Vector3 resultAdd = v1.add(v2);
    
    float dotResult = v1.dot(v2);
    Vector3 normalized = v1.normalize();
    

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "resultAdd v1 + v2 :" << resultAdd << std::endl;
    std::cout << "v1 dot v2: " << dotResult << std::endl;
    std::cout << "Normalize v1: " << normalized << std::endl;
    std::cout << "Length Normalize v1: " << normalized.length() << std::endl;
    std::cout << "Multiplacar v1 * 5: " << v1 * 5.0f << std::endl; 
    std::cout << "**********************************************" << std::endl; 

    Vector4 v3(1.0f, 0.0f, 1.0f, 1.0);
    Vector4 v4(0.0f, 1.0f, 1.0f, 1.0);
    
    Vector4 resultSubstract2 = v3 - v4;
    
    float dotResult2 = v4.dot(v3);
    Vector4 normalized2 = v4.normalize();
    

    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << "resultSubstract v3 - v4 :" << resultSubstract2 << std::endl;
    std::cout << "v3 dot v4: " << dotResult2 << std::endl;
    std::cout << "Normalize v4: " << normalized2 << std::endl;
    std::cout << "Length v4 normalized: " << normalized2.length() << std::endl;
    std::cout << "Multiplacar v3 * 5: " << v3 * 5.0f << std::endl; 
    std::cout << "**********************************************" << std::endl; 

    std::cout << "\nPruebas para Matrix3:" << std::endl;
    Matrix3 m1;
    Matrix3 m2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    Matrix3 m3 = m1 + m2;

    std::cout << "m1 " << std::endl;
    std::cout << m1 << std::endl;
    std::cout << "m2 " << std::endl;
    std::cout << m2 << std::endl;
    std::cout << "Suma de m1 y m2: " << std::endl;
    std::cout << m3 << std::endl;
    

    std::cout << "\nPruebas para Matrix4:" << std::endl;
    Matrix4 mat1, mat2, mat3, matr;
    mat1.scale(3,3,3);
    mat2.translate(2,2,2); 
    matr.rotateZ(90.0f);
    mat3 = matr * mat2 * mat1;

    Vector4 v6(1.0f,0.0f,0.0f,1.0f);
    Vector4 v5 = matr * v6;

    std::cout << matr << std::endl;
    
    std::cout << v5 << std::endl;


    return 0;
}

*/
