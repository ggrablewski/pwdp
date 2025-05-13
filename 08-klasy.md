## 8.2 Klasa jako rozszerzenie struktury

W poprzednim rozdziale przedstawiłem kilka prostych przykładów struktur. Okazuje się, że strukturę można bardzo łatwo zamienić na klasę, która jest w C++ podstawowym mechanizmem definiowania typów użytkownika. W tym celu wystarczy słowo kluczowe `struct` zamienić na inne słowo kluczowe, `class`, i już mamy klasę. Czyli jeśli mamy strukturę `Pixel`:

```c++   
struct Pixel
{
    int x;
    int y;
};
```

to możemy zamienić ją na klasę w bardzo prosty sposób:

```c++
class Pixel
{
    int x;
    int y;
};
```

Czy jest to klasa spełniająca wszystkie warunki, jakie na definicje klasy nakłada standard C++? Tak. Tej klay można użyć do utworzenia obiektu:

```c++
int main()
{
    Pixel p;  
}
```

Czy jest ona użyteczna? Nie, tak zdefiniowana klasa jest póki co całkowicie bezużyteczna, gdyż z tak zdefiniowanym obiektem nic nie można zrobić. Czegoś nam jeszcze brakuje i o tym czymś traktować będą kolejne części tego wykładu.