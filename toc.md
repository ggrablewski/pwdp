# Praktyczny wstęp do programowania 

## Spis treści

### 1. Preliminaria

- [Wstęp](./00-wstep.md)
- [Pierwszy program w C++](./01-pierwszy-program.md)
- [Narzędzia](./01-narzedzia.md)
  - [Instalacja i konfiguracja programu QtCreator](./01-qtcreator.md)
  - [Wprowadzenie do systemu CMake](./01-cmake.md)
  - [Debuger](./01-debugger.md)
- [Lista zadań nr 1](./listy/lista1.md)

### 2. Operacje wejścia-wyjścia; typy arytmetyczne i `std::string`

- [C++ jest językiem ze statyczną kontrolą typów. Definicje i deklaracje](./02-statyczna-kontrola-typow.md)
- [Zmienne typu `int`, `double`, `std::string`, `char`, `bool`](./02-typy-wbudowane.md)
- [Zakres zmiennej. Operator pobrania adresu. Przestrzeń nazw](./02-zakres.md)
- Podstawowe operacje wejścia-wyjścia
  - [Standardowy strumień wejścia: `std::cin`](./02-cin.md)
  - [Standardowy strumień wyjścia: `std::cout`](./02-cout.md)
  - [Nowoczesna obsługa standardowego strumienia wyjścia: `std::format` i `std::print`](./02-format-print.md)

- [lista zadań nr 2](./listy/lista2.md) 

- [Dodatek](02-dodatek.md): co robić, gdy `std::format` lub `std::print` nie działa

  - [fmtlib](02-fmtlib.md)

### 3. Instrukcje warunkowe; pętle; tablice, `std::array`, `std::vector`

- [Instrukcje i wyrażenia warunkowe](./03-wyrazenia-warunkowe.md)
  - [`if`](./03-if.md)
  - [`switch`](./03-switch.md)
  - Operator [`? :`](./03-wyr-warunkowe.md)
- [Pętle](03-loops.md)
  - [`for`](./03-for.md)
  - [`while` i `do`-`while`](./03-while.md)
  - [instrukcje `break` i `continue`](./03-break.md)
- [Tablice](./03-tablice.md)
- [Lista zadań nr 3](./listy/lista3.md)

### 4. Operacje na plikach. Przykład: pliki graficzne w formacie PGM

- [Pliki kontrolujemy za pomocą obiektów](./04-pliki.md)
- [Format PGM](./04-pgm.md)
- [Czytanie każdego znaku](./04-get.md)
- [Lista zadań nr 4](./listy/lista4.md)

### 5. Funkcje; deklaracja, definicja. Pliki nagłówkowe i źródłowe. Projekty

- [Co to jest funkcja? Deklaracja i definicja funkcji](05-funkcje.md)
- [Przykład](./05-example1.md)
- [Interfejs i implementacja, czyli pliki nagłówkowe i źródłowe](05-interfejs-implementacja.md)
- [W stronę projektów i bibliotek](./05-projekty-biblioteki.md)
- [Kolejne przykłady](05-example2.md)
- [Lista zadań nr 5](./listy/lista5.md)

### 6. Argumenty funkcji; wskaźnik i referencja

- [Przekazywanie argumentów przez wartość](06-arg-value.md)
- [Przekazywanie argumentów przez referencję](06-arg-reference.md)
- [Przekazywanie argumentów przez stałą referencję](06-arg-const-reference.md)
- [Przekazywanie argumentów przez wskaźnik i operator wyłuskania wartości](06-arg-pointer.md)
- [Używanie funkcji z argumentami wskaźnikowymi - operator pobrania adresu](06-arg-pointer-usage.md)
- [Przekazywanie funkcji jako argumentów funkcji](06-arg-function.md)
- [Argumenty funkcji `main`](06-arg-main.md)
- [Lista zadań nr 6](./listy/lista6.md)

### 7. Funkcje rekurencyjne

- Przykłady funkcji rekurencyjnych
- Co to jest *stack overflow*?
- Debugowanie programów z funkcjami rekurencyjnymi
- Lista zadań nr 7

### 8. Struktury, klasy i obiekty

- Struktura
- Klasa jako proste rozszerzenie struktury
  - konstruktor, destruktor
  - funkcje składowe
  - sekcje prywatne i publiczne
- Obiekt
- Lista zadań nr 8

### 9. Szablony i wyjątki

- Dlaczego typ danych przechowywanych w `std::vector` zapisywany jest w nawiasach ostrokątnych?
- Prosty przykład szablonu
- Co robić, gdy jakiś fragment programu zgłosi wyjątek? 

### 10. Bitowa reprezentacja typów całkowitoliczbowych. Operacje bitowe. Pliki tekstowe: kodowanie ASCII i UTF-8

### 11. Biblioteki: SFML

- [Krótkie wprowadzenie do SFML](./11-SFML-intro.md)
- [Prosty program w SFML](./11-SFML-pierwszy.md)
- [Kompilacja programów wykorzystujących SFML](./11-SFML-kompilacja.md)
- [Lista zadań nr 11](listy/lista11.md) 

### 12. Biblioteki: SFML (2)

### 13. Biblioteki: Qt

### 14. Biblioteki: Qt (2)

### 15. Przykład programu: fraktal Mandelbrota

### Zagadnienia egzaminacyjne 

