#include <iostream>

int x = 8;  // zmienna globalna

int& fun()
{
    return ::x;  // ::x oznacza "x z globalnej przestrzeni nazw"
}

int main()
{
    fun() = 10;  // równoważne: ::x = 10;
    std::cout << ::x << "\n";
}
