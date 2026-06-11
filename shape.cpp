#include <iostream>
#include <string>
#include <vector>
#define PI 3.1428
using namespace std;

class Shape{
    public:
     Shape() {}
     
     virtual void draw() = 0;
     virtual void describe() = 0;
     
};
class Circle:public Shape {
    private:
     double r;
    public:
     Circle(int rad) {
         r = rad;
     }
     
     void draw() override{
         cout << "This is a Circle : \n";
         cout << "radius = " << r << endl;
     }
    void describe() override{
         double area = PI*r*r;
         double prm = 2*PI*r;
         
            cout << "Area = " << area << endl;
            cout << "Perimeter = " << prm << endl;
     }
};
class Rectangle: public Shape {
    private:
     double w, l;
    public:
     Rectangle(double width, double length) {
         w = width;
         l = length;
     }
     
     void draw() override{
         cout << "This is a Rectangle : \n";
         cout << "widh = " << w << " length = " << l << endl;
     }
    void describe() override{
         double area = w*l;
         double prm = 2*(w+l);
         
            cout << "Are = " << area << endl;
            cout << "Perimeter = " << prm << endl;
    }
};
class Square: public Shape {
    private:
     double l;
    public:
    Square(double length) {
        l = length;
    }
    void draw() override{
         cout << "This is a Square : \n";
         cout << "length = " << l << endl;
     }
    void describe() override{
         double area = l*l;
         double prm = 4*l;
         
            cout << "Area = " << area << endl;
            cout << "Perimeter = " << prm << endl;
    }
};
int main() {
    Shape *sh[3];
    
    Circle c(10);
    Rectangle r(5, 3);
    Square s(4);
    
    sh[0] = &c;
    sh[1] = &r;
    sh[2] = &s;
    
    for(int i=0; i<3; i++) {
        sh[i]->draw();
        sh[i]->describe();
        cout << endl;   
    }
    return 0;
}
