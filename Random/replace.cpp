/*
	new_random.cpp - Searches specified file for string and
				replaces with a different string.
*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string stringReplace(string line, string initial_word,string replace_word);

int main() 
{

  string filename;

  string initial_word;

  string replace_word;

  string line;



  line = " track num wish num ";

  initial_word = "num";

  replace_word = "hey";



  cout << " initial line is \n" << line << endl;

  line = stringReplace(line, initial_word,replace_word);



  /*

  cout << "Please enter the name of a file: ";

  cin  >> filename;

  cout << "Please enter a word you would like to find: ";

  cin  >> initial_word;

  cout << "enter word you would you would like to replace word with:  ";

  cin  << replace_word; */



  cout << "new line modified is \n\n"<< line;

  

  getchar();

return 0;
}



string stringReplace(string line, string initial_word,string replace_word)

{
	unsigned short int pos;





	if (replace_word.size() < initial_word.size())

	{

		pos = line.find(initial_word, 0);



		while (pos < 1000)				// assumes that txt will  be less than 1000 char long

		{

			line.insert(pos + replace_word.size(), (replace_word.size() - initial_word.size()), ' ');

			pos = line.find(initial_word, pos+1);

		}

	}

	



	while (line.find(initial_word, 0) < 1000)



		line.replace(line.find(initial_word, 0), replace_word.size(), replace_word);



	return line;

}
