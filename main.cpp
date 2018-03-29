/*
Author: Leman Yan
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab_08

In this lab, we will develop a small utility program that can fix indentation in C or C++ source code files. It will have some limitations, but it will be able to cover a significant subset of valid C++ programs. Specifically, given a file with messed up indentation style:

*/

#include <iostream>

#include "funcs.h"



using namespace std;

int main(){
	
	/*
	cout<<removeLeadingSpaces("Hello world!  a")<<endl;
	cout<<removeLeadingSpaces("       int x = 1;  !")<<endl;
	
	cout<<countChar("}ad }dskdak kdkd!23232 }", '}')<<endl;

	string apple="} e1e } dasds }";

	char bracket = '}';

	if (apple[0]=='}')
	{
		cout<<apple[0]<<endl;

	}
	*/

	cout << unindent() << endl;

	//<<bad-code.cpp
	return 0;
}
