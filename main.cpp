/*****************************************
Header Merger
This program merges multiple nested header
files into a single one.
Includes all the header files into quotes
i.e. #include "fileName.h"
******************************************/
#include <iostream>
#include <string>

#include "parser.h"

using namespace std;


int main()
{
	string fileName = "test\\test.h"; // input file (to be merged with other sub-header-files)
	
	ofstream output("OUTPUT.h"); // output file (merged header file)
	
	parse_to_stream(output, fileName);
	
	output.close();
	
	return 0;
}
