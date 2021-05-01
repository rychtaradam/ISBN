#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>


class Kniha	{
public:
	Kniha();
	Kniha(const std::string, const std::string, const std::string);
	Kniha(const Kniha&);

	std::string getISBN()const;
	bool setISBN(const std::string);
	std::string getAutor()const;
	bool setAutor(std::string);
	std::string getNazev()const;
	bool setNazev(std::string);
	
	friend std::ostream& operator<<(std::ostream&, const Kniha&);

private:
	std::string isbn;
	std::string autor;
	std::string nazev;

	bool kontrolaISBN(const std::string)const;
	bool kontrolaAutorNazev(const std::string)const;
};

