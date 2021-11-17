#ifndef MRC_PARSER
#define MRC_PARSER

#include <iostream>

#include <fstream>
#include <vector>
#include <string>

#include "utils.h"

std::string getPathName(const std::string& s);


std::vector<std::string> included_files; // list of included files (to avoid multiple definitions)


void parse_to_stream(std::ofstream &file, std::string fileName)
{
	// open the "fileName" file copy it to the stream "file"
	// also parse if there are other "#include """ statements
	// and in case call itself recursively
	std::ifstream input(fileName);
	
	if(input.fail()){
		std::cerr << "file not found" << std::endl;
	}
	
	std::string pathName = getPathName(fileName);
	
	std::string str;
	std::vector<std::string> strvec;
	while(getline(input,str)){
		bool write_to_file = true;
		strvec = splitTokens(deleteInitialSpace(deleteMultipleSpace(str)),' ');
//		for(auto i : strvec) std::cout << i << " "; std::cout << strvec.size() << std::endl;
		if(strvec.size() > 1){
			if(strvec[0] == "#include" && strvec[1][0] == '\"'){
//				std::cout << "trovato un include..." << std::endl;
				std::string temp = pathName + "\\" + strvec[1].substr(1, strvec[1].size()-2);
//				std::cout << temp << std::endl;
				bool isIncluded = false; // check if is alredy included
				for(auto i=0; i<included_files.size() && isIncluded==false; i++)
					if(temp == included_files[i]) isIncluded = true;
				if(!isIncluded){
					included_files.push_back(temp); // avoid redefinition of the file
					parse_to_stream(file, temp); // recursively parse and include header files
				}
				write_to_file = false;
			}
			if(strvec[0] == "#pragma" && strvec[1] == "once") write_to_file = false;
		}
		if(write_to_file) file << str << std::endl;
	}
	input.close();
}



// ______________________________________________________________________________________

std::string getPathName(const std::string& s)
{
	char sep = '/';
	
#ifdef _WIN32
	sep = '\\';
#endif

	size_t i = s.rfind(sep, s.length());
	if (i != std::string::npos) return(s.substr(0, i));
	
	return("");
}



#endif
