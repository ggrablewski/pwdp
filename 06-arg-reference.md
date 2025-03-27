## 6.2 Przekazywanie argumentów funkcji (i jej wartości) przez referencję 

Bardzo często chcielibyśmy, by funkcja mogła modyfikować swoje argumenty. Można to osiągnąć na dwa sposoby: przekazując do funkcji zmienne lub obiekty przez referencję lub wskaźnik. Tu omawiam pierwszą z tych opcji.

#### 6.2.1 Referencja

Referencja to jakby nowa nazwa dla istniejącego obiektu. Oto przykład:

```c++  
int a = 1;
int & b = a;
```

W drugiej instrukcji pomiędzy nazwą zmiennej i jej typem stoi ampersand, `&`, który w tym kontekście oznacza referencję. Innymi słowy, jest to deklaracja `b` jako referencji do jakiejś zmiennej typu `int`. Jaka to zmienna zapisane jest w inicjalizatorze: `= a`. Czyli `int & b = a` to deklaracja `b` jako referencji do `a`. Od tej pory każda operacja na `a` jest operacją na `b` i *vice versa*, każda operacja na `b` jest operacją na `a`. 

```c++
std::cout << a << "\n";  // wyświetla 1 
b = 7;
std::cout << a << "\n";  // wyświetla 7
a = 2;
std::cout << b << "\n";  // wyświetla 2
```

Definiowanie referencji w kodzie, pomiędzy instrukcjami, spotyka się rzadko. Najczęściej widzimy je w interfejsach funkcji.

#### 6.2.2 Przekazywanie argumentu do funkcji przez referencję

Załóżmy, że chcemy napisać funkcję, która będzie inicjalizowała dwuwymiarową tablicę dynamiczną, ustalając jej rozmiar na $n \times n$, gdzie $ n > 0$ jest pewną liczbą naturalną, wypełniała jej elementy diagonalne wartością 1, a pozostałe - zerami. 

Gdybyśmy interfejs takiej funkcji zapisali w sposób opisany w poprzednim rozdziale, 

```c++
void init(std::vector<std::vector<double>> tab, int n); // to nie przejdzie
```

to mielibyśmy dwa kłopoty, oba związane z tym, że przekazywalibyśmy tablicę `tab` przez wartość:

- Funkcja `init` działałaby na kopii oryginalnej tablicy `tab`, dlatego nie wykonywałaby swojego zadania
- Funkcja  `init` działałaby na kopii oryginalnej tablicy `tab`, co wymagałoby pracochłonnego utworzenia kopii `tab` przed uruchomieniem `init`. 

O ile drugi z powyższych problemów związany jest "tylko" z wydajnością programu, to pierwszy dyskwalifikuje powyższe rozwiązanie jako po prostu błędne.  

Oba problemy rozwiązujemy, przekazując `tab` przez referencję:

```c++
void init(std::vector<std::vector<double>> & tab, int n)
```

Pełna definicja takiej funkcji może wyglądać następująco:

```c++    
void init(std::vector<std::vector<double>> & tab, int n)
{
    tab.resize(n);                  // tab ma n wierszy 
    for (int i = 0; i < n; i++)
    {
        tab[i].resize(n);           // każdy wiersz ma n elementów
        for (int j = 0; j < n; j++)
            tab[i][j] = 0.0;        // wszystkie elementy są zerowane
        tab[i][i] = 1.0;            // ale na diagonali ustawiamy 1
    }
}
```

Funkcji tej możemy użyć np. tak (definicję `init` pominąłem):

```c++
#include <iostream>
#include <vector>

// definicja jak powyżej
void init(std::vector<std::vector<double>> & tab, int n); 

int main()
{
    std::vector<std::vector<double>> v;
    init(v, 15);  // v jest jednostkową tablicą kwadratową 15 * 15
    v[5][0] = 1;
    for (auto x : v[5])  // wyświetla 6. wiersz (o indeksie 5)
        std::cout << x << " ";
    std::cout << "\n";
    init(v, 10);         // v jest jednostkową tablicą kwadratową 10 * 10
    for (auto x : v[5])  // wyświetla 6. wiersz (o indeksie 5)
        std::cout << x << " ";
    std::cout << "\n";
}
```

Program ten produkuje następujący wynik:

```txt
1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 1 0 0 0 0 
```

Jak widać, funkcja `init` faktycznie modyfikuje swój pierwszy argument, zmieniając jego rozmiar i zerując wszystkie elementy pozadiagonalne.

