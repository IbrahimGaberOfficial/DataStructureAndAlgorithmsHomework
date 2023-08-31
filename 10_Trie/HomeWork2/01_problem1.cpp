#include <bits\stdc++.h>
using namespace std;

class trie{
private:
    static const int MAX_CHAR = 26;
    trie *child[MAX_CHAR];
    bool is_leaf{ };
    char from{};

public:
    trie(char from_init) : from(from_init){
        memset(child, 0, sizeof(child));

    }
    trie() {
        memset(child, 0, sizeof(child));

    }
    void insert(string str, int idx){
        if(idx == str.size()){
            is_leaf = true;
        }
        else{
            int current = str[idx] - 'a';
            if(child[current] == nullptr)
                child[current] = new trie(str[idx]);
            child[current]->insert(str, idx + 1);
        }
    }
    bool word_exist(string str, int idx){
        if(idx == str.size())
            return is_leaf;
        int current = str[idx] - 'a';
        if(child[current] == nullptr)
            return false;
        return child[current]->word_exist(str, idx + 1);
    }
    bool prefix_exist(string str, int idx){
	if(idx == str.size())
		return true;
	int current = str[idx] - 'a';
	if(child[current] == nullptr)
		return false;
	return child[current]->prefix_exist(str, idx + 1);
    }
    // string collected = "";
    // void get_all_strings(vector<string> &str){
    //     trie* now = this;
    //     _get_all_strings(str, now);
    // }
    // void _get_all_strings(vector<string> &str, trie* now){
    //     for(int i = 0; i < MAX_CHAR; i++){
    //         if(now->child[i] != nullptr){
    //             collected += char('a' + i);
    //             if(now->child[i]->is_leaf){
    //                 // str.push_back(collected);
                    
    //             }
                
    //         }
    //     }
    // }
     void get_all_strings(vector<string> &str){
        trie* now = this;
        _get_all_strings(str, now);
    }
    void _get_all_strings(vector<string> &str, trie* now, string collected = ""){
        for(int i = 0; i < MAX_CHAR; i++){
            if(now->child[i] != nullptr){
                // cout << char('a' + i);
                collected += char('a' + i);
                if(now->child[i]->is_leaf){
                    str.push_back(collected);
                    // cout << " ";
                    // str.push_back(collected);
                    
                }
                _get_all_strings(str, now->child[i], collected);
                // cout << "\n";
                collected = "";
            }
            
            
        }
    }
};

int main(){
    trie* myTrie = new trie('#');
    myTrie->insert("abcd", 0);
    myTrie->insert("xyz", 0);
    myTrie->insert("a", 0);
    myTrie->insert("ab", 0);
    myTrie->insert("xyzw", 0);
    myTrie->insert("bcd", 0);
   

    vector<string> res;
    myTrie->get_all_strings(res);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
return 0;
}


