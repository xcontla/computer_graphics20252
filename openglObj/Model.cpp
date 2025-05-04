// Model.cpp
#include "Model.h"
#include <cmath>

float* Model::createCircle(int segments, float radius) {
    float* vertices = new float[(segments + 1) * 3];
    float angleStep = 2.0f * M_PI / (float)(segments - 1);
    for (int i = 1; i < segments + 1; ++i) {
        vertices[i * 3 + 0] = radius * cosf(angleStep * (i - 1));
        vertices[i * 3 + 1] = radius * sinf(angleStep * (i - 1));
        vertices[i * 3 + 2] = 0.0f;
    }
    return vertices;
}