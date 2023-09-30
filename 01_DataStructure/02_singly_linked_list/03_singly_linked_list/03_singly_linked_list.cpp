#include <bits\stdc++.h>
using namespace std;

struct Node{
    int data{};
    Node* next{};
    Node(int data): data(data){}

};
class LinkedList{
private:
    Node* head{ };
    Node* tail{ };
public:
    void insertEnd(int data){
        if(head == nullptr){
            // empty list
            head = new Node(data);
            tail = head;
            return;
        }
        tail->next = new Node(data);
        tail = tail->next;

    }
    void print_list(Node* head){
        if(head == nullptr)
            return;
        cout << head->data << " ";
        print_list(head->next);
    }
    void print(){
        print_list(head);
        cout << endl;
    }

};
void test_insert_end(){
    LinkedList myList;
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.print();
    myList.print();
}

int main(){

    test_insert_end();

return 0;
}
