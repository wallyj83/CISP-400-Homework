#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Account 
{
private:
	string 	name,
	      	address,
		    cityStateZip,
		    telephone_Number,
		    date_Last_Payment;
	
	double 	account_Balance;
	
	double place_holder;
	
	ofstream File;
	
	
public:
	
	Account()//default constructor *** initialize all data member to null or zero 20%
		{
			name = '\0';
        	address = '\0';
        	cityStateZip = '\0';
        	telephone_Number = '\0';
        	date_Last_Payment = '\0';
        	account_Balance = 0.00;
        	place_holder = 0;
		}  

		Account(string N,string A,string C,string T,string D, double Ab) //overloaded constructor
		{ 
			name=N;			
			address=A;
			cityStateZip=C;
			telephone_Number=T;
			date_Last_Payment=D;
			account_Balance=Ab;
			place_holder = 0;
		}

		bool Write (); // write Account object to file

		bool Read(); // read account object from file

		void Copy(Account & A) // copy account object
		{ 
			this ->name = A.name;
			this ->address = A.address;
			this ->cityStateZip = A.cityStateZip;
			this ->telephone_Number = A.telephone_Number;
			this ->date_Last_Payment=A.date_Last_Payment;
			this ->account_Balance=A.account_Balance;
		}

		void Cin() // get input data; ***change to input from stdin 10%
		{  
			/* Example from Prof
			Account Local(" John doe","1101 first st", "ca 95555", "555-1212","12/07/2006",3560.00);
	 		this->Copy(Local);
			return ;
			*/
			cout << " Please enter your Name: ";
			getline(cin, name);
			cout << " Please enter your Street Address: ";
			getline(cin, address);
			cout << " Please enter your City, State and Zip code: ";
			getline(cin, cityStateZip);
			cout << " Please enter your phone number: ";
			getline(cin, telephone_Number);
			cout << " Please enter the date of your last payment(Month/day/Year): ";
			getline(cin, date_Last_Payment);
			cout << " Please enter your account balance: ";
			getline(cin, account_Balance);
			return;
		}

		void Cout()//display Account object ***change to stdout 10% 
		{ 
			cout << " Printing account information    "<<endl;
			cout << " Name: " << name << endl;
			cout << " Address: " << address << endl;
			cout << " City, state and zip code: " << cityStateZip << endl;
			cout << " Phone number: " << telephone_Number << endl;
			cout << " Date of last payment: " << date_Last_Payment << endl;
			cout << " Account balance: " << account_Balance << endl;
			return;
			
		}
};

#endif

