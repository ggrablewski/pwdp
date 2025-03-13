## 5.1 Co to jest funkcja? Deklaracja i definicja funkcji

### 5.1 Co to jest funkcja

W przykładach z poprzedniego rozdziału, dotyczących formatu PGM, bardzo wiele kodu się powtarza. Przy czym to powtórzenie nie jest przypadkowe, a wynika z tego, że w każdym z nich potrzebowaliśmy rozwiązania bardzo podobnych lub  wręcz tych samych zadań. 

Przykładem jest fragment kodu przygotowujący tablicę dynamiczną:

```c++
std::vector<std::vector<int>> pixels;
pixels.resize(height);
for (int i = 0; i < pixels.size(); i++)
    pixels[i].resize(length);
```

Czyż nie byłoby prościej móc ten fragment kodu jakoś nazwać i potem używać tam, gdzie potrzebować będziemy tablicy dwuwymiarowej zmiennych typu `int`? Właśnie do takiego wydzielania kodu służą funkcje. 

Spróbujmy więc zamknąć powyższy kod wewnątrz funkcji. Najprostsze podejście mogłoby wyglądać nastepująco. Zamiast 

```c++
std::vector<std::vector<int>> pixels;
pixels.resize(height);
for (int i = 0; i < pixels.size(); i++)
    pixels[i].resize(length);
```

chcielibyśmy móc napisać tak:

```c++ 
auto pixels = init_pixels();
```

Proszę bardzo, oto rozwiązanie:

```c++
std::vector<std::vector<int>> init_pixels()
{
    const int length = 250;
    const int height = 250;
    std::vector<std::vector<int>> pixels;
    pixels.resize(height);
    for (int i = 0; i < pixels.size(); i++)
        pixels[i].resize(length);
    return pixels;
}
```

- Powyższy kod to przykład definicji funkcji (tu: o nazwie `init_piksels`).
- Definicja funkcji składa się z czterech części:
  - deklaracji wartości zwracanej prze tę funkcję (tu: `std::vector<std::vector<int>>`)
  - nazwy funkcji (tu: `init_pixels`)
  - ujętej w nawiasy okrągłe listy typów argumentów funkcji (tu: `()`, czyli lista argumentów jest pusta)
  - ujętego w klamry zestawu instrukcji (zwanego ciałem lub treścią funkcji, ang *function body*). 
    - Funkcja zwraca wartość za pomocą instrukcji `return`. 

Powyższa definicja ma poważną wadę: na stałe zapisano w niej rozmiar obrazka (250 na 250 pikseli). Dobrze byłoby móc funkcje parametryzować, czyli uzależniać jej działanie od wartości pewnych parametrów. Proszę bardzo, oto rozwiązanie:

```c++  
std::vector<std::vector<int>> init_pixels(int length, int height)
{
    std::vector<std::vector<int>> pixels;
    pixels.resize(height);
    for (int i = 0; i < pixels.size(); i++)
        pixels[i].resize(length);
    return pixels;
}
```

Teraz taką funkcję można wywołać następująco:

```c++
auto pixels = init_pixels(250, 250);
```

- Jeżeli funkcja ma jakieś argumenty, to typ każdego musi być znany w czasie kompilacji. Dlatego lista argumentów funkcji w jej definicji zawiera nie tylko ich nazwy, ale i typy. 

###  5.2 Deklaracja funkcji  

Deklaracja funkcji zawiera wszystkie informacje potrzebne do jej wywołania, nie zawiera natomiast informacji o tym, jaki kod jest przez nią wykonywany. W praktyce deklaracja funkcji składa się z 3 elementów:

- deklaracji wartości zwracanej prze tę funkcję (np: `std::vector<std::vector<int>>`)

  - jeżeli funkcja nie zwraca żadnej wartości, jako jej typ deklarujemy `void`, np.:

    ```c++ 
    void print_as_binary(int n);
    ```

- nazwy funkcji (np: `init_pixels`)

- ujętej w nawiasy okrągłe listy typów argumentów funkcji (nazwy argumentów są... nieobowiązkowe)

- i kończy się średnikiem. 

Deklaracje omówionych powyżej funkcji `init_pixels`  wyglądają następująco:

```c++
std::vector<std::vector<int>> init_pixels();                        // pierwsza
std::vector<std::vector<int>> init_pixels(int length, int height);  // druga
```

Jaka jest główna rola deklaracji w C++? Otóż tuż po zadeklarowaniu funkcji możemy jej używać, co bardzo ułatwia korzystanie z bibliotek funkcji. Zazwyczaj aby użyć biblioteki, włączamy do programu deklaracje  udostępnianych przez nią funkcji - służy do tego makroinstrukcja `#include`. Następnie informujemy kompilator (a w zasadzie tzw. *linker*), że chcemy, aby nasz program został połączony z gotowymi, skompilowanymi funkcjami z takie to a takiej biblioteki. Jak to zrobić - o tym później. W przypadku biblioteki standardowej wciąż musimy włączać deklaracje makroinstrukcją `#include` (co wkrótce ma w zasadzie odejść do przeszłości, po upowszechnieniu tzw. modułów), jednak nie musimy jawnie prosić kompilatora o dołączenie jaj plików binarnych do naszego programu - kompilator robi to automatycznie.       

### 5.3 Definicja funkcji

Definicję funkcji już widzieliśmy: to deklaracja plus ujęty w nawiasy klamrowe zbiór instrukcji wykonywanych przez tę funkcję. 

- Każda definicja jest jednocześnie deklaracją. 

- W programie może istnieć tylko jedna definicja danej funkcji i dowolna liczba jej deklaracji - jest to tzw. zasada ODR (ang. *one definition rule*).
- W C++ może istnieć wiele funkcji o tej samej nazwie. Muszą one jednak różnić się liczbą i/lub typem argumentów tak, by kompilator mógł jednoznacznie dopasować wywołanie funkcji do jej definicji.  