## 6.1 Przekazywanie argumentów przez wartość

W C++ istnieje wiele sposobów przekazywania argumentów do i z funkcji, Najprostszym jest przekazywanie argumentu przez wartość. Oto prosty przykład:

```c++
int bit_count(unsigned n)
{
    int counter = 0;
    while (n != 0)
    {
        if (n & 1)
            counter++;
        n >>= 1;
    }
    return counter;
}
```

- Mówimy, że argument przekazywany jest do lub z funkcji *przez wartość*, gdy między nazwą argumentu a jego typem (przekazywanie *do* funkcji) lub między typem funkcji a jej nazwą (przekazywanie wartości *z* funkcji) nie ma żadnego dodatkowego operatora czy znaku niebędącego "białym znakiem". 

  - Powyżej na liście argumentów mamy `unsigned n`. Między typem, `unsigned`, a nazwą, `n`, są tylko białe znaki. Dlatego `n` jest przekazywane przez wartość.
  - Podobnie, między typem wartości zwracanej przez funkcję, `int`, a jej nazwą, `bit_count`, znajdują się wyłącznie białe znaki: `int bit_count(unsigned n)`. Funkcja przekazuje więc swój wynik "przez wartość". 

- Charakterystyczną cechą przekazywania argumentu przez wartość jest to, że funkcja operuje na kopii oryginalnej zmiennej lub obiektu. 

  - Mimo że funkcja `bit_count` zmienia wartość swojego argumentu, nie ma to wpływu na jego oryginał. Spójrzmy na poniższy przykład:

    ```c++ 
    #include <iostream>
    
    int bit_count(unsigned n)
    {
        int counter = 0;
        while (n != 0)
        {
            if (n & 1)
                counter++;
            n >>= 1;
        }
        return counter;
    }
    
    int main()
    {
        unsigned k = 9;
        auto r = bit_count(k);
        std::cout << "bit_count(" << k << ") = " << r << "\n";
    }
    ```

    W przykładzie tym `k` jest przekazywane do `bit_count` jako jej argument. Jednak mimo że funkcja ta modyfikuje swój argument (znany jej jako `n`) operatorem `>>=`, nie ma to wpływu na wartość `k` w funkcji `main`, gdyż funkcja `bit_count` operuje na kopii `k`. Dlatego powyższy program wyświetli wartość `k` równą `9`. 

  - Wyrażenie `n >>= 1` równoważne jest wyrażeniu `n = n >> 1`, w którym w zmiennej `n` przesuwa się bity o jedną pozycję w prawo. 
  
  - Wyrażenie `if (n & 1)` jest równoważne wyrażeniu `if ((n & 1) != 0`.
  
    - przyjmuje ono wartość `true` wtedy i tylko wtedy, gdy w `n` ustawiony jest najmniej znaczący bit, czyli gdy `n` jest nieparzyste
  
  - Alternatywny zapis pętli `while` może wyglądać następująco:
  
    ```c++  
    while (n != 0)
    {
        if (n % 2 != 0)
            counter++;
        n /= 2;
    }
    ```
  
    lub nawet
  
    ```c++
    while (n != 0)
    {
        counter += n % 2;
        n /= 2;
    }
    ```
  
  - W tej chwili powinno być jasne, że funkcja `bit_count` zlicza bity w zapisie liczby `n` lub, alternatywnie, zlicza jedynki w reprezentacji dwójkowej liczby `n`. Np. dla `n` równego 9 reprezentacja dwójkowa tej wartości to `0b1001`, czyli `bit_count(9) == 2`. Powyższy program produkuje więc następujące wyjście:
  
    ```txt
    bit_count(9) = 2
    ```

 #### 6.1.1 Podsumowanie

- Argumenty przekazywane przez wartość są do funkcji kopiowane. Funkcja nie działa na oryginałach takich argumentów, lecz na ich kopiach, czyli na "wartościach".    