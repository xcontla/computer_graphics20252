#version 410 core
in vec3 fragColor;
in vec2 uv;
out vec4 color;

// numero complejo (a + ib) <-> (a,b)
 int mandelbrot(vec2 c)
{

        vec2 z = vec2(0.0);
        int iterations = 0;
        const int maxIterations = 500;

        while(length(z) <= 2.0 && iterations < maxIterations)
        {
            z = vec2(z.x * z.x - z.y * z.y, 2.0 * z.x * z.y) + c;
            iterations++;
        }

        return iterations;

}

void main()
{
    int iterations = mandelbrot(uv  * 1.0 - 0.5 );

    float man_color = float(iterations) / 100.0;
    color = vec4(man_color * fragColor, 1.0);
}