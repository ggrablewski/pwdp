## 5.2 Przykład definiowania i użycia funkcji

Przypomnijmy pierwszy program z poprzedniego wykładu:

```c++
#include <cmath>
#include <fstream>
#include <print>
#include <vector>

int main()
{
    const int length = 250;
    const int height = 250;
    const int max_color = 255;
    const double half_perimeter = length + height;
    const std::string filename = "moj_obrazek_0.pgm";

    std::ofstream out(filename);

    std::vector<std::vector<int>> pixels;
    pixels.resize(height);
    for (int i = 0; i < pixels.size(); i++)
    {
        pixels[i].resize(length);
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < length; x++)
        {
            double normalized_value = double(x + y) / half_perimeter;
            pixels[y][x] = std::round(normalized_value * max_color);
        }
    }

    std::println(out, "P2\n{} {}\n{}", length, height, max_color);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < length; x++)
        {
            out << pixels[y][x] << " ";
        }
        out << "\n";
    }
}
```

Funkcja `main` składa się z kilku logicznie oddzielnych części, z których większość można zrealizować w osobnych funkcjach. W programie oddzieliłem je od siebie pustymi liniami. 

- Definicja i inicjalizacja parametrów programu. Akurat tej części teraz nie będę zmieniał, gdyż wymagałoby to wprowadzenia dodatkowych elementów języka, na co przyjdzie lepsza pora. 
- Otwarcie pliku do zapisu. Akurat to nie jest najlepsze miejsce na tę operację, za chwilę to naprawię.   
- Definicja i inicjalizacja tablicy dynamicznej `pixels`.
- Wypełnienie tablicy `pixels` docelowymi wartościami poziomu intensywności bieli.
- Zapis tablicy `pixels` do pliku w formacie *Plain PGM*.  Tę czynność można logicznie połączyć z otwarciem pliku, co za chwilę uczynię. 

Przekształćmy odpowiednie dragmenty kodu w funkcje.

#### 5.2.1 Definicja i inicjalizacja tablicy przechowującej obraz

Kod oryginalny:

```c++ 
std::vector<std::vector<int>> pixels;
pixels.resize(height);
for (int i = 0; i < pixels.size(); i++)
{
    pixels[i].resize(length);
}
```

Kod odpowiadającej mu funkcji:

```c++
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
```

#### 5.2.2 Wypełnienie tablicy dynamicznej docelowymi wartościami poziomu intensywności bieli

Kod wyjściowy:

```c++
for (int y = 0; y < height; y++)
{
    for (int x = 0; x < length; x++)
    {
        double normalized_value = double(x + y) / half_perimeter;
        pixels[y][x] = std::round(normalized_value * max_color);
    }
}
```

Krótka analiza prowadzi do wniosku, że ten fragment kodu zależy od zmiennych `height`, `length`, `half_perimeter`, `max_color` i `pixels`. Z tym że `half_perimeter` to po prostu `height + length`, więc nie musimy tej wielkości przekazywać jako argument funkci. 

Definicja funkcji:

```c++  
void fill_pixels(std::vector<std::vector<int>>& pixels, int max_color)
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
```

- powyższa funkcja niczego nie zwraca, stąd jako typ jej wartości przyjmujemy `void`. 

- `fill_pixels` to oczywiście jej nazwa

- Przyjmuje ona 2 argumenty omówione już powyżej - nie ma wśród nich wysokości ani szerokości obrazka, gdyż wielkości te można odczytać z tablicy `pixels`.  

- Koniecznie należy zwrócić uwagę na ampersand (`&`) stojący między argumentem `pixels` a jego typem.

  ```c++
  std::vector<std::vector<int>> & pixels
  ```

  Zapis ten oznacza, że funkcja działa na oryginale tej tablicy. Każda jej modyfikacja dokonana przez funkcję jest modyfikacją oryginału. Pozostałe argumenty funkcja otrzymuje w postaci kopii oryginałów. 

- Skoro funkcja nie zwraca wartości, to nie musi zawierać instrukcji `return`.    

#### 5.2.4 Zapis danych (obrazu) do pliku

Kod oryginalny:

```c++
std::println(out, "P2\n{} {}\n{}", length, height, max_color);
for (int y = 0; y < height; y++)
{
    for (int x = 0; x < length; x++)
    {
         out << pixels[y][x] << " ";
    }
    out << "\n";
}
```

