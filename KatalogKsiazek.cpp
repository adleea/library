#include<cstring>
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;
#ifndef head
#define head
#include "Ksiazka.cpp"
#endif
#include "ListaWypozyczen.cpp"

#include "utility.h"

class KatalogKsiazek
{
private:
	int liczbaKsiazek ;
	vector<Ksiazka> katalog;
    ListaWypozyczen wypozyczenia;
public:
	KatalogKsiazek()
	{
		liczbaKsiazek = 0;
        wypozyczenia = ListaWypozyczen();
	};
	vector <Ksiazka> pokazKsiazki()
	{
		return katalog;
	}
	void dodajKsiazke(Ksiazka ksiazka)
	{
		katalog.push_back(ksiazka);
	}
	void usunKsiazke(int ID)
	{
		for(unsigned int i = 0; i < katalog.size(); i++)
		{
			if(katalog.at(i).pokazID() == ID)
				katalog.erase(katalog.begin() + i);
		}
	}

	void zrecenzuj(int ID, Recenzja recenzja)
	{
        Ksiazka *ksiazka = pokazKsiazke(ID);
        if (ksiazka) {
            ksiazka->zrecenzuj(recenzja);
        }
	}

    void wypozycz(int ID)
    {
        Ksiazka *ksiazka = pokazKsiazke(ID);
        if (ksiazka) {
            wypozyczenia.wypozycz(ksiazka);
        }
    }


    void zwroc(int ID)
    {
        Ksiazka *ksiazka = pokazKsiazke(ID);
        if (ksiazka) {
            wypozyczenia.anulujWypozyczenie(ksiazka);
        }
    }

    void przedluz(int ID)
    {
        wypozyczenia.przedluzTermin(ID);
    }

    void zarezerwuj(int ID)
    {
        Ksiazka *ksiazka = pokazKsiazke(ID);
        if (ksiazka) {
            ksiazka->zarezerwuj();
        }
    };

    void wypiszWszystkieKsiazki() {
        cout << "=== LISTA KSIAZEK: ===\n";
        for(unsigned int i = 0; i < katalog.size(); i++) {
            Ksiazka ksiazka = katalog.at(i);
            cout << ksiazka.pokazOpis() << "\n";
        }
        cout << "======================\n";
    }

    Ksiazka *pokazKsiazke(int ID) {
        for(unsigned int i = 0; i < katalog.size(); i++) {
            if(katalog.at(i).pokazID() == ID) {
                return &katalog.at(i);
            }
        }
        cerr << "Nie ma ksiazki o ID: " + to_string(ID) + ".\n";
        return NULL;
    }

    void wypiszDostepneKsiazki() {
        cout << "=== LISTA DOSTEPNYCH KSIAZEK: ===\n";
        for(unsigned int i = 0; i < katalog.size(); i++) {
            Ksiazka ksiazka = katalog.at(i);
            if (ksiazka.jestDostepna()) {
                cout << ksiazka.pokazOpis() << "\n";
            }
        }
        cout << "====================================\n";
    }

    void wypiszWypozyczoneKsiazki() {
        cout << "=== LISTA WYPOZYCZONYCH KSIAZEK: ===\n";
        wypozyczenia.wypiszWypozyczenia();
        cout << "====================================\n";
    }

    void wypiszZarezerwowaneKsiazki() {
        cout << "=== LISTA ZAREZERWOWANYCH KSIAZEK: ===\n";
        for(unsigned int i = 0; i < katalog.size(); i++) {
            Ksiazka ksiazka = katalog.at(i);
            if (ksiazka.jestZarezerwowana()) {
                cout << ksiazka.pokazOpis() << "\n";
            }
        }
        cout << "======================================\n";
    }
};
