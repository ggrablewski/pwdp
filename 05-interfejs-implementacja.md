## 5.3 Interfejs i implementacja, czyli pliki nagłówkowe i źródłowe

Skoro już doszliśmy do zamykania (hermetyzacji, enkapsulacji, kapsułkowania) kodu w funkcjach, należy wyjaśnić, w jaki sposób duże programy dzielone są na części i jak z tych części korzystać. 

Kod programów chcemy umieścić w wielu plikach, które będziemy kompilować i testować oddzielnie. Oczywiście podział ten robimy z głową i np. osobno grupujemy kod odpowiedzialny za operacje wejścia i wyjścia, osobno interfejs użytkownika, osobno obsługę baz danych itp. W jaki sposób możemy podpowiedzieć kompilatorowi, że kompiluje on tylko fragment większej całości, zachowując przy tym fundamentalną zasadę języka C++, że jest to język z silną statyczną kontrolą typów? Innymi słowy, jak przekazać do pliku A informację, że można w nim używać funkcji `f_b` zdefiniowanej w innym pliku, powiedzmy, B? Z pomocą przychodzi kolejna zasada, że w programie może istnieć dowolna (większa od zera) liczba deklaracji danej funkcji i że wystarczy jedna deklaracja, by danej funkcji można było używać. Dlatego dla każdego pliku z kodem źródłowy, tworzy się drugi plik, zawierający jego interfejs. Pierwszy z nich nazywamy implementacją, a drugi - interfejsem (jakiejś funkcjonalności). Implementację z reguły umieszczamy w plikach z rozszerzeniem `cpp`, tzw. plikach źródłowych, a interfejsy - w plikach z rozszerzeniem `*.h` zwanych plikami nagłówkowymi (ang. *header files*) lub po prostu nagłówkami. Nagłówki są jak nagłówki prasowe - zapowiadają, co znajduje się w kodzie / artykule. Uwaga: od powyższej zasady istnieją liczne wyjątki, ale o tym później. 

Spójrzmy na poniższy przykład, w którym program z poprzedniego podrozdziału ([5.2](./cpp/w05/functions)) podzieliłem na 3 pliki:

- `pgm.cpp` - plik z kodem (implementacją) obsługi formatu *Plain PGM*.
- `pgm.h` - plik z interfejsem pliku `pgm.cpp`
- `main.cpp` - program korzystający z kodu zawartego w `pgm.cpp`. 

​     