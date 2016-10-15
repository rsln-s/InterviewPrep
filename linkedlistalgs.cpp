#include <iostream>
#include <unordered_map>
#include <string>

class Node {
    
public:
    Node* next = nullptr;
    std::string data;
    
    Node (std::string val) { data = val; }
};

class List {
    
public:
    Node* head;
    
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
        std::cout << '\n';
        return;
    }
};

std::string kthtolast(List* l, int k){
    Node* iter = l->head;
    int size = 0;
    while((iter->next) != nullptr){
        size++;
        iter = iter->next;
    }
    size -= k-1;
    iter = l->head;
    while((iter->next) != nullptr){
        if (size == 0)
			return iter->data;
		size--;
        iter = iter->next;
    }
}

int main(){
    Node* a3 = new Node("a");
    List* l = new List(a3);
    l->append_to_tail("b");
    l->append_to_tail("c");
    l->append_to_tail("d");
    l->append_to_tail("e");
    l->append_to_tail("f");
    l->print_all();
	std::cout << kthtolast(l, 2) << '\n';	
    return 0;
}
