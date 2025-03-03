#include <fstream>
#include <print>
#include <string>
#include <stdexcept>

int main()
{
    std::string filename = "wierszyk.txt";
    std::ofstream out(filename);
    if (!out)
        throw std::runtime_error(std::format("failed to open \"{}\"", filename));
    std::string s =
        "Przyszedł gość do doktora, biada na swe zdrowie.\n"
        "- Jakaś mi żaba - mówi - wyrosła na głowie.\n"
        "- Umówmy się - odrzekło to zwierzę niegłupie -\n"
        "Nie ja jemu na głowie, lecz on mnie na dupie.\n\n"
        "Andrzej Waligórski, \"Bajeczki Babci Pimpusiowej\"\n";

    std::print(out, "{}", s);
}
