#include "headers.h"

int main(){

    start_info();

    vector<Employee> collection = load_data();

    init_list(collection);

    cout << "Program ended\n\n";
    return 0;
}