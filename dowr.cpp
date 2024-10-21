#include "dowr.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

#define NAME_MARK "_name_" 
#define PARAMETER_MARK "_param_"

std::fstream readFileObject;
std::fstream writeFileObject;

void read_new_file(std::string fileName){
	if(!readFileObject.is_open()){
		readFileObject.open(fileName, std::fstream::in);
	}
	else{
		printf("Error! File already opened...\n");
	}
	return ;
}

void close_opened_file(std::string fileName){
	if(readFileObject.is_open()){
		printf("Closing file...\n");
		readFileObject.close();
	}
	else{
		printf("Already closed...\n");
	}
	return ;
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
	}
	return ;
}
void close_write_file(std::string fileName){
	if(writeFileObject.is_open()){
		printf("Closing file...");
		writeFileObject.close();
	}
	else{
		printf("Write file already closed!");	
	}
	return;
}

int main(int argc, char *argv[]){
	std::string fileName = argv[2];
	read_new_file(fileName);
	std::string fileNameDoc = fileName.append("DOC");
	open_write_file(fileNameDoc);
	std::string line;
	std::smatch name_match;
	std::smatch param_match;
	std::regex marks(NAME_MARK, PARAMETER_MARK);
	if(readFileObject.is_open() && !readFileObject.eof()){
		while(getline(readFileObject, line)){
			if(std::regex_search(line, name_match, marks)){
				writeFileObject << line << "\n";	
			}
		}	
}

	close_write_file(fileName);
	close_opened_file(fileNameDoc);
	return 0;
}
