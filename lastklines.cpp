// Write a method to print the last Klines of an input file using C++

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#define BUF_SIZE 256

int main(int argc, char* argv[]){
	std::ifstream myfile0("linefile.txt");
	char buffer[BUF_SIZE];
	char line7[BUF_SIZE], line6[BUF_SIZE], line5[BUF_SIZE], line4[BUF_SIZE], line3[BUF_SIZE], line2[BUF_SIZE], line1[BUF_SIZE];
	int linecount = 0;
	while(!myfile0.eof()){
		myfile0.getline(buffer, BUF_SIZE);
		linecount++;
	}

	std::cout << "Line count: " << linecount << '\n';

	myfile0.close();

	std::ifstream myfile("linefile.txt");

	for (int i = 0; i < linecount-8; i++){
		myfile.getline(buffer, BUF_SIZE);
	}

		
	myfile.getline(line7, BUF_SIZE);
        myfile.getline(line6, BUF_SIZE);                
        myfile.getline(line5, BUF_SIZE);                
        myfile.getline(line4, BUF_SIZE);                
        myfile.getline(line3, BUF_SIZE);                
        myfile.getline(line2, BUF_SIZE);                
        myfile.getline(line1, BUF_SIZE);                
	std::cout << line7 << '\n' << line6 << '\n' << line5 << '\n' << line4 << '\n' << line3 << '\n' << line2 << '\n' << line1 << '\n';
	return 0;
}
