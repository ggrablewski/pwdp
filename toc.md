# Praktyczny wstęp do programowania 

## Spis treści

### 1. Preliminaria

- [Wstęp](./00-wstep.md)
- [Pierwszy program w C++](./01-pierwszy-program.md)
- [Narzędzia](./01-narzedzia.md)
  - [Instalacja i konfiguracja programu QtCreator](./01-qtcreator.md)
  - [Wprowadzenie do systemu CMake](./01-cmake.md)
  - [Debuger](./01-debugger.md)
- [Lista zadań nr 0](./listy/lista1.md)

### 2. Operacje wejścia-wyjścia; typy arytmetyczne i std::string

- [C++ jest językiem ze statyczną kontrolą typów](./02-statyczna-kontrola-typow.md)
- Deklarowanie i używanie zmiennych typu `int`, `double`, `std::string`, `char`
- Zakres zmiennej; operator pobrania adresu
- Standardowy strumień wejścia: `std::cin`
- Standardowy strumień wyjścia: `std::cout`
- Nowoczesna obsługa standardowego strumienia wyjścia: `std::format` i `std::print`
- lista zadań nr 1 

### 3. Instrukcje if, if-else, switch; pętle; tablice, std::array, std::vector

- Instrukcje warunkowe
  - `if`
  - `if-else`
  - `switch`
- Pętle
  - `for`
  - `for` "w stylu Javy"
  - `while`
  - `do`-`while`
- Tablice
  - Tablice "w stylu C"
  - `std::array`
  - `std::vector`
- Lista zadań nr 2

### 4. Operacje na plikach. Przykład: pliki graficzne w formacie PGM

- Pliki kontrolujemy za pomocą obiektów
  - `std::ifstream`
  - `std::ofstream`
- Format PGM
- Lista zadań nr 3

### 5. Funkcje; deklaracja, definicja. Pliki nagłówkowe i źródłowe. Projekty

- Co to jest funkcja?
- Deklaracja funkcji
- Definicja funkcji
- Interfejs i implementacja, czyli pliki nagłówkowe i źródłowe
- W stronę projektów i bibliotek
- Lista zadań nr 4

### 6. Argumenty funkcji; wskaźnik i referencja

- Przekazywanie argumentów przez wartość
- Przekazywanie argumentów przez referencję
- Przekazywanie argumentów przez stałą referencję
- Przekazywanie argumentów przez wskaźnik - operator wyłuskania wartości
- Używanie funkcji z argumentami wskaźnikowymi - operator pobrania adresu 
- Lista zadań nr 5

### 7. Funkcje rekurencyjne

- Przykłady funkcji rekurencyjnych
- Co to jest stackoverflow?
- Debugowanie programów z funkcjami rekurencyjnymi
- Lista zadań nr 6

### 8. Struktury i klasy

- Struktura
- Klasa jako proste rozszerzenie struktury
  - konstruktor, destruktor
  - funkcje składowe
  - sekcje prywatne i publiczne
- Lista zadań nr 7

### 9. Szablony i wyjątki

- Dlaczego typ danych przechowywanych w `std::vector` zapisywany jest w nawiasach ostrokątnych?
- Prosty przykład szablonu
- Co robić, gdy jakiś fragment programu zgłosi wyjątek? 

### 10. Bitowa reprezentacja typów całkowitoliczbowych. Operacje bitowe. Pliki tekstowe: kodowanie ASCII i UTF-8



### 11. Biblioteki. Przykład: SFML

### 12. Biblioteki. SFML

### 13. Biblioteki. Przykład: Qt

### 14. Biblioteki. Qt

### 15. Przykład programu: fraktal Mandelbrota











### Nieobiektowe jądro języka

- [Typy wbudowane](./02-typy-wbudowane.md)

- [Elementarne operacje na typach wbudowanych](./03-elementarne-operacje.md)

- [Arytmetyka liczb zmiennopozycyjnych](./04-arytmetyka-zmiennopozycyjna.md)

- [Tablice](05-tablice.md)
- [Wskaźniki](./06-wskazniki.md)
  - [`qsort` w akcji](06a-qsort.md)

- Instrukcje złożone
  - instrukcja warunkowa (if)
  - pętla for
  - pętla while
  - pętla do ... while
  - instrukcja switch

- [Struktury](./07-struktury.md)
- [Referencje](./08-referencje.md)
- [Funkcje](./08-funkcje.md)
  - [Definicja i deklaracja funkcji](./08a-deklaracja-i-definicja.md)
  - [Reguła ODR](./08b-regula-ODR.md)

  - [Przekazywanie argumentów do funkcji](./08c-argumenty-funkcji.md)

  - [Wartość funkcji](./08d-wartosc-funkcji.md)

  - [Argumenty domyślne funkcji](./08e-argumenty-domyslne.md)

  - [Operatory jako funkcje](./08o-operatory.md)

  - [Funkcje `inline`](./08f-funkcje-inline.md)

  - [Funkcja `main`](./08g-funkcja-main.md)

  - [Funkcje statyczne](./08h-funkcje-statyczne.md)

  - [Stos wywołań funkcji (*call stack*)](./08i-call-stack.md)

- 
