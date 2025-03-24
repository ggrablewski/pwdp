#include <print>
#include <string>

#include "pgm.h"

int main()
{
    const int width = 250;
    const int height = 250;
    const int max_color = 255;
    const std::string filename = "fun_obrazek.pgm";

    auto pixels = init_pixels(width, height);
    fill_pixels(pixels, max_color);
    save_image(pixels, filename, max_color);

    std::println("Image has been written to \"{}\"", filename);
}
