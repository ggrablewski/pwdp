## Lista zadań nr 7

1. (1 pkt.) Napisz i przetestuj rekurencyjną funkcję `std::string wspak(const std::string&)`, która będzie zwracać swój argument czytany wspak. Czyli np `wspak("Ala ma kota")` powinno zwracać `"atok am alA"`.

2. (2 pkt.) Napisz i przetestuj rekurencyjną funkcję `std::string hex(int n)`, która zwracać będzie liczbę `n` zapisaną w systemie szesnastkowym i poprzedzoną znakami `0x` lub `0X`. Np `hex(10)` powinno zwracać napis `0xa` lub `0XA`, a `hex(33)` powinno zwracać `0x21` lub `0X21`. 
   Wskazówka: wykorzystaj rekurencję do zapewnienia prawidłowej kolejności wyświetlanych znaków.

3. (2 pkt. - powinno być co najmniej 4 pkt., ale wtedy większość studentów zaliczyłaby tę listę na mniej niż 50%, z drugiej strony potrzebne są jakieś wyzwania, prawda?) 
   Zaimplementuj rekurencyjną funkcję 
   `int binsearch(int value, const std::vector<int>& v, int first, int last)`

   która za pomocą [wyszukiwania binarnego](https://pl.wikipedia.org/wiki/Wyszukiwanie_binarne) wyszukuje wartości `value` w uporządkowanej rosnąco tablicy `v` pomiędzy jej indeksami `first` i `last`. Możesz założyć, że `first` i `last` mieszczą się w dopuszczalnym zakresie indeksów tablicy, czyli że $0 \le \mathrm{first}, \mathrm{last} < \mathrm{v.size()}$. Funkcja ta powinna zwracać indeks, pod którym wartość  `value` znajduje się w tablicy `v`, lub `-1`, jeżeli `value` nie ma w `v`. 

   Wskazówka: wyszukiwanie binarne opisane jest w wielu źródłach, w tym na powyżej zalinkowanej stronie w Wikipedii. Większość dostępnych rozwiązań ma charakter iteracyjny (czyli opiera się na jakiejś pętli). Tu chodzi o to, by rozwiązać ten problem za pomocą rekurencji, oczywiście samodzielnie.

   Prosty test formalnej poprawności rozwiązania (ale chodzi jeszcze o efektywność zapewnianą przez wyszukiwanie binarne):

   ```c++
   int main()
   {
       std::vector<int> w = {1, 3, 6, 6, 8, 10, 34, 45, 55, 99, 99};
       std::cout << "w =";
       for (auto n : w)
           std::cout << " " << n;
       std::cout << "\n";
       for (int n : {0, 1, 2, 3, 50, 99, 100})
       {
           auto pos = binsearch(n, w, 0, w.size() - 1);
           if (pos < 0)
               std::cout << "nie znaleziono " << n << " w tablicy 'w'\n";
           else
               std::cout << "znaleziono " << n 
                         << " w tablicy 'w' pod indeksem " << pos << "\n";
       }
   }
   ```

   Spodziewany wynik:

   ```txt
   w = 1 3 6 6 8 10 34 45 55 99 99
   nie znaleziono 0 w tablicy 'w'
   znaleziono 1 w tablicy 'w' pod indeksem 0
   nie znaleziono 2 w tablicy 'w'
   znaleziono 3 w tablicy 'w' pod indeksem 1
   nie znaleziono 50 w tablicy 'w'
   znaleziono 99 w tablicy 'w' pod indeksem 10
   nie znaleziono 100 w tablicy 'w'
   ```

   Generalnie pomysł polega na znalezieniu indeksu mniej więcej w połowie poszukiwanego zakresu. Jeżeli pod tym indeksem znajduje się poszukiwana wartość, to kończymy. Jeśli nie, to dalej sprawdzamy tylko lewą lub prawą "połowę" tablicy, na lewo lub prawo do sprawdzonego indeksu, wykorzystując uporządkowanie liczb w tablicy. Rekurencję kończymy, gdy zakres ma długość 1, a zależnie od Waszej implementacji może to być też 2 (to pozwoli uniknąć pustego, czyli ujemnego zakresu w kolejnym kroku).