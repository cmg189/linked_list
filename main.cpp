#include "headers.h"

int main(){
    // read data from file and initalize linked list
    vector<Employee> collection = load_data();
    pair<List*, List*> head_tail = init_list(collection);
    //List* node = new List();
    //node->output_all(head_tail.first);
    // output program description
    start_info();

    // output linked list operations to choose from
    bool done = false;
    while(!done){
        int choice = menu();
        switch(choice){
            case 1:{
                Employee person = create_object();
                break;
            }
            case 2:{
                break;
            }
            case 3:{
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

    cout << "Program ended\n\n";
    return 0;
}