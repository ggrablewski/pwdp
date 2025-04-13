## 6.5 Używanie funkcji z argumentami wskaźnikowymi - operator pobrania adresu

Funkcje z argumentami wskaźnikowymi wywołujemy w charakterystyczny sposób - przekazując do nich adresy zmiennych a nie same zmienne, jak to ma miejsce w przypadku przekazywania argumentów przez wartość lub referencję.

Spójrzmy raz jeszcze na przykład z poprzeniego rozdaiału:

 ```c++
 int square(int* p)
 {
     return *p * *p; 
 }
 ```

Funkcję tę można by w programie wywołać tak:

```c++
int n = 8;
std::cout << square(&n) << "\n";
```

W tym przypadku argumentem funkcji `square` w punkcie jej wywołania jest `&n`, czyli adres zmiennej `n`. 

Oczywiście, funkcję tę można by też wywołać w następujący sposób:

```c++
int n = 8;
int* p = &n;
std::cout << square(p) << "\n";
```

Tak czy owak, bez operatora pobrania adresu, `&`, się tu nie obejdzie. 