#ifndef know
#define know

#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node
{
    Node<T> *next;
    T data;
    Node<T>(T d, Node<T> *N = nullptr)
    {
        data = d;
        next = N;
    }
};
template <typename T>
struct Kolejka
{
    Node<T> *head = nullptr;
    Kolejka() = default;
    ~Kolejka();
    void add(T a);
    void show();
    void save(int &exit, Node<T> *&return_next, Node<T> *&return_data);
};
template <typename T>
Kolejka<T>::~Kolejka()
{
    Node<T> *find = head;
    Node<T> *kill = nullptr;
    while (find != nullptr)
    {
        kill = find;
        find = find->next;
        delete kill;
    }
}
template <typename T>
void Kolejka<T>::add(T a)
{

    Node<T> *adder = new Node<T>(a);
    if (head == nullptr || a >= head->data)
    {
        adder->next = head;
        head = adder;
    }
    else
    {
        Node<T> *find = head;
        Node<T> *find_previous = nullptr;
        while (find != nullptr && a < find->data)
        {
            find_previous = find;
            find = find->next;
        }
        find_previous->next = adder;
        adder->next = find;
    }
}
template <typename T>
void Kolejka<T>::show()
{
    Node<T> *find = head;
    while (find != nullptr)
    {
        cout << find->data << endl;
        find = find->next;
    }
    cout << endl;
}
template <typename T>
void Kolejka<T>::save(int &exit, Node<T> *&return_next, Node<T> *&return_data)
{
    Node<T> *find = return_next;
    return_data = find;
    cout << "find = " << find << endl;
    if (find == nullptr)
    {
        exit = 0;
    }
    else
    {
        return_next = find->next;
        cout << "return_next = " << return_next << endl;
    }
}

#endif
