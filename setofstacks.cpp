#include <iostream>
#include <stack>
#include <vector>

class SetOfStacks{
	std::vector<std::stack<int>> stacks;
	int threshold;
	int size_of_last;

public:
	SetOfStacks (int t) {  
		threshold = t;	
		std::stack<int> first;
		stacks.push_back(first);
	}

	void push(int val){
		if(size_of_last == threshold){
			std::stack<int> another;
			stacks.push_back(another);
			size_of_last = 0;
		}
		(stacks.back()).push(val);
		size_of_last++;
	}

	void pop(){
		if((size_of_last == 1) && (stacks.size() > 1)){
			stacks.pop_back();
			size_of_last = threshold;
			return;
		}		
		(stacks.back()).pop();
	}

	int top(){
		return (stacks.back()).top();
	}
};

int main(){
	SetOfStacks* set = new SetOfStacks(3);
	set->push(2);
    set->push(3);
    set->push(4);
    set->push(5);
    set->push(6);
	std::cout << set->top();
	set->pop();
	set->pop();
	set->pop();
	std::cout << " " << set->top() << " ";
    set->pop();
    std::cout << " " << set->top() << " ";
	return 0;
}
