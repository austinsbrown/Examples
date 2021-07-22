#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{


	string input, output, writer; 										// declare input and output strings

	ifstream infile;
	ofstream  outfile;

	input = argv[1]; 													// ste input and output variables equal to string variables
	output = argv[2];

	cout << "\nOpening input file: " << input << "\n" << endl;
	infile.open(input.c_str());
	if( infile.fail() ) 												// infile fail condition
	{
		cout << string(15,'*') << " File Open Error "
		<< string(15,'*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << input << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl;
		cout <<"\n";
		return 1;
	}
	
	cout << "Opening output file: " << output << endl;
	cout << "\n";

	outfile.open(output.c_str());
	if( outfile.fail() ) 												// outfile fail condition
	{
		cout << string(15,'*') << " File Open Error "
		<< string(15,'*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << output << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl;
		cout << "\n";
		return 1;
	}

	getline(infile, writer); 											// read and write first line to file
	outfile << writer << endl;

	outfile << left << setw(12) << "Last Name"; 						// write column headings
	outfile << setw(12) << "First Name" << setw(9) << "Average";
	outfile << "Letter" << endl;
	outfile <<  setw(12) << "---------" << setw(12) << "----------";
	outfile <<setw(9) << "-------" << "------" << endl;

	string firstname; 													// storing the firstname
	getline(infile, firstname, ',');

	string lastname; 													// storing the lastname
	getline(infile, lastname, ',');

	float score1, score2, score3, score4; 								// extracts the scores for the first person
	infile >> score1 >> score2 >> score3 >> score4;

	float average;
	char grade; 														// computes the average of the first person
	average = (score1 + score2 + score3 + score4) / 4;
	if(average >= 90)
	{
		grade = 'A';
	}
	else if(average >= 80 && average < 90)
	{
		grade = 'B';
	}
	else if(average >= 70 && average < 80)
	{
		grade = 'C';
	}
	else if(average >= 60 && average < 70)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}

	outfile << showpoint << setprecision(2) << fixed; 					// writes info for first person to file
	outfile << setw(12) << lastname.substr(0,9) << setw(12) 
	<< firstname.substr(0,10);
	outfile << setw(9) << average << grade << endl;

	infile.ignore(INT_MAX, '\n');

	getline(infile, firstname, ','); 									// gets second firstname
	getline(infile, lastname, ','); 									// gets second last name
	infile >> score1 >> score2 >> score3 >> score4; 					// extracts the scores for the second person

	average = (score1 + score2 + score3 + score4) / 4; 					// calculates average for second person
	if(average >= 90)
	{
		grade = 'A';
	}
	else if(average >= 80 && average < 90)
	{
		grade = 'B';
	}
	else if(average >= 70 && average < 80)
	{
		grade = 'C';
	}
	else if(average >= 60 && average < 70)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}

	outfile << setw(12) << lastname.substr(0,9) << setw(12) 
	<< firstname.substr(0,10);
	outfile << setw(9) << average << grade << endl;

	infile.ignore(INT_MAX, '\n');

	getline(infile, firstname, ','); 								// gets third firstname
	getline(infile, lastname, ','); 								// gets third last name
	infile >> score1 >> score2 >> score3 >> score4; 				// extracts the scores for the third person

	average = (score1 + score2 + score3 + score4) / 4; 				// calculates average for third person
	if(average >= 90)
	{
		grade = 'A';
	}
	else if(average >= 80 && average < 90)
	{
		grade = 'B';
	}
	else if(average >= 70 && average < 80)
	{
		grade = 'C';
	}
	else if(average >= 60 && average < 70)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}

	outfile << setw(12) << lastname.substr(0,9) << setw(12) << firstname.substr(0,10);
	outfile << setw(9) << average << grade << endl;

	infile.ignore(INT_MAX, '\n');

	outfile <<  setw(12) << "---------" << setw(12) << "----------";
	outfile <<setw(9) << "-------" << "------" << endl;

	infile.close();
	outfile.close();
	return 0;
}
