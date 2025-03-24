### 3.2 Pętle `while` i `do-while`

#### 3.2.1. Pętla `while`

Pętla `while` wykonuje jakąś operację tak długo, jak spełniony jest określony warunek. Spójrzmy na przykład:

```c++ 
#include <iostream>
#include <print>

int main()
{
    int n = 7; 
    int k = 22;
    int a = 1;
    while((n * a) % k != 1)
    {
       a++;        
    }
    int b = -(n * a / k);
    std::println("n   = {:5}, k   = {:5}", n, k);
    std::println("a   = {:5}, b   = {:5}", a, b);
    std::println("n*a = {:5}, k*b = {:5}", n * a, k * b);
    std::println("a*n + b*k = {}",  a * n + b * k); 
}
```

Powyższy program dla danych liczb całkowitych $n$ i $k$ znajduje takie liczby całkowite `a` i `b`, że $na + kb = 1$. [Wiadomo](https://en.wikipedia.org/wiki/Diophantine_equation#One_equation), że jeżeli $n$ i `k` są względnie pierwsze, to równanie to zawsze ma rozwiązanie. Rozwiązanie jest proste. Bierzemy jedną z liczb wyjściowych, np. `n` i wyznaczamy kolejne jej wielokrotności aż dojdziemy do takiej, której reszta z dzielenia przez drugą liczbę wyjściową, `k` , równa się 1. Zmienna `a` jest licznikiem tej wielokrotności. W momencie, w którym pętla się zatrzyma, warunek `(n * a) % k != 1`  ma wartość `false`. Czyli reszta z dzielenia `n * a` przez `k` wynosi `1`. Czyli istnieje `c` takie, że $na = ck + 1$. Czyli $na - ck = 1$. A więc w naszym równaniu wystarczy wziąć $b = -c$, by spełnione było $na + kb = 1$. Jak obliczyć $c$ wiedząc, że  $na = ck + 1$? Dzieląc obie strony przez $k$ i odrzucając część ułamkową otrzymujemy $c = \lfloor \frac{na}{k} \rfloor$ , gdzie $\lfloor x \rfloor$ to tzw. [podłoga](https://pl.wikipedia.org/wiki/Pod%C5%82oga_i_sufit) liczby rzeczywistej $x$, czyli największa liczba całkowita nie większa od $x$. Operację  $\lfloor x \rfloor$ dla liczb nieujemnych realizuje w C++ dzielenie całkowitoliczbowe, czyli operator `/`. Stąd instrukcja `int b = -(n * a / k);`. 

Ogólna postać pętli `while` ma postać 

```c++
while(warunek)
    instrukcja;
```

- *warunek* to dowolne wyrażenie logiczne (lub mu równoważne). W powyższym przykładzie jest to `(n * a) % k != 1`, czyli pętla ma działać tak długo, jak długo reszta z dzielenia iloczynu `n*a` przez `k` nie równa się 1. 
- *instrukcja* to dowolna instrukcja. Zwykle jest to instrukcja blokowa (ciąg instrukcji ujęty w klamry).

Dodatkowo

- Operator `%` wyznacza resztę z dzielenia swojego lewego argumentu przez prawy.
- Operator `!=` to operator relacyjny, który zwraca `true` wtedy i tylko wtedy, gdy jego argumenty są różne. 

#### 3.2.2 Pętla `do-while`

Pętla `do-while` jest bardzo podobna do pętli `while`, różni ją nieco składnia, a przede wszystkim to, że warunek jej kontynuacji testowany jest po wykonaniu bloku instrukcji i dlatego ten blok wykona się co najmniej raz. Jako przykład rozważmy ten wycinek kodu:

```c++
const auto strong_password = "qwerty123";
std::string s;
do
{
	std::cout << "password: ";
	std::cin >> s;
}while (s != strong_password);
```

We fragmencie tym program wczytuje z klawiatury hasło i porównuje je z wzorcem zapisanym "na sztywno" w zmiennej `strong_password`. Oczywiście takie porównanie musimy wykonać co najmniej raz, dlatego pętla `do-while` jest do takich zadań nieco bardziej poręczna. 

Kilka komentarzy:

- Nigdy, nigdy, przenigdy nie formatuj `while` kończącego pętlę `do-while` tak, by słowo to rozpoczynało nowy wiersz. Czyli NIGDY nie pisz tak:

  ```c++  
  do
  {
  	std::cout << "password: ";
  	std::cin >> s;
  }
  while (s != strong_password); // złe formatowanie kodu!!!
  ```

  Dlaczego? Bo programiści C++ (i C) przyjęli zasadę, że aby natychmiast odróżniać w kodzie pętlę `while` od pętli `do-while`, tę pierwszą zawsze rozpoczyna się od `while` stojącego na początku wiersza, a tę drugą zawsze pisze się po klamrze zamykającej zakres pętli.

- Pętla `do-while` używana jest najrzadziej ze wszystkich pętli.
