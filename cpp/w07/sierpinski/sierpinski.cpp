#include <cmath>
#include <iostream>
#include <vector>

using Plansza = std::vector<std::vector<bool>>;

void wytnij(Plansza& plansza, int x0, int y0, int length)
{
    if (length < 3)
        return;
    int smaller = length / 3;
    for (int y = y0 + smaller; y < y0 + 2 * smaller; y++)
    {
        for (int x = x0 + smaller; x < x0 + 2 * smaller; x++)
        {
            plansza[y][x] = true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            wytnij(plansza, x0 + i * smaller, y0 + j * smaller, smaller);
        }
    }
}

void pisz(const Plansza& plansza)
{
    for (const auto& linia : plansza)
    {
        for (auto punkt : linia)
        {
            if (punkt)
                std::cout << "  ";
            else
                std::cout << "██";
        }
        std::cout << "\n";
    }
}

int main()
{
    const int level = 4;
    const int length = std::pow<int>(3, level);
    Plansza plansza(length);
    for (auto& v : plansza)
        v.resize(length);

    wytnij(plansza, 0, 0, length);
    pisz(plansza);
}
