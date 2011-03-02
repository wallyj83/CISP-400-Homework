/*

//Here’s a class declaration:
class Move
{
private:
double x; double y;
public:
Move(double a = 0, double b = 0); // constructor 10%
showmove() const; // shows current x, y values of object 10%
Move add(const Move & m) const;  // 30%
// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// Move object initialized to new x, y values and returns it
reset(double a = 0, double b = 0); // resets x,y to a, b //10%
};
//Supply member function definitions and a driver program that exercises the class. //40%
//Due by end of class today
//post to your website and email me the URL
//subject: cisp400 your name mid1
//  CISP 400
//  Joshua Parker-Roriz
//  main.cpp
//  Quiz 1
//
*/

#include <iostream>
#include <iomanip>
using namespace std;
class Move
{
private:
	double x; 
	double y;
public:
	Move(double a=0, double b=0); //Constructor
	 void showmove() const; //Shows current values of x and y
	 // main.cpp:34: error: ISO C++ forbids declaration of ‘showmove’ with no type
	 //	Changed type to void
	Move add(const Move & m) const;
	// Adds x of m to x of invoking object to get new x,
	// adds y  of m to y of invoking object to get new y,
	// Move object intialized to new x, y values and returns it
	void reset (double a=0, double b=0); //resets x,y to a,b 
	// main.cpp:39: error: ISO C++ forbids declaration of ‘rest’ with no type
	// changed type to void
};

Move::Move(double a, double b)
{
 x=a;
 y=b;
}

void Move::showmove() const
{
	cout << "x = " << x << "  y = " << y << endl;
}

Move Move::add(const Move & m) const
{
 return Move( x + m.x, y + m.y );
}

void Move::reset(double a, double b)
{
x=a;
y=b;
}


int main()
{
	Move test;
	cout << "Testing showmove() const" <<endl;
	test.showmove();
	
	cout << " Testing testTemp" << endl;
	Move testTemp(10,7);
	testTemp.showmove();
	
	cout << "Testing Move add(const Move & m) const" <<endl;
	test= testTemp.add(testTemp);
	test.showmove();
	
	cout << "Testing reset(double a, double b) " <<endl;
	test.reset();
	testTemp.reset();
	test.showmove();
	testTemp.showmove();
	
	return 0;
}






