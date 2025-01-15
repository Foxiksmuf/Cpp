#include <iostream>

using namespace std;

class Wektor {
private:
    double x;
    double y;
    double z;
public:
    Wektor(double x = 0, double y = 0, double z = 0);
    double getX();
    double getY();
    double getZ();
    Wektor& operator+(const Wektor&);
    Wektor& operator-(const Wektor&);
    Wektor& operator*(double);
    Wektor& operator/(double);
    friend Wektor& operator*(double, const Wektor&);
};

Wektor::Wektor(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Wektor::getX() {
    return x;
}

double Wektor::getY() {
    return y;
}

double Wektor::getZ() {
    return z;
}

Wektor& Wektor::operator+(const Wektor& wektor) {
    Wektor* w = new Wektor(this->x + wektor.x, this->y + wektor.y, this->z + wektor.z);
    return *w;
}

Wektor& Wektor::operator-(const Wektor& wektor) {
    Wektor* w = new Wektor(this->x - wektor.x, this->y - wektor.y, this->z - wektor.z);
    return *w;
}

Wektor& Wektor::operator*(double skalar) {
    Wektor* w = new Wektor(this->x * skalar, this->y * skalar, this->z * skalar);
    return *w;
}

Wektor& Wektor::operator/(double skalar) {
    Wektor* w = new Wektor(this->x / skalar, this->y / skalar, this->z / skalar);
    return *w;
}

Wektor& operator*(double skalar, const Wektor& wektor) {
    Wektor* w = new Wektor(wektor.x * skalar, wektor.y * skalar, wektor.z * skalar);
    return *w;
}

int main() {
    Wektor w1(1, 2, 3);
    Wektor w2(3, 4, 5);
    Wektor w3;

    w3 = w1 + w2;
    cout << "Suma: (" << w3.getX() << ", " << w3.getY() << ", " << w3.getZ() << ")" << endl;

    w3 = w1 - w2;
    cout << "Ró¿nica: (" << w3.getX() << ", " << w3.getY() << ", " << w3.getZ() << ")" << endl;

    w3 = w1 * 2;
    cout << "Mno¿enie przez skalar: (" << w3.getX() << ", " << w3.getY() << ", " << w3.getZ() << ")" << endl;

    w3 = 2 * w1;
    cout << "Mno¿enie przez skalar: (" << w3.getX() << ", " << w3.getY() << ", " << w3.getZ() << ")" << endl;

    w3 = w1 / 2;
    cout << "Dzielenie przez skalar: (" << w3.getX() << ", " << w3.getY() << ", " << w3.getZ() << ")" << endl;

    return 0;
}