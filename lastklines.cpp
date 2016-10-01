// Write a method to print the last Klines of an input file using C++

#include <iostream>
#include <fstream>
#include <queue>
#include <iterator>
#include <string>
#define NUM_LINES 7

int main(int argc, char* argv[]){
	std::ifstream myfile("linefile.txt");
	std::string buffer;
	std::queue <std::string> lines;
	
	while(lines.size() < NUM_LINES+1){
		std::getline(myfile, buffer);
		lines.push(buffer);
	}
	
	while(!myfile.eof()){
		std::getline(myfile, buffer);
		lines.pop();
		lines.push(buffer);
	}
	while(lines.size() > 1){
		std::cout << lines.front() << '\n';
		lines.pop();
	}
	return 0;
}
