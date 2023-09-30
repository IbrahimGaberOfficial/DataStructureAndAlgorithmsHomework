#include <bits\stdc++.h>
using namespace std;

void generateAllPossibleSubString(string str){
    unordered_map<string, int> hash_table;
    for(int i = 0; i < str.size(); i++){
        for(int j = i; j < str.size(); j++){
            // cout << str.substr(i, j - i + 1) << " ";
            string tmp = str.substr(i, j - i + 1);
            hash_table[tmp]++;
        }
    }
    int i = 0;
    for(auto x : hash_table){
        cout << i++ << ": " << x.first << endl;
    }
}

int main(){

    generateAllPossibleSubString("abba");
    string str = "a";

    
return 0;
}
