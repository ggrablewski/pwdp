## 3.1.1 Operator `? :` 

Czasami w programie zachodzi potrzeba warunkowego przypisania wartości jakiejś zmiennej. Innymi słowy, przypisania jednej z dwóch wartości zależnie od tego, czy jakiś warunek jest, czy nie jest spełniony. W języku C++ służy do tego trójargumentowy operator `? :`.

Powiedzmy, że chcemy, by rozmiar jakiejś tablicy zależał od tego, czy wartość zmiennej `n` jest mniejsza czy większa lub równa 0. Możemy to napisać tak:

```c++  
int rozmiar;
if (n < 0)
    rozmiar = 100;
else
    rozmiar = 1000;
```

To samo przy pomocy operatora warunkowego `? :` można zapisać znacznie krócej:

```c++
int rozmiar = (n < 0) ? 100 : 1000;
```

- pierwszym argumentem operatora `? :` jest wyrażenie logiczne (warunek). Zwykle nie musi być ono ujmowane w nawiasy, ale powiedzmy, że to dobry zwyczaj programistyczny. 
- drugim argumentem jest wartość wyrażenia, jeżeli warunek jest spełniony
- trzecim argumentem jest wartość wyrażenia, jeżeli warunek nie jest spełniony

Mogłoby się wydawać, że operator `? :` to tylko sposób na mniej pisania. Nie. W niektórych kontekstach jest niezastąpiony. Na przykład gdy chcemy zdefiniować stałą o wartości zależnej od jakiegoś warunku. przykład:

```c++
const int rozmiar = (n < 0) ? 100 : 1000;
```

Powyższej definicji stałej `rozmiar` nie da się zapisać za pomocą instrukcji `if` (czy wiesz dlaczego?).
