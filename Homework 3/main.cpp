/* 
10. Phone Number List
Write a program that has an array of at least 10 string objects that 
hold people’s names and phone numbers. You may make up your own strings, 
or use the following:
“Becky Warren, 678-1223”
“Joe Looney, 586-0097”
“Geri Palmer, 223-8787”
“Lynn Presnell, 887-1212”
“Holly Gaddis, 223-8878”
“Sam Wiggins, 486-0998”
“Bob Kain, 586-8712”
“Tim Haynes, 586-7676”
“Warren Gaddis, 223-9037”
“Jean James, 678-4939”
“Ron Palmer, 486-2783”
The program should ask the user to enter a name or partial name to search for in the array. 
Any entries in the array that match the string entered should be displayed. For example, 
if the user enters “Palmer” the program should display the following names from the list:
Geri Palmer, 223-8787
Ron Palmer, 486-2783 
*/
//  CISP 400
//  Joshua Parker-Roriz
//  main.cpp
//  Homework 3
//	CH10PC10

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

typedef struct Phone_list
{
	string name;
	string phone;

} Phone_list;

Phone_list vecList[11];


int main()
{

vecList[0].name = "Becky Warren";
vecList[0].phone = "678-1223";
vecList[1].name = "Joe Looney";
vecList[1].phone = "586-0097";
vecList[2].name = "Geri Palmer";
vecList[2].phone = "223-8787";
vecList[3].name = "Lynn Presnell";
vecList[3].phone = "887-1212";
vecList[4].name =  "Holly Gaddis";
vecList[4].phone = "223-8878";
vecList[5].name = "Sam Wiggins";
vecList[5].phone ="486-0998";
vecList[6].name = "Bob Kain";
vecList[6].phone ="586-8712";
vecList[7].name = "Tim Haynes";
vecList[7].phone ="586-7676";
vecList[8].name = "Warren Gaddis";
vecList[8].phone ="223-9037";
vecList[9].name = "Jean James";
vecList[9].phone ="678-4939";
vecList[10].name = "Ron Palmer";
vecList[10].phone ="486-2783";

	string tempStr;
	size_t found;
	int i;
	int y;
	
	char response;
		cout << "Would you like to search for phone numbers?(y/n)";
		cin >> response;
	while(toupper(response) == 'Y')
		{
		cout << "Please enter the name or partial name to search for." << endl;
		cout << ": ";
		cin >> tempStr;
		y=0;
		for(i=0; i < 11; i++)
			{
			found=vecList[i].name.find(tempStr);
			if (found!=string::npos)
				{
				cout << vecList[i].name <<", " <<  vecList[i].phone <<endl;
				y=1;
				}
			}	
			if (y==0)
				{
				cout << "\nUnable to find the name you entered" << endl;
				}
			cout << "\nWould you like like to try again?(y/n) ";
			cin >> response;
		}
		cout << "Thank you for using this program"<< endl;
	return 0;
}