## 6.6 Przekazywanie funkcji jako argumentów innych funkcji

Argumentami funkcji mogą być nie tylko wyrażenia (np. `2 + 3`), zmienne (np. typu `int`), wskaźniki czy obiekty (np. `std::cout`), ale i funkcje. Technicznie, w takim przypadku funkcja otrzymuje jako argument wskaźnik na funkcję, którą ma wywołać. Nie wchodząc w szczegóły (czyli np. w opis definiowania wskaźników na funkcję), poniżej przedstawię tylko praktyczne sposoby radzenia sobie z przekazywaniem funkcji jako argumentów innych funkcji.

Zacznijmy od typu. Jaki typ ma funkcja? Otóż typ w C++ zawsze można odczytać z deklaracji, pomijając w niej nieistotne elementy. Np. w deklaracji 

```c++
int x;
```

nieistotna jest nazwa zmiennej. Podobnie w deklaracji funkcji

```c++
double sin(double x);
```

nieistotna jest jej nazwa oraz nazwa jej argumentu. W końcu, funkcja `double cos(double y)` jest tego samego typu, co powyższe funkcja `sin`. Typem obu tych funkcji jest więc `double (double)`. Stąd wniosek, że można zadeklarować funkcję (np. o nazwie `f`) przyjmującą jako argument inną funkcję w następujący sposób:

```c++
void f(double (double));
```

I faktycznie, jest to zapis poprawny, choć nieużyteczny - jak bowiem w treści funkcji `f` mielibyśmy odwołać się do jej argumentu funkcyjnego? Potrzebujemy więc w deklaracji argumentu jego nazwy. W tym przypadku będzie to (formalna) nazwa funkcji, taka, jaką "widzi" funkcja `f`. Stąd deklaracja poprawna *oraz* użyteczna funkcji przyjmującej inną funkcję w swoim argumencie może wyglądać następująco:

```c++  
void f(double fun(double));
```

### 6.6.1 Przykłady

#### 6.6.1.1 Suma ciągu

Oto przykład funkcji, która wyznacza sumę skończonego ciągu $\sum_{i=k}^n f(i)$:

```c++
double sum_seq(double f(int), int first, int last)
{
    double sum = 0.0;
    for (int i = first; i <= last; i++)
        sum += f(i);
    return sum;
}
```

Można użyć jej w programie w następujący sposób

```c++
double harmonic(int i)
{
    return 1.0 / i;
}

int main()
{   
    const double euler = 0.577215664901532860;
    int N = 10'000'000;
    auto h = sum_seq(harmonic, 1, N);
    auto gamma = h - log(N);
    std::cout << "H(" << N << ") = " << h << "\n";
    std::cout << "g(" << N << ") = " << gamma << "\n";
    std::cout << "\terr = " << euler - gamma << "\n"; 
}
```

Program ten wyznacza sumę częściową szeregu harmonicznego, $H_{10000000}$ oraz przybliżoną wartość stałej Eulera $\gamma$: 

```txt
H(10000000) = 16.6953
g(10000000) = 0.577216
	err = -4.99974e-08
```

- Funkcję przekazujemy do innej funkcji po prostu poprzez jej nazwę (tu: `harmonic`)

  ```c++ 
  sum_seq(harmonic, 1, N);
  ```

Czy moglibyśmy użyć jako pierwszego argumentu funkcji `sum_seq` funkcji `sin` z biblioteki standardowej (`#include <cmath>`)?

```c++ 
#include <cmath>
// ...
sum_seq(sin, 1, N);
```

W tym przypadku kompilator wygeneruje komunikat o błędzie:

```txt
main.cpp:21:22: error: invalid conversion from ‘double (*)(double) noexcept’ to ‘double (*)(int)’ [-fpermissive]
```

- funkcje o różnych argumentach mają różne typy, których nie można mieszać
- typ funkcji kompilator uzyskuje, zastępując jej nazwę wyrażeniem `(*)`. 
  - Skąd gwiazdka? Ano stąd, że przekazując funkcję do funkcji, tak naprawdę przekazujemy jej adres, czyli wskaźnik. 

Żeby było ciekawiej, błędu nie ma, jeśli zamiast `sin` napiszemy `std::sin`. Dużo tłumaczenia, dlaczego tak jest. W skrócie: `sin` to "normalna" funkcja wspólna dla języków C i C++ i jej typ to `double (*)(double)`, natomiast `std::sin` to rodzina funkcji generowanych z szablonu, przy czym jedna z nich ma sygnaturę `double (*)(int)` wymaganą przez funkcję `sum_seq`. Tę konkretną funkcję z rodziny `std::sin` można zapisać jako `std::sin<int>`, co zostanie omówione nieco szerzej przy okazji omawiania szablonów. 

#### 6.6.1.2 Pochodna

Oto przykład funkcji wyznaczającej numeryczne przybliżenie pochodnej innej funkcji:

```c++ 
double derivative(double f(double), double x, double h = 1e-8)
{
    return (f(x + h/2)) - f(x - h/2)) / h;
}
```

Jest to przykład funkcji z argumentem domyślnym (tu: `double h = 1e-8`). Argumentu domyślnego nie musimy podawać podczas wywoływania funkcji - w takim przypadku kompilator sam wstawi tam wartość domyślną

```c++ 
auto d0 = derivative(sin, 0);       // h = 1e-8
auto d1 = derivative(sin, 0, 1e-6); // h = 1e-6 
```



Projekt z powyższym programem można pobrać [tutaj](./cpp/w06/fun-arguments). 
