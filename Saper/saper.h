#ifndef SAPER
#define SAPER

#include<iostream>

struct Spole
{
    int liczba=0;
    bool odkryty = false, kursor = false, flaga = false;

};

struct Srekordy
{
    std::string imie;
    int czas;
    Srekordy *next;

};

void plansza (int x, int y, int ilosc_bomb, Spole **&mapa);
void puste_odkryj(int x, int y, int kx, int ky, Spole **mapa);
bool spr_wygr(int x, int y, int ilosc_bomb, Spole **mapa);
void odkryj_wszystko(int x, int y, Spole **mapa);
void rekord_zapisz(int czas, std::string imie, std::string nazwa);
void kasuj(Spole **mapa, int y);
void nowy_element(Srekordy *&head, int czas, std::string imie);
void kasuj_liste(Srekordy *head);
int dl_listy(Srekordy *head);

#endif // SAPER

