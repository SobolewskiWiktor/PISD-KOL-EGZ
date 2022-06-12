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
    void usun(); 
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
void Sznur :: wypisz()
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
void Sznur :: usun()
{
    // suma skranych ele 
   // usuwa cala czworke jezeli suma jest rowna
   // usuwa 1 i 4 ele jezeli suma jest rozna
Node * runner = pocz;
Node * runnerhelp = nullptr;
Node * killer = nullptr;
int jeden = 0;
int dwa = 0;
int trzy = 0;
int cztery = 0;
while(runner != nullptr && runner -> nast != nullptr && runner -> nast -> nast != nullptr && runner -> nast -> nast -> nast != nullptr)
{

   jeden = runner -> dane;
   dwa = runner -> nast -> dane;
   trzy = runner -> nast -> nast -> dane;
   cztery = runner -> nast -> nast -> nast -> dane; 

   if(jeden+cztery == dwa + trzy)
   {
      if(runner == pocz)
      {
        for(int i=0; i<4; i++)
        {
           killer = pocz;
           pocz = pocz -> nast;
           delete killer; 
        }
        runner = pocz;
      }
      else
      {
        for(int i=0; i<4; i++)
        {
           killer = runner;
           runner = runner -> nast;
           delete killer; 
        }
        runnerhelp -> nast = runner;
      }
   }
   else
   {
     if (runner == pocz)
     {
        killer = pocz;
        pocz = pocz -> nast;
        delete killer;
        runner = pocz;
        runner = runner -> nast; 
        runnerhelp = runner;
        runner = runner -> nast;
        killer = runner;
        runner = runner -> nast;
        runnerhelp -> nast = runner; 
        delete killer ; 
     }
     else
     {
       killer = runner;
       runner = runner -> nast;
       runnerhelp -> nast = runner;  
       delete killer; 
       runner = runner ->nast; 
       runnerhelp = runner;
       runner = runner -> nast;
       killer = runner;
       runner = runner -> nast;
       runnerhelp -> nast = runner; 
       delete killer; 
     
     }
   }
}

}

#endif
