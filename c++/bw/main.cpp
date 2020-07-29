#include <iostream>
#include <unistd.h>
#include "SInfo.h"
using namespace std;

int main()
{
    //设置控制台标题
    system("title C++ 学生信息管理系统");
    cout <<"   ******************************************" << endl;
    cout <<"   ******************************************" << endl;
    cout <<"   ******                              ******" << endl;
    cout <<"   ******   江南大学学生信息管理系统   ******" << endl;
    cout <<"   ******                              ******" << endl;
    cout <<"   ******************************************" << endl;
    cout <<"   ******************************************" << endl;
    //创建管理系统对象
    Infosys mamasys;
    sleep(1);
    //key接收一个值，根据key的值执行不同的功能
    char key = '0';
    cout << endl << "请输入需要执行的功能：" << endl;
    cin >> key;
    cout << endl;

    while (key !=0)
    {
        switch (key)
        {
            case '1':		//添加学生信息
                cout << "自动循环添加数据，结束添加请输入-1" << endl << endl;
                while (mamasys.AddMess());
                cout << endl << "已添加" << endl << endl;
                break;
            case '2':		//输出所有信息
                mamasys.PrintMess();
                break;
            case '3':		//查找 姓名||学号
                mamasys.FindMess();
                break;
            case '4':		//排序 学号、成绩、升序、降序
                mamasys.SortMess();
                break;
            case '5':		//在中间插入学生数据
                mamasys.InsertMess();
                break;
            case '6':		//删除学生的数据
                mamasys.DeteleMess();
                break;
            case '7':		//修改学生的数据
                mamasys.ModifyMess();
                break;
            case '8':		//修改学生的数据
                mamasys.StatMess();
                break;
            case '9':		//退出程序
                return 0;
        }

        system("pause");

        system("cls");			//每次功能执行完，清屏，输出提示信息
        sleep(1);
        mamasys.Hint();

        //功能执行完毕，key再接收一个值
        cout << endl << "请输入需要执行的功能：" << endl;
        cin >> key;
        cout << endl;
    }
    return 0;
}