//
/*
 2. Test Averaging
 Write a program that dynamically allocates an array large enough to hold any number of scores the user wishes to enter. (Use the function you wrote in
 problem #1). Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. Another function should then 
 be called that calculates the average score. The program should display sorted list of scores and average, with appropriate headings.
 Input validation: Do not accept negative numbers for test scores. 
 */
//  CISP 400
//  Joshua Parker-Roriz
//  main.cpp
//  HomeWork 1-2
//
/* 
 Decomp
 3.0 Main
    3.1 Sort 
    3.2 Avg
 
 */

#include <iostream>
#include <iomanip>
using namespace std;

void sorting(int tr[], int);
int avg(int tr[], int);
int compare (const void * a, const void * b);


int main (void)
{
	int *iptr;
    int temp;
    int avgtemp;
    cout << " Please enter a number of ellements to create: " << endl;
    cin >> temp;
    while(cin.get() != '\n');
    
    iptr = new int[temp];
    if (iptr == NULL)
    {
    	cout << " Error Allocating Memory!\n";
    	return 5;
    }
    cout << " test: " << temp << endl;
    sorting(iptr, temp);
   	avgtemp =avg(iptr, temp);
   	cout << " The Average score is: " << avgtemp;
    cout << " Press any key to end";
    while(cin.get() != '\n');
    return 0;
}



void sorting(int tr[], int temp)
{
    int i;
    for(i=1; i <=temp; i++)
    {
   	cout << "Please enter the " << i <<" score : ";
   	cin >> tr[i];
    while(cin.get() != '\n');
    }
    qsort(tr, temp, sizeof(int), compare);
}

int avg(int tr[], int temp)
{
	int sum=0;
	for(int i=0; i<temp; i++)
		sum= sum + tr[i];
		sum = sum/temp;
	return sum;
	
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
