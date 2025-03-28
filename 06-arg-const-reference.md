## 6.3 Przekazywanie argumentów przez stałą referencję

Każdy z dotychczas omówionych sposobów przekazywania argumentów do funkcji, przez wartość i referencję, ma swoje zalety i wady. Przekazywanie przez wartość zabezpiecza oryginał argumentu przed przypadkową modyfikacją wewnątrz funkcji, jednak dla dużych, "tłustych" jego kopiowanie do funkcji obiektów może być zasobo- i czasochłonne. Z kolei przekazywanie argumentu przez referencję jest szybkie, jednak może być stosowane wyłącznie dla argumentów posiadających swój adres. Nie można w ten sposób przekazać np. liczb (stałych) lub wartości funkcji. Ponadto utrudnia analizę poprawności programu, gdyż sugeruje, że nasza funkcja chce modyfikować każdy argument przekazany jej przez "zwykłą referencję". Problemy te można łatwo rozwiązać za pomocą stałej referencji. Oto przykład jej użycia w funkcji, wyznaczającej sumę elementów tablicy liczby typu `int`:

```c++        
int suma(const std::vector<int> & v)
{
    int sum = 0;
    for (auto n: v)
        sum += n;
    return sum;
}
```

Charakterystyczną cechą przekazywania argumentu przez stałą referencję jest słowo kluczowe `const` oraz symbol referencji, `&`. 

Rozpatrzmy kolejny przykład, funkcję wyznaczającą większą z dwóch liczb:

```c++
int max(const int& n, const int& m)
{
    return (n < m) ? m : n;
}
```

Można jej użyć zarówno do argumentów mających adres, jak i takich, które adresu nie mają. 

```c++
int main()
{
    int n = 9;
    int m = 8;
    int k = max(n, m); // n i m mają adres
    int q = max(1, 3); // ani 1, ani 3 nie ma adresu 
}
```

Jak to możliwe, że kompilator generuje referencję do liczby, np. `1`, która przecież nie ma własnego adresu? Otóż w takim przypadku program tworzy kopię wartości w osobnych zmiennych tymczasowych i przekazuje adres tych zmiennych do funkcji. W ten sposób przekazywanie przez stałą referencję możliwe jest zarówno dla zmiennych i obiektów "adresowalnych", jak `n` w powyższym przykładzie, jak i nieadresowalnych, jak `1` .