## Lista zadań nr 6

1. (2 pkt) Zgodnie z [twierdzeniem Goldbacha-Eulera](https://en.wikipedia.org/wiki/Goldbach%E2%80%93Euler_theorem), 
   ![{\displaystyle \sum _{p}^{\infty }{\frac {1}{p-1}}={{\frac {1}{3}}+{\frac {1}{7}}+{\frac {1}{8}}+{\frac {1}{15}}+{\frac {1}{24}}+{\frac {1}{26}}+{\frac {1}{31}}}+\cdots =1.}](https://wikimedia.org/api/rest_v1/media/math/render/svg/7d7d718001b4c250e49c7858fb8574e8286de851)
   gdzie suma przebiega po wszystkich liczbach naturalnych $p$ będących [doskonałymi potęgami](https://en.wikipedia.org/wiki/Perfect_power) większymi od 1. Listę doskonałych potęg $\le 1000$ można znaleźć w Encyklopedii ciągów pod numerem [A001694](https://oeis.org/A001694). Można też je wygenerować komputerowo. W tym celu zaimplementuj dwie funkcje, `perf_pow` i `special_sum` tak, aby poniższy program wyznaczał 

   - sumę $$\displaystyle \sum_{p \in S(N)} \frac{1}{p-1}$$ , gdzie $S(N)$ to zbiór doskonałych potęg $p$ takich, że $2 \le p \le N$
   - odległość tej sumy do wartości granicznej 1. 

   A to wszystko dla $N = 10^0, 10^1, \ldots, 10^7$, 

   ```c++
   int main()
   {
       for (int n = 10; n <= 10'000'000; n *= 10)
       {
           std::set<int> perf_pow = perfect_powers(n);
           double sum = special_sum(perf_pow);
           std::cout << n << "\t" << sum << "\t" << 1.0 - sum << "\n";
       }
   }
   ```

   - funkcja `perfect_powers(N)` powinna zwracać zbiór (`std::set<int>`) doskonałych potęg większych od 1 i mniejszych lub równych `N` .
   - funkcja `special_sum` powinna wyznaczać sumę $$\displaystyle \sum_{p\in S(N)} \frac{1}{p-1} $$ , gdzie $S(N)$ to zbiór doskonałych potęg z przedziału $[2, N]$ otrzymany za pomocą funkcji `perfect_powers`.

   Uwagi. 

   - `std::set<int>`  to standardowy kontener C++ (`#include <set>`) służący do przechowywania liczb typu `int`, przy czym, podobnie jak w zbiorach znanych z matematyki, każdy element jest unikatowy, tzn. wszystkie wartości przechowywane w `std::set<int>` są różne.

   - Jeżeli zdefiniujemy kontener `s`  instrukcją `std::set<int> s;`, to nowe elementy dodajemy do niego funkcją składową ("po kropce") `insert`, np. `s.insert(2)`, `s.insert(n)` itp. Powtórne dodanie tego samego elementu nie powoduje żadnego efektu (`std::set` przechowuje tylko jeden element o danej wartości). 

   - Jeżeli zdefiniujemy kontener `s`  instrukcją `std::set<int> s;`, to możemy wypisać wszystkie jego elementy w pętli 

     ```c++    
     for (int n : s)
         std::cout << n << "\n";  // ogólnie: n przebiega wszystkie elementy s
     ```

     Zmieniając treść tej pętli, można łatwo zaimplementować funkcję `special_sum`

   - Pierwsze 3 wiersze wyświetlane przez moje rozwiązanie tego zadania wyglądają następująco:

     ```txt
     10		0.60119		0.39881
     100		0.868122	0.131878
     1000	0.962427	0.0375734
     ```

   - Jeżeli w Twoim rozwiązaniu w trzeciej kolumnie ujrzysz liczby ujemne, to masz błąd.   

2. (2 pkt) Zaimplementuj funkcję `trapez` wyznaczającą numeryczne przybliżenie wartości całki z dowolnej funkcji w dowolnym skończonym przedziale. Funkcja ma mieć 4 argumenty:

   - całkowaną funkcję (`f`)
   - początek przedziału całkowania (`a`)
   - koniec przedziału całkowania (`b`)
   - liczbę trapezów, którymi przybliżamy wykres funkcji (`N`)

   Metoda trapezów opisana jest m.in. w Wikipedii [angielskiej](https://en.wikipedia.org/wiki/Trapezoidal_rule) i [polskiej](https://pl.wikipedia.org/wiki/Wz%C3%B3r_trapez%C3%B3w). W skrócie, chodzi o wyznaczenie sumy 

   $${\displaystyle \int \limits _{a}^{b}f(x)\,dx\approx {\frac {b-a}{{2}{N}}}\left(f(x_{0})+f(x_{N})+2f(x_{1})+\ldots +2f(x_{N-1})\right).}$$ 

   w której $f$ to całkowana funkcja, $a$ i $b$ to początek i koniec przedziału całkowania, a $x_k = a + hk$ dla $k=0,1,\ldots,N$, gdzie $h = (b-a)/N$. Z powyższego wynika też, że  $x_0 = a$ i $x_N = b$, 

   - Zastosuj swoje rozwiązanie do znalezienia wartości całek

     - $$\int_0^1 x \, dx$$
     - $$\int_0^1 x^2 \, dx$$
     - $$\int_0^1 x^3 \, dx$$
     - $$\pi^{-1}\int_0^\pi \sin^2(x) \, dx$$

     dla kilku wartości $ h = (b-a)/N$. Czy wiesz, dlaczego ostatnią z powyższych całek tak łatwo i tak dokładnie można wyznaczyć metodą trapezów?
