#include "date_type.h"
#include <iostream>

using namespace std;

short int getDate(DATE_TYPE &);
void string_To_MDY(string,  DATE_TYPE &);
char * Strchcpy(char *, char * , int);

short int getDate(DATE_TYPE &user_date) {

	// prompt user to quit or input date, parse and store in a DATE_TYPE
	// return 0 if all well, 1-8 for problems, 9 for user quit
	short ret;
	char response;    //user input: "Y" or "N" determines whether the program runs
  	string date_string; //user input: calendar date in MM/DD/YY format
	cout << "\n\nDo you want to convert and validate a date?(Y/N): ";
  	cin >> response;
  	if (toupper(response) == 'Y')
  	{
  	cout << "\nEnter the date in mm/dd/yy form: ";
    cin >> date_string;
	string_To_MDY(date_string, user_date);
	ret = 0;
	}
	else 
	{
	ret = 9;
	}
return ret;
}



void string_To_MDY(string data, DATE_TYPE &user_date)
{
  
  	char month[3],
       	day[3],
       	year[3];
  	char * ch_ptr;


	ch_ptr = new char [data.size()+1];

	strcpy (ch_ptr, data.c_str());

  ch_ptr = Strchcpy(month, ch_ptr, '/');
  ++ch_ptr;
  ch_ptr = Strchcpy(day, ch_ptr, '/');
  ++ch_ptr;
  Strchcpy(year, ch_ptr, '\0');
	
  user_date.month = atoi(month);
  user_date.day   = atoi(day);
  user_date.year  = atoi(year);
	
} 


char * Strchcpy(char * target, char * source, int ch)
{
  while (*source != ch && *source != '\0')
    {
      *target = *source;
      ++target;
      ++source;
    }

  *target = '\0';

  return source;

}


