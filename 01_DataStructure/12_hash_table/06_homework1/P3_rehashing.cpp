/**
 * the problem is to make hash_string() work with characters lower, upper 
 * and digits
*/
#include <bits\stdc++.h>
using namespace std;
struct PhoneEntry
{
    const static int INTERNAL_LIMIT = 2147483647;
    string name;
    int phoneNumber;
    PhoneEntry(string name, int phoneNumber) : name(name), phoneNumber(phoneNumber)
    {}
    int hash_string(string str, int n = 65407){
        int base = 26 + 26 + 10; // upper and lower and digits
        long long nn = n;
        long long sum = 0;
        for(int i = 0; i < int(str.size()); i++){
            int value = 0;
            if(islower(str[i]))
                value = str[i] - 'a';
            else if(isupper(str[i]))
                value = 26 + str[i] - 'A';
            else if(isdigit(str[i]))
                value = 26 + 26 + str[i] - '0';
            else{
                cout << "character " << str[i] << ", in  index : " << i << " is not letter nor digit\n";
                assert(false);
            }
            sum = sum * base + value;
            sum = sum % nn;
        }
        return sum;
    }
    // int hash_string(string str, int n){
    //     long long nn = n;
    //     long long sum = 0;
    //     for(int i = 0; i  < (int)str.size(); i++){
    //         sum = (sum * 26 + str[i] - 'a') % nn;
    //     }
    //     return sum % nn;
    // }
    int hash(){
        return hash_string(name, INTERNAL_LIMIT);
    }
    void print(){
        cout << " [ " << name << " , " << phoneNumber << " ]";
    }
};

class PhoneHashTable{
private:
    int tableSize;
    double limit_load_factor{ };
    int number_of_elements{ };
    vector<vector<PhoneEntry>> table;
public:
    PhoneHashTable(int tableSize = 5, double limit_load_factor = 0.75) : 
    tableSize(tableSize), limit_load_factor(limit_load_factor){
        table.resize(tableSize);
    }
    void copy_table(vector<vector<PhoneEntry>> &old, vector<vector<PhoneEntry>> &the_new){
        for(int i = 0; i < int(old.size()); i++){
            int vector_size = old[i].size();
            if(!vector_size)
                continue;
            for(int j = 0; j < vector_size; j++){
                PhoneEntry tmp = old[i].back();
                old[i].pop_back();
                int idx = tmp.hash() % tableSize;
                the_new[idx].push_back(tmp);
            }
        }
    }
    void rehashing(){
        tableSize = 2 * tableSize;
        vector<vector<PhoneEntry>> new_table;
        new_table.resize(tableSize);
        copy_table(table, new_table);
        swap(table, new_table);
    

    }

    void put(PhoneEntry phone){
        int idx = phone.hash() % tableSize;
        for(int i = 0; i < table[idx].size(); i++){
            if(phone.name == table[idx][i].name){
                // make update and return
                table[idx][i]= phone;
                return;
            }
        }
        number_of_elements++;
        double new_load_factor = double(number_of_elements) / double(tableSize);
        if(new_load_factor > limit_load_factor){
            rehashing();
        }
        table[idx].push_back(phone);
    }
    bool remove(PhoneEntry phone){
        int idx = phone.hash() % tableSize;
        for(int i = 0; i < table[idx].size(); i++){
            if(table[idx][i].name == phone.name){
                swap(table[idx][i], table[idx].back());
                table[idx].pop_back();
                return true;
            }
        }
        return false;
    }
    // search if element is found and update the passed argument with the 
    // found element
    bool get(PhoneEntry &phone){
        int idx = phone.hash() % tableSize;
        for(int i = 0; i < table[idx].size(); i++){
            if(table[idx][i].name == phone.name){
                phone = table[idx][i];
                return true;
            }
        }
        return false;
    }
    // print all elements in hash table
    void print_all(){
        for(int hash = 0; hash < tableSize; hash++){
            if(!table[hash].size())
                continue;
            cout << "Hash  " << hash << " :";
            for(int i = 0; i < table[hash].size(); i++){
                table[hash][i].print();
            }
            cout << endl;
        }
    }
};


int main(){

    PhoneHashTable *phoneTable = new PhoneHashTable();

    phoneTable->put({"a", 122});
    phoneTable->put({"b", 122});
    phoneTable->put({"z", 122});
    phoneTable->put({"zv", 122});
    phoneTable->put({"saad", 122});

    phoneTable->put({"sada", 122});
    phoneTable->put(PhoneEntry("saad", 155));
    phoneTable->print_all();

    PhoneEntry e("saad", 0);
    if(phoneTable->get(e))
        cout << e.phoneNumber << endl;

    cout << "\nNo RTE.\n";
return 0;
}
