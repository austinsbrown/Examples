#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
	ifstream infile; 										// declare in stream

	string input; 											// prompt for input
	cout <<"\nEnter in the name of the input file: ";
	cin >> input;
	cout << input << "\n" << endl;

	infile.open(input.c_str()); 							// attempt to open the File

	bool fileOpen = false; 									// test test for corect file
	while(fileOpen == false)
	{
		infile.close();
		infile.clear();
		infile.open(input.c_str());

		if(! infile.fail())
		{
			fileOpen = true;
		}
		else
		{
			cout << "*************** File Open Error ***************" << endl
			<< "==> Input file failed to open properly!!" << endl
			<< "==> Attempted to open file: " << input << endl
			<< "==> Please try again..." << endl
			<< "***********************************************\n" << endl;

			cout <<"Enter in the name of the input file: ";
			cin >> input;
			cout << input;
			cout << "\n" << endl;

		}
	}

	char current; 											// priming read
	infile.get(current);


	int numCount = 0; 										// counter for digits
	int charCount = 0; 										// counter for characters
	int otherCount = 0; 									// counter for other characters
	int total = 0;

    int charTotal = 0; 										// for totaling up each type
    int numTotal = 0;
    int otherTotal = 0;
    int absTotal = 0;

	string line; 											// for checking for the endline char
	int lineNum = 0;

	bool emptyfile = false; 								// test for empty file
	if(! infile.good())
	{
		cout << "************* Input File Is Empty *************" << endl
		<< "==> The input file is empty." << endl
		<< "==> Terminating the program." << endl
		<< "***********************************************\n" << endl;
	}

	else
	{
		cout << left << setw(15) << "Line number" 			// output headings
		<< setw(10) << "Letters" << setw(10) << "Digits"
		<< setw(10) << "Other"
		<< setw(10) << "Total" << endl;

		cout << setw(15) << "-----------" << setw(10) << "-------" 
		<< setw(10) << "------" << setw(10) << "-----"
		<< setw(10) << "-----" << endl;

		while(infile)
		{

			if(current != '\n')
			{
				if(isdigit(current)) 						// check for digits
				{
					numCount++;
				}

				else if(isalpha(current)) 					// check for characters
				{
					charCount++;
				}

				else
				{
					otherCount++;
				}
			}

			else
			{
				otherCount++;
				lineNum++;

				total = numCount + charCount + otherCount; // find the total number of characters

				cout << setw(15) << lineNum << setw(10) << charCount << setw(10) << numCount
				<< setw(10) << otherCount << setw(10) << total << endl;

				charTotal = charTotal + charCount;
				numTotal = numTotal + numCount;
				otherTotal = otherTotal + otherCount;

				charCount = 0;
				numCount = 0;
				otherCount = 0;

			}

			infile.get(current);
		}

		absTotal = charTotal + numTotal + otherTotal;		// find the total of all characters

		float charPercent, numPercent, otherPercent;

		charPercent = (float(charTotal) / float(absTotal)) * 100;
		numPercent = (float(numTotal) / float(absTotal)) * 100;
		otherPercent = (float(otherTotal) / float(absTotal)) * 100;

		cout <<"--------------------------------------------------" << endl;
		cout << setw(15) << "Totals" << setw(10) << charTotal << setw(10) << numTotal
		<< setw(10) << otherTotal << setw(10) << absTotal << endl;

		cout << fixed << setprecision(2);

		cout << setw(15) << "Percent" << setw(10) << charPercent
		<< setw(10) << numPercent << setw(10) << otherPercent << endl;
		 cout << endl;
	}

	return 0;
}
