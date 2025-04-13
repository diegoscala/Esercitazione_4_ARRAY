#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//this function reads the input file and update all the relevant data initialized in the main
//n: number of assets
//s: sum invested
// w: array of sum's fractions invested in every asset
//r: array of assets' return
bool ImportFile(const string& inputFilePath,
                   size_t& n,
				   double& s,
                   double*& w,
                   double*& r);

//funtion to computate the rate of return based on the portfolio read in the input file
double Rate_of_Return(const size_t& n,
						const double* const& w,
                        const double* const& r);

//funtion to export a detailed report of the portfolio 
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& s,
				  const double& rrt,
				  const double& V,
                  const double* const& w,
                  const double* const& r);