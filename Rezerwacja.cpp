#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Rezerwacja {
private:
    int ID;

public:
    int status, nowyStatus;
    Rezerwacja(int ID){
        this->ID = ID;
        this->status = 0;
    };
    void zmienStatus(int nowyStatus){

        this->status = nowyStatus;
    };
    int pokazStatus(){

        return this->status;
    };
    int pokazID(){

        return this->ID;
    };
    
    int dodajID(){
        srand( (unsigned int)time( NULL ) );
        long int ID=(rand() % 500)+101;
        return (int)ID;
    };
};
