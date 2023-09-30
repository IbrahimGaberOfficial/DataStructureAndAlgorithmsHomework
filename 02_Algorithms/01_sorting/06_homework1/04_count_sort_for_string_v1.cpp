#include <bits\stdc++.h>
using namespace std;

class Solution{
public:
    static vector<string> countSortForString(vector<string> strs){
        vector<queue<string>> frequency(26);
        vector<string> result;
        for(int i = 0; i < strs.size(); i++){
            string currentStr = strs[i];
            int idx = currentStr[0] - 'a';
            frequency[idx].push(currentStr);
        }
        for(int i = 0; i < frequency.size(); i++){
            bool is_empty =  frequency[i].empty();
            while(!frequency[i].empty()){
                // cout << frequency[i].front() << " ";
                result.push_back(frequency[i].front());
                frequency[i].pop();
            }
            // if(!is_empty)
                // cout << endl;
        }
        return result;
    }
};

void test( vector<string> strs){
    vector<string> result;
    result = Solution::countSortForString(strs);
    for(auto x : result)
        cout << x << " ";
    cout << endl;
}
int main(){

    vector<string> strs = {"ziad", "belal", "adam", "baheir", "ali"};
    test(strs);

    strs = {"xz", "xa", "bc", "be"};
    test(strs);
return 0;
}
