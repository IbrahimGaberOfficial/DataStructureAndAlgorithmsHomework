#include <bits\stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> my_stack;
    stack<int> min_stack;
    
    MinStack() {
        
    }
    
    void push(int val) {

        my_stack.push(val);
        if(min_stack.empty())
            min_stack.push(val);

        else if(val < min_stack.top())
            min_stack.push(val);
        else
            min_stack.push(min_stack.top());
    }
    
    void pop() {
        my_stack.pop();
        min_stack.pop();
        
    }
    
    int top() {
        return my_stack.top();
        
    }
    
    int getMin() {
        return min_stack.top();
        
    }
    int getSize(){
        return my_stack.size();
    }
};



int main(){


//   Your MinStack object will be instantiated and called as such:
  MinStack* obj = new MinStack();
    obj->push(10);
    obj->push(15);
    obj->push(8);
    obj->push(20);
    obj->push(24);
    obj->push(7);
    cout << obj->getSize() << " \n";
    int sz =  obj->getSize();
    for(int i = 0; i < sz; i++){
        cout << obj->getMin() << " ";
        obj->pop();
    }

    cout << "\nNo RTE.\n";
 

return 0;
}
