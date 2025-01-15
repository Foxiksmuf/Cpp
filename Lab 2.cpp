#include <iostream> 
#include <string> 

using namespace std;

class Auto
{
private:
	string producent;
	string kolor;
	int pojemnoscSilnika;

public:
	Auto()
	{
		producent = "";
		kolor = "";
		pojemnoscSilnika = 0;
	}

	Auto(string producent, string kolor, int pojemnoscSilnika)
	{
		this->producent = producent;
		this->kolor = kolor;
		this->pojemnoscSilnika = pojemnoscSilnika;
	}

	string getProducent()
	{
		return producent;
	}

	string getKolor()
	{
		return kolor;
	}

	int getPojemnoscSilnika()
	{
		return pojemnoscSilnika;
	}

	void wyswietlInformacje()
	{
		cout << "Pojemnosc silnika: " << pojemnoscSilnika << endl;
		cout << "Producent: " << producent << endl;
		cout << "Kolor: " << kolor << endl;
	}
};

Auto* znajdzAuto(Auto* auta, int pojemnoscSilnika, int liczbaAut)
{
	Auto* wynik = new Auto[liczbaAut];
	int licznik = 0;

	for (int i = 0; i < liczbaAut; i++)
	{
		if (auta[i].getPojemnoscSilnika() == pojemnoscSilnika)
		{
			wynik[licznik] = auta[i];
			licznik++;
		}
	}

	return wynik;
}

int main()
{
	int pojemnoscSilnika;
	int liczbaAut;

	cout << "Podaj pojemnosc silnika: ";
	cin >> pojemnoscSilnika;

	cout << "Podaj liczbe aut: ";
	cin >> liczbaAut;

	// Tworzymy tablice statyczna i dynamiczna
	Auto autaStatyczna[] = { Auto("Fiat","Czerwony",1000), Auto("Ford","Niebieski",1500), Auto("BMW","Czarny",2000), Auto("Audi","Srebrny",3000), Auto("Opel","Zielony",2500) };
	Auto* autaDynamiczna = new Auto[liczbaAut];

	// Wypelniamy tablice dynamiczna
	for (int i = 0; i < liczbaAut; i++)
	{
		string producent;
		string kolor;
		int pojemnoscSilnika;

		cout << "Podaj dane auta nr " << i + 1 << endl;
		cout << "Producent: ";
		cin >> producent;

		cout << "Kolor: ";
		cin >> kolor;

		cout << "Pojemnosc silnika: ";
		cin >> pojemnoscSilnika;

		autaDynamiczna[i] = Auto(producent, kolor, pojemnoscSilnika);
	}

	// Znajdujemy auto w tablicy statycznej
	cout << "Auto z tablicy statycznej: " << endl;
	Auto* autoStatyczne = znajdzAuto(autaStatyczna, pojemnoscSilnika, 5);
	autoStatyczne[0].wyswietlInformacje();

	// Znajdujemy auto w tablicy dynamicznej
	cout << "Auta z tablicy dynamicznej: " << endl;
	Auto* autaDynamiczne = znajdzAuto(autaDynamiczna, pojemnoscSilnika, liczbaAut);

	for (int i = 0; i < liczbaAut; i++)
	{
		if (autaDynamiczne[i].getPojemnoscSilnika() != 0)
		{
			autaDynamiczne[i].wyswietlInformacje();
		}
	}

	// Zwalniamy pamiec
	delete[] autaDynamiczna;
	delete[] autaDynamiczne;
	delete[] autoStatyczne;

	return 0;
}