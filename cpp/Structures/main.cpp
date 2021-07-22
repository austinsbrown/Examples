#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

struct subscriberName
{
	string firstName;
	string lastName;
	int id;
};

struct addressStruct
{
	string streetName, city, state;
	int zip;
};

struct dateStruct
{
	string month;
	int day, year;
};

struct renInfoStruct
{
	int monthsLeft;
	dateStruct date;
};

struct topStruct
{
	subscriberName subName;
	addressStruct address;
	renInfoStruct renInfo;
};

bool openInputFile(ifstream &inputstream)
{
	string input; // input file name
	cout << "\nEnter name of input file or Control-C to quit program: ";
	cin >> input;
	cout << input << endl;

	inputstream.open(input.c_str()); // open file

	if(inputstream.fail())
	{
		cout << "\n*************** File Open Error ***************" << endl
		<< "==> Input file failed to open properly!!" << endl
		<< "==> Attempted to open file: " << input << endl
		<< "==> Please try again..." << endl
		<< "***********************************************" << endl;
		return false;
	}	

	else
	{
		return true;
	}
}

bool openOutputFile(ofstream &outputstream)
{
	string output;
	cout << "\nEnter name of output file or Control-C to quit program: ";
	cin >> output;
	cout << output << endl << endl;

	outputstream.open(output.c_str()); // open file

	if(outputstream.fail())
	{
		cout << "*************** File Open Error ***************" << endl
		<< "==> Output file failed to open properly!!" << endl
		<< "==> Attempted to open file: " << output << endl
		<< "==> Please try again..." << endl
		<< "***********************************************" << endl;
		return false;
	}	

	else
	{
		return true;
	}
}

topStruct structReader(ifstream &inputstream)
{
	subscriberName subName; // declare my structures
	addressStruct address;
	dateStruct date;
	renInfoStruct renInfo;
	topStruct top;
	
	inputstream >> subName.firstName; // name structure
	inputstream >> subName.lastName;
	inputstream >> subName.id;
	
	inputstream.ignore(INT_MAX, '\n'); // address struct
	getline(inputstream, address.streetName, '\n');

	getline(inputstream, address.city, '\n');

	getline(inputstream, address.state, '\n');
	
	inputstream >> address.zip;

	inputstream >> renInfo.monthsLeft; // months remaining in subscription
	
	inputstream >> date.month >> date.day >> date.year; // date struct

	renInfo.date = date;
	
	top.subName = subName;
	top.address = address;
	top.renInfo = renInfo;

	return top;
}

void structWriter(topStruct top, ofstream &outputstream)
{
	outputstream << "*******************************************************" << endl
	<< top.subName.firstName << " " << top.subName.lastName 
	<< "(" << top.subName.id << ")" << endl
	<< top.address.streetName << endl
	<< top.address.city << ", " << top.address.state << " " << top.address.zip << endl
	<< "The last renewal notice was sent on " << top.renInfo.date.month 
	<< " " << top.renInfo.date.day << ", " << top.renInfo.date.year << endl
	<< "*******************************************************\n" << endl;
}

int main()
{
	ifstream infile;
	ofstream outfile;
	topStruct top;
	
	bool fileOpen = false; // open the input file
	while(fileOpen == false)
	{
		fileOpen = openInputFile(infile);	
	}
	
	fileOpen = false;
	while(fileOpen == false)
	{
		fileOpen = openOutputFile(outfile);	
	}
	
	top = structReader(infile);
	if(! infile.good())
	{
		cout << "===> Input file is empty.  Program terminated\n" << endl;
		
		outfile << "----------------------------------------------------" << endl
		<< "==> The input file does not contain any information." << endl
		<< "----------------------------------------------------" << endl;
	}
	
	else
	{
		int expNum = 0;
		int subNum = 0;
	
		while(infile.good())
		{	
			if(top.renInfo.monthsLeft == 0)
			{
				expNum++;
				structWriter(top, outfile);
			}
		
			cout << "====> Processing Customer ID: " << top.subName.id << endl;
			subNum++;
			top = structReader(infile);
		}
	
		cout << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Number of subscribers processed: " << subNum << endl;
		cout << "The number of expired subscriptions is: " << expNum << endl;
		cout << "-----------------------------------------------\n" << endl;
	}
	
	
	
	infile.close();
	outfile.close();
	return 0;
}
