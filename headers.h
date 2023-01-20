#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// stored in linked list
class Employee {
    public:
        // constructors
        Employee();
        Employee(string name, int id, string position, float salary);

        // accessors
        string get_name();
        int get_id();
        string get_position();
        float get_salary();

        // mutators
        void set_name(string name);
        void set_id(int id);
        void set_position(string position);
        void set_salary(float salary);

    private:
        string name;
        int id;
        string position;
        float salary;
};

// double linked list
class List {
    public:
        //List();
        List(Employee person);
        Employee data;
        List* infront;
        List* behind;

        void append();

};

// output program description
void start_info();

// initialize objects from file
vector<Employee> load_data();

// initialize list from objects
void init_list(vector<Employee> collection);

// menu choices
int menu();