#include "saper.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;


//Funkcja generujaca plansze
void plansza (int x, int y, int ilosc_bomb, Spole **&mapa)
{

    srand(time(0));

    int Bx, By;

    mapa = new Spole*[y];
    for(int i = 0; i < y; i++)
        mapa[i]= new Spole[x];

    for(int i=0; i < y ; i++)
        for(int j=0; j < x; j++)
        {
            mapa[i][j].odkryty = false;
            mapa[i][j].kursor = false;
        }
    mapa[0][0].kursor=true;



    for (int i =0; i < ilosc_bomb; i++)
    {
        do
        {
            Bx = rand()%x;
            By = rand()%y;
        }
        while(mapa[By][Bx].liczba == 9);

        mapa[By][Bx].liczba = 9;
    }

    //Srodek bez ramki
    for(int i=0; i < y ; i++)
    {
        for(int j=0; j < x; j++)
        {
            if(mapa[i][j].liczba == 9)
            {
                if(i>0 && i<y-1 && j>0 && j<x-1)
                {
                    if(mapa[i+1][j].liczba != 9)
                        mapa[i+1][j].liczba ++;

                    if(mapa[i+1][j+1].liczba != 9)
                        mapa[i+1][j+1].liczba ++;

                    if(mapa[i][j+1].liczba != 9)
                        mapa[i][j+1].liczba ++;

                    if(mapa[i-1][j+1].liczba != 9)
                        mapa[i-1][j+1].liczba ++;

                    if(mapa[i-1][j].liczba != 9)
                        mapa[i-1][j].liczba ++;

                    if(mapa[i-1][j-1].liczba != 9)
                        mapa[i-1][j-1].liczba ++;

                    if(mapa[i][j-1].liczba != 9)
                        mapa[i][j-1].liczba ++;

                    if(mapa[i+1][j-1].liczba != 9)
                        mapa[i+1][j-1].liczba ++;

                }

            }
        }
    }

    //Ramka
    //Lewy gorny rog
    if(mapa[0][0].liczba == 9)
    {
        if(mapa[0][1].liczba != 9)
            mapa[0][1].liczba ++;

        if(mapa[1][1].liczba != 9)
            mapa[1][1].liczba ++;

        if(mapa[1][0].liczba != 9)
            mapa[1][0].liczba ++;


    }

    //Lewy dolny rog
    if(mapa[y-1][0].liczba == 9)
    {
        if(mapa[y-2][0].liczba != 9)
            mapa[y-2][0].liczba ++;

        if(mapa[y-2][1].liczba != 9)
            mapa[y-2][1].liczba ++;

        if(mapa[y-1][1].liczba != 9)
            mapa[y-1][1].liczba ++;

    }

    //Prawy gorny rog
    if(mapa[0][x-1].liczba == 9)
    {
        if(mapa[0][x-2].liczba != 9)
            mapa[0][x-2].liczba ++;

        if(mapa[1][x-2].liczba != 9)
            mapa[1][x-2].liczba ++;

        if(mapa[1][x-1].liczba != 9)
            mapa[1][x-1].liczba ++;

    }

    //Prawy dolny rog
    if(mapa[y-1][x-1].liczba == 9)
    {
        if(mapa[y-1][x-2].liczba != 9)
            mapa[y-1][x-2].liczba ++;

        if(mapa[y-2][x-2].liczba != 9)
            mapa[y-2][x-2].liczba ++;

        if(mapa[y-2][x-1].liczba != 9)
            mapa[y-2][x-1].liczba ++;

    }

    //Lewa sciana
    for(int i = 1; i < y - 1; i++)
    {
        if(mapa[i][0].liczba == 9)
        {
            if(mapa[i-1][0].liczba != 9)
                mapa[i-1][0].liczba ++;

            if(mapa[i-1][1].liczba != 9)
                mapa[i-1][1].liczba ++;

            if(mapa[i][1].liczba != 9)
                mapa[i][1].liczba ++;

            if(mapa[i+1][1].liczba != 9)
                mapa[i+1][1].liczba ++;

            if(mapa[i+1][0].liczba != 9)
                mapa[i+1][0].liczba ++;
        }

    }

    //Prawa sciana
    for(int i = 1; i < y - 1; i++)
    {
        if(mapa[i][x-1].liczba == 9)
        {
            if(mapa[i-1][x-1].liczba != 9)
                mapa[i-1][x-1].liczba ++;

            if(mapa[i-1][x-2].liczba != 9)
                mapa[i-1][x-2].liczba ++;

            if(mapa[i][x-2].liczba != 9)
                mapa[i][x-2].liczba ++;

            if(mapa[i+1][x-2].liczba != 9)
                mapa[i+1][x-2].liczba ++;

            if(mapa[i+1][x-1].liczba != 9)
                mapa[i+1][x-1].liczba ++;
        }

    }

    //Gorna sciana
    for(int i = 1; i < x - 1; i++)
    {
        if(mapa[0][i].liczba == 9)
        {
            if(mapa[0][i-1].liczba != 9)
                mapa[0][i-1].liczba ++;

            if(mapa[1][i-1].liczba != 9)
                mapa[1][i-1].liczba ++;

            if(mapa[1][i].liczba != 9)
                mapa[1][i].liczba ++;

            if(mapa[1][i+1].liczba != 9)
                mapa[1][i+1].liczba ++;

            if(mapa[0][i+1].liczba != 9)
                mapa[0][i+1].liczba ++;
        }

    }

    //Dolna sciana
    for(int i = 1; i < x - 1; i++)
    {
        if(mapa[y-1][i].liczba == 9)
        {
            if(mapa[y-1][i-1].liczba != 9)
                mapa[y-1][i-1].liczba ++;

            if(mapa[y-2][i-1].liczba != 9)
                mapa[y-2][i-1].liczba ++;

            if(mapa[y-2][i].liczba != 9)
                mapa[y-2][i].liczba ++;

            if(mapa[y-2][i+1].liczba != 9)
                mapa[y-2][i+1].liczba ++;

            if(mapa[y-1][i+1].liczba != 9)
                mapa[y-1][i+1].liczba ++;
        }

    }

}

