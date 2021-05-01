#include "Kniha.h"

const std::string defaultISBN = "978-0-321-56384-2";
const std::string defaultAutor = "Bjarne Stroustrup";
const std::string defaultNazev = "The C++ Programing Language";

// Výchozí konstruktor
Kniha::Kniha() {
	this->isbn = defaultISBN;
	this->autor = defaultAutor;
	this->nazev = defaultNazev;
}

//Konstruktor s parametry
Kniha::Kniha(const std::string isbn, const std::string autor, const std::string nazev) {
	if (!setISBN(isbn)) {
		this->isbn = defaultISBN;
		this->autor = defaultAutor;
		this->nazev = defaultNazev;
	}

	else if (!setAutor(autor)) {
		this->autor = defaultAutor;
		this->isbn = defaultISBN;
		this->nazev = defaultNazev;
	}

	else if (!setNazev(nazev)) {
		this->nazev = defaultNazev;
		this->isbn = defaultISBN;
		this->autor = defaultAutor;
	}
}

//Kopírovací konstruktor
Kniha::Kniha(const Kniha& k) {
	this->isbn = k.getISBN();
	this->nazev = k.getNazev();
	this->autor = k.getAutor();
}

//Getter a Setter pro ISBN
std::string Kniha::getISBN() const
{
	return this->isbn;
}

bool Kniha::setISBN(const std::string isbn)
{
	if (kontrolaISBN(isbn)) {
		this->isbn = isbn;
		return true;
	}

	else {
		return false;
	}
}

//Getter a Setter pro Autora
std::string Kniha::getAutor() const
{
	return this->autor;
}

bool Kniha::setAutor(std::string autor)
{
	if (kontrolaAutorNazev(autor)) {
		this->autor = autor;
		return true;
	}

	else {
		return false;
	}
}

//Getter a Setter pro Nazev
std::string Kniha::getNazev() const
{
	return this->nazev;
}

bool Kniha::setNazev(std::string nazev)
{
	if (kontrolaAutorNazev(nazev)) {
		this->nazev = nazev;
		return true;
	}

	else {
		return false;
	}
}

//Kontrola délky názvu a autora
bool Kniha::kontrolaAutorNazev(const std::string autornazev) const {
	if (autornazev.length() < 3 || autornazev.length() > 100) {
		return false;
	}
	else
		return true;
}

//Kontrola ISBN platnosti
bool Kniha::kontrolaISBN(const std::string isbn) const {
	//odtranìní pomlèky z ISBN
	std::string isbnbez = isbn;
	isbnbez.erase(remove(isbnbez.begin(), isbnbez.end(), '-'), isbnbez.end());

	int cislo;
	int zbytek = 0;

	//kontrola ISBN-10
	if (isbn.length() == 13) {
		cislo = 10;
		for (int i = 0; i < 9; i++) {
			zbytek += std::stoi(isbnbez.substr(i, 1)) * cislo;
			cislo--;
		}

		//kontrola jestli je kontrolní èíslice èíslo nebo X
		if (isbnbez.substr(9, 1) == "X") {
			zbytek += 10;
		}
		else {
			zbytek += std::stoi(isbnbez.substr(9, 1));
		}

		if (zbytek % 11 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//kontrola ISBN-13
	else if (isbn.length() == 17) {
		cislo = 1;
		for (int i = 0; i < 13; i++) {
			zbytek += std::stoi(isbnbez.substr(i, 1)) * cislo;
			if (cislo == 1) {
				cislo = 3;
			}
			else {
				cislo = 1;
			}
		}

		if (zbytek % 10 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

void rozdeleniISBN(std::string isbn) {
	std::replace(isbn.begin(), isbn.end(), '-', ' ');

	std::string rozdeleni[5];
	int i = 0;
	int reg = 0;
	std::stringstream ssin(isbn);
	while (ssin.good() && i < 5) {
		ssin >> rozdeleni[i];
		i++;
	}

	if (rozdeleni[0] != "978") {
		for (i = 4; i > 0; i--) {
			rozdeleni[i] = rozdeleni[i - 1];
		}

		rozdeleni[0] = "000";
		reg = 1;
	}

	std::string regiony[9] = { "(anglicky)", "(francouzsky)", "(nemecky)", "(japonsky)", "(rusky)", "(cinsky)", "(cesky, slovensky)" };

	int x = 0;

	switch (std::stoi(rozdeleni[1])) {
		case 0:
			x = 0;
			break;
		case 1:
			x = 0;
			break;
		case 2:
			x = 1;
			break;
		case 3:
			x = 2;
			break;
		case 4:
			x = 3;
			break;
		case 5:
			x = 4;
			break;
		case 6:
			x = 5;
			break;
		case 80:
			x = 6;
			break;
	}
	
	std::cout << " Prefix: " << rozdeleni[0] << " Region: " << rozdeleni[1] << " " << regiony[x] << " Vydavatel: " << rozdeleni[2] << " Vydani: " << rozdeleni[3] << std::endl;
}

//Pøátelská metoda pro výpis ISBN, autora a názvu knihy
std::ostream& operator<<(std::ostream& os, const Kniha& kniha) {
	os << "ISBN : " << kniha.isbn;
	rozdeleniISBN(kniha.isbn);
	std::cout << "Autor: " << kniha.autor << std::endl
		<< "Nazev: " << kniha.nazev << std::endl;
	return os;
}
