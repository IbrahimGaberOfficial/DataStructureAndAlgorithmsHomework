#include <bits\stdc++.h>
using namespace std;

class MagicDictionary {
public:
    static const int MAX_CHAR = 26;
    MagicDictionary* child[MAX_CHAR]{};
    bool is_leaf{};

    MagicDictionary() {
        memset(child, 0, sizeof(child));
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i = 0; i < dictionary.size(); i++){
            insert(dictionary[i]);
        }
    }
    void insert(string str, int idx = 0){
        if(idx == str.size()){
            is_leaf = true;
        }
        else{
            int current = str[idx] - 'a';
            if(child[current] == nullptr)
                child[current] = new MagicDictionary();
            child[current]->insert(str, idx + 1);
        }
    }
    bool word_exsist(string str, int idx = 0){
       MagicDictionary* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				return false;	// such path don't exist
			cur = cur->child[ch];
		}
		return cur->is_leaf;
        
    }
    bool search(string searchWord) {
        
        for(int i = 0; i < searchWord.size(); i++){
            char cpy = searchWord[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                searchWord[i] = ch;
                if(ch == cpy)
                    continue;
                if(word_exsist(searchWord))
                    return true;
            }
            searchWord[i] = cpy;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main(){


MagicDictionary *magicDictionary = new MagicDictionary();
vector<string> _input = {"hello", "leetcode", "teying"};
list<int> mylist;
magicDictionary->buildDict(_input);
cout << magicDictionary->search("hello"); // return False
cout << " " << magicDictionary->search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
cout << " " << magicDictionary->search("hell"); // return False
cout << " " << magicDictionary->search("leetcoded"); // return False

return 0;
}
