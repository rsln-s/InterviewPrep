#include <iostream>
#include <unordered_map>
#include <string>

struct Node {
	Node* next = nullptr;
	std::string data;

	Node (std::string val) { data = val; }
};

class List {

	Node* head;
	
public:
	List(Node* h) { head = h; }
	
	void append_to_tail(Node* new_tail){
		Node* iter = head;
		while(iter->next != nullptr){
			iter = iter->next;
		}
		iter->next = new_tail;
		return;
	}

	void append_to_tail(std::string val){
		Node* node = new Node(val);
		append_to_tail(node);
		return;
	}

	Node* remove_from_head(){
		Node* res = head;
		head = head->next;
		return res;
	}

    Node* peek_from_head(){
        return head;
    }   


	void remove (std::string val){
		Node* iter = head;
		if(iter->data == val){
			head = iter->next;
			free(iter);
			return;
		}
		if(iter->next == nullptr)
			return;
		while(true){
			if ((iter->next)->data == val){
				Node* to_be_deleted = iter->next;
				iter->next = (iter->next)->next;
				free(to_be_deleted);
				return;
			}
			if ((iter->next)->next == nullptr){
				free(iter);
				return;
			}
			iter = iter->next;	
		}	
	}

	void print_all(){		
                Node* iter = head;
		std::cout << iter->data << " ";
                while(iter->next != nullptr){
                        iter = iter->next;
                        std::cout << iter->data << " ";
                };
	}
};

class Queue{
	List* l;

public:
	Queue (std::string first_val){
		Node* head = new Node(first_val);
		l = new List(head);
	}

	void push(std::string val){
		l->append_to_tail(val);
	}

	std::string pop(){
		return (l->remove_from_head())->data;
	}

	std::string peek(){
		return (l->peek_from_head())->data;
	}	

	void print_all(){
		l->print_all();
	}

};

int main(){
	Queue* q = new Queue("-a");
	q->push("a");
	q->push("b");
	std::cout << "first: " << q->peek() << '\n';
	q->push("c");
	q->pop();
	q->print_all();
	return 0;
}
