#include <bits\stdc++.h>
using namespace std;


class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> Max_heap;
    int Kth;  
    KthLargest(int k, vector<int>& nums) : Kth(k) {
        
        int sz = (int)nums.size();
        for(int i = 0; i < sz; i++){
            Max_heap.push(nums[i]);
            if(Kth < Max_heap.size())
                Max_heap.pop();
        }
    }
    
    int add(int val) {
        Max_heap.push(val);
        if(Kth < Max_heap.size())
            Max_heap.pop();
        return Max_heap.top();
    }
};
int main(){

vector<int> nums{4, 5, 8 ,2};
KthLargest mySol(3, nums);
cout << mySol.add(3);
cout << endl <<  mySol.add(5);
cout << endl <<  mySol.add(10);
cout << endl <<  mySol.add(9);
cout << endl <<  mySol.add(4);

return 0;
}
