#include <fstream>
#include <format>
#include <iostream>
#include <print>
#include <string>
#include <stdexcept>

int main()
{
    std::string filename;
    std::cout << "podaj nazwę pliku: ";
    std::cin >> filename;
    std::ifstream in(filename);
    if (!in)
        throw std::runtime_error(std::format("failed to open \"{}\"", filename));
    std::string line;
    std::println("{:->40}", "");
    while (std::getline(in, line))
    {
        std::println("{}", line);
    }
}
