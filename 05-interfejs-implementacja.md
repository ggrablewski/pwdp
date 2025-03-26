## 5.3 Interfejs i implementacja, czyli pliki nagłówkowe i źródłowe

Skoro już doszliśmy do zamykania (hermetyzacji, enkapsulacji, kapsułkowania) kodu w funkcjach, należy wyjaśnić, w jaki sposób duże programy dzielone są na części i jak z tych części korzystać. 

Kod programów chcemy umieścić w wielu plikach, które będziemy kompilować i testować oddzielnie. Oczywiście podział ten robimy z głową i np. osobno grupujemy kod odpowiedzialny za operacje wejścia i wyjścia, osobno interfejs użytkownika, osobno obsługę baz danych itp. W jaki sposób możemy podpowiedzieć kompilatorowi, że kompiluje on tylko fragment większej całości, zachowując przy tym fundamentalną zasadę języka C++, że jest to język z silną statyczną kontrolą typów? Innymi słowy, jak przekazać do pliku A informację, że można w nim używać funkcji `f_b` zdefiniowanej w innym pliku, powiedzmy, B? Z pomocą przychodzi kolejna zasada, że w programie może istnieć dowolna (większa od zera) liczba deklaracji danej funkcji i że wystarczy jedna deklaracja, by danej funkcji można było używać. Dlatego dla każdego pliku z kodem źródłowy, tworzy się drugi plik, zawierający jego interfejs. Pierwszy z nich nazywamy implementacją, a drugi - interfejsem (jakiejś funkcjonalności). Implementację z reguły umieszczamy w plikach z rozszerzeniem `cpp`, tzw. plikach źródłowych, a interfejsy - w plikach z rozszerzeniem `*.h` zwanych plikami nagłówkowymi (ang. *header files*) lub po prostu nagłówkami. Nagłówki są jak nagłówki prasowe - zapowiadają, co znajduje się w kodzie / artykule. Uwaga: od powyższej zasady istnieją liczne wyjątki, ale o tym później. 

Spójrzmy na poniższy przykład, w którym program z poprzedniego podrozdziału ([5.2](./cpp/w05/functions)) podzieliłem na 3 pliki:

- `pgm.cpp` - plik z kodem (implementacją) obsługi formatu *Plain PGM*.
- `pgm.h` - plik z interfejsem pliku `pgm.cpp`
- `main.cpp` - program korzystający z kodu zawartego w `pgm.cpp`.

Projekt z omawianymi tu plikami można pobrać [tutaj](./cpp/w05/interfaces/).   

#### Plik 5.3.1 `pgm.h`

Zasadniczo pliki nagłówkowe zawierają wyłącznie deklaracje, jak na poniższym przykładzie:

```c++ 
#ifndef PGM_H
#define PGM_H

#include <string>
#include <vector>

std::vector<std::vector<int>> init_pixels(int width, int height);
void fill_pixels(std::vector<std::vector<int>>& pixels, int max_color);
void save_image(const std::vector<std::vector<int>>& pixels, 
                const std::string& filename, int max_color);

#endif  // PGM_H
```

Istnieją ważne wyjątki od tej reguły (szablony i funkcje *inline*), ale póki co zostajemy przy konwencji, że w plikach nagłówkowych znajdują się czyste interfejsy, czyli wyłącznie deklaracje. 

##### 5.3.1.1 Wartownik pliku nagłówkowego

W powyższym przykładzie plik nagłówkowy zaczyna się od makrodefinicji `#ifndef` i `#define`, a kończy makrodefinicją `endif`. Te trzy makroinstrukcje tworzą wspólnie tzw. wartownika pliku nagłówkowego i są charakterystycznym elementem plików nagłówkowych w języku C++ (oraz C). Makro definiowane w `#define` zwykle powiela pisaną wielkimi literami nazwę pliku, z podkreślnikiem zastępującym kropkę (tu: nazwę `pgm.h` zastępuje makro `PGM_H`). Chodzi o to, by w całym programie nie wystąpiły dwa makra o tej samej postaci. Celem wprowadzania wartownika jest uniemożliwienie wielokrotnego włączania tego samego kodu w tej samej jednostce kompilacji. Idea jest taka, że gdy kompilator po raz pierwszy "zabaczy" dany plik nagłówkowy podczas kompilacji właczającego go pliku `*.cpp `, to stwierdzi, że nie zna makra sterującego wartownikiem (tu: `PGM_H`) i wczyta zawartość pliku nagłówkowego, przy okazji definiując makro wartownika (`#define PGM_H`). W przypadku kolejnej próby włączenia do programu tego samego pliku nagłówkowego, kompilator stwierdzi, że makro wartownika już widział i pominie cały kod aż do makroinstrukcji `#endif`.       

#### Plik 5.3.2 `pgm.cpp`

Plik `pgm.cpp` zawiera po prostu definicje wszystkich funkcji zadeklarowowanych w `pgm.h` :

