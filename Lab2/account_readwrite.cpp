#include <string>
#include <fstream>
#include <iostream>
#include "account.h"
using namespace std;


bool Account::Write () {
	File.open ("Account.txt",ios::app); 
	char Tab='\t';
	if(!File) {
		cout << " can't open output file"<<endl; return false;
	} else {
		File<<name<<Tab
		  <<address<<Tab
		  <<cityStateZip<<Tab
		  <<telephone_Number<<Tab
		  <<date_Last_Payment<<Tab
		  << account_Balance<<endl;
	}
	return true;
}

bool Account::Read() { return false; }
// *** read next account object ,return false if no more object *** complete it 20%

