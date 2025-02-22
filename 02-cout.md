## 2.5 Standardowy strumień wyjścia: `std::cout`

Z obiektem `std::cout` spotkaliśmy się już niejednokrotnie. Obiekt ten zarządza standardowym, buforowanym strumieniem wyjścia, domyślnie związanym z konsolą programu.  Obiekt ten zdefiniowany jest w pliku nagłówkowym `<iostream>`. Prosty przykład użycia:

```c++ 
#include <iostream>

int main()
{
    int n = 6;
    double pi = 3.14;
    std::string s = "Ala ma kota ";
    std::cout << s << pi << " razy " << n << " razy\n"; 
}
```

i możliwy wynik:

```txt
Ala ma kota 3.14 razy 6 razy
```

- `std::cout` to uniwersalny obiekt, który zarządza standardowym strumieniem wyjścia (buforowanym) na konsolę programu (o ile taka istnieje) i potrafi wyświetlić wartości wszystkich typów podstawowych C++ (`int`, `char`, `double` itp.)
- Użycie `std::cout` wymaga wcześniejszego włączenia pliku `iostream` instrukcją ` #include <iostream>`.
- `std::cout` korzysta z operatora `<<`, a `std::cin` z operatora `>>`. Łatwo to zapamiętać, jeżeli przyrówna się je do grotów strzałek wskazujących kierunek przepływu danych.
- Kolejne wywołania operatora `<<` na `std::cout` można łączyć w łańcuchy, jak w powyższym przykładzie.