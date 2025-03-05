#include <cmath>
#include <fstream>
#include <print>
#include <vector>

int main()
{
    const int length = 250;
    const int height = 250;
    const int max_color = 256;
    const double radius_squared = length * length / 4.0;
    const std::string filename = "moj_obrazek_0.pgm";
    std::ofstream out(filename);

    std::vector<std::vector<int>> pixels;
    pixels.resize(height);
    for (int i = 0; i < pixels.size(); i++)
    {
        pixels[i].resize(length);
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < length; x++)
        {
            pixels[y][x] = std::round(double(x + y) / double(length + height) * max_color);
        }
    }

    std::println(out, "P2\n{} {}\n{}", length, height, max_color);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < length; x++)
        {
            out << pixels[y][x] << " ";
        }
        out << "\n";
    }
}
