#include <iostream>
#include <conio.h>
#include "saper.h"
#include "saper_konsola.h"
#include <fstream>


using namespace std;


int main()
{
    string wersja = "1.0";

    int wybor = 0, miejsce = 0;

    for(;;)
    {
        system("cls");
        cout << "=======================================================\n";
        kolor(14);
        cout <<        "\t\t\tSAPER v" << wersja;
        kolor(7);
        cout << "\n=======================================================";

        skok(0, 18);
        cout << "Artur Petrzak 2015";
        skok(0,4);

        switch(miejsce)
        {
            //Menu
            case 0:

                cout << "\t\t\tNowa gra\n\n";

                cout << "\t\t\tPomoc\n\n";

                cout << "\t\t\tRekordy\n\n";

                cout << "\t\t\tKoniec\n\n";

                skok(35, 4 + 2*wybor);

                cout << "<--";

                if(znacznik(wybor, 3))
                {
                    switch(wybor)
                    {
                        case 0:
                            miejsce=1;
                            wybor =0;
                        break;

                        //Pomoc
                        case 1:
                            miejsce=2;
                            wybor =0;
                        break;

                        //Rekordy
                        case 2:
                            miejsce=3;
                            wybor =0;
                        break;

                        //Koniec
                        case 3:
                            return 0;
                        break;
                    }
                }
                break;
            //Nowa Gra
            case 1:

                cout << "\t\tWybierz poziom trudnosci:\n\n";

                cout << "\t\t\tLatwy\n\n";

                cout << "\t\t\tSredni\n\n";

                cout << "\t\t\tTrudny\n\n";

                cout << "\t\t\tPowrot\n\n";

                skok(35, 6 + 2*wybor);

                cout << "<--";

                if(znacznik(wybor, 3))
                {
                    int czas=0;
                    string imie;
                    switch(wybor)
                    {
                        case 0:
                            czas=gra(8,8,10);
                            if(czas>0)
                            {
                                cout << "\n\nZapisales sie w rankingu! Podaj imie: ";
                                cin >> imie;
                                rekord_zapisz(czas,imie,"latwy");
                            }

                        break;

                        case 1:
                            czas=gra(16,16,40);
                            if(czas>0)
                            {
                                cout << "\n\nZapisales sie w rankingu! Podaj imie: ";
                                cin >> imie;
                                rekord_zapisz(czas,imie,"sredni");
                            }

                        break;

                        case 2:
                            czas=gra(30,16,99);
                            if(czas>0)
                            {
                                cout << "\n\nZapisales sie w rankingu! Podaj imie: ";
                                cin >> imie;
                                rekord_zapisz(czas,imie,"trudny");
                            }

                        break;

                        case 3:
                        miejsce=0;
                        wybor =0;
                        break;

                    }
                    miejsce = 0;
                    wybor = 0;

                }
                break;
            //Pomoc
            case 2:
                cout <<"\tSaper to gra strategiczna, w ktorej mamy za zadanie\n\ttak odslonic wszystkie pola, aby nie natrafic na mine.\n\n"
                       "\tStrzalki - ruch kursora.\n\n"
                       "\tSpacja - odkrycie pola.\n\n"
                       "\tF - ustawienie flagi.\n\n\n"
                       "\tNacisnij dowolny przycisk, aby powrocic do menu.";
                _getch();
                miejsce = 0;
                break;
             //Rekordy
             case 3:

                cout << "\t\tWybierz poziom trudnosci:\n\n";

                cout << "\t\t\tLatwy\n\n";

                cout << "\t\t\tSredni\n\n";

                cout << "\t\t\tTrudny\n\n";

                cout << "\t\t\tPowrot\n\n";

                skok(35, 6 + 2*wybor);

                cout << "<--";

                if(znacznik(wybor, 3))
                {
                    switch(wybor)
                    {
                        case 0:
                            wypisz_wyniki("latwy");
                        break;

                        case 1:
                            wypisz_wyniki("sredni");
                        break;

                        case 2:
                            wypisz_wyniki("trudny");
                        break;

                        case 3:
                        miejsce=0;
                        wybor =0;

                        break;

                    }
                }

             break;


        }
    }
    return 0;
}

