#include <iostream>
#include <string>
using namespace std;

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