/*
Author: Leman Yan
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab_08

In this lab, we will develop a small utility program that can fix indentation in C or C++ source code files. It will have some limitations, but it will be able to cover a significant subset of valid C++ programs. Specifically, given a file with messed up indentation style:

*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
	length=length-1;
	
	firstletter=empty[0];
	if(isspace(firstletter)){
		empty=empty.substr(1,length);
	}
		
	return empty;
}


string unindent(){

	string line;
	

	while(getline(cin , line)){		//Get the entire line
		//cout<<line<<endl;
		cout<<removeLeadingSpaces(line)<<endl;
	}



	return 0;
}


int countChar(string line, char c){

	int count=0;
	cout<<c<<endl;
	for(int i=0; i<line.length() ; i++){
		//cout<<line[i]<<endl;
		if(line[i]==c){
			count+=1;
		}


	}

}




































































