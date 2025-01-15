#include <iostream>

using namespace std;
static int a = 4;

class Urzadzenie {
protected:
	string firma;
	int obroty = 0;
public:
	Urzadzenie() {
	}
	Urzadzenie(string firma, int obroty) {
		this->firma = firma;
		this->obroty = obroty;
	}
	string daj_firme() {
		return this->firma;
	}
	int daj_obroty() {
		return this->obroty;
	}
	void parametry() {
		cout << "Marka : " << endl << 
			this->firma;
		cout << "Obroty : " << endl << 
			this->obroty;
		cout << endl;
	}
};
class WiertarkoWkretarka : public Urzadzenie {
private:
	double napiecie = 0;
	string bateria;
	int czas_ladow = 0;
public:
	WiertarkoWkretarka() {

	}
	WiertarkoWkretarka(double napiecie, string bateria, int czas_ladow, string firma, int obroty) : Urzadzenie(firma, obroty) {
		this->napiecie = napiecie;
		this->bateria = bateria;
		this->czas_ladow = czas_ladow;
	}
	double daj_napiecie() {
		return this->napiecie;
	}
	string daj_baterie() {
		return this->bateria;
	}
	int daj_czas_ladow() {
		return this->czas_ladow;
	}
	void parametry_urzadzenia() {
		cout << "Marka : " << 
			this->firma << endl;
		cout << "Obroty : " << 
			this->obroty << endl;
		cout << "Napiecie : " << 
			this->napiecie << endl;
		cout << "Bateria : " << 
			this->bateria << endl;
		cout << "Czas Ladowania : " << 
			this->czas_ladow << endl;
		cout << endl;
	}
};
class SzlifierkaKatowa : public Urzadzenie {
private:
	int moc = 0;
	int tarcze = 0;
public:
	SzlifierkaKatowa() {

	}
	SzlifierkaKatowa(int moc, int tarcze, string firma, int obroty) : Urzadzenie(firma, obroty) {
		this->moc = moc;
		this->tarcze = tarcze;

	}
	int daj_moc() {
		return this->moc;
	}
	int daj_tarcze() {
		return this->tarcze;
	}
	void parametry_urzadzenia() {
		cout << "Marka : " << 
			this->firma << endl;
		cout << "Obroty : " << 
			this->obroty << endl;
		cout << "Moc : " << 
			this->moc << endl;
		cout << "Tarcze : " << 
			this->tarcze << endl;
		cout << endl;
	}

};
//Szlifierka Katowa o najwiekszej liczbie obrotow
SzlifierkaKatowa znajdz_Szlifierke_0_najwyzszych_obrotach(SzlifierkaKatowa* tab) {
	int pamiec = 0;
	int indeks = 0;
	for (int i = 0; i < a; i++) {
		if (tab[i].daj_obroty() > pamiec) {
			indeks = i;
			pamiec = tab[i].daj_obroty();
		}
	}
	cout << "Najwieksza ilosc obrotow posiada Szlifierka katowa : " << endl;
	tab[indeks].parametry_urzadzenia();
	return tab[indeks];
}
//Wiertarko Wkretarka o najkrotszym ladowaniu
WiertarkoWkretarka znajdzWiertarke_o_najkrotszym_ladowaniu(WiertarkoWkretarka* tab) {
	int pamiec = 1000;
	int indeks = 0;
	for (int i = 0; i < a; i++) {
		if (tab[i].daj_czas_ladow() < pamiec) {
			indeks = i;
			pamiec = tab[i].daj_czas_ladow();
		}
	}
	cout << "Najktorszy czas ladowania posiada Wiertarka : " << endl;
	tab[indeks].parametry_urzadzenia();
	return tab[indeks];
}


int main() {
	SzlifierkaKatowa SzlifierkaKatowa1 = SzlifierkaKatowa(1800, 210, "Parkside", 6000);
	SzlifierkaKatowa SzlifierkaKatowa2 = SzlifierkaKatowa(2100, 220, "Makita", 7000);
	SzlifierkaKatowa SzlifierkaKatowa3 = SzlifierkaKatowa(1900, 250, "Bosch", 5500);
	SzlifierkaKatowa SzlifierkaKatowa4 = SzlifierkaKatowa(2250, 210, "Bosch", 7500);

	WiertarkoWkretarka WiertarkoWkretarka1 = WiertarkoWkretarka(12.4, "Alkaliczne", 10, "DeWalt", 1000);
	WiertarkoWkretarka WiertarkoWkretarka2 = WiertarkoWkretarka(17.6, "Litowo-Manganowe", 6, "Erbauer", 1400);
	WiertarkoWkretarka WiertarkoWkretarka3 = WiertarkoWkretarka(12.4, "Alkaliczne", 7, "DeWalt", 1200);
	WiertarkoWkretarka WiertarkoWkretarka4 = WiertarkoWkretarka(17.6, "Litowo-Manganowe", 5, "Makita", 1500);

	SzlifierkaKatowa SzlifierkiKatowe[] = { SzlifierkaKatowa1,SzlifierkaKatowa2,SzlifierkaKatowa3,SzlifierkaKatowa4 };
	WiertarkoWkretarka WiertarkoWkretarki[] = { WiertarkoWkretarka1,WiertarkoWkretarka2,WiertarkoWkretarka3,WiertarkoWkretarka4 };
	znajdzWiertarke_o_najkrotszym_ladowaniu(WiertarkoWkretarki);
	znajdz_Szlifierke_0_najwyzszych_obrotach(SzlifierkiKatowe);

}