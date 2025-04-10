## 6.7 Argumenty i wartość funkcji `main`

#### 6.7.1 Argumenty funkcji `main`

Funkcja `main` zgodnie ze standardem języka może mieć jedną z dwóch postaci:

- `int main()` - postać bezargumentowa
- `int main (int argc, const char* argv[])` - postać dwuargumentowa. 

Pierwszej z nich, bezargumentowej, używałem już tu wielokrotnie. Formy dwuargumentowej używa się w celu przetworzenia argumentów wiersza poleceń. Oto przykład:

```c++   
#include <print>

int main(int argc, const char* argv[])
{
    std::println("argc = {}", argc);
    for (int i = 0; i < argc; i++)
    {
        std::println("argv[{}] = {}", i, argv[i]);
    }
}
```

Jeżeli ten program uruchomię z konsoli z różnymi argumentami, to otrzymam różne wyniki (przy założeniu, że program nazywa się `main`:

```txt
> ./main 
argc = 1
argv[0] = ./main

> ./main Ala ma kota!
argc = 4
argv[0] = ./main
argv[1] = Ala
argv[2] = ma
argv[3] = kota!

> ./main Ala czyta "Przeminęło z wiatrem" 
argc = 4
argv[0] = ./main
argv[1] = Ala
argv[2] = czyta
argv[3] = Przeminęło z wiatrem
./main Ala czyta \"przeminęło z wiatrem\" 

> argc = 6
argv[0] = ./main
argv[1] = Ala
argv[2] = czyta
argv[3] = "przeminęło
argv[4] = z
argv[5] = wiatrem"

> ./main Ala czyta "\"Przeminęło z wiatrem\"" 
argc = 4
argv[0] = ./main
argv[1] = Ala
argv[2] = czyta
argv[3] = "Przeminęło z wiatrem"
```

Wydaje mi się, że powyższy przykład nie wymaga specjalnie szczegółowego komentarza 

- `argc` to liczba argumentów wiersza poleceń zwiększona o 1
- `argv` to tablica napisów w stylu języka C (każdy o typie `const char*`) przekazanych do programu podczas jego uruchomienia
  - `argv[0]` to nazwa programu (czy raczej: procesu), pod jakim został on uruchomiony
  - `argv[i]` dla `i` > 0 to kolejne argumenty wiersza poleceń traktowane jako napisy

#### 6.7.2 Wartość funkcji `main` 

Skoro funkcję `main` deklarujemy jako `int main()`, to zwraca ona wartość. Zwykle jest ona zapisywana w instrukcji `return`, podobnie jak ma to miejsce w przypadku każdej funkcji w C++:

```c++
int main()
{
    return 9;
}
```

Jeżeli "zapomnimy" o instrukcji `return`, to kompilator dopisze za nas instrukcję `return 0;` - funkcja `main` jako jedyna posiada tę własność. 

Wartość zwróconą z programu można odczytać w sposób zgodny z powłoką (ang. *shell*), w której uruchamia się ten program. Np. w systemach Linux w powłoce `bash` służy do tego komenda `$?`. Jeśli powyższy program po skompilowaniu ma nazwę `a.out`, to w powłoce `bash` możemy otrzymać następującą sesję:

```txt    
> ./a.out
> echo $?
9
> ala
bash: ala: nie znaleziono polecenia
> echo $?
127
> echo $?
0
```

- pierwsza wartość wyrażenia `$?`, 9, to wartość zwrócona przez program `a.out` instrukcją `return 9;`.

- druga wartość wyrażenia `$?`, 127, to wartość zwrócona przez próbę uruchomienia nieistniejącego programu, `ala`.

- trzecia wartość wyrażenia `$?`, 0, to wartość zwrócona prze polecenie `echo $?`, które zakończyło się poprawnie. Wartość `0` traktowana jest jako kod sygnalizujący bezproblemowe zakończenie poprzedniego polecenia. 

  

Projekt z powyższym programem można pobrać [tutaj](./cpp/w06/main). 



