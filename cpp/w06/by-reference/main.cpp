#include <iostream>
#include <vector>

void init(std::vector<std::vector<double>>& tab, int n)
{
    tab.resize(n);  // tab ma n wierszy
    for (int i = 0; i < n; i++)
    {
        tab[i].resize(n);  // każdy wiersz ma n elementów
        for (int j = 0; j < n; j++)
            tab[i][j] = 0.0;  // wszystkie elementy są zerowane
        tab[i][i] = 1.0;      // ale na diagonali ustawiamy 1
    }
}

int main()
{
    std::vector<std::vector<double>> v;
    init(v, 15);  // v jest jednostkową tablicą kwadratową 15 * 15
    v[5][0] = 1;
    for (auto x : v[5])  // wyświetla 6. wiersz (o indeksie 5)
        std::cout << x << " ";
    std::cout << "\n";
    init(v, 10);         // v jest jednostkową tablicą kwadratową 10 * 10
    for (auto x : v[5])  // wyświetla 6. wiersz (o indeksie 5)
        std::cout << x << " ";
    std::cout << "\n";
}
