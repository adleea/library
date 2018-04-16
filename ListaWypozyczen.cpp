#include <iostream>
#include <vector>
#include "Wypozyczenie.cpp"
#ifndef head
#define head
#include "Ksiazka.cpp"
#endif
using namespace std;

class ListaWypozyczen {
private:
    int liczbaWypozyczen;
    vector<Wypozyczenie> lista_w;
public:
    ListaWypozyczen() {
        liczbaWypozyczen = 0;
    };
    
    void anulujWypozyczenie(Ksiazka *ksiazka)
    {
        for(int i = 0; i < static_cast<int>(lista_w.size()); i++)
        {
            if(lista_w.at(i).pokazID() == ksiazka->pokazID())
                lista_w.erase(lista_w.begin()+i);
        }
        ksiazka->zwroc();
    }

    void przedluzTermin(int ID)
    {
        for(int i = 0; i < static_cast<int>(lista_w.size()); i++)
        {
            if(lista_w.at(i).pokazID() == ID)
            {
                Wypozyczenie *w = &lista_w.at(i);
                w->przedluz(20);
            }
        }
    }

    void wypozycz(Ksiazka *ksiazka) {
        if(ksiazka->jestDostepna()) {
            ksiazka->wypozycz();
            Data data = Data(2018, 12, 12);
            Wypozyczenie w = Wypozyczenie(ksiazka->pokazID(), data);
            lista_w.push_back(w);
        }
    }
    
    void wypiszWypozyczenia() {
        for(int i = 0; i < static_cast<int>(lista_w.size()); i++) {
            cout << lista_w.at(i).pokazOpis() << endl;
        }
    };
};
