// *************************************************************************
// Program File:                main.cpp
// Name:                        Austin Brown
// Course Section:              CS-317-03
// Due Date: 10/14/19
// Program Description:         Sorts all of the strings in a file using 
//                              quicksort then outputs the sorted words 
//                              to a different file.
// *************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void quickSort(string [], int, int);                                            // prototype for quickSort
int partition(string [], int, int);                                             // prototype for partition
void swap(string *, string *);                                                  // prototype for swap
void printArr(string [], int, ofstream &);                                      // prototype for array printing


int main()
{
    string words[1000];                                                         // array to hold the words
    int lowIndex = 0;                                                           // starting index 

    ifstream infile;                                                            // infile stream
    ofstream outfile;                                                           // outfile stream
    string inputFilename;                                                       // imput file name
    string outputFileName;                                                      // output file name

    cout << "Welcome to the sorting words program." << endl 
    << "Please enter the name of you input data file: ";
    cin >> inputFilename;                                                       // get the name of the input file from the terminal
    cout << "" << endl;
    cout << "Please enter the name of the output data file: ";
    cin >> outputFileName;                                                      // get the name of the output file from the terminal
    
    infile.open(inputFilename.c_str());                                         // open the input stream
    outfile.open(outputFileName.c_str());                                       // open the output stream

    int i = 0;                                                                  // index for words array
    int count = 0;                                                              // number of words in the array

    while(!infile.eof())                                                        // read words into array
    {
        infile >> words[i];                                                     // get a word from the input file
        i++;                                                                    // go to the next index of words array
        count++;                                                                // increment number of words
    }

    cout << count << " words found in " << inputFilename << endl;               // print the number of words found

    quickSort(words, lowIndex, count);                                          // call quicksort
    printArr(words, count, outfile);                                            // call the printing function
    

    infile.close();                                                             // close input stream
    outfile.close();                                                            // close output stream
    return 0;    
}


void quickSort(string arr[], int l, int h)                                      // quick sort declareation
{
    if(l < h)                                                                   // if l is greater or equal to h, there is nothing to do
    {
        int p = partition(arr, l, h);                                           // partition array                                     
        quickSort(arr, l, p-1);                                                 // recursive call on first part of array
        quickSort(arr, p+1, h);                                                 // recursive call on second part of array
    }
}


int partition(string arr[], int l, int h)                                       // partition declaration
{
    string p = arr[h];                                                          // set the partition to the last element in the array
    int i = l - 1;                                                              // set i to the low index minus 1
    
    for(int j=l; j <= h-1; j++)
    {
        if(!isupper(arr[j][0]) && !isupper(p[0]))                               // both elements are lowercase
        {
            if(arr[j] < p)                                                      // if a[j] goes before pivot
            {
                i++;                                                            // increment i
                swap(&arr[i], &arr[j]);                                         // swap 2 elements
            }
        }

        else if(isupper(arr[j][0]) && !isupper(p[0]))                           // first element is upper case
        {
            arr[j][0] =  tolower(arr[j][0]);                                    // convert to lowercase for comparison
            if(arr[j] < p)                                                      // if a[j] goes before pivot
            {
                arr[j][0] =  toupper(arr[j][0]);                                // convert back to uppercase
                i++;                                                            // increment i
                swap(&arr[i], &arr[j]);                                         // swap 2 elements
            }
            else
                arr[j][0] =  toupper(arr[j][0]);                                // just convert back to uppercase
            
        }

        else if(!isupper(arr[j][0]) && isupper(p[0]))                           // second element is uppercase
        {
            p[0] = tolower(p[0]);                                               // conert letter to lowercase
            if(arr[j] < p)                                                      // compare
            {
                p[0] = toupper(p[0]);                                           // retrun it to uppercase
                i++;                                                            // increment i
                swap(&arr[i], &arr[j]);                                         // swap two elements
            }
            else
                p[0] = toupper(p[0]);                                           // just return to uppercase
        }

        else                                                                    // both are uppercase
        {
            if(arr[j] < p)                                                      // if the current elemtent goes after the pivot
            {
                i++;                                                            // increment i 
                swap(&arr[i], &arr[j]);                                         // swap 2 elements
            }
        }
        
    }
    swap(&arr[i + 1], &arr[h]);                                                 // swap index i+1 and the element at the end
    return (i + 1);                                                             // return the index                                        
}


void swap(string *a, string *b)                                                 // swaps two elements
{
    string temp = *a;                                                           // set first elemtent to a temp variable
    *a = *b;                                                                    // set second element to first element
    *b = temp;                                                                  // set second to temp
}


void printArr(string arr[], int size, ofstream &outfile)                        // prints and formats an array
{
    int wordNum;                                                                // number of words per line 
    cout << "How many words per line should be printed? ";
    cin >> wordNum;                                                             // get number of words per line from command line

    for(int i=1; i<size; i++)                                                   // begin printing stuff
    {
        int j = 1;                                                              // incrementor for inner loop
        while (j <= wordNum)                                                    // 
        {
            outfile << setw(15) << arr[i];                                      // set field width and print out element
            outfile << " ";                                                     // print a space
            i++;                                                                // increment i
            j++;                                                                // increment j
        }
        outfile << endl;                                                        // newline
    }
}