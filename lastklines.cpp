// Write a method to print the last Klines of an input file using C++

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#define BUF_SIZE 256
#define NUM_LINES 7

int main(int argc, char* argv[]){
	std::ifstream myfile("linefile.txt");
	std::string buffer;
	std::vector <std::string> lines;
	
	while(lines.size() < NUM_LINES){
		std::getline(myfile, buffer);
		lines.push_back(buffer);
	}
	
	int i = 0;
	while(!myfile.eof()){
		std::getline(myfile, buffer);
		lines.at(i) = buffer;
		i++;
	}
	for (auto it = lines.begin(); it != lines.end(); ++it){
		std::cout << *it << '\n';
	}
	return 0;
}
