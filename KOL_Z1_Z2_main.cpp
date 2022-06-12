#include <iostream>
#include "KOL_Z1_Z2_bib.h"
using namespace std;
int main()
{
    Sznur jeden; 
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
            cout<<"Podaj liczbe:";
            cin>>liczba;
            jeden.wpisz(liczba);
            break;
        }
        case 2:
        {
            jeden.wypisz();
            break;
        }
        case 3:
        {
            jeden.usun();
            break;
        }
        case 4:
        {
            jeden.wpisz(9);
            jeden.wpisz(6);
            jeden.wpisz(6);
            jeden.wpisz(3);
            jeden.wpisz(3);
            jeden.wpisz(3);
            jeden.wpisz(3);
            jeden.wpisz(1);
            jeden.wpisz(1);
            jeden.wpisz(1);
            jeden.wpisz(1);
            jeden.wypisz();
            jeden.usun();
            jeden.wypisz(); 
            break; 
        }
        case 5:
        {
            jeden.wpisz(5);     
            jeden.wpisz(2);     
            jeden.wpisz(6);     
            jeden.wpisz(1);     
            jeden.wpisz(7);     
            jeden.wpisz(6);     
            jeden.wpisz(8);     
            jeden.wpisz(-100);    
            jeden.wpisz(10);     
            jeden.wpisz(20);     
            jeden.wpisz(100);     
            jeden.wpisz(1);     
            jeden.wpisz(1);     
            jeden.wpisz(-1023878);
            jeden.wypisz();
            jeden.usun();
            jeden.wypisz(); 
            break; 
        }
        case 6:
        {
           
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
