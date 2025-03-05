#include <cmath>
#include <fstream>
#include <print>
#include <vector>
#include <numbers>

int main()
{
    const int length = 250;
    const int height = 250;
    const int max_color = 256;
    const double radius = length / 2.0 - 5;
    const double radius_squared = radius * radius;
    const double inner_radius = radius - std::numbers::sqrt2 / 2.0;
    const double outer_radius = radius + std::numbers::sqrt2 / 2.0;

    const std::string filename = "moj_obrazek_2.pgm";
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
            double r = std::sqrt(dx * dx + dy * dy);
            if (r > outer_radius)
                continue;
            if (r < inner_radius)
            {
                pixels[y][x] = 0;
                continue;
            }
            double dr = (r - inner_radius) / std::numbers::sqrt2;
            double weighted_color = (1.0 - dr) * 0 + dr * pixels[y][x];
            pixels[y][x] = std::round(weighted_color);
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
