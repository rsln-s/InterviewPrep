#include <iostream>
#include <stack>

template <class T>
class MyQueue{
	std::stack<T> st1, st2;
	
	void flip_forward(){
            while(!st1.empty()){
                T el = st1.top();
				st1.pop();
                st2.push(el);
            }
	}

	void flip_back(){
            while(!st2.empty()){
                T el = st2.top();
				st2.pop();
                st1.push(el);
            }
	}

public:
	void push_back(T el){
		st1.push(el);
	}
	
	void pop_front(){
		if(st2.empty())
			flip_forward();
		st2.pop();
	}

	T front(){
		if(st2.empty())
			flip_forward();	
		return st2.top();
	}
	T back(){
		if(st1.empty())
			flip_back();
		return st1.top();	
	}
};

int main(){
	MyQueue<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	std::cout << "Back: " << q.back() << " front " << q.front() << '\n';
	q.pop_front();
	q.push_back(4);
    std::cout << "Back: " << q.back() << " front " << q.front() << '\n';
}
