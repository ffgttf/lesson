/*#include <iostream>
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
class Teacher {
public:
    Teacher(){num = 0; name = "NULL"; sex = "NULL";}
    Teacher(Student &s){
        num = s.num;
        name = s.name;
        sex = s.sex;
    }
    void display(){
        cout<<"teacher:"<<endl;
        cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"sex:"<<sex<<endl;
    }
private:
    int num;
    string name;
    string sex;
};
int main()
{
    Student s(1, "zhangsan", "male");
    s.display();
    Teacher t(s);
    t.display();
    return 0;
}*/
#include <iostream>
#include <string.h>
using namespace std;
class Student {
private:
    int num;
    string name;
    string sex;
public:
    Student(){num = 0; name = "NULL"; sex = "NULL";}
    Student(int nu, string na, string s){num = nu; name = na; sex = s;}
    void setinfo() {
        cout<<"num:";
        cin>>num;
        cout<<"name:";
        cin>>name;
        cout<<"sex:";
        cin>>sex;

    }
    void display(){
        cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"sex:"<<sex<<endl;
    }
};
class Teacher:public Student {
public:
    void setinfo() {
        Student::setinfo();
        cout<<"salary:";
        cin>>salary;
        cout<<"age:";
        cin>>age;
        cout<<endl;
    }
    void display() {
        Student::display();
        cout<<"salary:"<<salary<<endl;
        cout<<"age:"<<age<<endl;
    }
private:
    double salary; //薪水
    double age; //年龄
};
int main()
{
    Teacher t;
    t.Teacher::setinfo();
    t.Teacher::display();
}