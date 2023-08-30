#include <bits\stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
class trie{
public:
    trie *child[26]{};
    bool is_leaf{};
    trie(){
        memset(child, 0, sizeof(child));
    }
    //Dr Sol
    // the idea is if we reversed the inserted strings and also reversed the 
    // queries strings then then problem will be converted to prefix 
    // ahmed -> demha  and the querey med ->  dem which is prefix from demha
    void insert(string str, int idx = 0){
        reverse(str.begin(), str.end());
        trie *now = this;
        for(int i = 0; i < (int)str.size(); i++){
            if(i == str.size()){
                now->is_leaf = 1;
                return;
            }
            int current = str[i] - 'a';
            if(now->child[current] == nullptr)
                now->child[current] = new trie;
            now = now->child[current];

        }
    }
    bool suffex_exist(string str, int idx = 0){
        reverse(str.begin(), str.end());
        trie *now = this;
        for(int i = 0; i <= (int)str.size(); i++){
            if(i == (int)str.size()){
                return true;
            }
            int current = str[i] - 'a';
            if(now->child[current] == nullptr){
                return false;
            }
            now = now->child[current];
        }
        return true;
    }
};


int main(){

trie *mytrie = new trie();
mytrie->insert("ahmed");
mytrie->insert("ali");
mytrie->insert("saad");
mytrie->insert("ibrahim");

cout << mytrie->suffex_exist("med");


return 0;
}
