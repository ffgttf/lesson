#include <iostream>
using namespace std;
class student {
public:
    student(int n, float s) : num(n), score(s) {}

    int num;
    float score;
};
void max(student *pt, int n)
{
    student *p=pt, su(0, 0);
    float max;
    for (max=pt->score; p<pt+n; p++)
        if((p->score)>max) {
            max=p->score;
            su=*p;
        }
    cout<<"student num:"<<su.num<<" score:"<<su.score<<endl;
}
int main()
{
    student stu[5]{
            student(1001, 87),
            student(1002, 76),
            student(1003, 80.5),
            student(1004, 74),
            student(1005, 91)
    };
    max(stu,5);
    return 0;
}
