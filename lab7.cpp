<<<<<<< HEAD
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
    Student s1("Bat", 20, 3.8);
    
    s1.display(); // Мэдээлэл хэвлэх
    return 0;
}
=======
#include <iostream>   
#include <cmath>     
#include <string>     
using namespace std;

// Shape класс нь суурь класс болно
class Shape {
protected:
    string name;   // дүрсний нэр хадгалах гишүүн өгөгдөл
public:
    // байгуулагч функц - утга оноох
    Shape(string n = "Shape") {
        name = n;
    }

    // дэлгэцэнд дүрсний нэрийг хэвлэх функц
    virtual void display() {
        cout << "Shape name: " << name << endl;
    }
};

class TwoDShape : public Shape {   // Shape-аас удамшсан
public:
    //эх классын байгуулагчийг дуудах
    TwoDShape(string n = "2DShape", double xPos = 0, double yPos = 0)
        : Shape(n, xPos, yPos) {}
       // виртуал функц — дараагийн хүүхэд классууд өөрсдөө тодорхойлно
    virtual double area() = 0;          // талбай тооцох функц
    virtual double perimeter() = 0;  // периметр тооцох функц
};

// тойрог
// 2DShape-аас удамшсан тойрог класс
class Circle : public TwoDShape {   // 2DShape-аас удамшсан
private:
    double r;                    // радиус
public:
    // байгуулагч функц — төвийн координат, радиус, нэр авна    Circle(double cx, double cy, double radius, string n = "Circle")
        : TwoDShape(n, cx, cy) {  // эх класст координат ба нэр дамжуулна
        r = radius;                  // радиуст утга оноох }
// талбай тооцох 
    double area() override {
        return M_PI * r * r;
    }
 // тойргийн урт тооцох 
    double perimeter() override {
        return 2 * M_PI * r;
    }
      // дэлгэцэнд мэдээлэл хэвлэх 
    void display() override {
        cout << "\n" << endl;
        cout << "Name: " << name << endl;
         cout << "Center: (" << x << ", " << y << ")" << endl;
        cout << "Radius: " << r << endl;
        cout << "Area: " << area() << endl;
        cout << "Circumference: " << perimeter() << endl;
    }
};

// квадрат
class Square : public TwoDShape {     // 2DShape-аас удамшсан
private:
    double side;                           // талын урт
public:
    // байгуулагч функц — зүүн дээд оройн координат, талын урт, нэр
    Square(double topX, double topY, double s, string n = "Square")
        : TwoDShape(n, topX, topY) {  // эх класст нэр ба координат дамжуулна
        side = s;                     // талын урт онооно
    }
    // талбай = тал * тал
    double area() override {
        return side * side;
    }
    // периметр = 4 * тал
    double perimeter() override {
        return 4 * side;
    }
    // дэлгэцэнд мэдээлэл хэвлэх функц
    void display() override {
        cout << "\n" << endl;
         cout << "Name: " << name << endl;
        cout << "Top-left corner: (" << x << ", " << y << ")" << endl;
        cout << "Side length: " << side << endl;
        cout << "Area: " << area() << endl;
          cout << "Perimeter: " << perimeter() << endl;
    }
};


//гурвалжин
class Triangle : public TwoDShape {  // 2DShape-аас удамшсан
private:
    double side; // талын урт
public:
    // байгуулагч функц — дээд оройн координат, талын урт, нэр
    Triangle(double topX, double topY, double s, string n = "Triangle")
        : TwoDShape(n, topX, topY) {  // эх класст координат ба нэр дамжуулна
        side = s;                         // талын урт оноох
    }
     // талбай = (√3 / 4) * тал²
    double area() override {
        return (sqrt(3) / 4) * side * side;
    }
   // периметр = 3 * тал
    double perimeter() override {
        return 3 * side;
    }
    // дэлгэцэнд мэдээлэл хэвлэх функц
    void display() override {
        cout << "\n" << endl;
        cout << "Name: " << name << endl;
        cout << "Top vertex: (" << x << ", " << y << ")" << endl;
        cout << "Side length: " << side << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    // Тойрог үүсгэж, төвийг (0,0), радиусыг 5 гэж өгнө
    Circle c(0, 0, 5);
// Квадрат үүсгэж, зүүн дээд оройг (2,3), талын уртыг 4 гэж өгнө
    Square s(2, 3, 4);
// Зөв гурвалжин үүсгэж, дээд оройг (0,5), талын уртыг 6 гэж өгнө
    Triangle t(0, 5, 6);
    // Бүх дүрсийн мэдээллийг хэвлэх
    c.display();
    s.display();
    t.display();
    return 0; 
}

>>>>>>> e834154 (erdmee commit)
