#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.14;

class Bryla {

public:

	virtual void pole_powierzchni_calkowitej() {
		cout << "nieokreslony";
	}
	virtual void objetosc() {
		cout << "nieokreslony" << endl << ;
	}
	virtual void pobierz_dane() {
		cout << "nieokreslony" << endl << ; } };


class Walec :public Bryla {

private:
	int r;
	int h;

public:
	Walec(int r, int h) {
		this->r = r;
		this->h = h; }

	void pole_powierzchni_calkowitej() {
		cout << "Pole Powierzchni Walca: " << 2 * pi * r * (r + h); }

	void objetosc() {
		cout << "Objetosc Walca: " << endl <<  pi * pow(r, 2) * h; }

	void pobierz_dane() {
		cout << "Walec: " << endl <<;
		cout << "Promien: " << endl <<   r;
		cout << "Wysokosc: " << endl <<  h;
		objetosc();
		pole_powierzchni_calkowitej(); } };

class Stozek :public Bryla {
private:
	int r;
	int h;
	int l;
public:
	Stozek(int r, int h, int l) {
		this->r = r;
		this->h = h;
		this->l = l;  }

	void objetosc() {
		cout << "Objetosc Stozka: " << endl << (pi * pow(r, 2) * h) / 3;  }

	void pole_powierzchni_calkowitej() {
		cout << "Pole Powierzchni Stozka: " << endl << pi * r * (r + l);}

	void pobierz_dane() {
		cout << "Stozek: " << endl <<;
		cout << "Promien stozka: " << endl << r;
		cout << "Wysokosc stozka: " << endl << h;
		cout << "Dlugosc krawedzi bocznej: " << endl << l;

		objetosc();
		pole_powierzchni_calkowitej(); } };

class Czworoœcian_Foremny :public Bryla {
private:

	int a;

public:
	Czworoœcian_Foremny(int a) {
		this->a = a;
	}
	void objetosc() {
		cout << "Objetosc Czworoscianu Foremnego: " << endl << (pow(a, 3) * sqrt(2)) / 12;
	}
	void pole_powierzchni_calkowitej() {
		cout << "Pole Powierzchni Czworoscianu Foremnego: " << endl << pow(a, 2) * sqrt(3);
	}
	void pobierz_dane() {
		cout << "Czworoscian Foremny: " << endl << ;
		cout << "Bok: " << endl << a;
		objetosc();
		pole_powierzchni_calkowitej();
	} };

class Kula :public Bryla {
private:

	int r;

public:
	Kula(int r) {
		this->r = r;
	}
	void objetosc() {
		cout << "Objetosc Kuli: " << endl << (4 * pi * pow(r, 3)) / 3;
	}
	void pole_powierzchni_calkowitej() {
		cout << "Pole Powierzchni Kuli: " << endl  << 4 * pi * pow(r, 2);
	}
	void pobierz_dane() {
		cout << "Kula: " << endl << ;
		cout << "Promien: " << endl << r;
		objetosc();
		pole_powierzchni_calkowitej();
	}
};


class Prostopadloœcian :public Bryla {

private:
	int a;
	int b;
	int h;

public:
	Prostopadloœcian(int a, int b, int h) {
		this->a = a;
		this->b = b;
		this->h = h;
	}
	void objetosc() {
		cout << "Objetosc Prostopadloscianu: " << endl << a * b * h;
	}
	void pole_powierzchni_calkowitej() {
		cout << "Pole Powierzchni Prostopadloscianu: " << endl << 2 * (a * b + a * h + b * h);
	}
	void pobierz_dane() {
		cout << "Prostopadloscian: " << endl << ;
		cout << "Dlugosc boku A: " << endl << a;
		cout << "Dlugosc boku B: " << endl << b;
		cout << "Wysokosc prostopadloscianu: " << endl << h;
		objetosc();
		pole_powierzchni_calkowitej(); } };

void wywolac(Bryla& b) {

	b.pobierz_dane();  }

int main() {

	Walec (5, 4);
	Stozek s(6, 4, 3);
	Czworoœcian_Foremny c(4);
	Kula k(3);
	Prostopadloœcian p(5, 6, 7);

	wywolac(s);
	wywolac(w);
	wywolac(k);
	wywolac(c);
	wywolac(p);
}