#include <bits\stdc++.h>
using namespace std;

class Solution{
public:
    static bool checkValidTriangle(int a, int b, int c){
        
        if(((a + b) <= c) || ((a + c) <= b) || ((b + c) <= a))
            return false;
        return true;
    }
    static int largetPerimeter(vector<int> &nums){
        int max_perimeter = 0;
        sort(nums.begin(), nums.end());
        int P1 = 0,
            P2 = 1,
            P3 = 2;
        for(int i = 0; i < nums.size() && P3 < nums.size(); i++){
            if(checkValidTriangle(nums[P1], nums[P2], nums[P3])){
                max_perimeter = max(max_perimeter, (nums[P1] + nums[P2] + nums[P3]));
            }
            P1++, P2++, P3++;
        }
        return max_perimeter;
    }
};

void test(){
    vector<int> nums = {2, 1, 2};
    cout << Solution::largetPerimeter(nums) << endl;
    
    nums = {1, 2, 1};
    cout << Solution::largetPerimeter(nums) << endl;
   
    nums = {3, 2, 3, 4};
    cout << Solution::largetPerimeter(nums) << endl;
    
    nums = {3, 6, 2, 3};
    cout << Solution::largetPerimeter(nums) << endl;

}
int main(){
    test();


return 0;
}
