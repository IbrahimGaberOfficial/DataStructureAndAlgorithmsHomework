#include <bits\stdc++.h>
using namespace std;

class trie{
private:
    static const int MAX_CHAR = 26;
    trie *child[MAX_CHAR];
    bool is_leaf{ };

public:
    trie(){
        memset(child, 0, sizeof(child));
    }
    // void insert(string str, int idx){
    //     if(idx == str.size()){
    //         is_leaf = true;
    //     }
    //     else{
    //         int current = str[idx] - 'a';
    //         if(child[current] == nullptr)
    //             child[current] = new trie();
    //         child[current]->insert(str, idx + 1);
    //     }
    // }
    void insert(string str){
        trie *now = this;
        for(int i = 0 ; i <= str.size(); i++){
            if(i == str.size()){
                now->is_leaf = true;
                break;
            }
            int current = str[i] - 'a';
            
            if(now->child[current] == nullptr)
                now->child[current] = new trie();
            now = now->child[current];
            
            
        }
    }
    // bool word_exist(string str, int idx){
    //     if(idx == str.size())
    //         return is_leaf;
    //     int current = str[idx] - 'a';
    //     if(child[current] == nullptr)
    //         return false;
    //     return child[current]->word_exist(str, idx + 1);
    // }
    bool word_exist(string str){
        trie *now = this;
        for(int i = 0; i <= str.size(); i++){
            if(i == str.size()){
                return now->is_leaf;
            }
            int current = str[i] - 'a';
            if(now->child[current] == nullptr)
                return false;
            now = now->child[current];
        }
    }
    bool prefix_exist(string str, int idx){
	if(idx == str.size())
		return true;
	int current = str[idx] - 'a';
	if(child[current] == nullptr)
		return false;
	return child[current]->prefix_exist(str, idx + 1);
}
};

int main(){
    trie* myTrie = new trie();
    myTrie->insert("abc");
    myTrie->insert("ali");

   
    cout << myTrie->word_exist("abc");
    cout << endl << myTrie->prefix_exist("ab", 0);
    cout << endl << myTrie->word_exist("al");


return 0;
}


