#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < sz; i++){
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
    
};

int main(){

vector<int> nums{1, 2, 3, 1};

Solution mysol;
cout << mysol.containsDuplicate(nums) << endl;

cout << "\nNo RTE.\n";

return 0;
}
