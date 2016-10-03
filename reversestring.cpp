#include <iostream>
#include <stdlib.h>

void reverse(char* str){
	char c;
	int size = 0;
	while(str[size] != '\0'){
		size++;
	}
	for(int i = 0; i < size/2; i++){
		c = str[i];
		str[i] = str[size-i-1];
		str[size-i-1] = c;
	}
	return;
}

int main(int argc, char* argv[]){
	if (argc != 3){
		std::cout << "correct use: a.out [size] [your string]\n";
		return 1;
	}
	int size = atoi(argv[1]);
	char* str = (char*) malloc(size * sizeof(char));
	str = argv[2]; 
	reverse(str);
	std::cout << str << '\n';
	return 0;	
}
