#include <bits\stdc++.h>
using namespace std;
struct ListNode {
	int val {};
	ListNode* next {};
	ListNode(int data) : val(data) {}
};

class LinkedList {
public:
	ListNode *head { };
	ListNode *tail { };


	void print() {
		// DON'T change head itself.
		// 		You will lose it
		ListNode* temp_head = head;
		while(temp_head != nullptr) {
			cout<<temp_head->val<<" ";
			temp_head = temp_head->next;
		}
		cout<<"\n";
	}

	void insert_end(int value) {
		ListNode* item = new ListNode(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}

	// This code has memory leak, as we did not free memory
};

class Solution{
public:
 ListNode* partition(ListNode* head, int x) {
    if(!head)
            return nullptr;
        if(!head->next)
            return head;

        ListNode* less = new ListNode(INT_MIN);
        ListNode* more_or_equal = new ListNode(-1);
        ListNode *A = less;
        ListNode *B = more_or_equal;
        for(; head; head = head->next){
            if(head->val < x){
                A->next = head;
                A = A->next;
            }
            else{
                B->next = head;
                B = B->next;
            }

        }
        B->next = nullptr;
        if(less->next)
            head = less->next;
        else
            head = more_or_equal;

        A->next = more_or_equal->next;
        return head;
    }


};
void test1(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(2);

    ListNode* head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = nullptr;
Solution mysol;
ListNode* result = mysol.partition(head, 3);
for(; result; result = result->next){
    cout << result->val << " ";
}



}
void test2(){
    LinkedList *myList = new LinkedList();
    myList->insert_end(-8);
    myList->insert_end(-7);
    myList->insert_end(7);
    myList->insert_end(7);
    myList->insert_end(5);
    myList->insert_end(3);
    myList->insert_end(-7);
    myList->insert_end(-8);
    myList->insert_end(-1);
    myList->insert_end(9);
    myList->insert_end(-2);
    myList->insert_end(4);
    myList->insert_end(6);
    myList->insert_end(-4);
    myList->insert_end(-1);
    myList->insert_end(3);
    myList->insert_end(0);
    myList->insert_end(4);
    myList->insert_end(-8);
    myList->insert_end(8);
    myList->insert_end(6);
    myList->insert_end(-4);
    myList->insert_end(-4);
    Solution mysol;
    ListNode *result = mysol.partition(myList->head, 0);
    for(; result; result = result->next)
        cout << result->val << " ";
    
}

int main(){

test2();

return 0;
}
