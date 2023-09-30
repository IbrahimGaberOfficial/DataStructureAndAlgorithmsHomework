#include <bits\stdc++.h>
using namespace std;

class Solution{

public:
    static vector<int> wiggleSort(vector<int> &nums){
        vector<int> result;
        int p1 = 0,
            p2 = (int)nums.size() - 1;
        
        if(!(int)nums.size() || (int)nums.size() == 1)
            return nums;
        
        sort(nums.begin(), nums.end());
        while(p1 < p2){
            // case that size is odd then the two pointers meet in middel
            if(p1 == p2){
                result.push_back(nums[p1]);
                return result;
            }
            result.push_back(nums[p1++]);
            result.push_back(nums[p2--]);

        }
        return result;
    }
};
void printVector(vector<int> &nums){
    for(auto x : nums)
        cout << x << " ";
    cout << endl;
}
void test(){
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    nums = Solution::wiggleSort(nums);
    printVector(nums);

}
int main(){

    test();

return 0;
}
