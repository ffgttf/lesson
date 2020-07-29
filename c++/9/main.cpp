#include <iostream>
using namespace std;
#define pi 3.1415926
class Shape {
public:
    virtual double area()= 0;
    virtual void display() = 0;
};
class Circle:public Shape{
public:
    Circle(int a):radius(a){}
    double area(){
        return (2 * pi * radius * radius);
    }
    void display() {
        cout<<"Circle area: "<<area()<<endl;
    }
private:
    int radius;
};
class Square:public Shape {
public:
    Square(int b):sidelength(b){}
    double area() {
        return (sidelength * sidelength);
    }
    virtual void display() {
        cout<<"Square area: "<<area()<<endl;
    }
private:
    int sidelength;
};
class Rectangle:public Shape {
public:
    Rectangle(int c, int d):length(c),width(d){}
    double area() {
        return(length * width);
    }
    virtual void display() {
        cout<<"Rectangle area: "<<area()<<endl;
    }
private:
    int length;
    int width;
};
class Trapezoid:public Shape {
public:
    Trapezoid(int e, int f, int g):upperline(e),lowline(f),height1(g){}
    double area() {
        return ((upperline + lowline) * height1 * 0.5);
    }
    virtual void display() {
        cout<<"Trapezoid area: "<<area()<<endl;
    }
private:
    int upperline;
    int lowline;
    int height1;
};
class Triangle:public Shape {
public:
    Triangle(int h, int i):height2(h),baseside(i){}
    double area() {
        return (baseside * height2 * 0.5);
    }
    virtual void display() {
        cout<<"Triangle area: "<<area()<<endl;
    }
private:
    int height2;
    int baseside;
};
void fun(Shape *ptr) {
    ptr -> display();
}
int main()
{
    double n;
    Shape *p;
    Circle c1(2);
    Square s1(3);
    Rectangle r1( 4, 5);
    Trapezoid t1(6,7, 8);
    Triangle t2(9, 10);
    p=&c1;
    fun(p);
    n=p->area();
    p=&s1;
    fun(p);
    n=n+p->area();
    p=&r1;
    fun(p);
    n=n+p->area();
    p=&t1;
    fun(p);
    n=n+p->area();
    p=&t2;
    fun(p);
    n=n+p->area();
    cout<<"sum area: "<<n<<endl;
    return 0;
}

