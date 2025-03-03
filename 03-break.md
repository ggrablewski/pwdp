### 3.3 Instrukcje `break` i `continue`

#### 3.3.1 Instrukcja `break`

Czasami zachodzi potrzeba natychmiastowego zakończenia pętli. Służy do tego instrukcja `break`. Można jej używać w każdej pętli (a więc w `for`, `while` i `do-while`). Oto przykład jej użycia:

```c++
std::string s = "ab12qw";
for (auto c: s)
{
    if (c == `q`)
        break;
    std::cout << c;
}
```

Powyższa pętla wypisuje na ekranie kolejne znaki z napisu `s` aż do jego końca lub do pierwszego wystąpienia litery `q`.

#### 3.3.2 Instrukcja `continue`

Czasami dobrze byłoby móc czasami pomijać pozostałą część treści pętli. Służy do tego instrukcja `continue`. Poniższy kod wykorzystuje ją, by wyświetlić tylko te znaki z napisu `s`, które nie są wielkimi literami z zestawu ASCII:

```c++
std::string s = "Alina i Olek mają ADHD.";
for (auto c: s)
{
    if (std::isupper(c))
        continue;
    std::cout << c;
}
```

Program ten w moim komputerze daje taki wynik:

```txt
lina i lek mają .
```

Powyższy przykład jest bardzo prosty i łatwo byłoby przepisać treść pętli tak, by `continue` nie było potrzebne. Niemniej, w wielu praktycznych sytuacjach pętle bywają znacznie bardziej złożone i wówczas `continue` to znakomity sposób na uproszczenie kodu. Podobna uwaga odnosi się też oczywiście d=także do `break`.  



 