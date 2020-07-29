#include <iostream>
#include <fstream>
using namespace std;

struct staff {
    int num;
    char name[20];
    int age;
    int wage;
};

int main()
{
    staff p[7] = {
            1001,"zhang",20,5000,
            2013,"wang",24,7000,
            4800,"li",29,9000,
            720,"zhao",53,7900,
            987,"zhou",33,4800
    },p1;
    fstream iofile;
    iofile.open("C:/Users/xixin/Desktop/c&c++/c++/10/staff.dat",ios::in|ios::out|ios::binary);
    if(!iofile)
    {
        cerr<<"open error!"<<endl;
        abort();
    }
    int i,m,num;
    cout<<"The five staffs: "<<endl;
    for(i=0;i<5;i++) {
        cout<<p[i].num<<" "<<p[i].name<<" "<<p[i].age<<" "<<p[i].wage<<endl;
        iofile.write((char *)&p[i],sizeof(p[i]));
    }
    cout<<"Insert your data: "<<endl;
    for(i=0;i<2;i++) {
        cin>>p1.num>>p1.name>>p1.age>>p1.wage;
        iofile.seekp(0,ios::end);
        iofile.write((char *)&p1,sizeof(p1));
    }
    cout<<"The seven staffs: "<<endl;
    iofile.seekg(0,ios::beg);
    for(i=0;i<7;i++) {
        iofile.read((char *)&p[i],sizeof(p[i]));
        cout<<p[i].num<<" "<<p[i].name<<" "<<p[i].age<<" "<<p[i].wage<<endl;
    }
    bool find;
    cout<<"enter number you want search,enter 0 to stop.";
    cin>>num;
    while(num)
    {find=false;
        iofile.seekg(0,ios::beg);
        for(i=0;i<7;i++)
        {iofile.read((char *)&p[i],sizeof(p[i]));
            if(num==p[i].num)
            {m=iofile.tellg();
                cout<<num<<" is No."<<m/sizeof(p1)<<endl;
                cout<<p[i].num<<" "<<p[i].name<<" "<<p[i].age<<" "<<p[i].wage<<endl;
                find=true;
                break;
            }
        }
        if(!find)
            cout<<"can't find "<<num<<endl;
        cout<<"enter number you want search,enter 0 to stop.";
        cin>>num;
    }
    iofile.close();
    return 0;
}