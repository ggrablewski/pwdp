#include "pgm.h"

#include <cmath>
#include <fstream>

std::vector<std::vector<int>> init_pixels(int width, int height)
{
    std::vector<std::vector<int>> pixels;
    pixels.resize(height);
    for (int i = 0; i < pixels.size(); i++)
    {
        pixels[i].resize(width);
    }
    return pixels;
}

void fill_pixels(std::vector<std::vector<int>> &pixels, int max_color)
{
    const int height = pixels.size();
    const int width = pixels[0].size();
    const double half_perimeter = width + height;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double normalized_value = double(x + y) / half_perimeter;
            pixels[y][x] = std::round(normalized_value * max_color);
        }
    }
}

void save_image(const std::vector<std::vector<int>> &pixels, const std::string &filename, int max_color)
{
    int height = pixels.size();
    int width = pixels[0].size();

    std::ofstream out(filename);
    std::println(out, "P2\n{} {}\n{}", width, height, max_color);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            out << pixels[y][x] << " ";
        }
        out << "\n";
    }
}
