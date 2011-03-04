//CISP400 Lab2
//*** By  Jairus dela Vega
//*** using Visual Studio
//
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Account
{
    private:

    string   name,
             address,
             cityStateZip,
             telephone_Number,
             date_Last_Payment;
    double   account_Balance;
    fstream  File;
    long     numByte;
    
    public:
    
    Account()
    {
    //default constructor *** initialize all data member to null or zero 20%
        name = '\0';
        address = '\0';
        cityStateZip = '\0';
        telephone_Number = '\0';
        date_Last_Payment = '\0';
        account_Balance = 0.00;
        numByte = 0L;
    }  

    Account(string N,string A,string C,string T,string D, double Ab)//overloaded constructor
    {       name=N;
            address=A;
            cityStateZip=C;
            telephone_Number=T;
            date_Last_Payment=D;
            account_Balance=Ab;
            numByte = 0L;
    }
    bool Write (); // write Account object to file
    
    bool Read(); // read account object from file

    void Copy(Account & A) // copy account object
    {   this ->name=A.name;
        this ->address=A.address;
        this ->cityStateZip=A.cityStateZip;
        this ->telephone_Number=A.telephone_Number;
        this ->date_Last_Payment=A.date_Last_Payment;
        this ->account_Balance=A.account_Balance;
    }
        
    void Cin()// get input data; ***change to input from stdin 10%
    {
        //Account Local(" John doe","1101 first st", "ca 95555", "555-1212","12/07/2006",3560.00);
        //this->Copy(Local);
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter City, State and Zip Code: ";
        getline(cin, cityStateZip);
        cout << "Enter Phone Number: ";
        getline(cin, telephone_Number);
        cout << "Enter Date of Last Payment ";
        getline(cin, date_Last_Payment);
        cout << "Enter Account Balance: ";
        cin >> account_Balance;        
        return ;
    }
        
    void Cout()
    {
        cout<< "Print Account object....   "<<endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "City, State and Zip Code: " << cityStateZip << endl;
        cout << "Phone Number: " << telephone_Number << endl;
        cout << "Date of Last Payment: " << date_Last_Payment << endl;
        cout << "Account Balance: " << account_Balance << endl;
        return ;
    }
     //display Account object ***change to stdout 10%
};

int main()
{  // complete the main such that
        //(1)***it will prompt user for input until no more 20%
        //(2)***write each account objects to file  10%
        //(3)***loop to print all account object from file 10%
    const int SIZE = 1;
    Account A; // create object
    
    for(int i=0; i < SIZE; i++){
            A.Cin(); // initialize it
            A.Write();    // write it to end of file
            cin.ignore();
    }
    
    cout << "FILE CONTENTS" << endl;
    while(A.Read())
    {        A.Cout();
             cin.get();
    }
    cin.get();
    return 0;
}

bool Account::Write ()
{	File.open ("Account.txt", ios::out |ios::app); 
	char Tab='\t';
	if(!File)
	{ 
       cout << "can't open output file" <<endl;
       return false;
    }
	else File<< name<<Tab<<address<<Tab<<cityStateZip<<Tab<<telephone_Number<<Tab<<date_Last_Payment<<Tab<< account_Balance<<endl; File.close(); return true;
}

bool Account::Read()
{
    File.open ("Account.txt", ios::in);
    char Tab='\t';
    if(!File)
    {        cout << "Cannot read Account.txt. The file maybe missing or is corrupted" << endl;
             return false;
    }
    else
    {
        cout << " Reading contents of the file" << endl;
        File.seekg(numByte, ios::beg);         //tells where in the file will the program start to read info
        getline(File, name, Tab);
        getline(File, address, Tab);
        getline(File, cityStateZip, Tab);
        getline(File, telephone_Number, Tab);
        getline(File, date_Last_Payment, Tab);
        File >> account_Balance;
        numByte = File.tellg();               //tells current position of offset pointer
        //cout << "numByte: " << numByte << endl;
        
        if(File.eof())
        {
            File.close();
            cout << "Closing...";
            return false;    
        }
        else File.close(); return true;
    }
}
// *** read next account object ,return false if no more object *** complete it 20%


