## 5.4 Przykłady funkcji

#### 5.4.1 `max`

Funkcja wyznaczająca większą (dokładnie: nie mniejszą) z dwóch liczb typu `int`:

```c++ 
int max(int n, int m)
{
    return (n < m) ? m : n;
}
```

- Zastosowano tu trójargumentowy operator `? :`. 

- Powyższy kod jest równoważny zapisowi

  ```c++
  int max(int n, int m)
  {
      if (n < m) 
          return m; 
      else
          return n;
  }
  ```

#### 5.4.2 Największy wspólny dzielnik

Oto funkcja wyznaczająca największy wspólny dzielnik dwóch liczb naturalnych

```c++ 
int nwd(int n, int m)
{
    assert(n > 0 && m > 0);
    while ((n %= m) && (m %= n))
    {
        continue;
    }
    return std::max(n, m);
}
```

- `assert` to jedna z metod weryfikacji poprawności programu, wykonywana tylko w trybie kompilacji `Debug`. 
  - Wymaga włączenia nagłówka `<cassert>`.

- `&&` to operator iloczynu logicznego. Zamiast `&&` można w C++ pisać też po prostu `and`.

  - Operator `&&` posiada w C++ ważną właściwość zwaną *[short-circuit evaluation](https://en.wikipedia.org/wiki/Short-circuit_evaluation)*: jego argumenty przetwarzane są od lewej do prawej, przy czym drugi argument wartościowany jest tylko wtedy, gdy wartość pierwszego nie wystarcza do określenia wartości całego wyrażenia. Na przykład w wyrażeniu 

    ```c++   
    f() && g()
    ```

    funkcja `g` zostanie wywołana tylko wtedy, gdy `f()` zwróci `true`. Jeżeli bowiem `f()` zwróci `false`, to wartość całego wyrażenia równa jest `false`. Dlatego instrukcja 
    
    ```c++
    f() && g();
    ```
    
    równoważna jest instrukcji warunkowej
    
    ```c++
    if (f())
        g();
    ```

- Ponieważ argumentami operatora iloczynu logicznego (koniunkcji)  `&&` są wyrażenia arytmetyczne, przed wyznaczeniem wartości tego operatora zostaną one skonwertowane do wyrażeń logicznych ([boolowskich](https://pl.wikipedia.org/wiki/Logiczny_typ_danych)) przez porównanie z zerem. 

  - Konwersja wyrażenia arytmetycznego, nazwijmy je `A`, na wyrażenie logiczne następuje poprzez zamianę wyrażenia `A` na `(A) != 0`. 

  - W związku z powyższym wyrażenie 

    ```c++  
    while ((n %= m) && (m %= n))
    ```

    jest równoważne wyrażeniu 

    ```c++
    while ((n %= m) != 0 && (m %= n) != 0)
    ```

- Wyrażenie `n %= m` jest równoważne wyrażeniu `n = n % m`. Jego efektem jest zamiana wartości `n` na resztę z dzielenia `n` przez `m`. 

- Operatory przypisania, w tym `%=`, mają wartość. Jest nią wartość lewego argumentu po dokonaniu przypisania jej wartości argumentu prawego. 

  - Wartością `n %= m` jest reszta z dzielenia `n` przez `m`, która "przy okazji" zostaje też zapisana w `n` jako jego nowa wartość

- Wyrażenie testowane w pętli `while`, 
  ```c++
  while ((n %= m) != 0 && (m %= n) != 0)
  ```

  nie tylko testuje wartości `n` i `m`, ale także przy okazji je modyfikuje

  - dlatego treść pętli `while` jest pusta, a mimo to pętla kiedyś się zatrzyma

- Powyższa pęta zatrzyma się, gdy `n` lub `m` osiągnie wartość `0`

  - Jest niemożliwe, by obie te zmienne osiągnęły wartość `0` jednocześnie. 
  - Jeżeli wartość `0` osiągnie `n`, to druga część warunku, `(m %= n)`, nie jest ewaluowana, czyli unikamy próby wykonania niezdefiniowanej operacji, jaka byłoby wyznaczanie reszty z dzielenia przez zero.  Taka próba niemal na pewno zakończyłaby się padem programu. 

-  Instrukcję `contunue` w pustej treści pętli `while` można pominąć, jednak zwykle umieszcza się ją w celu podkreślenia, że pusta treść pętli to zabieg celowy, świadomy.  

- `std::max` to oczywiście funkcja wyznaczająca większą z dwóch liczb. 

