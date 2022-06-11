#include <iostream>
#include "KOL_Z1_Z1_bib.h"
using namespace std;
int main()
{
    Sznur pierwszy;
    int wybor; 
    while (true)
    {
        cout<<endl;
        cout<<"=== MENU ==="<<endl;
        cout<<"1. Wstaw Liczbe"<<endl;
        cout<<"2. Wypisz Sznur"<<endl;
        cout<<"3. Usun Elementy"<<endl;
        cout<<"4. TEST USUN"<<endl;
        cout<<"5. TEST USUN - 2"<<endl;
        cout<<"6. TEST PRZENIES"<<endl;
        cout<<"9. Wylacz Program"<<endl;
        cout<<"Wybor: ";
        cin>>wybor;
        switch (wybor)
        {
        case 1:
        {
        int liczba;
        cout<<"Podaj liczbe: ";
        cin>> liczba;
        pierwszy.wpisz(liczba);
        break;
        }
        case 2:
        {
            pierwszy.wypisz();
            break;
        }
        case 3:
        {
            int temp;
            cout<<"[INFO] - Podaj K "<<endl;
            cout<<"Podajesz: ";
            cin>>temp;
            pierwszy.usun(temp);
            break;
        }
        case 4:
        {
            pierwszy.wpisz(7);
            pierwszy.wpisz(6);
            pierwszy.wpisz(6);
            pierwszy.wpisz(3);
            pierwszy.wpisz(3);
            pierwszy.wpisz(3);
            pierwszy.wpisz(2);
            pierwszy.wpisz(1);
            pierwszy.wpisz(1);
            pierwszy.wpisz(1);
            pierwszy.wpisz(1);
            pierwszy.wypisz();
            pierwszy.usun(3);
            pierwszy.wypisz();
            break; 
        }
        case 5:
        {
            pierwszy.wpisz(7);
            pierwszy.wpisz(6);
            pierwszy.wpisz(6);
            pierwszy.wpisz(3);
            pierwszy.wpisz(3);
            pierwszy.wpisz(3);
            pierwszy.wpisz(2);
            pierwszy.wpisz(1);
            pierwszy.wpisz(1);
            pierwszy.wpisz(1);
            pierwszy.wpisz(1);
            pierwszy.wypisz();
            pierwszy.usun(7);
            pierwszy.wypisz();
            break; 
        }
        case 6:
        {
            pierwszy.wpisz(9);
            pierwszy.wpisz(9);
            pierwszy.wpisz(9);
            pierwszy.wpisz(8);
            pierwszy.wpisz(8);
            pierwszy.wpisz(6);
            pierwszy.wpisz(6);
            pierwszy.wpisz(6);
            pierwszy.wpisz(6);
            pierwszy.wpisz(5);
            pierwszy.wpisz(5);
            pierwszy.wpisz(5);
            pierwszy.wpisz(5);
            pierwszy.wpisz(2);
            pierwszy.wpisz(2);
            pierwszy.wpisz(1);
            pierwszy.wpisz(1);
            pierwszy.wypisz();
            pierwszy.przenies();
            pierwszy.wypisz();
            break; 
        }
        case 9:
        {
        cout<<"[INFO] - DO WIDZENIA :)"<<endl;
        exit( 123 );
        }
        default:
        {
            cout<<"[BLAD!] - WYBRALES ZLA OPCJE"<<endl;
            break;
        }
        }
    }
    
    return 0; 
}
