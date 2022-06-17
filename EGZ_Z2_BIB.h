#ifndef znam_bib
#define znam_bib
using namespace std; 
struct account
{
   private:
     struct Node
     {
        signed long long  account_number;
        int bank; 
        Node * next;
        Node(signed long long  k, int b,  Node * n = nullptr)
        {
            bank = b; 
            account_number = k;
            next = n; 
        } 
     };
     Node * first = nullptr; 
     public:
     account() = default; 
     void add(signed long long  a, int b);
     void show();  
     void save(); 
};
void account :: add(signed long long a, int b)
{
    Node * adder = new Node(a,b); 
    if(first == nullptr || a > first -> account_number)
    {
        adder -> next = first;
        first = adder; 
    }
    else
    {
        Node * find = first;
        Node * find_help = nullptr;
        while (find != nullptr && a < find -> account_number)
        {
            find_help = find;
            find = find -> next;
        }
        find_help -> next = adder;
        adder -> next = find; 
        
    }
}
void account :: show ()
{
    cout<<"[INFO] - Numery kont: "<<endl;
    Node * find = first; 
    while (find != nullptr)
    {
        cout<< find -> account_number <<" "<< find -> bank <<endl;
        find = find -> next; 
    }
    cout<<endl; 
    
}
void account:: save()
{
    cout<<"[INFO] - EKSPORTUJE"<<endl;
    Node * find = first;
    while (find != nullptr)
    {
        if(find -> bank == 1020)
        {
            cout<<"[INFO] - EKSPORTUJE do 1020"<<endl;
         ofstream strumien_do_pliku("1020.txt", ios::app);
         strumien_do_pliku << find -> account_number<<endl;
         strumien_do_pliku.close();
        }
        else if(find -> bank == 1140)
        {
             cout<<"[INFO] - EKSPORTUJE do 1140"<<endl;
         ofstream strumien_do_pliku("1140.txt", ios::app);
         strumien_do_pliku << find -> account_number<<endl;
         strumien_do_pliku.close();
        }
        else if(find -> bank == 2490)
        {
             cout<<"[INFO] - EKSPORTUJE do 2490"<<endl;
         ofstream strumien_do_pliku("2490.txt", ios::app);
         strumien_do_pliku << find -> account_number<<endl;
         strumien_do_pliku.close();
        }
        find = find -> next;
    }
    
}

#endif 
