#include <iostream>
using namespace std;
class Complex {
public:
    Complex(){real=0;imag=0;}
    Complex(double r,double i){real=r;imag=i;};
    friend Complex operator+ (Complex &c1, Complex &c2);
    friend Complex operator+ (int &i, Complex &c1);
    friend Complex operator+ (Complex &c1, int &i);
    void display();
private:
    double real;
    double imag;
};
Complex operator+ (Complex &c1,Complex &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator+ (int &i, Complex &c1)
{
    return Complex(c1.real + i, c1.imag);
}
Complex operator+ (Complex &c1,int &i)
{
    return Complex(c1.real + i, c1.imag);
}
void Complex::display()
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}
int main() {
    Complex c1(3,4),c2(5,-10), c3, c4, c5;
    int i = 10;
    c3=c1+c2;
    c4=i+c1;
    c5=c1+i;
    cout<<"c1:";c1.display();
    cout<<"c2:";c2.display();
    cout<<"c1+c2=";c3.display();
    cout<<i<<"+c1=";c4.display();
    cout<<"c1+"<<i<<"=";c5.display();
    return 0;

}
