#include <iostream>
#include <unordered_map>

/* Implement an algorithm to determine if a string has all unique characters. */

int main(int argc, char* argv[]){
	std::unordered_multimap<std::size_t, char> ht;
	std::hash<char> hash_fn;
	int i = 0;
	char* input = argv[1];
	while(input[i] != '\0'){
		auto range = ht.equal_range(hash_fn(input[i]));
		if (range.first != ht.end()){
			for (auto it = range.first; it != range.second; ++it){
				if (it->second == input[i]){
					std::cout << "Not unique\n";
					return 1;
				}
			} 
		}
		ht.emplace(hash_fn(input[i]), input[i]);
		++i;
	}
	std::cout << "Unique\n";
	return 0;
}
