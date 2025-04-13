#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Utils.hpp"

using namespace std;

int main()
{
	//initializing variables and array to store portfolio informations
	std::string inputFile = "data.txt";
	std::string outputFile = "result.txt";
	double s;
	size_t n;
	double *ptr1 = nullptr;
	double *ptr2 = nullptr;
	
	//reading and checking input file
	if(!ImportFile(inputFile, n, s, ptr1, ptr2))
		return 1;
	
	//initializing the two main parameters of the portfolio 
	double R = Rate_of_Return(n, ptr1, ptr2);
	double V = (R+1)*s;
	
	//exporting the results and, if fails, deallocating memory
	if(!ExportResult(outputFile, n, s, R, V, ptr1, ptr2))
	{
		delete[] ptr1;
		delete[] ptr2;
		return 1;
	}
	
	//deallocating memory 
	delete[] ptr1;
	delete[] ptr2;
	
    return 0;
}

