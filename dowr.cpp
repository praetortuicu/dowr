#include "dowr.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

#define NAME_MARK "_name_" 
#define PARAMETER_MARK "_param_"

std::fstream readFileObject;
std::fstream writeFileObject;
std::fstream writeLogObject;

/*
_name_: open_log_file
_param_: std::string &fileName
*/

void open_log_file(std::string &fileName){
	std::string log_name = fileName.append(".log");
	try{
		writeLogObject.open(log_name, std::fstream::in | std::fstream::out | std::fstream::app);
		writeLogObject << "Opened " << fileName << " successfully!\n";
	}
	catch(std::exception &e){
		printf("Something went wrong when creating the .log file!\n");
	}
}

void read_new_file(const std::string &fileName){
	if(!readFileObject.is_open()){
		readFileObject.open(fileName, std::fstream::in);
	}
	else{
		printf("Error! File already opened...\n");
	}
	return ;
}

void close_opened_file(const std::string &fileName){
	if(readFileObject.is_open()){
		printf("Closing file...\n");
		readFileObject.close();
	}
	else{
		printf("Already closed...\n");
	}
	return ;
}

void open_write_file(const std::string &fileName){
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
void close_write_file(const std::string &fileName){
	if(writeFileObject.is_open()){
		printf("Closing file...");
		writeFileObject.close();
	}
	else{
		printf("Write file already closed!");	
	}
	return ;
}

int main(int argc, char *argv[]){
	char *fname = argv[1];
	std::string fileName(fname);
	read_new_file(fileName);
	printf("Opening %s\n", fname);
	std::string fileNameDoc = fileName.append("DOC");
	open_write_file(fileNameDoc);
	std::string line;
	std::smatch name_match;
	std::smatch param_match;
	std::regex marks(NAME_MARK, PARAMETER_MARK);
	if(readFileObject.is_open() && !readFileObject.eof()){
		while(getline(readFileObject, line)){
			if(std::regex_search(line, name_match, marks)){
				printf("Writing into file...\n");
				writeFileObject << line << "\n";	
			}
		}	
}

	close_write_file(fileName);
	close_opened_file(fileNameDoc);
	return 0;
}
