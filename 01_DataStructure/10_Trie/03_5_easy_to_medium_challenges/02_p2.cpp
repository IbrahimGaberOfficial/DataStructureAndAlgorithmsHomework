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
    string first_word_prefix(const string &str){
        string result = "";
        trie *now = this;
        for(int i = 0; i <= str.size(); i++){
            if(i == (int)str.size()){
                if(now->is_leaf)
                    return result;
                return str;
            }
            int current = str[i] - 'a';
            if(now->child[current] == nullptr){
                if(now->is_leaf)
                    return result;
                return str;
            }
            else{
                result += str[i];
                now = now->child[current];
            }

        }
        return "faild";

    }
};

int main(){
    trie *mytrie = new trie();
    mytrie->insert("ahmedali", 0);
    mytrie->insert("saidmohamed", 0);
    mytrie->insert("ibrahimgaber", 0);
    mytrie->insert("heasham", 0);

    cout << mytrie->first_word_prefix("ahmedali");
    cout << endl << mytrie->first_word_prefix("x");
    


return 0;
}
