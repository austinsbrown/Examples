// ****************************************
// Program File: Cpp_header.cpp
// Name: Austin Brown
// Course Section: CPE-211-01
// Lab Section: 4
// Due Date:
// program description:
// What the program does.
// ****************************************

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

struct mathStruct // stores info read from file
{
	string operation;
	double num1, num2;
};

struct trigStruct
{
	string operation;
	string unit;
	double num;
};

bool openInputFile(ifstream&);
mathStruct mathReader(ifstream&);
trigStruct trigReader(ifstream&);


int main()
{
	ifstream infile;
	mathStruct math;
	trigStruct trig;
	string type;
	double answer;
	string dummy; // for controlling input stream

	openInputFile(infile);
	infile >> type; // priming read
	cout << endl;
	if(infile.eof()) // tests for empty file
	{
		cout << "*************** Empty Input File **************" << endl
		<< "==> The input file is empty." << endl
		<< "==> There is no information to process." << endl
		<< "==> Terminating the program!!!" << endl
		<< "***********************************************\n" << endl;

		exit(0);
	}
	
	while(! infile.eof())
	{
		if(type == "Math") // determine which structure to use
		{
			math = mathReader(infile);
			if(math.operation == "+") // addition
			{
				answer = math.num1 + math.num2;
				cout << "Add: " << math.num1 << "+" << math.num2 << " = "
				<< answer << endl;
			}

			else if(math.operation == "-") // subtraction
			{
				answer = math.num1 - math.num2;
				cout << "Sub: " << math.num1 << "-" << math.num2 << " = "
				<< answer << endl;
			}

			else if(math.operation == "*") // mult
			{
				answer = math.num1 * math.num2;
				cout << "Mul: " << math.num1 << "*" << math.num2 << " = "
				<< answer << endl;
			}

			else if(math.operation == "/") // div.
			{
				answer = math.num1 / math.num2;
				cout << "Div: " << math.num1 << "/" << math.num2 << " = "
				<< answer << endl;
			}

			else if(math.operation == "%") // subtraction
			{
				answer = int(math.num1) % int(math.num2);
				cout << "Mod: " << math.num1 << "%" << math.num2 << " = "
				<< answer << endl;
			}

			else
			{
				cout << "Invalid Operator for Math Operations: " << math.operation
				<< endl;
			}
		}

		else if(type == "Trig")
		{
			trig = trigReader(infile);
			if(trig.operation == "s") // sine
			{
				if(trig.unit == "d")
				{
					answer = sin(trig.num * (PI/180));
					cout << "sin(degrees): sin(" << trig.num << ") = " 
					<< answer << endl;
				}

				else
				{
					answer = sin(trig.num);
					cout << "sin(radians): sin(" << trig.num << ") = " 
					<< answer << endl;
				}
			}

			else if(trig.operation == "c") // cosine
			{

				if(trig.unit == "d")
				{
					answer = cos(trig.num * (PI/180));
					cout << "cos(degrees): cos(" << trig.num << ") = " 
					<< answer << endl;
				}
				else
				{
					answer = cos(trig.num);
				cout << "cos(radians): cos(" << trig.num << ") = " 
				<< answer << endl;
				}
			}

			else if(trig.operation == "t") // tangent
			{
				if(trig.unit == "d")
				{
					answer = tan(trig.num * (PI/180));
					cout << "tan(degrees): tan(" << trig.num << ") = " 
					<< answer << endl;
				}

				else
				{
					answer = tan(trig.num);
					cout << "tan(radians): tan(" << trig.num << ") = " 
					<< answer << endl;
				}
			}

			else
			{
				cout << "Invalid Operator for Trig Operations: " << trig.operation
				<< endl;
			}
		}

		else
		{
			cout << "Invalid Calculation Type: " << type << endl;
			infile >> dummy;
			infile >> dummy;
			infile >> dummy;
		}

		infile >> type;
	}

	cout << endl;
	infile.close();
	return 0;
}

bool openInputFile(ifstream &inputstream)
{
	bool fileOpen = false; // open the input file
	while(fileOpen == false)
	{
		string input; // input file name
		cout << "\nEnter the name of the input file: ";
		cin >> input;
		cout << input << endl;

		inputstream.open(input.c_str()); // open file

		if(inputstream.fail())
		{
			cout << "\n*************** File Open Error ***************" << endl
			<< "==>  Input file could not be opened." << endl
			<< "==>  " << input << " is an invalid file!!" << endl
			<< "==>  Please try again." << endl
			<< "***********************************************" << endl;
			fileOpen = false;
		}	

		else
		{
			fileOpen = true;
		}
	}
}

mathStruct mathReader(ifstream &infile)
{
	mathStruct math; // declare a math structure

	infile >> math.operation;
	infile >> math.num1;
	infile >> math.num2;

	return math;
}

trigStruct trigReader(ifstream &infile)
{
	trigStruct trig;

	infile >> trig.operation;
	infile >> trig.unit;
	infile >> trig.num;

	return trig;
}