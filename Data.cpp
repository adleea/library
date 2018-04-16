#include<cstring>
#include<sstream>
#include <time.h>

using namespace std;
class Data
{

private:
    struct tm data;
public:
	Data(int year, int month, int day)
	{
        data.tm_sec = 0;
        data.tm_min = 0;
        data.tm_hour = 12;
        data.tm_year = year - 1900;
        data.tm_mon = month - 1;
        data.tm_mday = day;
	}

	string pokazDate()
	{
		stringstream ss;
		ss << data.tm_mday << "/" << data.tm_mon + 1 << "/" << data.tm_year + 1900;
		return ss.str();
	}

    void dodajDni(int dni)
    {
        const time_t DZIEN = 24 * 60 * 60 ;

        time_t sekundy = mktime( &data ) + (dni * DZIEN);

        data = *localtime( &sekundy );
    }
};
