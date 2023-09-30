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
    static string removeFirstLetter(string str){
        string result = "";
        for(int i = 1; i < str.size(); i++){
            result += str[i];
        }
        return result;
    }
    static vector<string> countSortForStringV2(vector<string> strs){
        // needt vector<vector<string>> to store all strings equal in first letter
        vector<vector<string>> table(26);
        vector<string> result;
        for(int i = 0; i < strs.size(); i++){
            int idx = strs[i][0] - 'a';
            table[idx].push_back(removeFirstLetter(strs[i]));

        }
        for(int i = 0; i < 26; i++){
            table[i] = countSortForString(table[i]);
        }
        for(int i = 0; i < table.size(); i++){
            for(int j = 0; j < table[i].size(); j++){
                char removed_char = i + 'a';
                string complete_string = removed_char + table[i][j];
                cout << complete_string << " ";
                result.push_back(complete_string);
            }
        }
        return result;
    }
};

void test( vector<string> strs){
    vector<string> result;
    result = Solution::countSortForStringV2(strs);
    // for(auto x : result)
    //     cout << x << " ";
    cout << endl;
}
void test2(){
     vector<string> strs = {"ziad", "belal", "adam", "baheir", "ali"};
    test(strs);

    strs = {"axz", "axa", "zzz", "abc", "abe"};
    test(strs);
}

int main(){
    test2();
   
return 0;
}
