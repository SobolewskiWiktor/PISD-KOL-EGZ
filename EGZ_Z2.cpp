#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "EGZ_Z2_BIB.h"
#include "EGZ_Z2_BIB2.h"
using namespace std; 


bool check_bank_code(string linia)
{
  string iPKO = "1020";
  string mBank = "1140";
  string AliorBank = "2490"; 

  for(int i=4; i<8; i++)
  {
    if(linia[i]==iPKO[i-4] || mBank[i-4] == linia [i] || AliorBank[i-4] == linia[i])
    {
        
    }
    else
    { 
        return 0; 
    }
  }
  return 1; 
}


int main()
{
    int banked[4];
    account first; 
    int wybor;
    string nazwa; 
    int account[16];  
    while(true)
    {
        cout<<"== MENU =="<<endl;
        cout<<"1. Pobierz dane"<<endl;
        cout<<"2. Wyswietl pobrane"<<endl;
        cout<<"3. Eksportuj dane"<<endl; 
        cout<<"Wybor: ";
        cin>>wybor;
        switch (wybor)
        {
        case 1:
        {
         cout<<"podaj nazwe pliku"<<endl;
         cin>>nazwa;  
         ifstream strumen_z_pliku{nazwa};
         if(!strumen_z_pliku)
         {
         cout<<"[ERROR] - NIE MA TAKIEGO PLIKU"<<endl;
         }
         else
         {
           string linia; 
           string check_country = "PL";
           bool kraj = true; 
           cout<<"[INFO] - POBIERAM DANE ..."<<endl;
           do
           {
             signed long long  account_end = 0;
              int bank_end = 0;   
             getline(strumen_z_pliku, linia);
             cout<<linia<<endl; 
             for (int i = 0; i < 2; i++)
             {
                  if(linia[i]!=check_country[i])
                  { 
                    kraj = false;  
                  }
             }
             if(kraj == true)
             {
                cout<<"[INFO] - KRAJ ZGODNY"<<endl;
                bool bank = check_bank_code(linia);
                if(bank == true)
                {
                    cout<<"[INFO] - BANK ZGODNY"<<endl;
                    for(int i=12; i<27; i++)
                    {
                     account[i-12] = linia[i]-'0';
                    }
                    for(int i=0; i<16; i++)
                    {
                        account_end = account_end + account[i]*pow(10,15-i);
                    } 
                    for(int i=4; i<8; i++)
                    {
                        banked[i-4]=linia[i]-'0';
                    }
                    for(int i=0; i<4; i++)
                    {
                        bank_end = bank_end + banked[i]*pow(10,3-i);
                    }
                    first.add(account_end, bank_end);
                    
                }
                else
                {
                    cout<<"[INFO] - NIE ZGODNY BANK"<<endl;
                }
             }
             else
             {
                cout<<"[INFO] - NIE ZGODNY KRAJ"<<endl;
             }

             
           } while (!strumen_z_pliku.eof());
           strumen_z_pliku.close();
           
         }
        }
        break; 
        case 2:
        {
            first.show();
            break;
        }
        case 3:
        {
          first.save();
          break; 
        }
        
        }
    }
    return 0;
}
