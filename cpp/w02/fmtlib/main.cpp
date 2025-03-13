#include <iostream>
#include <fmt/format.h>

using std::cout;
using fmt::format;
using fmt::print;
using fmt::println;

int main()
{
    int n = 15;
    int m = 16;

    cout << format("{} + {} = {}\n", n, m, n + m);
    print("Ala ma {}\n", "kota");
    println("Ola ma {}\n", "psa");
}
