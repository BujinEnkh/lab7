#include <iostream>
#include <cmath> 
using namespace std;

//эх класс 
class Shape {
protected:
    string name; // дүрсний нэр
    static int count; //дүрс тоолох хувьсагч

public:
    // Параметертэй байгуулагч функц
    Shape(string n) {
        this->name = n;   // this ашиглаж өгөгдөл рүү хандсан
        count++;           // объект үүсэх бүрт нэмэгдэнэ
    }
    // Хийсвэр функцууд
    virtual double area() = 0;     // талбай олох
     virtual double perimeter() = 0; // периметр олох

     
    // Нэрийг авах 
    string getName() {
        return this->name; // this 
    }
    // static функц 
    static int getCount() {
        return count;
    }
};

// static хувьсагчийн анхны утгыг 0 
int Shape::count = 0;

//Circle класс
class Circle : public Shape {
    double radius;
public:
    // байгуулагч
    Circle(double r) : Shape("Circle") {
        this->radius = r;
    }
    // override хийсэн функцууд
    double area() override {
        return 3.1415 * radius * radius;
    }
    double perimeter() override {
        return 2 * 3.1415 * radius;
    }};

// Square класс
class Square : public Shape {
    double side;
public:
    Square(double s) : Shape("Square") {
        this->side = s;
    }
    double area() override {
        return side * side;
    }
    double perimeter() override {
        return 4 * side;
    }};

//Triangle класс
class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double x, double y, double z) : Shape("Triangle") {
        this->a = x;
        this->b = y;
        this->c = z;
    }
    double perimeter() override {
        return a + b + c;
    }
    double area() override {
        double s = perimeter() / 2; // хагас периметр
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

// гол 
int main() {
    // Олон объект
    Circle c1(3);
    Square s1(4);
    Triangle t1(3, 4, 5);
    Circle c2(2);
    Square s2(5);
    Triangle t2(6, 7, 8);

    // Массив үүсгэнэ
    Shape* shapes[6] = { &c1, &s1, &t1, &c2, &s2, &t2 };
    cout << "niit: " << Shape::getCount() << endl << endl;
    // Талбайгаар эрэмбэлэх (Bubble sort)
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (shapes[j]->area() > shapes[j + 1]->area()) {
                Shape* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }

    cout << "=Area=" << endl;
    for (int i = 0; i < 6; i++) {
        cout << shapes[i]->getName()
             << " | Area: " << shapes[i]->area()
             << endl;
    }

    cout << endl;

    //Периметрээр эрэмбэлэх
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (shapes[j]->perimeter() > shapes[j + 1]->perimeter()) {
                Shape* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }
    cout << "=Perimeter=" << endl;
    for (int i = 0; i < 6; i++) {
        cout << shapes[i]->getName()
             << " | Perimeter: " << shapes[i]->perimeter()
             << endl;
    }
    return 0;
}
