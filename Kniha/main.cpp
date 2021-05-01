#include "Kniha.h"

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	Kniha k1;
	Kniha k2("80-251-0897-X", "B. W. Kernighan, Dennis M. Ritchie", "Programovaci jazyk C");
	Kniha k3(k2);

	cout << "Objekt k1 vytvoreny vychozim konstruktorem" << endl
		<< "------------------------------------------" << endl
		<< k1 << endl;

	cout << "Objekt k2 vytvoreny konstruktorem s parametry" << endl
		<< "---------------------------------------------" << endl
		<< k2 << endl;

	cout << "Objekt k3 vytvoreny kopirovacim konstruktorem" << endl
		<< "---------------------------------------------" << endl
		<< k3 << endl;

	cout << "Zadani udaju o knize" << endl
		<< "--------------------" << endl;

	cout << "ISBN                  : ";
	std::string isbn;
	std::getline(cin, isbn);

	cout << "Autor (3 az 100) znaku: ";
	std::string autor;
	std::getline(cin, autor);

	cout << "Nazev (3 az 100) znaku: ";
	std::string nazev;
	std::getline(cin, nazev);

	cout << endl;

	if (k1.setISBN(isbn) && k1.setAutor(autor) && k1.setNazev(nazev)) {
		cout << "Objekt k1 po zmene" << endl
			<< "------------------" << endl
			<< k1 << endl;
	}

	else {
		cout << "Chybne zadane udaje." << endl;
		cout << endl;
	}
}