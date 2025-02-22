#include <chrono>
#include <format>
#include <iostream>

int main()
{
    int n = 15;
    int m = 16;

    // podstawowe użycie:
    std::cout << std::format("{} + {} = {}\n", n, m, n + m);

    // argumenty nazwane
    std::cout << std::format("{1} + {0} = {2}\n", n, m, n + m);
    std::cout << std::format("{0} / {0} = 1\n", n);

    // jak wyświetlić klamry?
    std::cout << std::format("{{}} + {{}} = {}\n", "{} + {}");

    // szerokość pola
    std::cout << std::format("{:10} + {:10} = {:10}\n", n, m, n + m);

    // wyrównywanie: <. ^ lub >
    std::cout << std::format("{:>10} + {:^10} = {:<10}\n", n, m, n + m);

    // wyrównywanie z wypełnianiem:
    std::cout << std::format("{:.>10} + {:.^10} = {:.<10}\n", n, m, n + m);

    // zmiana systemu liczbowego
    std::cout << std::format("{:15d} {:15d}\n", 35, 266);
    std::cout << std::format("{:15b} {:15b}\n", 35, 266);
    std::cout << std::format("{:#15b} {:#15b}\n", 35, 266);
    std::cout << std::format("{:15x} {:15x}\n", 35, 266);
    std::cout << std::format("{:#15x} {:#15x}\n", 35, 266);
    std::cout << std::format("{:15o} {:15o}\n", 35, 266);
    std::cout << std::format("{:#15o} {:#15o}\n", 35, 266);

    // dokładność wyświetlania liczb zmiennopozycyjnych
    auto x = 1.0 / 3.0;
    std::cout << std::format("{:.4} \n", x);
    std::cout << std::format("{:.8} \n", x);
    std::cout << std::format("{:.16} \n", x);
    std::cout << std::format("{:.50} \n", x);
    std::cout << std::format("{:.60} \n", x);
    std::cout << std::format("{:.60} \n", 0.3);
    std::cout << std::format("{:.10} \n", 0.25);
    std::cout << "\n";

    // zagnieżdżanie specyfikatorów
    std::cout << std::format("{:.{}} \n", x, 2);
    std::cout << std::format("{:.{}} \n", x, 6);
    std::cout << std::format("{:.{}} \n", x, 10);
    std::cout << std::format("{:.{}} \n", x, 14);
    std::cout << std::format("{:.{}} \n", x, 18);
    std::cout << std::format("{1:>6}: {0:.{1}} \n", x, 10);
    std::cout << std::format("{1:>6}: {0:.{1}} \n", x, 20);

    // wyświetlanie czasu
    std::cout << std::format("Bieżąca data: {:%d %B %Y}\n", std::chrono::system_clock::now());
    std::cout << std::format("Bieżący czas: {:%H:%M:%OS}\n", std::chrono::system_clock::now());
}
