## Lista zadań nr 3 

1. (1 pkt.) Napisz program, który wczyta słowo, po czym wypisze je w wspak. Np po wczytaniu "Ala", program ten powinien wypisać słowo "alA". Wskazówka: obiekty klasy `std::string` można traktować jak tablice znaków (czyli stosować na nich operartor `[]`).

2. (1 pkt.) Napisz program, który wyznaczy przybliżenie `s` całki $\int_0^1 x^2 \mathrm{d}x$ ze wzoru

$$
  \displaystyle s = \frac{1}{N}\sum_{i=0}^{N-1} \left(\frac{i}{N}\right)^2
$$

   dla N = 100 000 000. 

4. (1 pkt.) Napisz program, który w równych kolumnach wyświetla tabliczkę mnożenia. Wskazówka: chyba najłatwiej kwestię "równych kolumn" rozwiązać przy pomocy `std::format` lub `std::print`.   

5. (1 pkt.) Ciąg Collatza dany jest wzorem rekurencyjnym

$$ 
c_{n+1} =  \frac{1}{2}c_n \text{, gdy } c_n \text{ jest parzysta oraz } 
$$

$$ 
c_{n+1} =   3c_n + 1  \text{, gdy } c_n \text{ jest nieparzysta}
$$

Napisz program, który będzie wczytywał `c_1` z konsoli, a następnie wypisywał na ekranie 20 kolejnych elementów tego ciągu.

6. (1 pkt) Napisz program, który wczyta słowo, po czym wypisze je na ekranie, przy czym znaki będą wyświetlane na przemian w kolorach czerwonym i zielonym. Jak wyświetlać kolorowy tekst - patrz poprzednia lista.    
