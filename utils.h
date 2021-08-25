#ifndef MRC_UTILS
#define MRC_UTILS

#include <vector>
#include <string>



std::vector<std::string> splitTokens(std::string str,char c)
{
	std::vector<std::string> res;
	std::string temp;
	
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == c){
			res.push_back(temp);
			temp.clear();
		} else {
			temp = temp + str[i];
		}
	}
	//aggiunge l'ultimo
	if(temp != "") res.push_back(temp);
	
	return res;
}



std::string deleteChar(std::string str, char c)
{
	// elimina un determinato carattere dalla stringa
	std::string res;
	
	for(int i=0;i<str.length();i++)	if(str[i]!=c) res.push_back(str[i]);
	
	return res;
}


std::string deleteMultipleSpace(std::string str)
{
	//elimina gli spazi consecutivi facendoli diventare uno solo
	//per leggere file di input indentati (dove l'indentaizone non conta)
	
	
}


std::string deleteFirstSpace(std::string str)
{
	//elimina gli spazi iniziali
	std::string res;
	int inizio = 0;
	
	if(str[0] == ' ') inizio = 1;
	
	for(int i=inizio;i<str.length();i++){
		res = res + str[i];
	}
	
	return res;
}


std::string deleteChars(std::string str, int first, int last)
{
	//elimina i caratteri iniziali e finali
	std::string res;
	
	if(str.size()-last <= first) return str; //controllo
	for(int i=first;i<str.size()-last;i++){
		res = res + str[i];
	}
	
	return res;
}


bool contiene(std::string str, char c)
{
	// ritorna VERO se la stringa str contiene il carattere c	
	for(int i=0;i<str.length();i++){
		if(str[i] == c) return true;
	}
	
	return false;
}





#endif
