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
				cout << custName <<endl;
				cout << custStadd <<endl;
				cout << custCSZ << endl;
				cout << custPhone << endl;
				cout << custLastPay << endl;
				cout << custAcctBal << endl;
				y=1;
			}		
	return y;		
	}
	
};

void showmenu();
void flush();
void ClearScreen();
void searchAcc(char);

vector<custAccounts> acctns(20);

int main()
{
	char response;
	char choice;
	int y;
	response ='y';
	showmenu();
	cin >> choice;
	flush();
	while (choice != '5')
    {
    	ClearScreen();
      	if(choice== '1')cout << "test 1" << endl;
	   		else
            	if(choice== '2') searchAcc(response);
					else          
						if(choice== '3')cout << "test 3" << endl;
							else       
								if(choice== '4')cout << "test 4" << endl;
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
		int vecsize;
		y=0;
		vecsize=acctns.size() +1;
		
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
}