```c++
#include "pgm.h"

#include <cmath>
#include <fstream>

std::vector<std::vector<int>> init_pixels(int width, int height)
{
    std::vector<std::vector<int>> pixels;
    pixels.resize(height);
    for (int i = 0; i < pixels.size(); i++)
    {
        pixels[i].resize(width);
    }
    return pixels;
}

void fill_pixels(std::vector<std::vector<int>> &pixels, int max_color)
{
    const int height = pixels.size();
    const int width = pixels[0].size();
    const double half_perimeter = width + height;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double normalized_value = double(x + y) / half_perimeter;
            pixels[y][x] = std::round(normalized_value * max_color);
        }
    }
}

void save_image(const std::vector<std::vector<int>> &pixels, const std::string &filename, int max_color)
{
    int height = pixels.size();
    int width = pixels[0].size();

    std::ofstream out(filename);
    std::println(out, "P2\n{} {}\n{}", width, height, max_color);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            out << pixels[y][x] << " ";
        }
        out << "\n";
    }
}
```

- Jeżeli plikowi źródłowemu (*.cpp) towarzyszy plik nagłówkowy, to jego pierwszą instrukcją jest makroinstrukcja `#include` włączająca ten nagłówek.    

  ```c++
  #include "pgm.h"
  ```

#### 5.3.3 Plik `main.cpp` 

Po przeniesieniu większości kodu do pliku `pgm.cpp`, plik `main.cpp` ulega drastycznemu uproszczeniu:

```c++
#include <print>
#include <string>

#include "pgm.h"

int main()
{
    const int width = 250;
    const int height = 250;
    const int max_color = 255;
    const std::string filename = "fun_obrazek.pgm";

    auto pixels = init_pixels(width, height);
    fill_pixels(pixels, max_color);
    save_image(pixels, filename, max_color);
 
    std::println("Image has been written to \"{}\"", filename);
}
```

#### 5.5.3 Wady i zalety podziału programu na funkcje i pliki 

Podział nawet tak krótkiego programu na części i wydzielone do osobnych plików posiada jedną wadę: wymaga dodatkowego wysiłku. Ma też jednak kilka zalet.

- Znacznie łatwiej testować poprawność krótkich fragmentów kodu niż fragmentów długich

- Znacznie łatwiej jest zrozumieć logikę programu, jeśli operuje on na wyższym poziomie abstrakcji, jaki oferują funkcje. Tezę tę łatwo można zilustrować przykładem tego, co się dzieje, gdy poziom abstrakcji zamiast zwiększać, obniżamy. Rozpatrzmy jedną instrukcję z funkcji`fillpixels`: 

  ```asm    
   double normalized_value = double(x + y) / half_perimeter;
  ```

  Na poziomie asemblera wygląda ona następująco:

  ```asm
  mov     edx, DWORD PTR [rbp-52]
  mov     eax, DWORD PTR [rbp-56]
  add     eax, edx
  pxor    xmm0, xmm0
  cvtsi2sd        xmm0, eax
  divsd   xmm0, QWORD PTR [rbp-40]
  movsd   QWORD PTR [rbp-32], xmm0
  ```

  Czy łatwiej się czyta i analizuje niskopoziomowy kod w asemblerze, czy wysokopoziomowy kod w C++? A przecież można zejść jeszcze niżej, do kodu maszynowego. Ta sama instrukcja może bowiem wyglądać w nim tak (każdemu wierszowi asemblera odpowiada wiersz kodu maszynowego i386):

  ```txt 
  8b 55 d4 
  8b 45 d0      
  01 d0         
  66 0f ef c0   
  f2 0f 2a c0   
  f2 0f 5e 45 e0
  f2 0f 11 45 e8
  ```

  lub nawet tak:

  ```txt 
  8b55d48b45d001d0660fefc0f20f2ac0f20f5e45e0f20f1145e8
  ```

Proszę sobie teraz wyobrazić pisanie w asemblerze (nie mówiąc już o kodzie maszynowym) programów, w których kod wykonywalny liczy sobie dziesiątki czy nawet setki megabajtów! 

Im większy projekt, tym większe korzyści z jego podziału:

- Przyspieszenie czasu kompilacji podczas rozwijania aplikacji (powtórnej kompilacji wymagają wyłącznie pliki, które zmieniono od poprzedniej kompilacji)
- Możliwość tworzenia bibliotek (skompilowany kod + interfejsy)
- Relatywna łatwość w modyfikowaniu, testowaniu i późniejszym utrzymaniu kodu
- Możliwość używania tej samej bazy kodu w różnych kontekstach i przez różnych użytkowników.

Język C++ to język zorientowany na biblioteki. Pisze się je w nim łatwo, łatwo również się je wykorzystuje.  

#### 5.5.5 Kompilacja

Najprostszy sposób kompilacji programu podzielonego na części polega na "jednoczesnym" kompilowaniu wszystkich plików źródłowych (czyli tych z rozszerzeniem `.h`). W naszym przypadku mogłoby to wyglądać tak:

```txt
> g++ main.cpp pgm.cpp
```

- plików nagłówkowych ( `*.h` ) nie kompiluje się!

Ten sposób kompilacji nie ma jednak sensu, jeśli kompilacja zajmuje więcej niż kilka sekund, a my akurat coś w naszym programie ulepszamy. Kompilacja dużych programów może zajmować godziny i całkowicie w tym czasie blokować komputer (wielowątkowa kompilacja niektórych programów może zająć niemal całą pamięć operacyjną komputera!). Znacznie rozsądniej jest kompilować tylko to, co uległo zmianie od poprzedniej kompilacji (oraz wszystko to, co zależy od czegoś, co uległo zmianie). Istnieje wiele programów realizujących właśnie ten jeden cel: efektywną kompilację programów napisanych w C++. Omówię je w kolejnym rozdziale.