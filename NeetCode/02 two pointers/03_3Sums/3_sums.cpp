#include <bits\stdc++.h>
using namespace std;

class Solution{

public:
    static vector<vector<int>> _3Sums(vector<int> nums){
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int L = i + 1;
            int R = nums.size() - 1;
            for(int j = 0; j < nums.size(), L < R; j++){
                while(nums[i] + nums[L] + nums[R] < 0 && L < R){
                    L++;
                }
                while(nums[i] + nums[L] + nums[R] > 0 && L < R){
                    R--;
                }

                if(L < R && nums[i] + nums[L] + nums[R] == 0){
                    result.push_back({nums[i], nums[L], nums[R]});
                    break;
                }

            }
        }
        return result;

    }
};

void result(vector<int> &nums){
vector<vector<int>> result = Solution::_3Sums(nums);
    cout << "[";
    for(auto x : result){
        cout << "[";
        for(auto y : x){
            cout << y << " ";
        }
        cout << "] ";
    }
    cout << "]\n";

}
int main(){
    vector<int> nums = {0, 1, 1};
    result(nums);
    nums = {-3, 3, 4, -3, 1, 2};
    result(nums);
    
    nums = {-1, 0, 1, 2, -1, -4};
    result(nums);
    system("pause");
return 0;
}
