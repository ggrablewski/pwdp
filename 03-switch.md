## 3.1.2 Instrukcja `switch`

Instrukcja `switch` jest spotykana w programach stosunkowo rzadko. Dlatego tu omówię ją skrótowo.

Zacznijmy od przykładu:

```c++  
int n = 2;
// jakiś kod ustalający/zmieniający wartość n
switch(n)
{
    case 0: 
        std::cout << "n = 0\n";
        break;
    case 1: 
        std::cout << "n = 1\n";
        break;
    case 2: 
        std::cout << "n = 2\n";
        break;
    case 4: 
    case 5:
        std::cout << "n = 4 lub n = 5\n";
        break;
    default: throw std::logic_error("Błąd: nieoczekiwana wartość n"); 
}
```

- Argumentem `switch` musi być wyrażenie o wartości całkowitej (często jest to zmienna typu całkowitego, np. `int`). Tu jest nim `n`. 
- W bloku ujętym w klamry występuje seria etykiet `case` i - opcjonalnie - co najwyżej jedna etykieta `default`
- Po każdym `case` występuje liczba całkowita i dwukropek. Kompilator sprawdza wartość argumentu `switch`, po czym generuje instrukcję skoku do instrukcji stojącej tuż za etykietą z  wartością identyczną jak po etykiecie `case`. 
- Jeżeli takiej etykiety nie ma, generowany jest skok do instrukcji za etykietą `default`
- Jeżeli etykieta `default` nie występuje i żadna z wartości etykiet nie pasuje do wartości argumentu `switch`,  generowany jest skok za tę instrukcję (czyli `switch` jest jakby pomijane).
- Etykiety można łączyć - jak w powyższym przykładzie dla `n` = 4 i 5.
- Kod stowarzyszony z każdą etykietą należy kończyć instrukcją `break`, chyba że jesteśmy doświadczonymi programistami i wiemy, jakie to będzie ze sobą nieść konsekwencje. 
  - ostatni `break` w powyższym kodzie jest zbędny, ale też nie szkodzi.