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

- Przy przekazywaniu argument z lub do funkcji, przekazywanie przez wartość ma miejsce wtedy, gdy między nazwą argumentu a jej typem (przekazywanie do funkcji) lub między typem funkcji a jej nazwą (przekazywanie z funkcji) nie ma żadnego dodatkowego operatora czy znaku niebędącego "białym znakiem". 

  - Powyżej na liście argumentów mamy `unsigned n`. Między typem, `unsigned`, a nazwą, `n`, są tylko białe znaki. Dlatego `n` jest przekazywane przez wartość.
  - Podobnie, między typem wartości zwracanej przez funkcję, `int`, a jej nazwą, `bit_count`, znajdują się wyłącznie białe znaki. Funkcja przekazuje więc swoją wartość "przez wartość". 

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
        std::cout << k << "\n";        
    }
    ```

    W przykładzie tym `k` jest przekazywane do `bit_count` jako jej argument. Jednak mimo że funkcja ta modyfikuje swój argument (znany jej jako `n`) operatorem `>>=`, nie ma to wpływu na wartość `k` w funkcji `main`, gdyż funkcja `bit_count` operuje na kopii `k`. Dlatego powyższy program wyświetli wartość `9`. 

  - 

 