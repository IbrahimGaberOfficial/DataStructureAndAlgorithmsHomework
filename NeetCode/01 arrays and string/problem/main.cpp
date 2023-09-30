#include <bits\stdc++.h>
using namespace std;


 vector<int> runningSum(vector<int>& nums) {
        vector<int> Result;
        Result.push_back(nums.front());
        for(int i = 1; i < nums.size(); i++){
            Result.push_back( Result.at(i - 1) + nums.at(i));
        }
        return Result;
        
    }
int main(){

vector<int> nums;
nums.push_back(1);
nums.push_back(2);
nums.push_back(3);
nums.push_back(4);
vector<int> result = runningSum(nums);
for(int i = 0; i < result.size(); i++){
    cout << result[i] << " " ;
}

return 0;
}
