#include <bits\stdc++.h>
using namespace std;

struct Node{
    int data{};
    Node* next{};
    Node(int value) :data(value){

    }
    ~Node(){
        delete this;
    }
};

class LinkedList{
private:
    Node* head{};

public:
    LinkedList(){}
    void print(){
        Node* current = head;
        while(current){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void addElement(int value){
        Node* new_node = new Node(value);
        Node* current = head;
        if(!head){
            head = new_node;
            return;
        }
        else{
            // iterate until reach the tail node which it's next == null
            // and behave as insert end as if you have tail
            Node* tail = getTail();
            tail->next = new_node;

        }
    }
    Node* getTail(){
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        return current;
    }
};

int main(){

    LinkedList list;
    list.print();
    list.addElement(10);
    list.print();

    list.addElement(20);
    list.print();

    list.addElement(30);
    list.print();

    list.addElement(40);
    list.print();
    
    cout << list.getTail()->data << endl;

return 0;
}
