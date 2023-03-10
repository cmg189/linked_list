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

// constructors
List:: List(Employee person){
    this-> data = person;
    this-> infront = nullptr;
    this-> behind = nullptr;
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
pair<List*, List*> init_list(vector<Employee> collection){
    // create head node
    Employee person = collection.front();
    collection.erase(collection.begin());
    List* node = new List(person);
    node->infront = nullptr;
    node->behind = nullptr;
    List* head = node;
    List* tail = node;

    // add all objects to node
    while(!collection.empty()){
        person = collection.front();
        List* node = new List(person);
        node->infront = tail;
        node->behind = nullptr;
        tail->behind = node;
        tail = node;
        collection.erase(collection.begin());
    }

    // return the head and tail pointers 
    pair<List*, List*> head_tail = make_pair(head, tail);
    return head_tail;
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
    string new_line;
    int choice;
    cout << "\nChoose a list operation to perform\n";
    cout << "1 Add employee\n";
    cout << "2 Delete employee\n";
    cout << "3 Output list\n";
    cout << "4 End program\n\n";
    cout << "> ";
    cin >> choice;
    getline(cin, new_line);

    return choice;
}

// create new Employee object
Employee create_object(){
    string name, position, new_line;
    int id;
    float salary;

    cout << "\nEnter the details of the new employee\n\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    getline(cin, new_line);
    cout << "Position: ";
    getline(cin, position);
    cout << "Salary: $";
    cin >> salary;
    //
    // FIX ME
    // take into account if a user enters 85,500
    // cin as string then convert to float
    //

    Employee person(name, id, position, salary);

    return person;
}

// output all employees
void output_all(List* head){
    cout << "\n\t\tList of Employees\n\n";
    List* display = head;
    while(display != nullptr){
        Employee person = display->data;
        person.output_info();
        display = display->behind;
    }

    return;
}

// add employee to list
void append(pair<List*, List*>& head_tail, Employee person){
    List* node = new List(person);
    node->infront = head_tail.second;
    node->behind = nullptr;
    head_tail.second->behind = node;
    head_tail.second = node;

    cout << endl << person.get_name() << " has been added\n";
    return;
}

// return employee specified by user
Employee select_employee(pair<List*, List*> head_tail){
    bool list_end = false;
    int id;
    cout << "\nEnter the employee ID you would like to delete\n\n";
    cout << "> ";
    cin >> id;

    // start searching through list
    List* search = head_tail.first;
    Employee person = search->data;
    int target = person.get_id();

    while(target != id){
        search = search->behind;
        if(search == nullptr){
            list_end = true;
            break;
        }
        person = search->data;
        target = person.get_id();
    }

    // if ID is not found, return object with default constructor 
    if(list_end){
        cout << "\nEmployee not found with that ID\n\n";
        Employee not_found;
        return not_found;
    }

    return person;
}

// remove employee from list
void delete_employee(pair<List*, List*>& head_tail, Employee person){
    // indicates employee was not found
    if(person.get_name() == "VOID"){
        return;
    }

    // search list to see if deleting head or tail of list
    List* search = head_tail.first;
    do{
        cout << "finding\n";
        Employee find = search->data;
        if(find.get_id() == person.get_id()){
            // deleting head of list
            if(search == head_tail.first){
                head_tail.first = search->infront;
                search->infront->behind = nullptr;
                break;
            // deleting tail of list
            }else if(search == head_tail.second){
                head_tail.second = search->behind;
                search->behind->infront = nullptr;
                break;
            // deleting middle of list
            }else{
                search->behind->infront = search->infront;
                search->infront->behind = search->behind;
                break;
            }
            delete search;
            //return;
        }
        // keep searching list
        cout << "searching\n";
        search = search->infront;
    }while(search != nullptr);


    // FIX ME: loop exe only once
    /*
    while(search->infront != nullptr){
        cout << "finding\n";
        Employee find = search->data;
        if(find.get_id() == person.get_id()){
            // deleting head of list
            if(search == head_tail.first){
                head_tail.first = search->infront;
                search->infront->behind = nullptr;
                //break;
            // deleting tail of list
            }else if(search == head_tail.second){
                head_tail.second = search->behind;
                search->behind->infront = nullptr;
                //break;
            // deleting middle of list
            }else{
                search->behind->infront = search->infront;
                search->infront->behind = search->behind;
                //break;
            }
            delete search;
            //return;
        }
        // keep searching list
        cout << "searching\n";
        search = search->infront;
    }
    */

    return;
}