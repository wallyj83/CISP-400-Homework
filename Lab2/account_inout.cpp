#include <string>
#include <fstream>
#include <iostream>
#include "account.h"
using namespace std;


void Account::Cin() {  // get input data; ***change to input from stdin 10%
	Account Local(" John doe","1101 first st", "ca 95555", "555-1212","12/07/2006",3560.00);
	this->Copy(Local);
	return ;
}

void Account::Cout() { //display Account object ***change to stdout 10%
	cout<< "print account object   "<<endl;
}

