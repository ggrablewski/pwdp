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
  - `std::ifstream`
  - `std::ofstream`
- Format PGM
- Lista zadań nr 4

### 5. Funkcje; deklaracja, definicja. Pliki nagłówkowe i źródłowe. Projekty

- Co to jest funkcja?
- Deklaracja funkcji
- Definicja funkcji
- Interfejs i implementacja, czyli pliki nagłówkowe i źródłowe
- W stronę projektów i bibliotek
- Lista zadań nr 5

### 6. Argumenty funkcji; wskaźnik i referencja

- Przekazywanie argumentów przez wartość
- Przekazywanie argumentów przez referencję
- Przekazywanie argumentów przez stałą referencję
- Przekazywanie argumentów przez wskaźnik - operator wyłuskania wartości
- Używanie funkcji z argumentami wskaźnikowymi - operator pobrania adresu 
- Lista zadań nr 6

### 7. Funkcje rekurencyjne

- Przykłady funkcji rekurencyjnych
- Co to jest stackoverflow?
- Debugowanie programów z funkcjami rekurencyjnymi
- Lista zadań nr 7

### 8. Struktury i klasy

- Struktura
- Klasa jako proste rozszerzenie struktury
  - konstruktor, destruktor
  - funkcje składowe
  - sekcje prywatne i publiczne
- Lista zadań nr 8

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

