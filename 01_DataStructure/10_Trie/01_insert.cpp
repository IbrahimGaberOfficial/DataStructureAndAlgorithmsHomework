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
    void insert(string str, int idx){
        if(idx == str.size()){
            is_leaf = true;
        }
        else{
            int current = str[idx] - 'a';
            if(child[current] == nullptr)
                child[current] = new trie();
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
};

int main(){
    trie* myTrie = new trie();
    myTrie->insert("abc", 0);
   
    cout << myTrie->word_exist("abc", 0);
    cout << endl << myTrie->prefix_exist("ab", 0);


return 0;
}


