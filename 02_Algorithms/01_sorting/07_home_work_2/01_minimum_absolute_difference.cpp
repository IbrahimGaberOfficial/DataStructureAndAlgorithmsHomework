#include <bits\stdc++.h>
using namespace std;

class Solution{
public:
    static vector<vector<int>> minimumAbsDifference(vector<int> &nums){
        vector<vector<int>> result;
        int minimum_difference = INT_MAX;
        int nums_size = (int)nums.size();
        int current_difference = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums_size; i++){
            current_difference = abs(nums[i] - nums[i - 1]);
            if(minimum_difference > current_difference){
                minimum_difference = current_difference;
            }
        }
        for(int i = 1; i < nums_size; i++){
            current_difference = abs(nums[i] - nums[i - 1]);
            if(current_difference == minimum_difference){
                result.push_back({nums[i - 1], nums[i]});
            }
        }
        return result;

    }
};

void print2DVector(vector<vector<int>> &result){
    for(auto x : result){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void test(){
    vector<vector<int>> result;
    vector<int> nums = {4, 2, 1, 3};
    result = Solution::minimumAbsDifference(nums);
    print2DVector(result);
    

    nums = {1, 3, 6, 10, 15};
    result = Solution::minimumAbsDifference(nums);
    print2DVector(result);

    nums = {3, 8, -10, 23, 19, -4, -14, 27};
    result = Solution::minimumAbsDifference(nums);
    print2DVector(result);

}
int main(){

    test();

return 0;
}
