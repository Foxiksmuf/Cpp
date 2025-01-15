#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
	T* arr;
	int size;
	int top;
public:
	Stack(int s)
	{
		size = s;
		arr = new T[size];
		top = -1;
	}

	void push(T k)
	{
		if (top >= size - 1)
		{
			cout << "Stack overflow!" << endl;
			return;
		}
		arr[++top] = k;
	}

	T pop()
	{
		if (top < 0)
		{
			cout << "Stack underflow!" << endl;
			return 0;
		}
		return arr[top--];
	}

	bool isEmpty()
	{
		return top < 0;
	}

	void clear()
	{
		top = -1;
	}

	void printStack()
	{
		if (top < 0)
		{
			cout << "Stack is empty." << endl;
			return;
		}
		for (int i = 0; i <= top; i++)
			cout << arr[i] << endl;
	}
};

class Auto
{
private:
	string name;
	double max_speed;

public:
	Auto() {} // Dodanie domyœlnego konstruktora

	Auto(string n, double s)
	{
		name = n;
		max_speed = s;
	}

	string getName()
	{
		return name;
	}

	double getMaxSpeed()
	{
		return max_speed;
	}

	friend ostream& operator<<(ostream& os, Auto a)
	{
		os << a.name << " " << a.max_speed;
		return os;
	}
};

class Plane
{
private:
	string name;
	double max_speed;

public:
	Plane() {} // Dodanie domyœlnego konstruktora

	Plane(string n, double s)
	{
		name = n;
		max_speed = s;
	}

	string getName()
	{
		return name;
	}

	double getMaxSpeed()
	{
		return max_speed;
	}

	friend ostream& operator<<(ostream& os, Plane p)
	{
		os << p.name << " " << p.max_speed;
		return os;
	}
};

int main()
{
	// Stosy dla Auto
	Stack<Auto> autoStack(4);

	// Dodaj Auto
	autoStack.push(Auto("Mercedes", 200));
	autoStack.push(Auto("Ferrari", 240));
	autoStack.push(Auto("Toyota", 160));
	autoStack.push(Auto("BMW", 180));

	// Wyœwietl zawartoœæ stosu
	autoStack.printStack();

	// Stos dla Samolotów
	Stack<Plane> planeStack(4);

	// Dodaj Samoloty
	planeStack.push(Plane("Boeing", 800));
	planeStack.push(Plane("Airbus", 750));
	planeStack.push(Plane("Embraer", 650));
	planeStack.push(Plane("Cessna", 400));

	// Wyœwietl zawartoœæ stosu
	planeStack.printStack();

	return 0;
}