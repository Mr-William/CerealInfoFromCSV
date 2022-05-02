//WILLIAM GIBBS
//COSC1560 - PROGRAMMING II
//PROGRAM 8
//DUE:  13 Nov 2019

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "ccereal.h"
#include <Windows.h>


using namespace std;

//********************************************
//Function Prototype:                        *
//runp8(): Opens input data file,            *
//then enters into loop, in loop             *
//each data member is loaded into            *
//class.(Class must be declared in function) *
//After last data member is loaded,          *
//Output() is called from the class.         *
//Output() is responsible for appending      *
//info to file and displaying the            *
//same info to screen                        *
//********************************************
void runp8();


int main()
{
	runp8();

	return 0;
}

void runp8()
{
	ifstream fileIn("cereal.csv");

	if (!fileIn)
	{
		cout << "\nERROR OPENING FILE.\n";
		Sleep(1500);
		cout << "\nEnsure CSV file named 'cereal.csv' is in the same folder as the program.\n";
		Sleep(1000);
		cout << "Program terminating.\n\n";
		exit(EXIT_FAILURE);
	}

	else
	{
		cout << "This program utilizes classes to read data from a csv.\n";
		cout << "After reading an entry, the record will be appended to cereal.txt.\n";
		Sleep(1000);
		cout << "Please maximize your viewing window for best display.\n\n";
		Sleep(2000);
		cout << "Press enter to continue:  ";
		cin.ignore();

		//Printing the labels one time for a table.
		cout << "\n\n\n=============================================================================================================================================\n";
		cout << "|               Cereal Name               ";
		cout << "|MFR";
		cout << "|Type";
		cout << "|Calories";
		cout << "|Protein";
		cout << "|Fat";
		cout << "|Sodium";
		cout << "|Fiber";
		cout << "|Carbo";
		cout << "|Sugars";
		cout << "|Potass";
		cout << "|Vitamins";
		cout << "|Shelf";
		cout << "|Weight";
		cout << "|Cups";
		cout << "|Rating |\n";
		cout << "=============================================================================================================================================\n";


		while (!fileIn.eof())
		{
			CCereal cerealObj;
		}
	}
}