#include <limits>
#include <iostream>

int main()
{
    int x = std::numeric_limits<int>::max();
    int y = std::numeric_limits<int>::min();
    std::cout << "największa wartość, jaką można zapisac w int =  " << x << "\n";
    x = x + 1;
    std::cout << "po zwiększeniu jej o 1 otrzymujemy              " << x << "\n";
    std::cout << "najmniejsza wartość, jaką można zapisac w int = " << y << "\n";
    std::cout << "Liczba do niej przeciwna to                     " << -y << "\n";
}
