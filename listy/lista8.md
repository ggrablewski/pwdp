## Lista zadań nr 8 

1. (1 pkt) Napisz i przetestuj funkcje:

   - `int nwd(int n, int m)`, zwracającą największy wspólny dzielnik `n` i `m`
   - `int nww(int n, int m)`, zwracającą najmniejszą wspólną wielokrotność `n` i `m`. 

   Możesz założyć, że w przypadku `nwd` co najwyżej jedna z liczb `n` i `m` jest zerem, a w przypadku `nww`  oba argumenty są dodatnie. 

   Postaraj się tak zaprojektować `nww`, by w jak największym stopniu unikać ryzyka wystąpienia przepełnienia w typie `int`. 

   Pamiętaj, że `nwd` nie może zwrócić liczby ujemnej (ani zera).   

2. (3 pkt.) Korzystając z poprzedniego zadania zaprojektuj i przetestuj klasę `Ulamek` reprezentującą liczby wymierne w postaci `licz/mian`, gdzie `licz` i `mian` to składowe typu `int` klasy. 

   - Umieść dane w sekcji prywatnej

   - W sekcji publicznej zaimplementuj:

     - konstruktor sprawdzający, czy mianownik nie jest zerem (niech wówczas wypisze komunikat i/lub zgłosi wyjątek lub w inny sposób zareaguje na błąd) i upraszczający ułamek, jeśli licznik i mianownik mają wspólny dzielnik większy od 1, a także gwarantujący, że mianownik jest zawsze dodatni. 
     - składową stałą `numeratror` zwracającą licznik
     - składową stałą `denominator` zwracającą mianownik

     - `operator*` mnożący ułamek prze ułamek
     - `operator*` mnożący ułamek przez liczbę z prawej strony (czyli np. `ulamek * 2`)
     - `operator+` dodający ułamek do ułamka

     Te trzy operatory powinny w miarę możliwości być zaimplementowane tak, by nie prowokować przepełnienia w typie `int`. 

------

Uwagi.

- Implementacja funkcji  `operator*`  mnożącej ułamek przez liczbę stojącą z lewej strony operatora mnożenia (np. `2 * ulamek`) możliwa jest tylko poza klasą. To wymaga wprowadzenia konstrukcji `friend`. Proszę sobie to zostawić na dalszą naukę.
- Jeżeli potrafisz zaimplementować powyższe dwa operatory, to dasz sobie radę z pozostałymi, szkoda więc (chyba) na nie czasu.