Po przerobieniu na funkcję i dodaniu instrukcji otwierającej plik:

```c++
void save_image(const std::vector<std::vector<int>>& pixels, 
                const std::string& filename, 
                int max_color)
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

- Pierwszy i drugi argument tej funkcji przekazywany jest przez stałą referencję (bo w deklaracji widzimy `cosnt` oraz `&`). Moglibyśmy zastosować "zwykłe" przekazanie tych argumentów, bez `const` i bez `&`, jednak program działałby nieco woniej. Stałe referencje są tematem kolejnego wykładu. 

#### 5.2.5 Nowa funkcja `main`

Skoro zamknęliśmy najważniejsze elementy programu w osobnych funkcjach, to możemy ich użyć, by uprościć funkcję `main`:

```c++
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

Tak napisana funkcja ma przejrzystą strukturę. Można by wręcz powiedzieć, że odpowiada ona naturalnemu pseudokodowi:

1. Ustalenie wartości metadanych obrazka: jego wysokości, szerokości, zakresu odcieni szarości, nazwy pliku. 
2. Inicjalizacja bufora danych obrazu
3. Wypełnienie tego bufora danymi
4. Zapisanie bufora w pliku 

Tak rozpisana struktura programu może być zaimplementowana w dowolnym języku programowania. Punktu pierwszego nie przeniosłem do osobnej funkcji, gdyż żeby to zrobić dobrze, musiałbym wprowadzić już teraz kilka dodatkowych cech języka.

Projekt, w którym program z poprzedniego programu został rozbity na funkcje, można pobrać [tutaj](./cpp/w05/functions).

#### 5.2.6 Zalety funkcji

Głównym problemem, przed jakim stoją twórcy oprogramowania, jest jego złożoność. Współczesne programy nierzadko składają się z setek tysięcy a nawet milionów wierszy kodu. Jasne jest, że żaden człowiek nie czytał takiego programu w całości, posługiwać się więc musi kodem w większości przygotowanym przez innych. Główną zaletą funkcji jest to, że umożliwiają one rozbijanie większych problemów na mniejsze i ich, jak to się ładnie mówi w anglomowie, enkapsulację, co słownik tłumaczy jako "kapsułkowanie" lub "hermetyzacja". Chodzi tu o to, że funkcja to jakby czarna skrzynka z dobrze określonym interfejsem. Nie interesuje nas przecież, jak to się dzieje, że `std::cout` wyświetla tekst na ekranie. Interesuje nas interfejs `std::cout` (a więc m.in. operator `<<` i funkcja `std::print`) i odpowiedź na pytanie, w jaki sposób ten interfejs sygnalizuje powodzenie lub ewentualne niepowodzenie zleconej mu operacji. Jak już przygotujemy sobie takie "czarne skrzynki", to możemy z nich potem składać skrzynki większe, z nowym interfejsem. Z nich jeszcze większe. I każdej z nich używać w różnych kontekstach i do różnych celów. Taki podział

- Ułatwia wielokrotne stosowanie tego samego kodu (nie musimy od nowa wymyślać np. jak wyznaczyć pierwiastek kwadratowy z jakiejś liczby).
- W szczególności, bardzo przyspiesza kompilację kodu
  - Kodu raz skompilowanego nie trzeba kompilować ponownie

- Ułatwia czy wręcz umożliwia handel oprogramowaniem jako produktem zamkniętym (bez udostępniania klientowi kodu źródłowego swojego produktu). 
- Ułatwia testowanie kodu. Testowanie czarnych skrzynek różnej wielkości jest znacznie łatwiejsze i mniej pracochłonne niż testowanie milionów wierszy kodu. W gruncie rzeczy wystarczy bowiem testować, czy funkcja dla określonych parametrów wejściowych zawsze zwraca to, czego od niej oczekujemy. Co więcej, skrzynek raz przetestowanych nie trzeba testować ponownie. Nikt, poza twórcami biblioteki standardowej, nie testuje jej w swoich programach, choć oczywiście testujemy sposoby połączenia naszego programu z tą biblioteką. 
- Ułatwia zagwarantowanie, że nasz program jest poprawny. 
- Gwałtownie przyspiesza proces tworzenia oprogramowania, jednocześnie dramatycznie redukując koszt jego wytwarzania i zwłaszcza jego późniejszego utrzymania.

