#include<cstring>
#include<cstdlib>
#include <sstream>
using namespace std;
class Recenzja{
	
private:
	string recenzja;
	int ocena;
public:
	Recenzja(string rec, int nota){
		recenzja = rec;
		ocena = nota;
		
	}
	Recenzja(){};
    
	string pokazRecenzje(){
		stringstream ss;
		ss << recenzja << " " << ocena;
		return ss.str();
	}
	
};
