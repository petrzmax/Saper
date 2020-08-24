#include "saper_konsola.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

//Funkcja zmieniajaca kolor kursora
void kolor(int c)
{
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}

//Funckja ustawiajaca kursor na dowolnej pozycji (x,y)
void skok(short int x,short int y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

//Funkcja zmieniajaca wartosc wybor w zaleznosci od naciskanych strzalek (gora, dol). Zwraca true gdy wcisniemy enter
bool znacznik(int &wybor, int max)
{
    switch(_getch())
    {
        case 224:
            switch(_getch())
            {
                //Strzalka w gore
                case 72:
                    wybor--;
                    break;
                //Strzalka w dol
                case 80:
                    wybor++;
                    break;

            }
            //jesli wyjdziemy poza ilosc przyciskow(max) wybor dostaje minimalna lub maksymalna wartosc.
            if(wybor > max)
                wybor = 0;
            if(wybor < 0)
                wybor = max;
        break;

        //enter
        case 13:
            return true;
        break;

    }


    return false;

}

//Funkcja rysujaca plansze
void plansza_widok(int x, int y,Spole **&mapa, bool koniec)
{
    //Petle przechodzace po kazdej komorce planszy
    for(int i=0; i < y ; i++)
    {
        for(int j=0; j < x; j++)
        {
            //Jesli w danej komorce jest kursor, zmien kolor na zolty
            if(mapa[i][j].kursor)
                kolor(14);


            if(mapa[i][j].flaga && koniec == false)
            {
                if(!mapa[i][j].kursor)
                    kolor(12);
                cout << "F ";

                if(!mapa[i][j].kursor)
                    kolor(7);
            }
            else
            {
                if(mapa[i][j].odkryty == false && koniec == false)
                    cout << "O ";
                else
                {

                    if(mapa[i][j].liczba != 0 && mapa[i][j].liczba != 9)
                    {
                        if(!mapa[i][j].kursor)
                            kolor(11);
                        cout << mapa[i][j].liczba << " ";

                        if(!mapa[i][j].kursor)
                            kolor(7);
                    }
                    if(mapa[i][j].liczba == 0)
                        cout << ". ";
                    if(mapa[i][j].liczba == 9)
                    {
                        kolor(12);
                        cout << "# ";
                        kolor(7);
                    }
                }
            }
            if(mapa[i][j].kursor)
                 kolor(7);
        }
        cout << endl;
    }


}

//Funkcja zwracajaca przez referencje pozycje kursora
void kursor_xy(int x, int y, int &xp, int &yp, Spole **mapa)
{
    for(int i=0; i < y ; i++)
        for(int j=0; j < x; j++)
            if(mapa[i][j].kursor)
            {
                xp = j;
                yp = i;
                return;
            }
}

//Funckja odpowiedzialna za sterowanie, zwraca false gdy trafimy na bombe
bool sterowanie(int x, int y, Spole **mapa)
{
    //pozycja kursora (kx,ky)
    int kx, ky;
    kursor_xy(x,y,kx,ky,mapa);
    switch(_getch())
    {
        //Wcisniecie ktorejs ze strzalek
        case 224:
            switch(_getch())
            {
                //Gora
                case 72:
                    mapa[ky][kx].kursor=false;
                    if(ky-1<0)
                        mapa[y-1][kx].kursor=true;
                    else
                         mapa[ky-1][kx].kursor=true;
                    break;
                //Dol
                case 80:

                    mapa[ky][kx].kursor=false;
                    if(ky+1>y-1)
                        mapa[0][kx].kursor=true;
                    else
                         mapa[ky+1][kx].kursor=true;
                    break;
                //Lewo
                case 75:
                    mapa[ky][kx].kursor=false;
                    if(kx-1<0)
                        mapa[ky][x-1].kursor=true;
                    else
                         mapa[ky][kx-1].kursor=true;
                    break;
                break;

                //Prawo
                case 77:
                    mapa[ky][kx].kursor=false;
                    if(kx+1>x-1)
                        mapa[ky][0].kursor=true;
                    else
                         mapa[ky][kx+1].kursor=true;
                    break;
                break;

            }

        break;

        //spacja
        case 32:
        if(mapa[ky][kx].flaga == false)
        {
            if(mapa[ky][kx].liczba != 9)
               puste_odkryj(x,y,kx,ky,mapa);

            else
                return false;
        }

        break;

        //F
        case 102:
        if(mapa[ky][kx].odkryty == false)
            if(mapa[ky][kx].flaga == false)
                mapa[ky][kx].flaga = true;
            else
                mapa[ky][kx].flaga = false;
        break;
    }
    return true;

}

//Funkcja uruchamiajaca rozgrywke, zwraca czas rozgrywki. Przy przegranej zwraca 0
int gra (int x, int y, int ilosc_bomb)
{
    Spole **mapa;
    //Wygenerowanie planszy
    plansza(x,y,ilosc_bomb,mapa);
    int czas_start = time(0), czas;

    do
    {
        system("cls");
        plansza_widok(x,y,mapa,false);
        if(spr_wygr(x,y,ilosc_bomb,mapa))
        {
            czas = time(0) - czas_start;
            cout << "\nWygrales! \n\nTwoj czas to: " << czas  << " sekund.";
            _getch();
            return czas;
        }


    }while(sterowanie(x,y,mapa));

    system("cls");
    odkryj_wszystko(x,y,mapa);
    plansza_widok(x,y,mapa,true);
    kasuj(mapa,y);
    cout << "Przegrales";
    _getch();
    return 0;
}

//Funkcja wypisujaca wyniki
void wypisz_wyniki(string nazwa)
{
    ifstream plik_we(nazwa.c_str());
    string imie;
    int czas;
    system("cls");
    if(plik_we.is_open())
    {
        cout <<"\tImie: \t\tCzas:\n\n";
        while(!plik_we.eof())
        {
            plik_we >> imie >> czas;
            cout << "\t" << imie << "\t\t" << czas << endl;
        }
        plik_we.close();
    }
    else
        cout << "\n\n\t\t Brak wynikow";
    _getch();
}
