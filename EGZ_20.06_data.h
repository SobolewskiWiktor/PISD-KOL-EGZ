#ifndef know_two
#define know_two

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string imie;
    string nazwisko;
    string rok;
    string oceny;
    int index;
    float srednia;
    Student(string i, string n, string r, string o, int in, float sr)
    {
        imie = i;
        nazwisko = n;
        rok = r;
        oceny = o;
        index = in;
        srednia = sr;
    }

    bool operator>=(Student &t)
    {
        if (srednia >= t.srednia)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(Student &t)
    {
        if (srednia < t.srednia)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Student() = default;
};
ostream &operator<<(ostream &os, Student &t)
{
    os << t.imie << " " << t.nazwisko << " " << t.index << " Srednia: " << t.srednia << " Oceny: " << t.oceny;
    return os;
}

#endif
