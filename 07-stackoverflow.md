## 7.2 *Stack overflow*

#### 7.2.1 Przepełnienie stosu wskutek zbyt głębokiej rekurencji 

*Stackoverflow* to nazwa bardzo popularnego serwisu dla programistów, [stackoverflow.com](http://stackoverflow.com). Jest to też nazwa błędu, który prowadzi do padu programu, a który zwykle bywa spowodowany niewłaściwą implementacją funkcji rekurencyjnych. 

Spójrzmy raz jeszcze na przykład z poprzedniej części tego opracowania

```c++    
int silnia(int n)
{
    if (n == 0) 
        return 1;
    else
        return n * silnia(n - 1);
}
```

Co się stanie, jeżeli funkcje tę wywołamy z bardzo dużym argumentem, np. dla $n = 100~000~000$? A co, jeżeli wywołamy ją z `n` ujemnym? W obu przypadkach możemy spodziewać się wystąpienia błędu *stack overflow* i padu programu.

Jak już wspominałem, programy pisane w C++ zwykle posiadają specyficzną strukturę pamięci - przydzielana im przez system operacyjny pamięć dzielona jest na kilka oddzielnych części, w tym stertę i stos funkcji programu. Wszystkie dane niezbędne do uruchomienia każdej funkcji program przechowuje na stosie funkcji, przy czym każde wywołanie danej funkcji może wykorzystywać te same lub inne obszary pamięci stosu. Sam stos funkcji z reguły ma z góry określony rozmiar, który nie ulega zmianie podczas działania programu. W systemie Linux jest to obecnie ok. 8 MB. Każde kolejne wywołanie kolejnej funkcji powoduje, że program rezerwuje na stosie kolejna bajty pamięci. Jeżeli wywołań będzie zbyt dużo, program spróbuje przekroczyć granicę stosu, co z kolei spowoduje reakcję systemu operacyjnego i w zasadzie pewny pad programu. To właśnie jest *stack overflow*, czyli przepełnienie stosu.

Popatrzmy, co się stanie, gdy powyższą funkcję spróbujemy wywołać z argumentem `100'000'000`:

```txt
> ./a.out 
Naruszenie ochrony pamięci (zrzut pamięci)
> echo $?
139
```

Czyli program zakończył się nienormalnie z kodem błędu 139 odpowiadający otrzymaniu z systemu operacyjnego sygnału o wartości 129 - 128 = 11, czyli 

Spróbujmy wywołać funkcję `silnia` z argumentem `-1`:

```txt
> ./a.out 
Naruszenie ochrony pamięci (zrzut pamięci)
> echo $?
139
```

Uwaga. Przepełnienie stosu wskutek zbyt głębokiej rekurencji bardzo mocno zależy od poziomu optymalizacji oraz struktury funkcji rekurencyjnej. Na przykład powyższą funkcję `silnia` współczesne kompilatory potrafią zoptymalizować tak, że jej wywołanie nie zajmuje pamięci, w związku z czym wyrażenia w rodzaju `silnia(1'000'000'000)` wywołują się poprawnie.  

#### 7.2.2 Przepełnienie stosu wskutek zadeklarowania zbyt dużych tablic lokalnych

Stos można przepełnić albo poprzez wywołanie bardzo dużej liczby funkcji, albo prze zadeklarowanie w nich zmiennych i obiektów zajmujących bardzo dużo pamięci. 

Prosty przykład:

```c++
int main()
{
    int tab[10'000'000] = {0};
}
```

Funkcja `main()` składa się z jednej instrukcji, w której definiujemy tablicę `tab` o 10 milionach elementów typu `int`, a więc zajmującą 50 MB pamięci. To więcej niż posiada typowy stos. Podczas inicjalizacji tej tablicy powinno więc dojść do jego przepełnienia. 

```txt
> ./a.out
Naruszenie ochrony pamięci (zrzut pamięci)
```

Problemu tego nie ma z obiektami klasy `std::vector`, gdyż dane są w nich przechowywane nie na stosie, a na stercie programu. Inne, działające, choć niepolecane rozwiązanie, to deklarowanie takich dużych tablic jako zmiennych globalnych (czyli poza jakąkolwiek funkcją).