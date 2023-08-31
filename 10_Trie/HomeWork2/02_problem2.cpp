#include <bits\stdc++.h>
using namespace std;

class trie{
private:
    static const int MAX_CHAR = 26;
    bool is_leaf{ };
    char from{};
    trie *child[MAX_CHAR];

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
    
     void get_all_strings(vector<string> &str){
        trie* now = this;
        _get_all_strings(str, now);
    }
    void _get_all_strings(vector<string> &str, trie* now, string collected = ""){
        if(now->is_leaf)
            str.push_back(collected);
        for(int i = 0; i < MAX_CHAR; i++){
            if(now->child[i] != nullptr){
                // cout << char('a' + i);
               
                _get_all_strings(str, now->child[i], collected + char('a' + i) );

            }
            
            
        }
    }
    void auto_complete(string str, vector<string> &result, int idx = 0){
       trie* now = this;
       for(int i = 0; i < str.size(); i++){
        int current = str[i] - 'a';

        if(now->child[current] == nullptr)
            return;
        now = now->child[current];
       }
    //    if(now->is_leaf){
    //         result.push_back(str);
    //    }
       _get_all_strings(result, now);
       
    }
};

int main(){
    trie* myTrie = new trie('#');
    myTrie->insert("abcd", 0);
    myTrie->insert("ab", 0);
    myTrie->insert("a", 0);
    myTrie->insert("abx", 0);
    myTrie->insert("abyz", 0);
    myTrie->insert("xyz", 0);
    myTrie->insert("xyzw", 0);
    myTrie->insert("bcd", 0);
    myTrie->insert("bxd", 0);
    myTrie->insert("bid", 0);

   

    vector<string> res;
    string querey = "b";
    myTrie->get_all_strings(res);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << "\n------------------" << endl;

    vector<string> new_res;
    myTrie->auto_complete(querey, new_res);

   cout << "\n------------------" << endl;

    for(int i = 0; i < new_res.size(); i++){
        // if(!i){
        //     cout << new_res[i] << endl;
        //     continue;
        // }
        cout <<  querey +  new_res[i] << "\n";
    }
return 0;
}


