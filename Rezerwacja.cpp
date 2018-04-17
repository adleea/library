#include <iostream>
#include <vector>
#include <cstdlib>
#ifndef head
#define head
#include "Rezerwacja.cpp"
#include "KatalogKsiazek.cpp"
#endif

using namespace std;


class ListaRezerwacji{

private:
        int liczbaRezerwacji;
        vector <Rezerwacja> lista_r;
public:
        ListaRezerwacji(){

            liczbaRezerwacji = 0;
        };

        void anuluj_rezerwacje(Rezerwacja *rezerwacja){
         {
        for(int i = 0; i < static_cast<int>(lista_r.size()); i++)
        {
            if(lista_r.at(i).pokazID() == rezerwacja->pokazID())
                lista_r.erase(lista_r.begin()+i);
        }
        rezerwacja->zwroc();
    }
           
       

        vector <Rezerwacja>  pokaz_rezerwacje()
        {
            return lista_r;
        };

        void zrob_rezerwacje(int ID){

            for(int i=0; i<katalog.size(); i++)
            {
                if(katalog.at(i).pokazID() == ID)
                    lista_r.push_back(Rezerwacja);
            }
        }

};
