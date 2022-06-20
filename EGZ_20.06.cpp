// napisz priogram pobierający z jednego pliku dane studenta
// oddzielone one są ; oraz pobierajacy z drugiego pliku oceny
//  wylicza srednia i zapisuje ja w pliku, sortujac srednia z ocen
//  od najwiekszej do najmniejszej.
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include "EGZ_20.06_bib.h"
#include "EGZ_20.06_data.h"
using namespace std;

int main()
{
  Kolejka<Student> kolejeczka;
  int wybor;
  string linia_student;
  string linia_ocena;

  string imie = "";
  string nazwisko = "";
  string rok = "";
  string oceny = "";
  double temp = 0;

  double index = 0;
  float srednia = 0;
  while (true)
  {
    cout << "== MENU ==" << endl;
    cout << "1.Pobierz dane" << endl;
    cout << "2.Wyswietl pobrane" << endl;
    cout << "3.Zapisz" << endl;
    cout << "Wybieram: ";
    cin >> wybor;
    switch (wybor)
    {
    case 1:
    {
      ifstream z_pliku_pierwszy("studenci.txt");
      if (!z_pliku_pierwszy)
      {
        cout << "[ERROR] - BLAD PLIKU 1" << endl;
      }
      else
      {
        ifstream z_pliku_drugi("oceny.txt");
        if (!z_pliku_drugi)
        {
          cout << "[ERROR] - BLAD PLIKU 1" << endl;
        }
        else
        {
          do
          {
            int sredniki = 0;
            int dlugosc = 0;
            double ile_jest = 0;

            imie = "";
            nazwisko = "";
            rok = "";
            index = 0;

            temp = 0;
            getline(z_pliku_pierwszy, linia_student);
            getline(z_pliku_drugi, linia_ocena);
            // potrzebujemy zmienne na
            // imie, naziwsko, index, rok
            // srednia ocen , oceny
            dlugosc = linia_student.length();
            for (int i = 0; i < dlugosc; i++)
            {
              if (linia_student[i] == ';')
              {
                sredniki++;
              }
              else
              {
                if (sredniki == 0)
                {
                  index = index + ((linia_student[i] - '0') * pow(10, 5 - i));
                }
                else if (sredniki == 1)
                {
                  nazwisko = nazwisko + linia_student[i];
                }
                else if (sredniki == 2)
                {
                  imie = imie + linia_student[i];
                }
                else if (sredniki == 3)
                {
                  rok = rok + linia_student[i];
                }
              }
            }
            /* cout<<"index: "<<index<<endl;
            cout<<"imie: "<<imie<<endl;
            cout<<"nazwisko: "<<nazwisko<<endl;
            cout<<"rok: "<<rok<<endl; */

            float suma = 0;
            float ilejest = 0;
            string ocenastr = "";
            float ocena = 0;

            linia_ocena = linia_ocena + " ";

            for (int i = 0; i < linia_ocena.length(); i++)
            {
              if (linia_ocena[i] != ' ')
              {
                ocenastr = ocenastr + linia_ocena[i];
              }
              else
              {
                ocena = stof(ocenastr);
                suma += ocena;
                ilejest++;
                ocenastr = "";
              }
            }
            cout << "Srednia:" << suma / ilejest << endl;
            srednia = suma / ilejest;
            oceny = linia_ocena;
            Student studenciak(imie, nazwisko, rok, oceny, index, srednia);
            kolejeczka.add(studenciak);

          } while (!z_pliku_pierwszy.eof());
          z_pliku_drugi.close();
          z_pliku_pierwszy.close();
        }
      }
      break;
    }
    case 2:
    {
      kolejeczka.show();
      break;
    }
    case 3:
    {
      ofstream to_file("student_exit.txt");
      int exit = 1;
      Node<Student> *return_next = kolejeczka.head;
      Node<Student> *return_data;
      do
      {
        kolejeczka.save(exit, return_next, return_data);
        if (return_data != nullptr)
        {
          to_file << return_data->data << endl;
        }
        else
        {
          break;
        }
      } while (exit != 0);
      to_file.close();
      break;
    }
    }
  }

  return 0;
}
