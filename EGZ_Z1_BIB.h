#ifndef znam_bib
#define znam_bib
#include <string>
using namespace std;
struct Node
     {
        long long int nip;
        int IRS;
        string name; 
        Node * next;
        Node (long long int n, int R,  string nick, Node* nast = nullptr)
        {
            IRS = R; 
            nip = n;
            name = nick;
            next = nast;
        }
     }; 
struct NIP
{
     Node * head = nullptr;  
    NIP() = default;
    void create(long long int n, int R, string nick);
    void show();
    void save(Node * &return_next, long long int &return_nip, string &return_name, int &exit, int &IRS);    
};
void NIP::create(long long int n,int R, string nick)
{
    Node * add = new Node(n, R, nick);
    if(head == nullptr)
    {
      head = add;   
    }
    else
    {
        Node * find = nullptr;
        find = head;
        while (find -> next != nullptr)
        {
            find = find -> next; 
        }
        find -> next = add; 
    }
}
void NIP::show()
{
    Node * find = nullptr;
    find = head;  
    while (find != nullptr)
    {
        cout<<"NIP: "<< find -> nip<<" Nazwa: "<< find -> name<<endl;
        find = find -> next; 
    }
    
}
void NIP::save(Node * &return_next, long long int &return_nip, string &return_name, int &exit, int &IRS)
{
    Node * find = return_next;
    return_nip = find -> nip; 
    return_name = find -> name;
    IRS = find -> IRS; 
    return_next = find -> next; 
    if(return_next == nullptr)
    {
        exit = 0; 
    } 
    
}

#endif
