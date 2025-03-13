#include <cmath>
#include <fstream>
#include <print>
#include <vector>

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

void fill_pixels(std::vector<std::vector<int>>& pixels, int max_color)
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

void save_image(const std::vector<std::vector<int>>& pixels, const std::string& filename, int max_color)
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

int main()
{
    const int width = 250;
    const int height = 250;
    const int max_color = 255;
    const double half_perimeter = width + height;
    const std::string filename = "fun_obrazek.pgm";

    auto pixels = init_pixels(width, height);
    fill_pixels(pixels, max_color);
    save_image(pixels, filename, max_color);
    std::println("Image has been written to \"{}\"", filename);
}
