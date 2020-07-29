#include <iostream>
#include <fstream>
#include <list>
#include <sstream>		//字符串转换

using namespace std;

//信息管理系统类
class Infosys
{
private:
    //学生全局结构
    struct Student
    {//虽然学生属性都是字符串类型，但是后面对数据进行处理时，
        //也会将部分字符串数据转换为数字类型进行操作
        string name;		//姓名
        string age;			//年龄
        string num;			//学号
        string college;     //学院
        string diploma;     //学历
        string lesson_name;     //课程名
        string score;       //成绩
    };
    list<Student> studlist;	//存储所有学生信息的容器
    string path;			//文件路径
    //将容器中所有信息写入到文件中
    void ofsallMess();
    //通过二元谓词改变list.stor()的排序规则
    class Studentrule_1_1
    {//按照学号升序排序
    public:
        bool operator()(Student& p1, Student& p2);
    };
    class Studentrule_1_2
    {//按照学号降序排序
    public:
        bool operator()(Student& p1, Student& p2);
    };
    class Studentrule_2_1
    {//按照成绩升序排序
    public:
        bool operator()(Student& p1, Student& p2);
    };
    class Studentrule_2_2
    {//按照成绩降序排序
    public:
        bool operator()(Student& p1, Student& p2);
    };

public:
    //构造函数用于将文件中的内容按格式读取到list<Student>中
    Infosys();
    int Systemdoor();
    //输出提示信息成员函数
    void Hint();
    //添加学生信息
    bool AddMess();
    //查看所有学生信息
    void PrintMess();
    //查找（姓名||学号）
    void FindMess();
    //指定排序规则
    //1，按照学号升序
    //排序
    void  SortMess();
    //向中间插入学生数据
    void InsertMess();
    //删除学生的数据
    void DeteleMess();
    //修改学生的信息
    void ModifyMess();
    //统计学生数据
    void StatMess();
};
