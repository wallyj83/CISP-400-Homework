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

class Phone_list
{
private:
	
	string 	name,
			phone;

public:

	Phone_list()
	{
		name = '\0';
		phone = '\0';
	};
	void addPhone(string a, string b)
	{
		name = a;
		phone = b;
	}
	int viewName(string tempName, int i, int y)
	{
		
		size_t found;
		found=name.find(tempName);
		if (found!=string::npos)
			{
				cout << name << ", " <<phone <<endl;
				y=1;
			}		
	return y;		
	}
	
	
};

vector<Phone_list> list(11);


int main()
{

list[0].addPhone("Becky Warren","678-1223");
list[1].addPhone("Joe Looney", "586-0097");
list[2].addPhone("Geri Palmer", "223-8787");
list[3].addPhone("Lynn Presnell", "887-1212");
list[4].addPhone("Holly Gaddis", "223-8878");
list[5].addPhone("Sam Wiggins", "486-0998");
list[6].addPhone("Bob Kain", "586-8712");
list[7].addPhone("Tim Haynes", "586-7676");
list[8].addPhone("Warren Gaddis", "223-9037");
list[9].addPhone("Jean James", "678-4939");
list[10].addPhone("Ron Palmer", "486-2783");


	string tempStr;
	int i;
	int y;
	
	char response;
		cout << "Would you like to search for phone numbers?(y/n)";
		cin >> response;
	while(toupper(response) == 'Y')
		{
		cout << "Please enter the name or partial name to search for";
		cout << ": ";
		cin >> tempStr;
		y=0;
		for(i=0; i < 11; i++)
			{
			y =list[i].viewName(tempStr, i, y);
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