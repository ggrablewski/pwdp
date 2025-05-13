## 8.1 Struktury

Dotąd poznaliśmy dość szczegółowo typy podstawowe języka C++, takie jak podstawowe typy liczbowe (m.in. `int`, `char`, `double`), typy wskaźnikowe (np. `char*`, `const float*` czy `void*` ) oraz proste tablice (np. `int tab[100]`). To dość ubogi zestaw odpowiedni tylko dla twórców naprawdę niewielkich programów. Jednym z głównych czynników decydujących o sile i popularności C++ jest łatwość tworzenia w nim własnych typów danych, tzw. typów użytkownika. Najprostszym przykładem takich typów są struktury, które język C++ przejął z języka C.

#### 8.1.1 Definicja struktury jako typu danych

W językach C i C++ struktura to typ danych składający się z pól (zwanych też składowymi) o zasadniczo dowolnych typach. W szczególności składowymi struktur mogą być inne struktury. Struktury zawsze zajmują ciągły obszar w pamięci operacyjnej, z tym że ilość pamięci, jaką zajmują, może być większa od sumy pamięci zajmowanej przez każdą ze składowych, jeśli pozwoli to kompilatorowi generować bardziej efektywny kod.

Oto przykład struktury, która mogłaby opisywać punkt (piksel) na ekranie:

```c++
struct Pixel
{
    int x;
    int y;
};
```

A tu nieco bardziej złożony przykład hipotetycznej struktury, jaka mogłaby opisywać konto klienta banku, i której definicja opiera się na istnieniu innych struktur, `Pesel`, `Telephone` i `Balance`:

```c++
struct Account
{
    std::string name;
    Pesel pesel;
    Telephone telephone;
    Balance balance; 
};
```

A tu z kolei przykład struktury rekurencyjnej (tzn. zawierającej wskaźnik do struktury tego samego typu) używanej w implementacjach listy pojedynczo linkowanej:

```c++
struct Link
{
    int value;
    Link* next;
};
```

Należy koniecznie zwrócić uwagę na to, że definicja struktury *zawsze* kończy się średnikiem.  

#### 8.1.2 Używanie struktury do definiowania obiektów

Strukturami posługujemy się dokładnie tak, jak typami wbudowanymi. Aby zdefiniować zmienną (obiekt) typu zdefiniowanego przez strukturę, najpierw piszemy nazwę struktury, a potem - definiowanego obiektu:

```c++
Pixel pixel;
Account acc;
Link link;
```

Uwaga. W literaturze terminem "struktura" określa się zarówno typ danych definiowany za pomocą słowa kluczowego `struct`, jak i zmienną / obiekt. Z kontekstu zwykle łatwo się domyślić, co autor miał na myśli. Ja skłaniam się ku określeniu takich danych mianem "obiekt". 

#### 8.1.2 Dostęp do składowych (pól) obiektu

##### 8.1.2.1 Dostęp bezpośredni (notacja "z kropką")

Jeżeli mamy bezpośredni dostęp do danego obiektu, to do jego pól (czyli składowych z danymi) odwołujemy się za pomocą operatora `.` (kropka). Przykład:

```c++ 
Pixel pixel;
pixel.x = 8;
pixel.y = 90;
auto suma = pixel.x + pixel.y;
```

##### 8.1.2.2 Dostęp pośredni (notacja "ze strzałką")

Często zdarza się, że dostęp do obiektów zapewniają wskaźniki. W takim przypadku stosujemy operator wyłuskania składowej, `->`. przykład:

```c++  
Pixel pixel;
// jakiś kod...
Pixel* p = &pixel; // `p` wskazuje na `pixel`
p->x = 8;
p->y = 90;
auto suma = p->x + p->y;
```

W zapisie `p->x` informujemy kompilator, że chodzi nam o składową `x` obiektu wskazywanego przez `p`.   

#### 8.1.3 Inicjalizacja obiektu zdefiniowanego przez strukturę

Zalecaną metodą pracy z obiektami jest inicjalizacja ich stanu już w momencie ich tworzenia. Najczęściej stosuje się składnię, w której wartości początkowe składowych obiektu wypisuje się kolejno w nawiasach klamrowych:

```c++  
Pixel pixel = {2, 5};   // pixel.x = 2, pixel.y = 5
```

Ten sposób opiera się na założeniu, że pamiętamy lub za każdym razem sprawdzamy, jaka jest kolejność składowych w obiekcie. Bardziej nowoczesna, bezpieczna i czytelna składnia umożliwia podanie nazw pól po kropce, jak w tym przykładzie:

```c++
Pixel pixel = {.x = 2, .y = 5};  // pixel.x = 2, pixel.y = 5
```

#### 8.1.4 Przekazywanie obiektów do oraz z funkcji

Obiekty przekazujemy do i z funkcji tak, jak zwykłe zmienne. Możemy więc przekazywać je m.in. przez wartość, referencję, stałą referencję, wskaźnik, wskaźnik na stałą, stały wskaźnik i stały wskaźnik na stałą.

```c++
void zero(Pixel& pixel)
{
    pixel.x = 0;
    pixel.y = 0;
}
```

Kolejny przykład - piksel sąsiadujący z danym pikselem z lewej, przy założeniu okresowych warunków brzegowych i szerokości okna równej `Lx`:

```c++
Pixel left_neighbor(Pixel pixel, int Nx)
{
    pixel.x--;
    if (x < 0)
        x += Nx;
    return pixel;
}
```

#### 8.1.5 Wiązanie strukturalne

Wiązanie strukturalne (ang. *structured binding*) to cecha wprowadzona do C++ w wersji 17 w celu uproszczenia korzystania ze struktur oraz innych złożonych typów danych. W praktyce wygląda to tak (przy założeniu, że `left_neighbour` ma definicję jak w poprzednim punkcie):

```c++
Pixel pixel = {0, 0}; 
auto [x, y] = left_neighbor(pixel, 800);
```

Po wykonaniu ostatniej z powyższych instrukcji `x` będzie miało wartość składowej `x` obiektu zwróconego przez funkcję `left_neighbor`, a `y` - jego składowej `y`. 

Oczywiście nazwy zmiennych są dowolne:

```c++
auto [punkt_x, punkt_y] = left_neighbor(pixel, 800);
```

Można też używać referencji do składowych:

```c++
auto& [x, y] = left_neighbor(pixel, 800);
```

Wiązania strukturalne nie są niezbędnym elementem warsztatu programisty C++, niemniej, są bardzo popularne i przynajmniej powinniśmy rozumieć tego rodzaju zapis.