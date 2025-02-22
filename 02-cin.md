## 2.4 Standardowy strumień wejścia: `std::cin`

Zapewne chcielibyśmy móc wczytywać jakieś wartości z konsoli. W C++ służy do tego obiekt `std::cin` zdefiniowany w pliku nagłówkowym `<iostream>`. Prosty przykład użycia:

```c++ 
#include <iostream>

int main()
{
    std::cout << "Jak masz na imię?\n";
    std::string imie;
    std::cin >> imie;
    std::cout << "Ile masz lat?\n";
    int lata;
    std::cin >> lata;
    std::cout << "Cześć, " << imie << ", " << lata << "-latku!\n";
}
```

i możliwy wynik:

```txt
Jak masz na imię?
DonaldTheDuck
Ile masz lat?
4
Cześć, DonaldTheDuck, 4-latku!
```

- `std::cin` to uniwersalny obiekt, który zarządza standardowym strumieniem wejścia z konsoli programu (o ile taka istnieje) i potrafi wczytać wartości wszystkich typów podstawowych C++ (`int`, `char`, `double` itp.)
- Użycie `std::cin` wymaga wcześniejszego włączenia pliku `iostream` instrukcją ` #include <iostream>`.
- `std::cin` korzysta z operatora `>>`, a `std::cout` z operatora `<<`. Łatwo to zapamiętać, jeżeli przyrówna się je do grotów strzałek wskazujących kierunek przepływu danych.     