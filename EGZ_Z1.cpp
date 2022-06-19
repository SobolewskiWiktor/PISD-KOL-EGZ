#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "EGZ_Z1_BIB.h"
using namespace std;

bool check_nip(string linia)
{
    for(int i=0; i<10; i++)
    {
        if(linia[i]-'0' != 0 && linia[i]-'0' != 1 && linia[i]-'0' != 2 && linia[i]-'0' != 3 && linia[i]-'0' != 4 && linia[i]-'0' != 5 && linia[i]-'0' != 6 && linia[i]-'0' != 7 && linia[i]-'0' != 8 && linia[i]-'0' != 9)
        {
            return 0;
        } 
    }
    return 1; 
}
bool check_uzad(string linia)
{
    string uzad_p = "771";
    string uzad_r = "772";
    string uzad_t = "773";
    for(int i=0; i<3; i++)
    {
        if(linia[i] != uzad_p[i] && linia[i] != uzad_r[i] && linia[i] != uzad_t[i])
        {
            return 0;
        }
    }
    return 1; 
}
bool check_suma_kontrolna(string linia)
{
    int suma = 0;
    suma = suma + ((linia[0]-'0') * 6);
    suma = suma + ((linia[1]-'0') * 5);
    suma = suma + ((linia[2]-'0') * 7);
    suma = suma + ((linia[3]-'0') * 2);
    suma = suma + ((linia[4]-'0') * 3);
    suma = suma + ((linia[5]-'0') * 4);
    suma = suma + ((linia[6]-'0') * 5);
    suma = suma + ((linia[7]-'0') * 6);
    suma = suma + ((linia[8]-'0') * 7); 
    suma = suma%11;
    if(suma == (linia[9]-'0'))
    {
      return 1;
    }
    else
    {
        return 0; 
    }
}
int main ()
{
    string linia; 
    int wybor; 
    NIP jeden; 
    while (true)
    {
        cout<<"== MENU =="<<endl;
        cout<<"1.Pobierz plik"<<endl;
        cout<<"2.Wyswietl pobrane dane"<<endl;
        cout<<"3.Zapisz dane"<<endl;
        cout<<"Wybieram: ";
        cin>> wybor;
        switch (wybor)
        {
        case 1:
        {
        ifstream z_pliku("nipy.txt");
            if(!z_pliku)
            {
                cout<<"[ERROR] - BRAK PLIKU"<<endl; 
            }
            else
            {
             do
             {
                getline(z_pliku, linia);
                cout<<linia<<endl;
                bool check_nip_ok = check_nip(linia);
                if(check_nip_ok == true)
                {
                  cout<<"[INFO] - DLUGOSC NIPU POPRAWNA"<<endl;
                  bool uzad_skarbowy = check_uzad(linia);
                  if(uzad_skarbowy == true)
                  {
                   cout<<"[INFO] - POPRWANY UZAD SKARBOWY"<<endl;
                   bool suma_kontrolna = check_suma_kontrolna(linia);
                   if(suma_kontrolna == true)
                   {
                    cout<<"[INFO] - POPRAWNA SUMA KONTROLNA"<<endl;
                    long long int set_nip = 0; 
                      for(int i=0; i<12; i++)
                      {
                        set_nip = set_nip + ((linia[i]-'0')*pow(10, 9-i));
                      }
                      set_nip = set_nip + 2; 
                      int dlugosc = linia.length();
                      string nazwa;
                      for(int i=11; i<dlugosc; i++)
                      {
                        nazwa=nazwa + linia[i];
                      }
                      int R = 0; 
                      for(int i= 0; i<3; i++)
                      {
                         R = R + ((linia[i]-'0')*pow(10, 2-i));
                         cout<<"R: "<<R<<endl;
                      }
                      cout<<"exportuje IRS: "<< R <<endl;
                      jeden.create(set_nip, R,  nazwa);

                       
                   }
                   else
                   {
                    cout<<"[ERROR] - NIE POPRAWNA SUMA KONTROLNA"<<endl;
                   }
                  }
                  else
                  {
                   cout<<"[ERROR] - ZLY UZAD SKARBOWY"<<endl; 
                  }

                }
                else
                {
                  cout<<"[ERROR] - ZLA DLUGOSC NIPU"<<endl; 
                }    
             } while (!z_pliku.eof());
             

            }
            break; 
        }
        case 2:
        {
            jeden.show(); 
            break; 
        }
        case 3: 
        {
            Node * return_next = jeden.head;
            long long int return_nip = 0;
            string return_name;    
            int return_exit = 1;  
            int IRS = 0; 
            while (return_exit != 0)
            {
              jeden.save(return_next, return_nip, return_name, return_exit, IRS);
              if(IRS == 771)
              {
                ofstream do_pliku("piotrkow.txt", ios::app);
                do_pliku << return_nip <<" "<<return_name<<endl; 
                do_pliku.close();
              }
              else if (IRS == 772)
              {
                ofstream do_pliku("radomsko.txt", ios::app);
                do_pliku << return_nip <<" "<<return_name<<endl; 
                do_pliku.close();
              }
              else if (IRS == 773)
              {
                ofstream do_pliku("tomaszow.txt", ios::app);
                do_pliku << return_nip <<" "<<return_name<<endl; 
                do_pliku.close();
              }
            }
             
        }
        }  
    }
    
    return 0;
}
