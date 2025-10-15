#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.display();
    return 0;
}
