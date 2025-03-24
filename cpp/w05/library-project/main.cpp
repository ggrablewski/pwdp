#include <iostream>

#include <lz4.h>

int main()
{
    const int N = 10'000;
    char tekst[] =
        "Szuja - naomamiał, natruł i nabujał\n"
        "Szuja - a wierzyłam przecież mu jak nikt\n"
        "Szuja - dziecku kazał mówić \"proszę wuja\"\n"
        "Alleluja wesołego zrobił mi i znikł\n"
        "Szuja - niewykluta larwa i szczeżuja\n"
        "Szuja - do najtępszych pierwotniaków rym\n"
        "Szuja - bezlitosny kamień i statuja\n"
        "Fałsz i ruja ekskluzywnie powodują nim\n"

        "Gdy życie zdarło z faceta już maskę\n"
        "Gdy mu fasada rozpada się z trzaskiem\n"
        "Gdy zza niej wyjrzy jak dupa z pokrzywy\n"
        "Pysk zły i obrzydliwy i pryśnie cały blef\n"
        "O wtedy chociaż się pragniesz powściągać\n"
        "Nie nasobaczyć i nie naurągać\n"
        "Choć inwektywą żywą nie chcesz chlustać\n"
        "To same usta wykrzykną tobie wbrew:\n"

        "Szuja - pióra by pożyczyć od Anouilh'a (od Anouilh'a)\n"
        "Szuja - by opisać co to jest za typ\n"
        "Szuja - kawał matrymonialnego zbója\n"
        "Z pieszczot dwója, nieudana galareta z ryb\n"
        "Szuja - najpiękniejszy kęs mi życia ujadł\n"
        "Szuja - toczył ze mnie hektolitry łez\n"
        "Szuja - cóż takiego uczyniłam mu ja\n"
        "Żem jak tuja poderżnieta przezeń dzisiaj jest\n"
        "Mówię ci poderżnietą jest\n";

    char bufor[N] = {0};

    auto result = LZ4_compress_default(tekst, bufor, sizeof(tekst) - 1, N);
    std::cout << sizeof(tekst) << " -> " << result << "\n";
}
