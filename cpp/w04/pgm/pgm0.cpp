#include <cmath>
#include <fstream>
#include <print>
#include <vector>

int main()
{
    const int length = 250;
    const int height = 250;
    const int max_color = 255;
    const double half_perimeter = length + height;
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
            double normalized_value = double(x + y) / half_perimeter;
            pixels[y][x] = std::round(normalized_value * max_color);
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