Projekt można pobrać [stąd](./cpp/w06/by-reference).

#### 6.2.3 Przekazywanie wartości funkcji przez referencję

Przekazywanie wyniku przez referencję może się wydawać dziwne i mało użyteczne, ale to tylko pozory. Czasami jest to najlepsze możliwe rozwiązanie. Zacznijmy od prostego, nieco akademickiego przykładu: 

```c++  
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
```

W przykładzie tym `fun()` zwraca referencję do `::x`, czyli do zmiennej globalnej `x`. Oznacza to, że wszędzie tam, gdzie możemy napisać `::x`, możemy też napisać `f()` i *vice versa*. Skoro poprawna jest instrukcja `::x = 10;`, to instrukcja `f() = 10` jest jej równoważna i tak samo poprawna. Powyższy program jest więc poprawny i wyświetla

```txt
10
```

#### 6.2.4 Przeciążanie operatora strumieniowego

Powiedzmy, że chcielibyśmy móc wyświetlić zawartość tablicy dynamicznej `std::vector<int> v` za pomocą znanej konstrukcji `std::cout << v << "\n";`. Nie jest to trudne. Wystarczy w tym celu zdefiniować funkcję o nazwie `operator<<` i odpowiednio dobranych argumentach. Argumenty muszą być dwa, bo `operator<<` posiada argument lewy (pierwszy) i prawy (drugi). Pierwszy musi odpowiadać typowi obiektu `sdd::cout`, czyli np. być równy `std::ostream`, drugim zaś powinien być typ obiektu `v`, czyli `std::vector<int>`. Wartość tej funkcji musi być zaś takiego typu, by można było za nim napisać `<< "\n";`, czyli ponownie użyć operatora `<<`. Wartość ta musi być więc równoważna `std::cout`. Skoro równoważna, to musi być przekazana przez referencję. Stąd mamy gotowe (nie najlepsze, ale dopuszczalne) rozwiązanie:

```c++  
std::ostream& operator<<(std::ostream& out, std::vector<int>& v)
{
    out << "[";
    if (!v.empty())
        out << v[0];
    for (int i = 1; i < v.size(); i++)
        out << ", " << v[i];
    out << "]";
    return out;
}
```

Koniecznie należy zwrócić uwagę na to, że strumień `out` przekazywany jest do i z funkcji poprzez referencję. Żadna inna metoda (poza wskaźnikami) nie wchodzi w grę, gdyż obiektów zarządzających strumieniami nie można kopiować z oczywistych względów. Z kolei tablicę dynamiczną `v` przekazuję prze referencję tylko w celu optymalizacji prędkości działania funkcji - czyli z chęci uniknięcia kosztownego i niepotrzebnego kopiowania tablicy do funkcji. Najlepszym sposobem przekazania tego argumentu byłaby stała referencja, o czym będzie mowa nieco później.      

Funkcję tę możemy przetestować np. tak:

```c++
#include <iostream>
#include <vector>

// kod jak powyżej, tu pomijam
std::ostream& operator<<(std::ostream& out, std::vector<int>& v);

int main()
{
    std::vector<int> tab = {1, 2, 3, -1, -2};
    std::cout << tab << "\n";
}
```

Otrzymamy następujący wynik:

```txt
[1, 2, 3, -1, -2]
```

Zauważmy, że dzięki temu, że `operator<<` zwraca referencję do pierwszego argumentu, instrukcja

```c++  
std::cout << tab << "\n";
```

jest dokładnie równoważna ciągowi instrukcji 

```c++
std::cout << tab;
std::cout << "\n";
```

Definiowanie funkcji o nazwach zaczynających się od słowa `operator` nazywane jest w C++ przeciążaniem (ang. *overloadnig*) operatora. Nie jest to trudny temat, ale nie jest to też główny temat niniejszego wykładu, nie będę więc tu rozwijał tego tematu. Można go potraktować trochę jako ciekawostkę, a trochę jako wyjaśnienie działania obiektów `std::cout` i `std::cin` oraz związanych z nimi operatorów `<<` i `>>`. Tak, ten sposób realizacji operacji wejścia i wyjścia w C++ w całości opiera się na przeciążaniu tych dwóch operatorów. Warto o tym wiedzieć, by nie dać się zaskoczyć np. podczas sesji z debugerem. Na obecnym etapie nauki nic więcej na ten temat wiedzieć (chyba) nie potrzeba.