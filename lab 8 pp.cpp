#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* losowanie() {
    int i;
    srand(time(NULL));
    int tabelalosliczb[100000];
    for (i = 0; i < 100000; i++) {
        tabelalosliczb[i] = (rand() % 99) + 1;
    }
    return tabelalosliczb;
}

int zliczanienajczestszej(int* tabela, int stotysiecy)
{
    int a = 0, b = 0, i = 0, j = 0, najczestsza;
    for (i; i < stotysiecy; i++) {
        for (j; j < stotysiecy; j++) {
            if (tabela[i] == tabela[j])
                b++;
        }
        if (b > a) {
            a = b;
            najczestsza = tabela[i];
        }
    }
    cout << najczestsza;
         return  najczestsza;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    int* s = losowanie();
    cout << "Najczêœciej powtarzaj¹ca siê liczba: ";
    zliczanienajczestszej(s, 100000);
    return 0;
}
