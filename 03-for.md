#### 3.2.1 Pętla `for`

Pętla `for` jest podstawową pętlą języka C++. Spotyka się ją powszechnie. Służy przede wszystkim do wykonania określonej instrukcji (zwykle - blokowej) z góry określoną liczbę razy. Spójrzmy na przykład:

```c++
#include <print>

int main()
{
	const int N = 100'000'000;
	double suma = 0.0;
	for (int i = 1; i < N; i++)
	{
    	suma += 1.0 / i;
	}
	std::println("Suma odwrotności {} liczb naturalnych wynosi {}", N, suma);
}
```

 i wynik działania tego programu:

```txt 
Suma odwrotności 100000000 liczb naturalnych wynosi 18.997896403852554
```

- pętla `for` zawsze składa się z  4 części, z których każda może być pusta:
  - `for (inicjalizator; warunek; inkrementacja) instrukcja`
    - *inicjalizator* zwykle zawiera definicję zmiennej (lub zmiennych) sterującej pętli, np. `int n = 1`.  
    - *warunek* to dowolne wyrażenie logiczne (czyli mające wartość typu `bool`) określające, jak długo pętla ma się wykonywać
      - jeżeli warunek jest pusty, to kompilator wstawi tam `true` i otrzymamy pętlę nieskończoną, którą można jednak przerwać z wnętrza pętli, np. instrukcją `break`. 
    - *inkrementacja* to dowolne wyrażenie, którego wartość wyznaczana jest po każdym wykonaniu *instrukcji*. W praktyce jest to instrukcja, która zmienia wartość zmiennej sterującej. 
    - instrukcja to *instrukcja* (zwykle blokowa, czyli ciąg instrukcji ujętych w klamry) sterowana pętlą `for`.
- zwyczajowo w *inicjalizatorze* pętli `for` definiuje się *zmienną sterującą* pętlą (w naszym przykładzie jest to zmienna `i` typu `int`). 
  - Wartość tej zmiennej testuje się w *warunku* i modyfikuje w *inkrementacji*.
  - Zmienna ta jest niewidoczna poza pętlą
- *inicjalizator* wykonywany jest dokładnie raz na samym początku wykonywania pętli
- warunek sprawdzany jest przed każdorazowym wykonaniem *instrukcji*. Jego niespełnienie powoduje przerwanie pętli i skok do kodu za pętlą `for`.   

Dodatkowo w powyższym programie:

- Zapis `i++` oznacza "zwiększ `i` o 1"
- Zapis `100'000'000` zawiera opcjonalne apostrofy ułatwiające orientację co do wartości liczby.

### 3.2.2 Pętla `for` "w stylu Javy"

Istnieje też nowoczesna wersja pętli `for`, która służy do przeglądania wszystkich elementów kontenerów. W tej chwili za wcześnie jest na tłumaczenie, czym są kontenery. Póki co wystarczyć powinna informacja, że należą do nich `std::string`, `std::vector` i ciąg elementów tego samego typu ujęty w klamry, np. `{1, 2, 4, 8}`. Oto przykład tej "nowoczesnej" pętli `for`:

```c++ 
#include <print>
#include <string>

int main()
{
    std::string s = "Mam pięć lat!";
    for (auto c : s)
	    std::println("znak \'{:c}\', kod ASCII: dec = {:>3d}, hex = {:2x}", c, c, c);
}
```

Wynik działania tego programu sugeruje, że w moim komputerze polskie litery kodowane są jako pary znaków spoza zestawu ASCII:

```txt
znak 'M', kod ASCII: dec =  77, hex = 4d
znak 'a', kod ASCII: dec =  97, hex = 61
znak 'm', kod ASCII: dec = 109, hex = 6d
znak ' ', kod ASCII: dec =  32, hex = 20
znak 'p', kod ASCII: dec = 112, hex = 70
znak 'i', kod ASCII: dec = 105, hex = 69
znak '�', kod ASCII: dec = 196, hex = c4
znak '�', kod ASCII: dec = 153, hex = 99
znak '�', kod ASCII: dec = 196, hex = c4
znak '�', kod ASCII: dec = 135, hex = 87
znak ' ', kod ASCII: dec =  32, hex = 20
znak 'l', kod ASCII: dec = 108, hex = 6c
znak 'a', kod ASCII: dec =  97, hex = 61
znak 't', kod ASCII: dec = 116, hex = 74
znak '!', kod ASCII: dec =  33, hex = 21
```

Ogólna składnia "nowoczesnej" pętli `for` wygląda następująco:

```c++
for (auto element : kontener)
    // rób coś z element
```

Istnieją też warianty z "dekoracjami", np. 

```
for (auto && element : kontener)
```

itp., ale za wcześnie, by je tu omówić.

Warto pamiętać, że można pisać tak:

```c++
for (auto n : {1, 2, 4, 6, 16})
    std::cout << n * n << "\n";  
```

Pętla ta wyświetli kwadraty kolejnych elementów nienazwanego kontenera `{1, 2, 4, 8, 16}`.

```txt
1
4
16
36
256
```









