#include "headers.h"

// constructors
Employee:: Employee(){
    this-> name = "VOID";
    this-> id = 0;
    this-> position = "VOID";
    this-> salary = 0;
    return;
}

Employee:: Employee(string name, int id, string position, float salary){
    this-> name = name;
    this-> id = id;
    this-> position = position;
    this-> salary = salary;
    return;
}

// accessors
string Employee:: get_name(){ return name; }

int Employee:: get_id(){ return id; }

string Employee:: get_position(){ return position; }

float Employee:: get_salary(){ return salary; }

// mutators
void Employee:: set_name(string name){
    this-> name = name;
    return;
}

void Employee:: set_id(int id){
    this-> id = id;
    return;
}

void Employee:: set_position(string position){
    this-> position = position;
    return;
}

void Employee:: set_salary(float salary){
    this-> salary = salary;
    return;
}

// constructor
List:: List(Employee person){
    List* node = new List(person);
    node-> data = person;
    node-> infront = nullptr;
    node-> behind = nullptr;
    return;
}


// output program description
void start_info(){
    cout << "\t\tDouble Linked List\n\n";
    cout << "Initalize employee objects to store them in a double linked list\n\n";
    cout << "Employee's have the following attributes:\n";
    cout << "- Name\n- ID\n- Position\n- Salary\n\n";
    return;
}

// initialize list from file
void load_data(){
    const string FILE = "data.txt";

    // open file for reading
    ifstream reading;
    reading.open(FILE);
    if(reading.fail()){
        cout << "Unable to load employee data from " << FILE << "\n\n";
        cout << "Program ended\n\n";
        exit(EXIT_FAILURE);
    }

    // remove all commas and make Employee objects 
    string line;
    vector<Employee> collection;
    while(getline(reading, line)){
        // name
        int comma_index = line.find(",");
        string temp = line.substr(comma_index +2);
        string name = line.substr(0, comma_index);

        // ID
        comma_index = temp.find(",");
        string str_id = temp.substr(0, comma_index);
        int id = stoi(str_id);

        // department
        comma_index = temp.find(",");
        temp = temp.substr(comma_index +2);
        comma_index = temp.find(",");
        string dept = temp.substr(0, comma_index);

        // salary 
        comma_index = temp.find(",");
        string str_salary = temp.substr(comma_index +2);
        float salary = stof(str_salary);

        // save objects
        Employee person(name, id, dept, salary);
        collection.push_back(person);
    }

    reading.close();

    return;
}