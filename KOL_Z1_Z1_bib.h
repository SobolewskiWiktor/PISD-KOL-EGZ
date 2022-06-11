#ifndef znam_bib
#define znam_bib
using namespace std;
struct Sznur
{ 
    struct Node
    {
        int dane;
        Node * nast;
        Node(int D, Node * N = nullptr)
        {
            dane = D;
            nast = N; 
        }
    };
    Node * pocz = nullptr;
    void wpisz(int a);
    void wypisz();
    void usun(int k);
};
void Sznur :: wpisz(int a)
{
    Node * nowy = new Node (a); 
    if (pocz == nullptr || a >= pocz -> dane )
    {
        nowy -> nast = pocz; 
        pocz = nowy;
    }
    else
    {
        Node * zaszuk = nullptr;
        Node * szuk = pocz;
        while (szuk != nullptr && szuk -> dane > a)
        {
            zaszuk = szuk;
            szuk  = szuk -> nast; 
        }
        zaszuk -> nast = nowy;
        nowy -> nast = szuk;
        
    }
}
void Sznur::wypisz()
{
    if (pocz == nullptr)
    {
      cout<<"[BLAD!] - SZNUR JEST PUSTY"<<endl;
    }
    else
    {
        Node * biegacz;
        biegacz = pocz;
        cout<<"[INFO] - TWOJ SZNOR TO: ";
        while (biegacz != nullptr)
       {
        cout<<biegacz -> dane<<" ";
        biegacz = biegacz -> nast;
       }
       cout<<endl;
    }
    
}
void Sznur::usun(int k)
{
    int czy_trojka = 1;
    int srednia = 0;  
    Node * pocz_szuk;
    Node * kon_szuk;
    Node * sr_szuk;  
    Node * poprzednia; 
    kon_szuk = pocz;
    sr_szuk = kon_szuk -> nast;
    pocz_szuk = sr_szuk -> nast; 
    while (pocz_szuk != nullptr)
    {
        if(czy_trojka == 3 )
        {
            cout<<endl;
          
          srednia = (pocz_szuk ->dane + sr_szuk -> dane + kon_szuk -> dane)/3; 
          cout<<"[INFO] - Srednia to: "<< srednia <<endl;
          if(srednia < k && kon_szuk == pocz)
          {
              cout<<"[INFO] - Usuwam pierwszy element z pierwszej 3 "<<endl;
              pocz = kon_szuk -> nast; 
              kon_szuk = pocz_szuk -> nast;
              sr_szuk = kon_szuk -> nast; 
              poprzednia = pocz_szuk;  
              pocz_szuk = sr_szuk -> nast;

          }
          else if(srednia >= k && kon_szuk == pocz)
          {
               cout<<"[INFO] - Usuwam drugi i ostatni element z pierwszej 3 "<<endl;
               poprzednia = kon_szuk; 
               kon_szuk -> nast = pocz_szuk -> nast; 
               kon_szuk = pocz_szuk -> nast;
               sr_szuk = kon_szuk -> nast; 
               pocz_szuk = sr_szuk -> nast;  
          }
          else if(srednia < k )
          {
              cout<<"[INFO] - Usuwam pierwszy element z kolejnej 3 "<<endl;
              poprzednia -> nast = kon_szuk -> nast; 
              kon_szuk = pocz_szuk -> nast;
              sr_szuk = kon_szuk -> nast; 
              poprzednia = pocz_szuk; 
              pocz_szuk = sr_szuk -> nast;
          }
          else if(srednia >= k )
          {
              cout<<"[INFO] - Usuwam drugi i ostatni element z kolejnej 3 "<<endl;
              poprzednia = kon_szuk; 
              kon_szuk -> nast = pocz_szuk -> nast; 
              kon_szuk = pocz_szuk -> nast;
              sr_szuk = kon_szuk -> nast; 
              pocz_szuk = sr_szuk -> nast; 
          }

          srednia = 0;
          czy_trojka = 1;  
        }
        else
        {
         czy_trojka ++;  
        } 
    }
    
}
#endif
