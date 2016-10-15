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

int main(){
    Node* a1 = new Node("aa");
    Node* a2 = new Node("ab");
    Node* a3 = new Node("dc");
    List* l = new List(a3);
    l->append_to_tail(a1);
    l->append_to_tail(a2);
    l->append_to_tail("ab");
    l->append_to_tail("cg");
    l->append_to_tail("aa");
    l->print_all();
    
    std::unordered_map<std::size_t, std::string> ht;
    std::hash<std::string> hash_fn;
    
    Node* iter = l->head;
    ht.emplace(hash_fn(iter->data), iter->data);
    
    while((iter->next) != nullptr){
        auto range = ht.equal_range(hash_fn((iter->next)->data));
        if (range.first != ht.end()){
            for (auto it = range.first; it != range.second; it++){
                if(it->second == (iter->next)->data){
                    Node* tbd = iter->next;
                    iter->next = (iter->next)->next;
                    if(iter->next == nullptr)
                        goto print_and_finish;
                    free(tbd);
                }
            }
        }else{
            ht.emplace(hash_fn((iter->next)->data), (iter->next)->data);
        }
        iter = iter->next;
    }
print_and_finish:
    l->print_all();
    return 0;
}
