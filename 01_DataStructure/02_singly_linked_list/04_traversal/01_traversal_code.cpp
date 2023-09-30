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
    void print(){
        for(Node*curr = head; curr != nullptr; curr = curr->next)
            cout << curr->data << " ";
        cout << endl;
    }
    Node* getNthItem(int idx){
        int i = 0;
        for(Node* curr = head; curr && i <= idx; curr = curr->next, i++){
            if(i == idx){
                return curr;
            }
        }
        return nullptr;

    }
    int search(int target){
        int i = 0;
        for(Node* curr = head ; curr; curr = curr->next, i++){
            if(curr->data == target){
                return i;
            }
        }
        return -1;
    }
    int improvedSearch(int target){
        int i = 0;
        for(Node* curr = head; curr, curr->next; curr = curr->next, i++){
            // check if the next value of currnet is the target
            // then swap them(current value and next value)
            if(curr->next->data == target){
                swap(curr->data, curr->next->data);
                return i;
            }
        }
        return -1;
    }

};
void test_traversal(){
    LinkedList myList;
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.print();
    myList.insertEnd(4);
    myList.print();

}

void test_get_nth_item(){
    LinkedList myList;
    myList.insertEnd(0);
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.insertEnd(4);
    
    cout << myList.getNthItem(2)->data << endl;
    cout << myList.getNthItem(4)->data << endl;
    cout << myList.getNthItem(5) << endl; // null pointer
    


}

void test_search(){
     LinkedList myList;
    myList.insertEnd(0);
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.insertEnd(4);
    cout << "idx = " << myList.search(4) << endl;
    cout << "idx = " << myList.search(7) << endl;
}

void test_improved_search(){
     LinkedList myList;
    myList.insertEnd(0);
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.insertEnd(4);
    myList.print();
    cout << "idx = " << myList.improvedSearch(4) << endl;
    myList.print();
    cout << "idx = " << myList.improvedSearch(7) << endl;
    myList.print();
}
int main(){

    // test_get_nth_item();
    // test_search();
    test_improved_search();

    cout << "\nNo RTE.\n";

return 0;
}
