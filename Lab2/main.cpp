/*
CISP400 Lab 2

C++ does not support object persistence, the ability of data objects to outlive the 
programs that created them. However, it's possible to create that capability through 
either user defined functions or more generally through add-on solutions[1].
The application program and accompanying class “Account” located at:
Y:\stu_data\Wei\cisp400\session 6_7\objFile.cpp
Demonstrates using user defined functions to achieve object persistency.
Even though the entire application compiles and runs; 
but both the application program and the Account class implementation 
are only partially complete.
Your assignment is to eliminate these voids.
And create an ISAM like file structure for the Account database.
Work as a team to complete the assignment
See the program source and ***ed comments for detail requirements as well as points assigned.
Please:

1.     upload your source code to your website and include the URL in the same email

2.     your email subject : cisp400 your_team lab2, please include the name of team mates in email as well

3.     you can use either Visual Studio or the Linux to test your modification, be sure to include this in your comments
*/

// CISP400 Lab2
// *** By  (Group 2, Joshua Parker-Roriz, Devon and Daniel)
//*** using Linux/Mac

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "account.h"
using namespace std;


extern bool Account::Write();
extern bool Account::Read();


int main() {  // complete the main such that 
		//(1)***it will prompt user for input until no more 20%
		//(2)***write each account objects to file  10%
		//(3)***loop to print all account object from file 10%

	char temp;
	Account A ; // create object

	do
	{
		A.Cin(); // initialize it
 		
 		A.Write();	// write it to end of file
	
	temp=A.statusre();
	
	}
	while(toupper(temp)=='Y');
	
return 0;
}

