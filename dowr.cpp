#include "dowr.h"
#include <fstream>
#include <iostream>
#include <regex>

std::fstream readFileObject;
std::fstream writeFileObject;

void read_new_file(std::string fileName){
	if(!readFileObject.is_open()){
		readFileObject.open(fileName, std::fstream::in);
	}
	else{
		printf("Error! File already opened....\n");
		return ;
	}
}

void close_opened_file(std::string fileName){
	if(readFileObject.is_open()){
		printf("Closing file...\n");
		readFileObject.close();
	}
	else{
		printf("Could not open file! Already closed....\n");
		return ;
	}
}

void open_write_file(){
	writeFileObject.open("README.md", std::fstream::out | std::fstream::app);
	if(readFileObject.is_open()){
		printf("File open, waiting to write in README.md....\n");	
	}
}

int main(int argc, char *argv[]){
	std::string fileName = argv[2];
	read_new_file(fileName);
	open_write_file();



	close_opened_file(fileName);
	return 0;
}
