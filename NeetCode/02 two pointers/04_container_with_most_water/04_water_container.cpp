#include <bits\stdc++.h>
using namespace std;

class Solution{
public:
    // static int mostWater(vector<int> nums){
    //     pair<int, int> maxAlone = {0, 0};
    //     for(int i = 1; i < nums.size(); i++){
    //         if(maxAlone.first <= nums[i] * (i)){
    //             maxAlone = {nums[i] * (i), i};
    //         }
    //     }
    //     // cout << maxAlone.first << " " << maxAlone.second << endl;
    //     int maxArea = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         int currentArea = abs(maxAlone.second - i) * min(nums[i], nums[maxAlone.second]);
    //         if(maxArea < currentArea)
    //             maxArea = currentArea;
    //     }
    //     return maxArea;
    // }
    static int mostWater(vector<int> nums){
        int L = 0;
        int R = nums.size() - 1;
        int maxArea = 0;
        while(L < R){
            int currentArea = abs(R - L) * min(nums[L] , nums[R]);
            maxArea = max(currentArea, maxArea);
            if(nums[L] < nums[R]){
                L++;
            }       
            else if(nums[L] > nums[R]){
                R--;
            }
            else if(nums[L] == nums[R]){
               L++;
            }
        }
        return maxArea;
    }
};

void result(vector<int> &nums){
    cout << Solution::mostWater(nums) << endl;
}
int main(){
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    result(nums);

    nums = {1, 1};
    result(nums);

    nums = {3, 4, 2, 16, 4, 5, 6};
    result(nums);


return 0;
}
