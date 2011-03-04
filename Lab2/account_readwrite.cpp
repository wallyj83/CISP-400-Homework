#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "account.h"
using namespace std;


bool Account::Write () 
{
	File.open ("Account.txt", ios::out | ios::app); 
	char Tab='\t';
	if(!File) 
		{
		cout << " can't open output file"<<endl; 
		return false;
		} 
	else 
	{
		File<<name<<Tab
		<<address<<Tab
		<<cityStateZip<<Tab
		<<telephone_Number<<Tab
		<<date_Last_Payment<<Tab
		<<account_Balance<<endl;
		
	}
	
	File.close();
	
	return true;
}

bool Account::Read() // *** read next account object ,return false if no more object *** complete it 20%
{ 

File.open ("Account.txt", ios::in); 
	char Tab='\t';
	if(!File) 
		{
		cout << "Can not read file Account.txt " <<endl; 
		return false;
		} 
	else 
	{
		cout << " Current accoutns recorded are: " << endl;
		file.seekg(place_holder, ios::beg);
		getline(File, name, Tab);
		getline(File, address, Tab);
		getline(File, cityStateZip, Tab);
		getline(File, telephone_Number, Tab);
		getline(File, date_Last_Payment, Tab);
		getline(File, account_Balance);
		place_holder = File.tellg();
		
		if(File.eof())
		{
			File.close();
			cout << "End of file";
			return false;
		}
		else
		{
			file.close();
			Return true;
		}
		
	}
	
 }


