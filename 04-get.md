## Funkcja `get()`, czyli czytanie każdego znaku

Wydawać by się mogło, że za pomocą `std::cin` i `std::ifstream` potrafimy wczytać ze strumienia wejścia lub pliku dowolną liczbę, napis lub znak. Niestety nie. Liczby i napisy - tak. Znaki w większości też, ale nie wszystkie. Sęk w tym, że jedyny sposób wczytywania danych, jaki dotąd przedstawiłem, operator `>>`, z definicji pomija tzw. białe znaki, czyli m.in. znaki spacji, tabulacji, przejścia do nowego wiersza (`'\n'`) i powrotu na początek wiersza (`'\r'`). Aby wczytać dowolny znak, należy skorzystać z innych metod. 

Najprostsza polega na użyciu tzw. funkcji składowej `get` na obiekcie kontrolującym strumień. Oto prosty przykład:

```c++    
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream

int main () 
{
    std::string str;
    std::cout << "Podaj nazwę istniejącego pliku tekstowego: ";
    std::cin >> str; 

    std::ifstream in(str); // otwieramy plik

    char c;
    while (in.get(c))      // w pętli czytamy wszystkie znaki 
        std::cout << c;
}
```

Jedynym nowością w tym programie jest wyrażenie

```c++ 
in.get(c)
```

umieszczone jako argument instrukcji `while`. 

- znaczna część funkcji w C++ wywoływana jest za pomocą składni obiektowej, w której najpierw piszę się nazwę obiektu, potem kropkę, a potem nazwę funkcji. Obiekt jest wówczas pierwszym, wyróżnionym argumentem takiej funkcji. Mówi się też, że ta funkcja działa na tym obiekcie. W żargonie języków obiektowych taką funkcje często zwie się *metodą*. Ja często nazywam określam je jako *funkcje składowe*. 
- funkcja składowa `get` wczytuje kolejny znak (bajt) niezależnie od jego wartości Nadaje się więc do wczytywania białych znaków czy wręcz plików binarnych.
- Funkcja ta zwraca referencję do obiektu kontrolującego strumień - nie tu miejsce tłumaczyć, co to znaczy. W tej chwili wystarczy wiedzieć, że toi coś, na co ona zwraca, w naturalny sposób zamienia się na `true` w przypadku, gdy udało się wczytać kolejny znak, i `false`, gdy operacja zakończyła sie niepowodzeniem (bo np. przeczytaliśmy już całą zawartość pliku). Dlatego wyrażenia typu `while(in.get(c))` są powszechnie używane w operacjach na plikach. 

Oczywiście funkcję składową `get` można też stosować na obiekcie `std::cin`. W tym przypadku, o ile pamięć mnie nie myli, jako znak końca strumienia służy kombinacja klawiszy `ctrl+D` (Linux). Litera D jest czwartą literą alfabetu angielskiego, odpowiada jej więc wartość 3 (bo pierwszej literze odpowiada 0). Sprawdzamy w tabeli kodów [ASCII](https://pl.wikipedia.org/wiki/ASCII): faktycznie, znak o wartości 3 ma "wartość" *End of Text*. 

```c++
// program kopiujący standardowe wejście na standardowe wyjście
#include <iostream> 

int main () 
{
    char c;
    while (std::cin.get(c))   
        std::cout << c;
}
```