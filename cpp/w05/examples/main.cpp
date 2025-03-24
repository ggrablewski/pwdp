#include <cassert>
#include <iostream>

/// trzy implementacje funkcji nwd

int nwd(int n, int m)
{
    assert(n > 0 && m > 0);
    if (n > m)
        std::swap(n, m);
    while (n > 0)
    {
        m %= n;
        std::swap(n, m);
    }
    return m;
}

int nwd2(int n, int m)
{
    assert(n > 0 && m > 0);
    while ((n %= m) && (m %= n))
    {
        continue;
    }
    return std::max(n, m);
}

int nwd3(int n, int m)
{
    assert(n > 0 && m > 0);
    if (n > m)
        std::swap(n, m);
    while (n > 0)
    {
        m -= n;
        if (n > m)
            std::swap(n, m);
    }
    return m;
}

int main()
{
    std::cout << nwd(12, 15) << " " << nwd(12, 13) << "\n";
    std::cout << nwd(15, 12) << " " << nwd(13, 12) << "\n";
    std::cout << nwd(15, 15) << " " << nwd(1, 1) << "\n";

    std::cout << nwd2(12, 15) << " " << nwd2(12, 13) << "\n";
    std::cout << nwd2(15, 12) << " " << nwd2(13, 12) << "\n";
    std::cout << nwd2(15, 15) << " " << nwd2(1, 1) << "\n";

    std::cout << nwd3(12, 15) << " " << nwd3(12, 13) << "\n";
    std::cout << nwd3(15, 12) << " " << nwd3(13, 12) << "\n";
    std::cout << nwd3(15, 15) << " " << nwd3(1, 1) << "\n";

    std::cout << "\n";
}
