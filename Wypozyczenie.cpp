#include <iostream>
#include "Data.cpp"
#include "utility.cpp"

using namespace std;

class Wypozyczenie{

private:
    int ID;
    Data data;
public:
    Wypozyczenie(int ID, Data data) : data(2018,5,31)
    {
        this->ID = ID;
        this->data = data;
    }

    void przedluz(int dni)
    {
        data.dodajDni(dni);
    }

    int pokazID()
    {
        return ID;
    }

    string pokazOpis() {
        return "Ksiazka o ID: " + to_string(ID) + " jest wypozyczona do " + data.pokazDate();
    }
};


