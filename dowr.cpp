#include "dowr.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

#define NAME_MARK "_name" 
#define PARAMETER_MARK "_param"

std::fstream readFileObject;
std::fstream writeFileObject;

void read_new_file(std::string fileName){
	if(!readFileObject.is_open()){
		readFileObject.open(fileName, std::fstream::in);
	}
	else{
		printf("Error! File already opened...\n");
		return ;
	}
}

void close_opened_file(std::string fileName){
	if(readFileObject.is_open()){
		printf("Closing file...\n");
		readFileObject.close();
	}
	else{
		printf("Could not open file! Already closed...\n");
		return ;
	}
}

void open_write_file(std::string fileName){
	std::string fileDocName;
	fileDocName.append(fileName);
	writeFileObject.open(fileDocName, std::fstream::out | std::fstream::app);
	if(readFileObject.is_open()){
		printf("File open, waiting to write in file doc...\n");
	}
	else{
		printf("Failed to open doc file! File to read couldn't open...");
		return ;
	}
}

int main(int argc, char *argv[]){
	std::string fileName = argv[2];
	read_new_file(fileName);
	open_write_file(fileName);
	std::string line;
	std::smatch name_match;
	std::smatch param_match;
	std::regex marks(NAME_MARK, PARAMETER_MARK);
	if(readFileObject.is_open() && !readFileObject.eof()){
		while(getline(readFileObject, line)){
			std::regex_search(line, name_match, marks);
	}	
}


	close_opened_file(fileName);
	return 0;
}
