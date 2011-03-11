// randomAccess.cpp 
// Asks user for a filename and word.  It then displays the number of 
//  lines containing the word and then displays each line. 
//  CISP 400
//  Group 2 Joshua Parker-Roriz, Devon Bonanno, Daniel Nakashima
//  random.cpp
//  Team Assignment random.cpp


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  	string filename;
  	string word;
  	string tempWord;
  	string line;
  	size_t found;
  	
  	
  	
  	cout << "Please enter the name of a file: ";
  	cin >> filename;
  	cout << "Please enter a word you would like to find: ";
  	cin >> word;
	cout << "Please enter the word you would like to replace it with: ";
	cin >> tempWord;
 	
   	
   	
   	fstream fin(filename.c_str(), ios::in|ios::out);
   
   //ofstream fintemp(filename.c_str(),ios::app);
  	streampos currentPosition = fin.tellg(); //unsigned long int
  	vector<streampos> linePositions;
 
 	while(getline(fin, line))
 	{
    	if(string::npos!=line.find(word)) 
    	{
    		linePositions.push_back(currentPosition);
    	}
    	currentPosition = fin.tellg();
  	}
 
  	// We need to clear the error flag that was set when we tried 
  	//  to read past the end of the file. 
  	fin.clear();
  
   	vector<streampos>::iterator itr;
  	for(itr = linePositions.begin(); itr!=linePositions.end(); ++itr) 
  	{
    	fin.seekg(*itr);
    	getline(fin, line);
    	found = line.find(word);
    	cout << line << endl;
    	while(found!=string::npos)
    		{
    		line.replace(found, word.size(),tempWord);
    		found = line.find(word, found +1);
    		}
    	fin.seekp(*itr);
    	fin.write(line.c_str(), line.size());
  	}
  	fin.close();
 
  return 0;
}

// work as a team modify the above program such that it will replace
// any selected word with another
// i. e. find "num" and replace with "Mom" or "Dady"
// use the test file input.txt in session 5_6 folder
// Due next wednesday before class
//