#include<cstring>
#include<vector>
#include<iostream>
#include"KatalogKsiazek.cpp"

using namespace std;
int Ksiazka::nextID = 0;
void wypelnijKatalog(KatalogKsiazek *katalog);

int main()
{
	KatalogKsiazek *katalog = new KatalogKsiazek();
    wypelnijKatalog(katalog);

    // TEST WYPELNIENIA KATALOGU:
    katalog->wypiszWszystkieKsiazki();

    katalog->wypiszDostepneKsiazki();
    katalog->wypiszZarezerwowaneKsiazki();
    katalog->wypiszWypozyczoneKsiazki();

    // TEST WYPOZYCZANIA I REZERWOWANIA:
    katalog->wypozycz(1);
    katalog->wypozycz(1);
    katalog->zarezerwuj(1);
    katalog->zarezerwuj(2);
    katalog->wypozycz(34);
    katalog->wypiszWszystkieKsiazki();

    katalog->wypiszDostepneKsiazki();
    katalog->wypiszZarezerwowaneKsiazki();
    katalog->wypiszWypozyczoneKsiazki();

    // TEST ZMIANY RECENZJI:
    Ksiazka *ksiazka = katalog->pokazKsiazke(0);
    ksiazka->zrecenzuj(Recenzja("Calkiem ciekawa ksiazka", 5));

    katalog->wypiszWszystkieKsiazki();

    // TEST PRZEDLUZANIA TERMINU ODDANIA:
    katalog->przedluz(1);
    katalog->wypiszWypozyczoneKsiazki();

    // TEST ZWRACANIA WYPOZYCZONEJ KSIAZKI:
    katalog->zwroc(1);
    katalog->zwroc(1);
    katalog->zwroc(2);

    katalog->wypiszWszystkieKsiazki();


	delete katalog;
	return 0;
}

void wypelnijKatalog(KatalogKsiazek *katalog)
{
    Recenzja recenzja("slabe" , 2);
    Ksiazka ksiazka1("J.R.R Tolkien", "Bractwo Pierscienia", 0, recenzja);
    Ksiazka ksiazka2("J.R.R Tolkien", "Dwie Wieze", 0, recenzja);
    Ksiazka ksiazka3("J.R.R Tolkien", "Powrot Krola", 0, recenzja);

    katalog->dodajKsiazke(ksiazka1);
    katalog->dodajKsiazke(ksiazka2);
    katalog->dodajKsiazke(ksiazka3);
}
