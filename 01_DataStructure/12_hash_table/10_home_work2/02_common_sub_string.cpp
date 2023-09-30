#include <bits\stdc++.h>
using namespace std;

void commonSubString(string &str1, string &str2){
    // generate all possible sub strings and add to unordred_map
    unordered_map<string, int> hash_table1, hash_table2;

    for(int i = 0; i < str1.size(); i++){
        for(int j = i; j < str1.size(); j++){
            string tmp = str1.substr(i , j - i + 1);
            hash_table1[tmp];
        }
    }
    for(int i = 0; i < str2.size(); i++){
        for(int j = i; j < str2.size(); j++){
            string tmp = str2.substr(i , j - i + 1);
            hash_table2[tmp];
        }
    }
    for(auto x : hash_table1){
        string tmp = x .first;
        if(hash_table2.count(tmp)){
            cout << tmp << endl;
        }
    }
}

int main(){

    string str1 = "aaaaa";
    string str2 = "aaaaa";
    commonSubString(str1, str2);

return 0;
}
