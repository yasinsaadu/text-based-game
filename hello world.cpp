#include <iostream>
#include <string>
using namespace std;

void greet(const string& name) {
    cout << "Hello, " << name << "!" << endl;
}
int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    greet(name);   
    return 0;
}
