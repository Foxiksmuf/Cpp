#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 100;

void wypelnijTablice(int tab[], int size);
void sortuj(int tab[], int size, bool czyRosnaco);
int znajdz(int tab[], int size, int szukana);

int main()
{
    srand(time(NULL));

    int tablica[SIZE];
    int szukana = 0;
    int pozycja = -1;

    wypelnijTablice(tablica, SIZE);
    cout << "Podaj liczbe do wyszukania: ";
    cin >> szukana;
    sortuj(tablica, SIZE, true);
    pozycja = znajdz(tablica, SIZE, szukana);

    if (pozycja > -1)
        cout << "Liczba " << szukana << " znajduje sie na miejscu nr: " << pozycja << endl;
    else
        cout << "Liczby " << szukana << " nie ma w tablicy!" << endl;

    return 0;
}

void wypelnijTablice(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand() % 101;
    }
}

void sortuj(int tab[], int size, bool czyRosnaco)
{
    int tmp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (czyRosnaco)
            {
                if (tab[j] > tab[j + 1])
                {
                    tmp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = tmp;
                }
            }
            else
            {
                if (tab[j] < tab[j + 1])
                {
                    tmp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = tmp;
                }
            }
        }
    }
}

int znajdz(int tab[], int size, int szukana)
{
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == szukana)
            return i;
    }
    return -1;
}