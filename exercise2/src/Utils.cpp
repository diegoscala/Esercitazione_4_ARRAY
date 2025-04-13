#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "iomanip"

using namespace std;

bool ImportFile(const string& inputFilePath,
                   size_t& n,
				   double& s,
                   double*& w,
                   double*& r)
{
	ifstream fstr(inputFilePath);
	
	if(fstr.fail())
	{
		cerr << "file reading failed" << endl;
		return false;
	}
	
	std::string tmp;
	getline(fstr, tmp);
	s = stod(tmp.substr(2));
	
	getline(fstr, tmp);
	n = stoi(tmp.substr(2));
	
	w = new double[n];
	r = new double[n];
	
	getline(fstr, tmp);
	
	std::string wStr, rStr;
    std::istringstream ss;
	
	for (int i = 0; i < n; ++i)
	{
		std::getline(fstr, tmp);
		
		ss.clear();
        ss.str(tmp);

        std::getline(ss, wStr, ';');
        std::getline(ss, rStr);

        w[i] = std::stod(wStr);
        r[i] = std::stod(rStr);
	}
	
	
	return true;
}

double Rate_of_Return(const size_t& n,
						const double* const& w,
                        const double* const& r)
{
	double rrt = 0;
	for (unsigned int i = 0; i < n; i++)
		rrt += w[i]*r[i];
    return rrt;
}

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
				  const double& s,
				  const double& rrt,
				  const double& V,
                  const double* const& w,
                  const double* const& r)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);
	
	if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }
	
	file << "S = " << fixed << setprecision(2) << s << ", n = " << n << endl;
	
	file << "w = [";
	for (size_t i = 0; i < n; i++)
	{
        file << (i != 0 ? " " : "") << w[i];
	}
	file << "]" << endl;
	
	file << "r = [";
	for (size_t i = 0; i < n; i++)
	{
        file << (i != 0 ? " " : "") << r[i];
	}
	file << "]" << endl;
	
	file << "Rate of return of the portfolio: " << fixed << setprecision(4) << rrt << endl;
	file << "V: "<< fixed << setprecision(2) << V << endl;
	
	file.close();
	
	return true;
}
	
	