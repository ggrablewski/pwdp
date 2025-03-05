#include <cmath>
#include <fstream>
#include <print>
#include <vector>

int main()
{
    const int length = 250;
    const int height = 250;
    const int max_color = 256;
    const double radius = length / 2.0;
    const double radius_squared = radius * radius;
    const std::string filename = "moj_obrazek_1.pgm";
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

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < length; x++)
        {
            double dx = x - length / 2.0;
            double dy = y - height / 2.0;
            double r_kwadrat = dx * dx + dy * dy;
            double r = std::sqrt(r_kwadrat);
            if (r > length / 2.0)
                continue;
            pixels[y][x] = 0;
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
