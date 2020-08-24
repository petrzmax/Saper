#ifndef SAPERKONSOLA
#define SAPERKONSOLA

#include "saper.h"

void kolor(int c);
void skok(short int x,short int y);
bool znacznik(int &wybor, int max);
void plansza_widok(int x, int y,Spole **&mapa, bool koniec);
void kursor_xy(int x, int y, int &xp, int &yp, Spole **mapa);
bool sterowanie(int x, int y, Spole **mapa);
int gra (int x, int y, int ilosc_bomb);
void wypisz_wyniki(std::string nazwa);

#endif // SAPERKONSOLA

