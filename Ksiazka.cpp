#include<cstring>
#include <sstream>
#include"Recenzja.cpp"
#include<iostream>
using namespace std;
class Ksiazka
{
private:
	string autor;
	string tytul;
	Recenzja recenzja;
	static int nextID;
	int ID;

    void zmienStatus(int nowyStatus)
    {
        this->status = nowyStatus;
    }

public:
	int status;
	Ksiazka(string autor, string tytul, int status, Recenzja recenzja)
	{
		this->autor = autor;
		this->tytul = tytul;
		this->ID = nextID;
		this->status = status;
		this->recenzja = recenzja;
		nextID++;
	}

	int pokazID(){
		return ID;
	}
	
	string pokazAutora()
	{
		return autor;
	}

	string pokazTytul()
	{
		return tytul;
	}

	int pokazStatus()
	{
		return status;
	}

    string opisStatusu() {
        if (status == 0) {
            return "Dostepna";
        } else if (status == 1) {
            return "Zarezerwowana";
        } else if (status == 2) {
            return "Wypozyczona";
        }
        return "Niepoprawny status";
    }

	string pokazRecenzje()
	{
		return recenzja.pokazRecenzje();
	}
	void zrecenzuj(Recenzja recenzja)
	{
		this->recenzja = recenzja;

	}
    string pokazOpis()
    {
    	stringstream ss;
    	ss<<+ ". " + autor + ", " + tytul + ". Recenzja: " + recenzja.pokazRecenzje() + ". Status: " + opisStatusu();
        return ss.str();			//ID) + ". " + autor + ", " + tytul + ". Recenzja: " + recenzja.pokazRecenzje() + ". Status: " + opisStatusu();
    }

    void zarezerwuj()
    {
    	stringstream ss;
        if (status == 0) {
            zmienStatus(1);
        } else {
        	ss<< ".\n";
            cerr << "Nie mozna zarezerwowac ksiazki o ID: " << ss.str();		//to_string(ID) << ".\n";
        }
    }

    void wypozycz()
    {
    	stringstream ss;
        if (status == 0) {
            zmienStatus(2);
        } else {
        	ss<< ".\n";
            cerr << "Nie mozna wypozyczyc ksiazki o ID: " << ss.str();		//to_string(ID) << ".\n";
        }
    }

    void zwroc()
    {
    	stringstream ss;
        if (status == 2) {
            zmienStatus(0);
        } else {
        	ss<< ".\n";
            cerr << "Nie mozna zwrocic ksiazki o ID: " << ss.str();			//to_string(ID) << ".\n";
        }
    }

    bool jestWypozyczona()
    {
        return status == 2;
    }

    bool jestZarezerwowana()
    {
        return status == 1;
    }

    bool jestDostepna()
    {
        return status == 0;
    }
};


