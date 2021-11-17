/*****************************************
        Header Merger v0.1-alpha
           2021 Andrea Marchi
This program merges multiple nested header
files into a single one.
Includes all the header files into quotes
i.e. #include "fileName.h"
******************************************/
#include <iostream>
#include <cstring>

#include "parser.h"

using namespace std;

#define HEADER_MERGER_VERSION  "v0.1-beta"


int main(int argc, char **argv)
{
	if(argc < 2){
		// no parameters given
		cout << "Header Merger " << HEADER_MERGER_VERSION;
		cout << " - (c) 2021 Marchi Technology" << endl << endl;
		cout << "   Merges multiple header files into a single one" << endl << endl;
		cout << "Usage: header_merger (input_fileName) [-o <output_fileName>]" << endl << endl;
		cout << "   if no output_fileName is provided default file name is the one with" << endl;
		cout << "   \"_merged\" at the end" << endl;
		#ifdef __WIN32
		cout << endl;
		system("pause");
		#endif
		return 0;
	}
	string fileName = argv[1]; // takes input file from command line
	
	string fNameOutput = fileName;
	fNameOutput.insert(fNameOutput.length()-2, "_merged"); // add the string before the file extension NO HPP
	for(auto i=0; i<argc; i++){
		if(strcmp(argv[i], "-o")==0 && argc > i) fNameOutput = argv[i+1];
	}
	
	ofstream output(fNameOutput); // output file (merged header file)
	
	parse_to_stream(output, fileName);
	
	output.close();
	
	return 0;
}
/*
	TODO:
	
	- Includere molti file header da linea di comando
	
*/
