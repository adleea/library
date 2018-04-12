#include <iostream>
#include <vector>
#include <cstdlib>
#include "Rezerwacja.cpp"

using namespace std;

//Tworzenie klasy

class ListaRezerwacji{

private:
        int liczbaRezerwacji;
        vector <Rezerwacja> lista_r;
public:
        ListaRezerwacji(){

            liczbaRezerwacji = 0;
        };

        void anuluj_rezerwacje(int ID){

            for(int i=0; i<lista_r.size(); i++)
            {
                if(lista_r.at(i).pokazID() == ID)
                    lista_r.erase(lista_r.begin()+i);
            }
        }
       // pokaz1rezerwacje();

        vector <Rezerwacja>  pokaz_rezerwacje()
        {
            return lista_r;
        };

        void zrob_rezerwacje(int ID){

//            for(int i=0; i<katalog.size(); i++)
//            {
//                if(katalog.at(i).pokazID() == ID)
//                    lista_r.push_back(Rezerwacja);
//            }
        }

};
