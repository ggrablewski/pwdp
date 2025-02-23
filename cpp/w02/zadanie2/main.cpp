#include <iostream>
#include <thread>

int main()
{
    std::cout << sizeof("ą") << "\n";
    std::cout << sizeof("ąć") << "\n";
    std::cout << sizeof("ąćś") << "\n";
    std::cout << sizeof("ążźź") << "\n";

    std::string s0("");
    std::string s1("s");
    std::string s2("ss");
    std::string s3("sss");
    std::string s4("ss5555555555555555999999999999999999999999999999999999999999999999999999999999999999999999999999555555555555555555555ss");
    std::cout << sizeof(s0) << "\n";
    std::cout << sizeof(s1) << "\n";
    std::cout << sizeof(s2) << "\n";
    std::cout << sizeof(s3) << "\n";
    std::cout << sizeof(s4) << "\n";

    std::cout << "\033[7;30mbold red text\033[0m\n";
    char c0 = 0xC4;
    char c1 = 0x84;
    std::cout << c0 << c1 << "\n";


}
