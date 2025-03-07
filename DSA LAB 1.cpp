#include <iostream>
using namespace std;

void lab1() {
    int num = 10;      
    int* ptr = &num;   

    cout << "Before modification:" << endl;
    cout << "Variable value: " << num << endl;
    cout << "Pointer value: " << *ptr << endl;

    *ptr = 20;  

    cout << "After modification:" << endl;
    cout << "Variable value: " << num << endl;
    cout << "Pointer value: " << *ptr << endl;
}

int main() {
    lab1();
    return 0;
}