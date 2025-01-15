
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int nwd(int a, int b, int i) {
	if (a == b) {
		i++;
		cout << "liczba wywolan rekurencyjnych : " << i << endl;
		return a;
	}
	else if (a > b) {
		i++;
		return nwd(a - b, b, i);
	}
	else return
		i++;
		nwd(a, b - a, i);
}
int main() {
	int a, b, i;
	i = 0;
	cout << "Podaj 2 liczby " << endl;
	cin >> a >> b;
	system("CLS");
	cout << "NWD wynosi " << nwd(a, b, i) << endl;
	

	system("pause");
	return 0;

}