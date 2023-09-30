#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int data { };
	Node *next { };
	Node(int data) :
			data(data) {
	}
	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;	// let's maintain how many nodes 

	vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node *node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node *node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

public:

	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	LinkedList(const LinkedList&) = delete;
	LinkedList& operator=(const LinkedList &another) = delete;
	~LinkedList(){
		Node* current = head ;
		while(current){
			// delete current;
			head = head->next;
            debug_remove_node(current);
			delete current;
			current = head;
		}
        delete tail;
        tail = head = nullptr;
        length = 0;
      
    }
	void debug_print_address() {
		for (Node *cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node *node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int) debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n" << flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
		for (Node *cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
			return;
		}

		assert(head != nullptr);
		assert(tail != nullptr);
		assert(tail->next == nullptr);

		if (length == 1)
			assert(head == tail);
		else {
			assert(head != tail);

			if (length == 2)
				assert(head->next == tail);
			else if (length == 3) {
				assert(head->next);
				assert(head->next->next == tail);
			}
		}
		int len = 0;
		Node *prev = nullptr;
		for (Node *cur = head; cur; prev = cur, cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?

		assert(length == len);
		assert(length == (int)debug_data.size());
		assert(prev == tail);	// last node is tail
	}

	////////////////////////////////////////////////////////////

	void print() {
		for (Node *cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	// These 2 simple functions just to not forget changing the vector and length
	void delete_node(Node *node) {
		debug_remove_node(node);
		--length;
		delete node;
	}

	void add_node(Node *node) {
		debug_add_node(node);
		++length;
	}

	void insert_end(int value) {
		Node *item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else
			tail->next = item, tail = item;

		debug_verify_data_integrity();
	}

	////////////////////////////////////////////////////////////
    Node* getNthItem(int idx){
        int i = 1;
        for(Node* current = head; current; current = current->next, i++){
            if(i == idx){
                return current;
            }
        }
        return nullptr;
    }
    Node* getNthItemBack(int idx){
        return getNthItem(length + 1 - idx);

    }
    ////////////////////////////////////////////////////////////////
    // using length variable to check firstly
    // make the parameter list2 pass by refrence as the copy constructor 
    // is distabled above ^
    bool is_same( LinkedList &list2){
        if(list2.length != this->length)
            return false;
        
        // check every single node until reach to end or until 
        // there is no equal nodes
        // need 2 pointers to point to first node in each likned list
        
        // same lenghth, so if they same data , they are identical
        Node* list1_pointer = this->head;
        Node* list2_pointer = list2.head;
        while(list1_pointer && list1_pointer){
            if((list1_pointer->data != list2_pointer->data))
                return false;
            list1_pointer = list1_pointer->next;
            list2_pointer = list2_pointer->next;
        }
        return true;

    }

    // is same without using lenth
    
    bool is_sameV2(LinkedList &list2){
        // again use two pointers
        // check the data until reaching null
        // if one of the pointer reaches null before the second,
        // they are not identical lists
        Node* current = head;
        Node* list2_point = list2.head;
        if(!current & !list2_point)
            return true;
        if((!current && list2_point) || (current && !list2_point))
            return false;
        while(current && list2_point){
            if(current->data != list2_point->data)
                return false;
            current = current->next;
            list2_point = list2_point->next;
        }
        // if(current != list2_point)
        //     return false;
        // return true;
        return (current == list2_point);
    }
};
void test1(){
    LinkedList list1, list2;
    list1.insert_end(10);
    list1.insert_end(20);
    list1.insert_end(30);
    list1.insert_end(40);
    cout << list1.is_sameV2(list2) << endl; // 0
    list2.insert_end(10);
    list2.insert_end(20);
    list2.insert_end(30);
    list2.insert_end(40);
    cout << list1.is_sameV2(list2) << endl; // 1
    list2.insert_end(50);
    cout << list1.is_sameV2(list2) << endl; // 0
    list2.~LinkedList();
    list2.insert_end(10);
    cout << "\ninsertion\n" << endl;

    LinkedList list3;
    list3.insert_end(3);
    list3.insert_end(4);
    list3.insert_end(5);
    list3.insert_end(6);
    list3.print();
    cout << list1.is_sameV2(list3) << endl; // 0





    cout << "\n\n\n";
   
}

int main() {
	test1();
	// test2();
	//test3();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}

