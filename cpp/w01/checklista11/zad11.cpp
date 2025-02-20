#include <cmath>
#include <iostream>

int silnia(int k)
{
    if (k <= 1)
        return 1;
    return k * silnia(k - 1);
}

int main()
{
    double suma = 0.0;
    for (int i : {1, 2, 3, 4, 5})
    {
        suma = suma + 1 / silnia(i);
    }
    std::cout << "suma odwrotności silni pięciu kolejnych liczb naturalnych wynosi " << suma << "\n";
    std::cout << "spodziewamy się tu liczby bliskiej " << exp(1.0) - 1.0 << "\n";
}
