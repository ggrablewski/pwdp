## 11.3 Kompilacja programów wykorzystujących SFML

#### 11.3.1 Kompilacja za pomocą CMake

Oto mój plik `CMakeLists.txt`, którego używam do kompilacji programu z poprzedniego punktu (cały projekt - [tutaj](./cpp/w11/sfml30)):

```cmake
cmake_minimum_required(VERSION 3.10)
project(sfml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(sfml sfml.cpp)
target_link_libraries(sfml PRIVATE SFML::Graphics)
```

Z nowych elementów warto omówić:

- Instrukcja `find_package` testuje istnienie określonej biblioteki, tu: SFML, a w przypadku jej znalezienia, konfiguruje kilka zmiennych środowiskowych. Biblioteka może składać się z kilku modułów (ang. *components*). Powyżej zapisana instrukcja `find_package` poszukuje w biblioteki SFML w wersji 3, przy czym do poprawnej kompilacji niezbędna (ang. `REQUIRED`) jest obecność modułu Graphics biblioteki SFML. 
  - Obsługiwane komponenty: `System`, `Window`, `Graphics`, `Network`, `Audio`, `Main`
- Instrukcja `target_link_libraries` informuje `cmake`, że program `sfml` ma być połączony z biblioteką `SFML::Graphics`, przy czym nie jest jej to faktyczna nazwa, a tylko zmienna przechowująca nazwę tej prawdziwej biblioteki. 
  - "Nazwy" dostępnych modułów to  `SFML::System`, `SFML::Window`, `SFML::Graphics`, `SFML::Network`, `SFML::Audio`, `SFML::Main` 

#### 11.3.2 Kompilacja z wiersza poleceń, kompilator `gcc` lub `clang`

  Zakładając, że powyższy program znajduje się w pliku `sfml.cpp`, można go skompilować poleceniem 

```txt
g++ sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
```









