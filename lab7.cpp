#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double gpa;

public:
    Student(string n, int a, double g) {
        name = n;
        age = a;
        gpa = g;
        cout << "Student object created! linkers" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    //Обьект үүсгэх үед байгуулагч функц автоматаар дуудагдана
    Student s1("Bat", 21, 3.8);
    
    s1.display(); // Мэдээлэл хэвлэх
    return 0;
}