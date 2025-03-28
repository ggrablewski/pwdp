## 6.4 Przekazywanie argumentów przez wskaźnik i operator wyłuskania wartości

Jak wiemy, w C++ występuje operator pobrania adres, `&`. Na przykład wartością wyrażenia `&n` jest adres, pod którym przechowywana jest zmienna `n`. Skoro istnieją wyrażenia reprezentujące adresy, to istnieją też specjalne typy danych przeznaczone do przechowywania adresów. Charakteryzują się one specjalną składnią wykorzystującą symbol gwiazdki (`*`) , ten sam, którego używamy do reprezentowania mnożenia.

```c++  
int n = 3;
int* p = &n;  // p przechowuje adres n
```

Wskaźnik to dość szeroki temat. Tu ograniczam się do informacji podstawowych, koniecznych do posługiwania się funkcjami bibliotecznymi wykorzystującymi w swoim interfejsie właśnie wskaźniki. 

Przede wszystkim powinniśmy wiedzieć, jak wyłuskać wartość wskazywaną przez wskaźnik. Podpowiedź kryje się w deklaracji tego rodzaju zmiennych. Jeżeli bowiem `p` zadeklarowano za pomocą wyrażenia `int* p`, które można też zapisać równoważnie jako `int * p` lub `int *p`, to najwyraźniej wyrażenie `*p` ma typ `int`. I tak też jest w rzeczywistości. 

```c++      
int n = 3;
int* p = &n;
*p = 4;
std::cout << n << "\n";
```

W powyższym programie definiujemy zmienną `p` jako wskaźnik na `int` i przypisujemy jej adres `n`. Następnie za jej pomocą modyfikujemy wartość `n`.

Tego rodzaju manipulacje (odczyt lub zapis zmiennej, np. `n`, za pomocą zmiennej wskaźnikowej, np. `p`) nazywamy ***adresowaniem pośrednim***.

Adresowanie pośrednie można wykorzystać podczas projektowania interfejsów funkcji. 

#### 6.4.1 Przykłady

##### 6.4.1.1 Podnoszenie liczby do kwadratu

Oto przykład prostej funkcji, która zwraca kwadrat argumentu przekazanego przez wskaźnik:

```c++ 
int square(int* p)
{
    return *p * *p; 
}
```

W powyższym zapisie `*p` to wartość (typu `int`) wskazywana przez `p`, a środkowa gwiazdka (otoczona spacjami), `  *  `, to operator mnożenia. Jak widzimy, ten sam symbol, `*`, zależnie od kontekstu, może oznaczać operator wyłuskania wartości (ze wskaźnika) bądź operator mnożenia. 

Ten sam kod można napisać nieco bardziej zrozumiale:

```c++
int square(int* p)
{
    int n = *p;
    return n * n; 
}
```

W tym przypadku na samym początku funkcji wyłuskujemy wartość wskazywaną przez wskaźnik do osobnej zmiennej (tu: do zmiennej `n`), a następnie posługujemy się tą zmienną jak w zwykłym kodzie.

Powyższy kod można też zapisać przy pomocy referencji:

```c++ 
int square(int* p)
{
    int& n = *p;
    return n * n; 
}
```

Skoro nasza funkcja `square` nie modyfikuje swojego argumentu, a jedynie go czyta, to jeszcze lepszym rozwiązaniem byłoby przekazanie argumentu przez wskaźnik na stałą:

```c++
int square(const int* p)
{
    int n = *p;
    return n * n; 
}
```

- Wskaźnika na stałą używamy wtedy, gdy za jego pomocą chcemy tylko czytać, ale nie potrzebujemy modyfikować zmienną lub obiekt przezeń wskazywaną
- Stosowanie wskaźników na stałą ułatwia kontrolę poprawności programu, poprawia też jego czytelność
- Wskaźnik na stałą definiujemy, uzupełniając nazwę typu wskazywanego przez wskaźnik modyfikatorem `const`, jak na powyższym przykładzie 

Każdą z powyższych funkcji `square`, niezależnie od implementacji, musimy wywoływać z jawnym argumentem wskaźnikowym:

