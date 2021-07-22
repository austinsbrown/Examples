#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

bool openInputFile(ifstream&);
float average(float [],int);
float *arrayReader(ifstream&);
float *BubbleSort (float [], int);
float findMeadian(float [], int);
float findVariance(float [], int, float);

int main()
{
	ifstream infile; // declare input stream
	float *arr; // declare array of size 50

	openInputFile(infile);

	arr = arrayReader(infile); // get the array
	int size = arr[0]; // get the size

	float mean = average(arr, size);
	float *sortedArr = BubbleSort(arr, size);
	float meadian = findMeadian(sortedArr, size);
	float variance = findVariance(sortedArr, size, mean);
	float standDev = sqrt(variance);
	
	cout << left;
	cout << setw(25) << "\n*************** File Statistics ***************" << endl
	<< "***********************************************" << endl
	<< setw(25) << "Number of Values........." << size << endl
	<< setw(25) << "Average.................." << mean << endl
	<< setw(25) << "Median..................." << meadian << endl
	<< setw(25) << "Variance................." << variance << endl
	<< setw(25) << "Standard Deviation......." << standDev << endl
	<< setw(25) << "***********************************************\n" << endl;
	
	infile.close();
	return 0;
}

bool openInputFile(ifstream &inputstream)
{
	bool fileOpen = false; // open the input file
	while(fileOpen == false)
	{
		string input; // input file name
		cout << "\nEnter the name of the input file (ctrl-c to exit): ";
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

float average(float array[], int size)
{
	float sum = 0;

	for(int i = 1; i < size + 1; i++)
	{
		sum = sum + array[i];
	}

	float average;
	average = sum / size; // calc average

	return average;
}

float *arrayReader(ifstream &inputstream)
{
	int index = 0;
	float num;
	static float array[50];

	inputstream >> array[index];
	index++;
	int total = array[0];
	
	if(inputstream.eof())
	{
		cout << "\n*************** Empty Input File **************" << endl
		<< "==> The input file is empty." << endl 
		<< "==> There is no information to process." << endl
		<< "==> Terminating the program!!!" << endl
		<< "***********************************************" << endl << endl;
		exit(0);
	}
	
	if(inputstream.fail())
	{
		cout << "\n*************** File Read Error ***************" << endl
		<< "==> Error occurred reading the number of values" << endl
		<< "==> present in the input file." << endl 
		<< "==> Program terminated." << endl
		<< "***********************************************\n" << endl;
			
		exit(0);
	}
	
	while(inputstream.good())
	{
		inputstream >> array[index];
		index++;
		
		if(inputstream.fail() && !inputstream.eof())
		{
			cout << "\n*************** File Read Error ***************" << endl
			<< "==> Error occurred reading in one of the numbers." << endl
			<< "==> Program terminated." << endl
			<< "***********************************************\n" << endl;
			
			exit(0);
		}
	}

	if(total != index-2)
	{
		cout << "\n*************** File Read Error ***************" << endl
		<< "==> Error occurred reading in one of the numbers." << endl
		<< "==> Program terminated." << endl
		<< "***********************************************\n" << endl;
			
		exit(0);
	}
	
	return array;
}

float *BubbleSort (float arr[], int n)
{
	int i, j;
	n++;
	arr[0] = 1000;
	
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n-i-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j]+arr[j+1];
				arr[j+1] = arr[j]-arr[j + 1];
				arr[j] = arr[j]-arr[j + 1];
			}
		}
	}	
	return arr;
}

float findMeadian(float arr[], int n)
{
	float meadian;
	int index1;
	int index2;

	if(n % 2 != 0)
	{
		index1 = (n / 2);
		meadian = arr[index1];
	}
	else
	{
		index1 = n / 2;
		index2 = (n/2) - 1;
		meadian = (arr[index1] + arr[index2]) / 2;
	}
	return meadian;
}

float findVariance(float arr[], int n, float average)
{
	float sum = 0;
	float var;
	for(int i = 0; i < n; i++)
	{
		sum += (arr[i] - average) * (arr[i] - average);
	}
	var = sum / (n);

	return var;
}