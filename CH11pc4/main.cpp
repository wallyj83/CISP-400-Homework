/*
 Chapter 11 Programming Challenge 4 (CH11PC4)
 
 4. Customer Accounts
 Write a program that uses a class to store the following data about a 
 customer account:
 Name
 Address
 City, state, and ZIP
 Telephone number
 Account Balance
 Date of last payment
 The program should use an array of at least 20 class objects. It 
 should let the user enter data into the array, change the contents 
 of any element, and display all the data stored in the array. 
 The program should have a menu-driven user interface.
 Input Validation: When the data for a new account is 
 entered, be sure the user enters data for all the fields. 
 No negative account balances should be entered.
 
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class custAccounts
{
private:
    
    string 	custName,
    custStadd,
    custCSZ,
    custPhone,
    custLastPay;
    
    int accNum;
    
    float 	custAcctBal;
	
    
    
public:
    
    custAccounts()
	{
	
    custName = '\0';
    custStadd = '\0';
    custCSZ = '\0';
    custPhone = '\0';
    custLastPay = '\0';
    custAcctBal = 0;
	}
    
    int viewName(string tempName, int i, int y)
	{
    size_t found;
    found=custName.find(tempName);
    if (found!=string::npos)
        {
        cout <<"Account Number: "<< accNum << endl;
        cout <<"Customer name: "<< custName <<endl;
        cout <<"Customer Street Address: "<< custStadd <<endl;
        cout <<"Customer City State zip: "<< custCSZ << endl;
        cout <<"Customer Phone Number: "<< custPhone << endl;
        cout <<"Customer last pay date: " << custLastPay << endl;
        cout <<"Customer Account Balance: " <<  custAcctBal << endl << endl;
        y=1;
        }		
    return y;		
	}
    
    void allcustAcc()
    {
    cout <<"Account Number: "<< accNum << endl;
    cout <<"Customer name: "<< custName <<endl;
    cout <<"Customer Street Address: "<< custStadd <<endl;
    cout <<"Customer City State zip: "<< custCSZ << endl;
    cout <<"Customer Phone Number: "<< custPhone << endl;
    cout <<"Customer last pay date: " << custLastPay << endl;
    cout <<"Customer Account Balance: " <<  custAcctBal << endl << endl;
    
    }
    
    void addCust(int z, string a, string b, string c, string d, string e, float f)
    {
    accNum = z;
    custName = a;
    custStadd = b;
    custCSZ = c;
    custPhone = d;
    custLastPay = e;
    custAcctBal = f;
    
    }
	
};


void showmenu();
void showmenu1();
void flush();
void ClearScreen();
void searchAcc(char);
void addAcc();
void editAcc();
void printall();

vector<custAccounts> acctns(10);

int main()
{
    acctns[0].addCust(1,"Becky Warren","15 North Road","State, City, 01538","678-1223","10/05/09",300.00);
    acctns[1].addCust(2,"Joe Looney","22 North Road","State, City, 01538","586-0097","11/09/09",250.00);
    acctns[2].addCust(3,"Geri Palmer","22 South Road","State, City, 01538","223-8787","1/07/09",350.00);
    acctns[3].addCust(4,"Lynn Presnell","16 east Road","State, City, 01538","887-1212","12/09/10",150.00);
    acctns[4].addCust(5,"Holly Gaddis","85 west Road","State, City, 01538","223-8878","2/23/09",50.00);
    acctns[5].addCust(6,"Sam Wiggins","33 west will way","State, City, 01538","486-0998","3/09/09",25.00);
    acctns[6].addCust(7,"Bob Kain","89 North Road","State, City, 01538","586-8712","4/09/09",86.00);
    acctns[7].addCust(8,"Tim Haynes","110 21st ave","State, City, 01538","586-7676","5/09/09",235.00);
    acctns[8].addCust(9,"Warren Gaddis","19 36 ave ","State, City, 01538","223-9037","6/09/09",190.00);
    acctns[9].addCust(10,"Jean James","235 North Road","State, City, 01538","678-4939","7/09/09",310.00);
    
    
	char response;
	char choice;
	response ='y';
	showmenu();
	cin >> choice;
	flush();
	while (choice != '5')
        {
    	ClearScreen();
      	if(choice== '1') addAcc();
        else
            if(choice== '2') searchAcc(response);
            else          
                if(choice== '3')cout << "test 3" << endl;
                else       
                    if(choice== '4')printall();
                    else
                        cout << "That's not a choice."<<endl;
        
        showmenu();
        cin>>choice;flush();
        }
    cout << "Bye!\n";
    
	return 0;
}
void showmenu()
{
    cout << "Please enter 1, 2, 3, 4, or 5:"<<endl<<
    "1) Enter Data 			2) Search"<<endl<<
    "3) Update Data		        4) Show All"<<endl<<
    "5) quit"<<endl;
}
void showmenu1()
{
    cout << "Please slect wich field to edit:"<<endl<<
    "1) Name 						2) Street Address"<<endl<<
    "3) City State Zip	     	4) Phone Numer"<<endl<<
    "5) Last date of Payment	6) Balanace"<<endl<<
    "7) Quit"<<endl;
}


void flush()
{
	char ch;
	while ( ch=cin.get()!= '\n');
}

void ClearScreen()
{//begin ClearScreen
#ifdef _WIN32
    system("cls");//windows
#else
    system("clear");//linux
#endif
}//end ClearScreen

void searchAcc(char response)
{
	while(toupper(response) == 'Y')
		{
		string tempStr;
		int i;
		int y;
		long vecsize;
		y=0;
		vecsize=acctns.size();
		
		cout << "Please enter the name or partial name to search for";
		cout << ": ";
		cin >> tempStr;
		
		for(i=0; i < vecsize; i++)
			{
			y =acctns[i].viewName(tempStr, i, y);
            
			}
        
        
        if (y==0)
            {
            cout << "\nUnable to find the name you entered" << endl;
            }
        cout << "\nWould you like like to try again?(y/n) ";
        cin >> response;
        }
    return ;
}

void addAcc()
{
    long vecsize;
    int myInt;
    int acctemp;
    myInt=1;
    string a, b, c, d,  e; 
    float f;
    vecsize=acctns.size();
    acctemp = (int)vecsize+1;
    acctns.push_back(custAccounts());
    cout << "Please enter the Customer's First and Last Name." << endl;
    cout << ": ";
    getline(cin, a);
    cout <<" Please enter the Customer's Street Address." << endl;
    cout << ": ";
    getline(cin, b);
    cout <<"Please enter the Customer's City, State, Zip." << endl;
    cout << ": ";
    getline(cin, c);
    cout <<"Please enter the Customer's Phone Number." << endl;
    cout << ": ";
    getline(cin, d);
    cout <<"Please enter the Customer's last date of payment" << endl;
    cout <<": ";
    getline(cin, e);
    cout <<"Please enter the account balance for the customer" << endl;
    cout <<": ";
    cin >> f;
    
    acctns[vecsize].addCust(acctemp, a,b,c,d,e,f);
    return;
}

void printall()
{
    long vecsize;
    int i;
    vecsize=(int)acctns.size();
    for(i=0; i < vecsize; i++)
        {
        
        acctns[i].allcustAcc();
        
        }
}
void editAcc()
{
    int vectemp;
    char choice;
    cout << "Please enter the account number you wish to edit"<< endl;
    cout << ": ";
   	cin >> vectemp;
   	showmenu1();
	vectemp=vectemp-1;
	cin >> choice;
	flush();
	while (choice != '7')
        {
    	ClearScreen();
      	if(choice== '1') 
        	{
            cout <<"Please enter the Customer's First and Last name."<<endl;
            cout <<": ";
            cin>>acctns[vectemp].custName;
           }    
        else
            if(choice== '2') searchAcc(response);
            else          
                if(choice== '3')cout << "test 3" << endl;
                else       
                    if(choice== '4')printall();
                    else
                        if(choice== '5')printall();
                        else
                            if(choice== '6')printall();
                            else
                            cout << "That's not a choice."<<endl;
        
        showmenu();
        cin>>choice;flush();
        }

    
}