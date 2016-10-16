#include <iostream>
#include <stack>

void sort_stack(std::stack<int>& st){
	std::stack<int> tmp;
	int pivot, buf;
	while (!st.empty()){
		pivot = st.top();
		st.pop();
		if(tmp.empty()){
			tmp.push(pivot);
			continue;
		}
		if (pivot < tmp.top()){
			while(true){
				if (tmp.empty())
					break;
				buf = tmp.top();
				if (pivot > buf)
					break;
				tmp.pop();
				st.push(buf);
			}
		}
		tmp.push(pivot);
	}
	while(!tmp.empty()){
		buf = tmp.top();
		tmp.pop();
		st.push(buf);
	}
}

int main(){
	std::stack<int> st;
	st.push(1);
	st.push(19);
	st.push(4);
	st.push(7);
	st.push(3);
	sort_stack(st);
	int buf;
	while(!st.empty()){
		buf = st.top();
		st.pop();
		std::cout << buf << " ";
	}
	std::cout << '\n';
	return 0;
}
