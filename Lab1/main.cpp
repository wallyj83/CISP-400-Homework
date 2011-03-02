/*
//  Project: Lab1 (lab1_main.cpp)
//
//  purpose: accepts user string for calendar date using format MM/DD/YY, converts 
//           character numerals to integer and prints date with month name as a  
//           character string (e.g. Jan)
//  
//  Who: Group 2
//  When: 2/10/11
//  What: 	Changed given code from C to C++ and added documentation. 
//			Changed the Date type memory allocation
*/

#include "date_type.h"
#include <iomanip>							// Added for Compiler issues
#include <iostream>							// Added for Compiler issues
using namespace std;

extern void displayResult(const DATE_TYPE&);
extern short int getDate(DATE_TYPE&);
extern bool validDate(DATE_TYPE&);
extern bool dateToString(DATE_TYPE&);


int main(void) {

	short int input = 0;
	// * change* DATE_TYPE *user_date = &(DATE_TYPE){0,0,0,0,""};  // Allocate memory for a DATE_TYPE
							  //    and assign address to a pointer
	
	DATE_TYPE user_date; // using pass by refrence, with no need for memory allocation
	do {
		input = getDate(user_date);		// get input from user

		switch (input) {

		case 0:	{	if (checkDate(user_date)) 
						{
							if (dateToString(user_date)) 
								{
								displayResult(user_date);
								} 
							else 
								{
								// dateToString error
								}
						} 
					else 
						{
						// checkDate error
						}
				}
		break;

		case 1: {	// getDate input error
			}
			break;

	} while (input < 9);

return 0;
}