//Funkcja rekurencyjna odkrywajaca wszystkie puste pola w obrebie wlasnie odkrytego pola
void puste_odkryj(int x, int y, int kx, int ky, Spole **mapa)
{
    if(kx < 0 || kx >= x)
        return;
    if(ky < 0 || ky >= y)
        return;

    if(mapa[ky][kx].odkryty == false && mapa[ky][kx].flaga == false)
    {
        mapa[ky][kx].odkryty = true;
        if(mapa[ky][kx].liczba != 0)
            return;
    }
    else
        return;


    puste_odkryj(x,y,kx+1,ky-1,mapa);
    puste_odkryj(x,y,kx+1,ky,mapa);
    puste_odkryj(x,y,kx+1,ky+1,mapa);
    puste_odkryj(x,y,kx-1,ky-1,mapa);
    puste_odkryj(x,y,kx-1,ky,mapa);
    puste_odkryj(x,y,kx-1,ky+1,mapa);
    puste_odkryj(x,y,kx,ky+1,mapa);
    puste_odkryj(x,y,kx,ky-1,mapa);

}

//Funkcja zwraca true jesli grasz wygral
bool spr_wygr(int x, int y, int ilosc_bomb, Spole **mapa)
{
    int ilosc_nieodkrytych = 0;
    for(int i=0; i < y ; i++)
        for(int j=0; j < x; j++)
        {
            if(mapa[i][j].odkryty == false)
                ilosc_nieodkrytych++;
        }
    if(ilosc_nieodkrytych == ilosc_bomb)
        return true;
    else
        return false;

}

//Funkcja odkrywajaca wszystkie pola
void odkryj_wszystko(int x, int y, Spole **mapa)
{
    for(int i=0; i < y ; i++)
        for(int j=0; j < x; j++)
        {
            if(mapa[i][j].flaga == false || mapa[i][j].liczba != 9)
                mapa[i][j].odkryty = true;
        }

}

//Funkcja zapisujaca rekord do pliku
void rekord_zapisz(int czas, string imie, string nazwa)
{
    Srekordy *head = NULL;
    ifstream plik_we(nazwa.c_str());
    string imieTmp;
    Srekordy *T, *tmp;
    int czasTmp, dl;

    if(plik_we.is_open())
    {
        while(!plik_we.eof())
        {
            plik_we >> imieTmp >> czasTmp;
            nowy_element(head,czasTmp,imieTmp);
        }
        plik_we.close();
    }
    nowy_element(head,czas,imie);
    tmp = head;
    dl = dl_listy(head);
    T = new Srekordy[dl];

   //Przepisuje zawartosc listy do tablicy
   for(int i = 0; i < dl; i++)
   {
       T[i].czas = tmp->czas;
       T[i].imie = tmp->imie;
       tmp=tmp->next;
   }
   //Sortuje tablice
   for(int i = 0; i < dl; i++)
    {
        for(int j = 0; j < dl - i - 1; j++)
        {
            if(T[j].czas > T[j+1].czas)
            {
                Srekordy temp = T[j];
                T[j] = T[j+1];
                T[j+1] = temp;

            }
        }
     }


    ofstream plik_wy(nazwa.c_str());
    for(int i = 0; i < dl; i++)
    {
        plik_wy << '\t' << T[i].imie << '\t' << T[i].czas;
    }

    kasuj_liste(head);
    delete [] T;
    plik_wy.close();

}

//Funkcja usuwajaca tablice wskaznikow
void kasuj(Spole **mapa, int y)
{
    for(int i = 0; i < y; i++)
        delete [] mapa[i];
    delete []mapa;
}

//Zwraca dlugosc listy
int dl_listy(Srekordy *head)
{
    int i=0;
    while(head!=NULL)
    {
        i++;
        head=head->next;
    }
    return i;
}

//Funkcja dodajaca element na koncu listy, jesli lista nie istnieje, tworzy ja
void nowy_element(Srekordy *&head, int czas, string imie)
{
    Srekordy *akt = new Srekordy;
    Srekordy *tmp = head;
    if(head == NULL)
        head = akt;
    else
    {
        while(tmp->next != NULL)
        {
            tmp=tmp->next;
        }
        tmp->next = akt;
    }
    akt->imie = imie;
    akt->czas = czas;
    akt->next = NULL;
}

//Funkcja usuwajaca liste
void kasuj_liste(Srekordy *head)
{
    Srekordy *temp;
    while(head!=NULL)
    {
        temp = head;
        head=head->next;
        delete temp;
    }
}
