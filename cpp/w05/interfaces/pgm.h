#ifndef PGM_H
#define PGM_H

#include <string>
#include <vector>

std::vector<std::vector<int>> init_pixels(int width, int height);
void fill_pixels(std::vector<std::vector<int>>& pixels, int max_color);
void save_image(const std::vector<std::vector<int>>& pixels, const std::string& filename, int max_color);

#endif  // PGM_H
