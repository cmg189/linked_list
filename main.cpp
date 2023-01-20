#include "headers.h"

int main(){

    vector<Employee> collection = load_data();
    init_list(collection);
    start_info();

    cout << "Program ended\n\n";
    return 0;
}