```c++
int main()
{
    int n = 9;
    return square(&n);
}
```

- Koniecznie proszę zwrócić uwagę na to, że argumentem `square` jest wskaźnik na `int`, tu uzyskany poprzez zastosowanie operatora `&` na zmiennej `n`.

##### 6.4.1.2 Zamiana liczb (`swap`)

W poprzednim przykładzie mieliśmy do czynienia z funkcją, która nie modyfikowała argumentów przekazywanych jej przez wskaźnik . Czas na funkcję, która dokona takich modyfikacji. Jednym z prostszych przykładów jest funkcja, która zamienia (ang. *swap*) wartości dwóch zmiennych. Czyli jeśli mamy np. `n` o wartości 1 i `m` o wartości 0, to po wywołaniu `swap(n, m)` chcemy, żeby to `n` miało wartość 0, a `m` wartość 1. Oto przykładowa implementacja:

```c++ 
void swap(int* pm, int* pn)
{
    int tmp = *pm;   // tmp przechowuje pierwotną wartość m
    *pm = *pn;       // do m wpisujemy pierwotną wartość n
    *pn = tmp;       // do n wpisujemy pierwotną wartość m
}
```

Alternatywnie, można sobie pomóc, jak w poprzednim przykładzie, wyłuskując wartości wskazywane przez `pn` i `pm`:

```c++
void swap(int* pm, int* pn)
{
    int& n = *pn; // n to zmienna wskazywana przez pn
    int& m = *pm; // m to zmienna wskazywana przez pm
    int tmp = m;   // tmp przechowuje pierwotną wartość m
    m = n;         // do m wpisujemy pierwotną wartość n
    n = tmp;       // do n wpisujemy pierwotną wartość m
}
```

##### 6.4.1.3 Zerowanie wektora 

Oto nieco bardziej złożony przykład funkcji `zeruj`, która wypełnia tablicę dynamiczną `tab` zerami:

```c++   
void zeruj(std::vector<int>* pv)
{
    auto & tab = *pv;
    for (int i = 0; i < tab.size(); i++)
        tab[i] = 0;
}
```

- W powyższym przykładzie wyłuskałem obiekt wskazywany przez `v`  za pomocą referencji. Brak referencji w tym przypadku byłby błędem, gdyż instrukcja `auto tab = *pv;` powodowałaby kopiowanie tablicy do `tab`, a przecież, po pierwsze, chcemy zerować elementy oryginału a nie kopii, po drugie, nie chcemy niepotrzebnych kopiowań potencjalnie dużych ilości danych. 

- Alternatywna wersja pętli for:

  ```c++  
  for (auto & n : tab)
      n = 0;
  ```

  - Znak referencji, `&`, jest tu konieczny, bo modyfikujemy zawartość kontenera `tab`
  - Znak referencji informuje kompilator, że `n` ma być referencją do kolejnych elementów kontenera `tab`, dlatego modyfikacja `n` powoduje jednoczesną modyfikację `tab`. 

###### 6.4.1.3.1 Operator `->`

Bez referencji powyższy kod mógłby wyglądać tak:

```c++
void zeruj(std::vector<int>* pv)
{
    for (int i = 0; i < pv->size(); i++)
        (*pv)[i] = 0;
}
```

Należy zwrócić tu uwagę na wyrażenie `pv->size()`, w którym zastosowano operator wyłuskania składowej, `->`. Ogólnie, zapis `p->q` jest równoważny zapisowi `(*p).q`. Operartor `->` wprowadzono do języka, aby uniknąć dużej liczby nawiasów. W końcu nieco łatwiej przeczytać 

```c++
p->get(1)[0].front()->size()
```

 niż 

```c++
((*p).get(1)[0].front()).size()
```
Podobnie sprawa ma się z `root->next->next->value` i `(*(*(*root).next).next).value`.  W obu przypadkach wyrażenie z operatorami `->` czytamy po prostu od lewej do prawej i nie musimy wracać do przeczytanego tekstu, gdy zobaczymy prawy nawias, `)`.    