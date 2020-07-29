#include <iostream>
#include <string.h>
using namespace std;
class Teacher {
public:
    Teacher(string na, int a, string s, string ad, string ph, string tit) {name = na;age = a;sex = s;address = ad, phone = ph; title = tit;}
    void display();
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string title;
};
class Cadre {
public:
    Cadre(string na, int a, string s, string ad, string ph, string po) {name = na;age = a;sex = s;address = ad, phone = ph; post = po;}
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string post;
};
class Teacher_Cadre:public Teacher,public Cadre {
public:
    Teacher_Cadre(string na, int a, string s, string ad, string ph, string tit,string po, int w):Teacher(na,a,s,ad,ph,tit),Cadre(na,a,s,ad,ph,po),wages(w){}
    void show();
protected:
    int wages;
};
void Teacher::display() {
    cout<<"Teacher:"<<endl
        <<"name: "<<name<<endl
        <<"age: "<<age<<endl
        <<"sex: "<<sex<<endl
        <<"address: "<<address<<endl
        <<"phone: "<<phone<<endl
        <<"title: "<<title<<endl;
}
void Teacher_Cadre::show() {
    Teacher::display();
    cout<<"post: "<<Cadre::post<<endl
        <<"wages: "<<wages<<endl;
}
int main()
{
    Teacher_Cadre one("zhangsan", 20, "male", "JNU", "10010", "advanced","Math", 10000);
    one.show();
    return 0;
}
