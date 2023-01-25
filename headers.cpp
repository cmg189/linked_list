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

// outputs all private member variables of object
void Employee:: output_info(){
    cout << "Employee: " << this->get_name() << endl;
    cout << "ID: " << this->get_id() << endl;
    cout << "Position: " << this->get_position() << endl;
    cout << "Salary: $" << this->get_salary() << endl << endl;
    return;
}

// constructor
List:: List(Employee person){
    this -> data = person;
    this-> infront = nullptr;
    this-> behind = nullptr;
    return;
}

// output all objects in data
void List:: output_all(List* head){
    List* display = head;
    while(display != nullptr){
        Employee person = display->data;
        person.output_info();
        display = display->behind;
    }
    return;
} 

// initialize objects from file
vector<Employee> load_data(){
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
        string temp = line.substr(comma_index +1);
        string name = line.substr(0, comma_index);

        // ID
        comma_index = temp.find(",");
        string str_id = temp.substr(0, comma_index);
        int id = stoi(str_id);

        // department
        comma_index = temp.find(",");
        temp = temp.substr(comma_index +1);
        comma_index = temp.find(",");
        string dept = temp.substr(0, comma_index);

        // salary 
        comma_index = temp.find(",");
        string str_salary = temp.substr(comma_index +1);
        float salary = stof(str_salary);

        // save objects
        Employee person(name, id, dept, salary);
        collection.push_back(person);
    }

    reading.close();

    return collection;
}

// initialize list from objects
void init_list(vector<Employee> collection){
    // create head node
    Employee person = collection.front();
    collection.erase(collection.begin());
    List* node = new List(person);
    node->infront = nullptr;
    node->behind = nullptr;
    List* head;
    List* tail;
    head = node;
    tail = node;

    // add all objects to node
    while(!collection.empty()){
        person = collection.front();
        node = new List(person);
        node->infront = tail;
        node->behind = nullptr;
        tail->behind = node;
        tail = node;
        collection.erase(collection.begin());
    }

    //node->output_all(head);

    return;
}

// output program description
void start_info(){
    cout << "\t\tDouble Linked List\n\n";
    cout << "This list stores Employee objects that have the following attributes\n";
    cout << "Name, ID, Position, and Salary\n";
    return;
}

// get list operation from user
int menu(){
    int choice;
    cout << "\nChoose a list operation to perform\n";
    cout << "1 Add employee\n";
    cout << "2 Delete employee\n";
    cout << "3 Output list\n";
    cout << "4 End program\n\n";
    cout << ">";
    cin >> choice;

    return choice;
}