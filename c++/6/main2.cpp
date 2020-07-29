#include <iostream>
#include <string.h>
using namespace std;
class Student {
public:
    Student(){num = 0; name = "NULL"; sex = "NULL";}
    Student(int nu, string na, string s){num = nu; name = na; sex = s;}
    void display(){
        cout<<"student:"<<endl;
        cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"sex:"<<sex<<endl;
    }
    int num;
    string name;
    string sex;
};
class Teacher:public Student {
public:
    void display_1() {
        display();
        cout << "teacher:" << endl;
        cout << "num:" << num << endl;
        cout << "name:" << name << endl;
        cout << "sex:" << sex << endl;
    }
};
int main()
{
    Student s(2, "lisi", "female");
    s.display();
    return 0;
}