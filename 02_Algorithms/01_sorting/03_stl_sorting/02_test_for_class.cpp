#include <bits\stdc++.h>
using namespace std;

class Employee{
private:
    int salary;
    int age;
    string name;
public: 
    Employee(int emp_salary, int emp_age, string emp_name) :
        salary(emp_salary), age(emp_age), name(emp_name){

    }
    int getSalary(){
        return salary;
    }
    int getAge(){
        return age;
    }
    string getName(){
        return name;
    }
    void print(){
        cout << "[ " << name << ", " << age << ", " << salary << "]";
    }
};

bool compareSalary(Employee first, Employee secode){
    return first.getSalary() < secode.getSalary();
}
bool compareAge(Employee first, Employee secode){
    bool compare = (first.getAge() < secode.getAge());
    return compare;
}
bool compareName(Employee first, Employee secode){
    bool compare = (first.getName() < secode.getName());
    return compare;
}
void printEmployees(vector<Employee> emp_list){
    for(auto x : emp_list){
        x.print();
        cout << " ";
    }
    cout << endl;
}
int main(){

Employee 
    emp1(5000, 20, "ali"),
    emp2(4000, 22, "said"),
    emp3(6000, 26, "mona");
    vector<Employee> emp_list = {emp1, emp2, emp3};

sort(emp_list.begin(), emp_list.end(), compareSalary);
printEmployees(emp_list);

sort(emp_list.begin(), emp_list.end(), compareAge);
printEmployees(emp_list);

sort(emp_list.begin(), emp_list.end(), compareName);
printEmployees(emp_list);

return 0;
}
