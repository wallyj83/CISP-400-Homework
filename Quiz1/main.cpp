/*Quiz 1

    Pig Latin is a language game of alterations played in English. 

see: http://en.wikipedia.org/wiki/Pig_Latin

To form the Pig Latin form of an English word the onset of the first syllable is transposed
 to the end of the word and an ay is affixed (for example, trash yields ash-tray and plunder 
yields under-play and computer yields omputer-cay). The purpose of the alteration is to both 
obfuscate the encoding and to indicate for the intended recipient the encoding as 'Pig Latin'. 
The reference to Latin is a deliberate misnomer, as it is simply a form of jargon, used only for 
its English connotations as a 'strange and foreign-sounding language'.

Design and implement a program which will accept any English word and output the Pig Latin word.
Be sure to use modular design for your solution and following the programming guide lines discussed in class -- 
i.e. use C++ string in lieu of C string when applicable.
*/
//  CISP 400
//  Joshua Parker-Roriz
//  main.cpp
//  Quiz 1
//
/*
	3.0 Main	
		3.1 getinput
		3.2 convert
		3.2 output
*/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void getInput(string &);
void convert(string &, string &);
void displayout(string &);

string input;
string output;

int main()
{
	getInput(input);
	convert(input, output);
	displayout(output);
	return 0;
}

void getInput(string &input)
{
	cout << "This Program translates English words into PIG Latin" << endl;
	cout << "Please enter a word to be translated: ";
	getline(cin, input);
	return;
}

void convert(string &input, string &output)
{
	string tempStr;
	size_t found;
	size_t fcopy;
	
	int size, tmpSize;
	size=input.length();
	found=input.find_first_of("aeiou");
	tmpSize = size - found;
	output.assign(input, found, tmpSize);
	output.append("-");
	output.append(input, 0, found);
	output.append("ay");
	return;
}

void displayout(string &output)
{

cout << "\nThe PIG Latin translation is: " << output << endl;

}