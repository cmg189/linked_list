#include "headers.h"

int main(){
    // read data from file and initalize linked list
    vector<Employee> collection = load_data();
    pair<List*, List*> head_tail = init_list(collection);

    // output program description
    start_info();

    // output linked list operations to choose from
    bool done = false;
    while(!done){
        int choice = menu();
        switch(choice){
            case 1:{
                Employee person = create_object();
                append(head_tail, person);
                break;
            }
            case 2:{
                Employee person = select_employee(head_tail);
                delete_employee(head_tail, person);
                break;
            }
            case 3:{
                output_all(head_tail.first);
                break;
            }
            case 4:{
                done = true;
                break;
            }
            default:{
                cout << "\nInvalid selection\n";
                break;
            }
        }
    }

    cout << "\nProgram ended\n\n";
    return 0;
}