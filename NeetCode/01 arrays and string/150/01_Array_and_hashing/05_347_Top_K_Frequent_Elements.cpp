// https://leetcode.com/problems/top-k-frequent-elements/description/
#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> theResult(k,0);
        unordered_map<int, int> elementFrequency;
        priority_queue<pair<int, int>> priorityQ;
        for(auto x : nums){
            elementFrequency[x]++;
        }
        //swap the element then push it into hte prorityQ
        for(auto element : elementFrequency){
                priorityQ.push({element.second, element.first});
            }
            // cout  << element.first << " : " << element.second << "\n";
            for(int i = 0; i < k; i++){
                pair<int, int> getPriorityQ = priorityQ.top();
                priorityQ.pop();
                theResult[i] = getPriorityQ.second;
        }
        
    return theResult;
    }
    
};

int main(){
Solution mySol;
vector<int> nums = {1, 1, 1, 2, 2, 3};

vector<int> theResult = mySol.topKFrequent(nums, 2);
for(auto x : theResult){
    cout << x << " ";
}


return 0;
}
