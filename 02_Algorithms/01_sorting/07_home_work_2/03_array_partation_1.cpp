#include <bits\stdc++.h>
using namespace std;

class Solution{

public:
    static int arrayPairSum(vector<int> &nums){
        int max_par_sum{};
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i+=2){
            max_par_sum += nums[i];
        }
        return max_par_sum;
    }
};

void test(){
    vector<int> nums = {1, 4, 3, 2};
    cout << Solution::arrayPairSum(nums) << endl;
    
    nums = {6, 2, 6, 5, 1, 2};
    cout << Solution::arrayPairSum(nums) << endl;
}
int main(){

    test();

return 0;
}
