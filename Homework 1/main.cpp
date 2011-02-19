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
using namespace std;

void dynamic(int , int);


int main (void)
{
	int *iptr;
    int temp;
    
    cout << " Please enter a number of ellements to create: " << endl;
    cin >> temp;
    while(cin.get() != '\n');
    iptr = new int[temp];
    if (iptr == NULL)
    {
    	cout << " Error Allocating Memory!\n";
    	return 5;
    }
    
    cout << " Press any key to end";
    while(cin.get() != '\n');
    return 0;
}

