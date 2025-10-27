#include <iostream>   
#include <cmath>      // математикийн функцүүд
#include <vector>     // vector ашиглах
#include <algorithm>  // sort функц хэрэглэх
using namespace std;

// Суурь класс
class Shape {
protected:
    string name; // нэр хадгалах хувьсагч
public:
    Shape(string n = "Shape") { // байгуулагч функц
        name = n; // нэр
    }

    virtual double area() = 0;   // талбай олох функц 
    virtual void display() = 0;  // дэлгэцэнд хэвлэх функц
};

// 2D класс
class TwoDShape : public Shape {
protected:
    double x, y; // координат
public:
    // байгуулагч функц, эх классын байгуулагчийг дуудна
    TwoDShape(string n = "2DShape", double a = 0, double b = 0) : Shape(n) {
        x = a;
        y = b;
    }
};

// Тойрог класс
class Circle : public TwoDShape {
private:
    double r; // радиус
public:
    Circle(double cx, double cy, double radius) : TwoDShape("Circle", cx, cy) {
        r = radius; // радиус
    }

    // талбай = π * r * r
    double area() override {
        return M_PI * r * r;
    }

    // дэлгэцэнд хэвлэх
    void display() override {
         cout << "Circle" << endl;
        cout << "Center: (" << x << "," << y << ")" << endl;
        cout << "Radius: " << r << endl;
         cout << "Area: " << area() << endl;
        cout << endl;
    }
};

// Квадрат класс
class Square : public TwoDShape {
private:
    double side; // талын урт
public:
    Square(double a, double b, double s) : TwoDShape("Square", a, b) {
        side = s; // талын урт
    }

    double area() override {
        return side * side; // талбай = тал * тал
    }

    void display() override {
         cout << "Square" << endl;
        cout << "Top-left: (" << x << "," << y << ")" << endl;
          cout << "Side: " << side << endl;
         cout << "Area: " << area() << endl;
         cout << endl;
    }
};

// Гурвалжин класс
class Triangle : public TwoDShape {
private:
    double side; // талын урт
public:
    Triangle(double a, double b, double s) : TwoDShape("Triangle", a, b) {
        side = s; // талын урт хадгална
        }
    double area() override {
        return (sqrt(3) / 4) * side * side; // талбай = √3/4 * s²
    }
    void display() override {
        cout << "----- Triangle -----" << endl;
        cout << "Top: (" << x << "," << y << ")" << endl;
        cout << "Side: " << side << endl;
        cout << "Area: " << area() << endl;
        cout << endl;
    }
};

int main() {
    //объектууд
    Circle c1(0, 0, 5);
    Circle c2(1, 1, 2);
    Square s1(2, 3, 4);
    Square s2(0, 0, 3);
    Triangle t2(1, 2, 5);
    Triangle t1(0, 4, 6);

    // Дүрснүүдийг vector-т хадгална
    vector<Shape*> shapes;
    shapes.push_back(&c1);
    shapes.push_back(&c2);
    shapes.push_back(&s1);
    shapes.push_back(&t1);
    shapes.push_back(&s2);
    shapes.push_back(&t2);

    // Талбайгаар нь эрэмбэлнэ (жижигээс том)
    sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
        return a->area() < b->area();
    });
    // Дүрснүүдийг хэвлэх
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->display();
    }
    return 0;
}
