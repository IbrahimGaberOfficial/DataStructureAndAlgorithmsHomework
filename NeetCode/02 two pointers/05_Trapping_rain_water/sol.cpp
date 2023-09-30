#include <bits\stdc++.h>
using namespace std;

class Solution{
public:
    static int calculateArea(vector<int> &height, int p0, int p1){
        int clac_height = min(height[p0], height[p1]);
        int calc_long = p1 - p0 - 1;
        return clac_height * calc_long;
    }
    static int trapingRainWater(vector<int> &height){
        // check the size > 2
        if(height.size() <= 2)
            return 0;
        
        int p0{}, p1{}, 
            p2 = (int)height.size() - 1;
        // get the valid range to work on
        // check the starting pos height[p0], which it not 0, and
        // height[P0] > height[P0 + 1]
            while(height[p0] < height[p0 + 1])
                p0++;

        // check the ending pos height[P2], which height[P2] > height[P2 -1]
            while(height[p2] <= height[p2 - 1])
                p2--;

        int sum_of_blocks;
        int calculated_area{};
        int trapped_water = 0;
        while(p0 < p2){
            sum_of_blocks = 0;
            p1 = p0 + 1;
            while(height[p1] <= height[p0] && p1 < p2){
                sum_of_blocks += height[p1];
                p1++;
            }
            // clculate the in between p0 and p1
            calculated_area = calculateArea(height, p0, p1);
            trapped_water += (calculated_area - sum_of_blocks);
            p0 = p1;
        }
        return trapped_water;
    }

};

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Solution::trapingRainWater(height) << endl;

    height = {4, 2, 0, 3, 2, 5};
    cout << Solution::trapingRainWater(height) << endl;

    height = {4, 2, 0, 3, 2, 2};
    cout << Solution::trapingRainWater(height) << endl;


return 0;
}
