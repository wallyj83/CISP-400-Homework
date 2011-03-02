/*
	new_random.cpp - Searches specified file for string and
				replaces with a different string.
*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class fileClass {

	private:
		string filename;
		string from;		// string to change from
		string to;		// string to change to
		ifstream fin;

	public:
		void findString();
		void stringReplace();

};

int main() {

	// get filename from user
	// allocate new fileClass with that filename
	// get "from" and "to" strings from user
	// pass strings to fileClass object
	// tell user how it went

return 0;
}

