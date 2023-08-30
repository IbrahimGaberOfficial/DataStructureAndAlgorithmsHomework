#include <bits\stdc++.h>
using namespace std;

static const int MAX_CHAR = 26;
class trie{
public:
    trie *child[MAX_CHAR];
    bool is_leaf{};
    
    trie(){
        is_leaf = false;
        memset(child, 0, sizeof(child));
    }
    void insert(vector<string> &path ){
        for(int i = 0; i < (int)path.size(); i++){
            _insert_word(path[i]);
            
        }
    }
    void _insert_word(string &str){
        trie *now = this;
        for(int i = 0; i <= (int)str.size(); i++){
            if(i == (int)str.size()){
                now->is_leaf = 1;
                return;
            }
            int current = str[i] - 'a';
            if(now->child[current] == nullptr)
                now->child[current] = new trie();
            now = now->child[current];
        }
    }
    bool sub_path_exist(vector<string> &sub_path){
        
        for(int i = 0; i < sub_path.size(); i++){
            if(!word_exist(sub_path[i]))
                return false;
        }
        return true;
    }
    bool word_exist(string str){
        trie *now = this;
        for(int i = 0; i <= (int)str.size(); i++){
            if(i == (int)str.size()){
                return now->is_leaf;
            }
            int current = str[i] - 'a';
            if(now->child[current] == nullptr)
                return false;
            now = now->child[current];
        }
         return true;
    }
};

int main(){

   trie *tree = new trie();

	vector<string> path;

	path = {"home", "software", "eclipse"};
	tree->insert(path);

	path = {"home", "software", "eclipse", "bin"};
	tree->insert(path);

	path = {"home", "installed", "gnu"};
	tree->insert(path);

	path = {"user", "mostafa", "tmp"};
	tree->insert(path);

	path = {"user", "mostafa", "tmp"};
	cout << tree->sub_path_exist(path) << "\n"; // 1

	path = {"user", "mostafa"};
	cout << tree->sub_path_exist(path) << "\n"; // 1

	path = {"user", "mos"};
	cout << tree->sub_path_exist(path) << "\n"; // 0

	path = {"user", "mostafa", "private"};
	cout << tree->sub_path_exist(path) << "\n"; // 0



return 0;
}
