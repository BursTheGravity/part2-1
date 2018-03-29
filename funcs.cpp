/*
Author: Leman Yan
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab_08

In this lab, we will develop a small utility program that can fix indentation in C or C++ source code files. 
It will have some limitations, but it will be able to cover a significant subset of valid C++ programs. 
Specifically, given a file with messed up indentation style:

*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
- removeLeadingSpaces works but seems overcomplicated
	- INNATE PROBLEM WITHIN THIS CODE WHICH AFFECTS WHOLE OUTPUT:
		- Currently goes through the word checks if current and following letter are spaces for some reason
		- As a result, makes use of line.length() - 1:
			- ***THIS GETS RID OF YOUR LAST CHARACTER IN EVERY LINE!!!***
		- Afterwards, there is still an extra space because of this implementation as well, which is manually removed at the end
	
	- Instead, can just check if current letter is not a space and add it to the final output
	- Variables definitely need better names and organization
*/

/*
OLD CODE
string removeLeadingSpaces(string line){
	char letter;
	char secondletter;
	char firstletter;
	string empty="";	
		
	for(int i=0; i<line.length()-1 ; i++){
		letter=line[i];
		secondletter=line[i+1];

		if (isspace(letter) && isspace(secondletter))  //If its a space
		{
			//letter="";
			//empty+=letter;
			
		}
		else{
			empty+=line[i];
		}
	}

	int length=empty.length();
	//length=length-1;
	
	firstletter=empty[0];
	if(isspace(firstletter)){
		empty=empty.substr(1,length);
	}
	
	return empty;
}
*/

string removeLeadingSpaces(string line) {
	char letter;
	string ans = "";
	
	for (int i = 0; i < line.length(); i++ ) {
		char letter = line[i];
		//when we get to the last of the initial spaces, we can just take the rest
		if (!isspace(letter)) {
			ans += line.substr(i);
			return ans;
		}
	}
	
}

//currently only prints count in beginning and doesn't output anything
int countChar(string line, char c){

	int count=0;
	for(int i=0; i<line.length() ; i++){
		if(line[i]==c){
			count+=1;
		}
	}
	
	//never returned an output in function (fixed):
	return count; 
}

//- unindent() supposedly takes an input and unindents it?
/*- works, but is only printing the lines as they are "fixed"
- would be better if it returned a string output, as it would be easier to debug later on
- FOR SOME REASON: last character of output disappears for every line -> this was a problem within removeLeadingSpaces
*/
string unindent(){

	string line;
	string ans = "";
	
	int openBr, closedBr;
	
	while(getline(cin , line)){		//Get the entire line
		//cout<<removeLeadingSpaces(line)<<endl; //old code
		
		//FIXED CODE: Added functionality for proper bracket placement
		int numTabs = openBr - closedBr;
		string tabs = "";
		string cleanLine = removeLeadingSpaces(line);
		if (cleanLine[0] == '}') { numTabs -= 1; }
		
		for (int i = 0; i < numTabs; i++ ) {
			tabs += "\t";
		}
		ans += tabs + cleanLine + "\n";
		
		openBr += countChar(line, '{');
		closedBr += countChar(line, '}');
	}

	return ans;
}



