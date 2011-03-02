#ifndef DATE_TYPE_DEF
#define DATE_TYPE_DEF
#include <string>					
using namespace std;

typedef struct {
	short int status;
	short int day;
	short int month;
	short int year;
	string date_string;
} DATE_TYPE;

#endif
