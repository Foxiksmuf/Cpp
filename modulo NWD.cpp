#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int modulo(int a, int b, int i)
{
	if (a == 0)
	{
		i++;
		cout << "liczba wywolan rekurencyjnych : " << i << endl;
		cout << "wynik : ";
		return b;
	}
	else
	{
		i++;
		return modulo(b % a, a, i);
	}

}

int main() {
	int a, b, i;
	i = 0;
	cout << "podaj dwie liczby" << endl;
	cin >> a >> b;
	system("CLS");
	cout << modulo(a, b, i);
	system("PAUSE");
	return(0);



}