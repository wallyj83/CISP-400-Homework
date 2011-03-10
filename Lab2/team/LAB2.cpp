//	Lab 2
//  Who: Group 2 Joshua Parker-Roriz, Devon Bonanno, Daniel Nakashima
//  When: 3/09/11

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Account
{
	private:
	string	name,
			address,
			cityStateZip,
			telephone_Number,
			date_Last_Payment;

	double	account_Balance;
			ofstream File;

	public:

	// default constructor initialize all to null or zero
	Account()
	{		
			name="";
			address="";
			cityStateZip="";
			telephone_Number="";
			date_Last_Payment="";
			account_Balance=0;
	}

	Account(string N,string A,string C,string T,string D, double Ab) //overloaded constructor
	{
				name=N;
				address=A;
				cityStateZip=C;
				telephone_Number=T;
				date_Last_Payment=D;
				account_Balance=Ab;
	}

	bool Write (); // write Account object to file
	bool Read(); // read account object from file

	void Copy(Account & A) // copy account object
	{		
			this ->name=A.name;
			this ->address=A.address;
			this ->cityStateZip=A.cityStateZip;
			this ->telephone_Number=A.telephone_Number;
			this ->date_Last_Payment=A.date_Last_Payment;
			this ->account_Balance=A.account_Balance;
	}


	// get input data; ***change to input from stdin 10%
	//{Account Local(" John doe","1101 first st", "ca 95555", "555-1212","12/07/2006",3560.00);
	void Cin()
	{
		 Account Local;
		
		 cout<<"Enter the customer's name:";
		 fflush(stdin);
		 getline (cin,Local.name);
		 
		 cout<<"Enter the customer's address:";
		 fflush(stdin);
		 getline (cin,Local.address);
		 
		 cout<<"Enter the city,state,zip:";
		 fflush(stdin);
		 getline(cin,Local.cityStateZip);
		 
		 cout<<"Enter the customer's telephone number:";
		 fflush(stdin);
		 getline(cin,Local.telephone_Number);
		 
		 cout<<"Enter the date of last payment:";
		 fflush(stdin);
		 getline(cin,Local.date_Last_Payment);
		 
		 cout<<"Enter the account balance:";
		 cin>>Local.account_Balance;

		 cin.get();

		 this->Copy(Local);

		return ;
	}

	//display Account object ***change to stdout 10%
	void Cout()
	{
		cout<<"\nName:                  "<<name<<endl;
		cout<<"\nAddress:               "<<address<<endl;
		cout<<"\nCity,State,Zip:        "<<cityStateZip<<endl;
		cout<<"\nPhone Number:          "<<telephone_Number<<endl;
		cout<<"\nDate of Last Payment:  "<<date_Last_Payment<<endl;
		cout<<"\nAccount Balance:       "<<account_Balance<<endl;
	 
	} 

};

// *** read next account object ,return false if no more object *** complete it 20%
 bool Account::Read() 
 {
	ifstream inFile;	
	char Tab = '\t';
	inFile.open("Account.txt",ios::in);
	  
    getline(inFile,name,Tab);
    
    while (!inFile.eof()) 
	{
	getline(inFile,address, Tab);
	getline(inFile,cityStateZip, Tab);
	getline(inFile,telephone_Number, Tab);
	getline(inFile,date_Last_Payment, Tab);
	inFile >> account_Balance;                		
	
	Cout();    
	inFile.ignore();
	
	getline(inFile,name, Tab);
    }	
	
	inFile.close();
	return false;
    
              		
}

bool Account::Write() {
	File.open("Account.txt",ios::app);
	char Tab='\t';

	if (!File) 
	{
		cout<<"can't open output file"<<endl;
		return false;
	}
	else File	<<	name				<<Tab
				<<	address				<<Tab
				<<	cityStateZip		<<Tab
				<<	telephone_Number	<<Tab
				<<	date_Last_Payment	<<Tab
				<<	account_Balance		<<Tab;
	File.close();
	return true;
}


int main()
{ 
		// complete the main such that
        //(1)***it will prompt user for input until no more 20%
        //(2)***write each account objects to file  10%
        //(3)***loop to print all account object from file 10%

	char choice;
	Account A; // create object	
	
	cout<<"ENTER NEW RECORD? (Y/N) ";
	cin>>choice;
	cin.ignore();
	
	while (toupper(choice)=='Y') 
	{
          A.Cin();
          A.Write();
          cout<<"ENTER NEW RECORD? (Y/N) ";
          cin>>choice;
    } 
    
    
	A.Read();   
	
	getchar();   
	return 0;
}
