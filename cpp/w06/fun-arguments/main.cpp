#include <cmath>
#include <iostream>

double sum_seq(double f(int), int first, int last)
{
    double sum = 0.0;
    for (int i = first; i <= last; i++)
        sum += f(i);
    return sum;
}

double harmonic(int i)
{
    return 1.0 / i;
}

int main()
{
    const double euler = 0.577215664901532860;
    int N = 10'000'000;
    auto h = sum_seq(std::sin<int>, 1, N);
    auto gamma = h - log(N);
    std::cout << "H(" << N << ") = " << h << "\n";
    std::cout << "g(" << N << ") = " << gamma << "\n";
    std::cout << "\terr = " << euler - gamma << "\n";
}
