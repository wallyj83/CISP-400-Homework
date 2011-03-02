//
/*Chapter 9 Programming Challenge 2 (CH9PC2)
1. Array Allocator
Write a function that dynamically allocates an array of integers. The function should accept an
integer argument indicating the number of elements to allocate. The function should return a pointer to  the array.
*/
//  CISP 400
//  Joshua Parker-Roriz
//  main.cpp
//  HomeWork 1
//


#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


vector<int> myvector;

int main ()
{
	
    int temp;
   
    
    cout << " The current size of the vector is: " << (int) myvector.size() << endl;
    cout << " Please enter a number of ellements to create: ";
    cin >> temp;
    while(cin.get() != '\n');
  	myvector.resize(temp);
  	cout << " The current size of the vector is: " << (int) myvector.size() << endl;
    cout << " Press any key to end";
    while(cin.get() != '\n');
    return 0;
}

