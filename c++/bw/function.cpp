#include <iostream>	
#include <list>
#include <unistd.h>
#include "SInfo.h"
using namespace std;

int Infosys::Systemdoor()
{
    string username = "teacher", password = "root";
    string name, temp;
    int number = 3;
    while (1)
    {
        cout << "                用 户 名：";
        cin >> name;
        cout << "                密    码：";
        cin >> temp;
        if (name != username || temp != password)
        {
            number--;
            if (number >0)
            {
                cout << "          用户名/密码错误!你还有" << number << "次机会" << endl;
            }
            else
                cout << "用户名/密码错误!" << endl, exit(0);

        }
        else
        {
            cout << "********************密码正确********************" << endl<<endl;
            return 1;
        }
    }

}
void Infosys::ofsallMess()
{
	ofstream ofst;
	//以清空源文件内容方式打开文件
	ofst.open(path, ios::trunc);

	//判断文件是否打开成功
	if (!ofst.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//将容器中的所有信息写入到文件中
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
		ofst << endl << it->num << endl << it->name << endl << it->age << endl << it->college << endl << it->diploma << endl << it->lesson_name << endl << it->score;

	//关闭文件
	ofst.close();
}
void Infosys::Hint()
{
	cout << "--------学生信息管理系统--------" << endl << endl;
	cout << "1 添加学生信息（尾部添加）" << endl;
	cout << "2 查看所有学生信息" << endl;
	cout << "3 查找学生信息（学号、姓名）" << endl;
	cout << "4 排序学生信息（学号、成绩、升序、降序）" << endl;
	cout << "5 插入学生信息（在输入学号信息前插入）" << endl;
	cout << "6 删除学生数据（学号、姓名）" << endl;
	cout << "7 修改学生数据（学号）" << endl;
	cout << "8 输出统计数据（总和、平均值等）" << endl;
	cout << "9 退出程序" << endl << endl;
	cout << "所有功能在执行完毕后，都会自动将当前信息保存进文件" << endl << endl;
}
Infosys::Infosys()
{
	cout << "输入你的文件路径，加后缀名，一般为txt文件（没有则创建该文件）：" << endl;
	cin >> path;
    cin.ignore(100, '\n'); //防止路径过长造成的自动换行

	ifstream ifstr;
	ifstr.open(path, ios::in);		//打开文件路径中的文件，如果打开失败则创建该文件
	if (!ifstr.is_open())
	{
		ofstream temp(path);		//创建文件
		temp.open(path, ios::out);
		if (!temp.is_open())		//检测是否创建成功
		{
			cout << "创建文件失败，退出程序" << endl;
			exit(-1);
		}
		//文件成功创建则关闭文件
		temp.close();
	}
	system("cls");

	//将文件中所有内容读取到list容器中
	ifstream ifst;
	ifst.open(path, ios::in);

	char line[14];		//这里必须是字符数组
	Student temp;

	//空读取一行因为新文件第一行不保存内容
	ifst.getline(line, sizeof(line));

	//成行读取文件中的内容
	//循环读取五行信息，每五行将信息插入到容器中
	while (!ifst.eof())
	{
		//保存到临时学生temp中
		ifst.getline(line, sizeof(line));
		temp.num = line;		//学号
		ifst.getline(line, sizeof(line));
		temp.name = line;		//姓名
		ifst.getline(line, sizeof(line));
		temp.age = line;		//年龄
        ifst.getline(line, sizeof(line));
        temp.college = line;		//学院
        ifst.getline(line, sizeof(line));
        temp.diploma = line;		//学历
		ifst.getline(line, sizeof(line));
		temp.lesson_name = line;        //课程
		ifst.getline(line, sizeof(line));
		temp.score = line;      //成绩

								//将temp插入到学生容器中
		studlist.push_back(temp);
	}
	sleep(1);
	Systemdoor();   // 登录
	Hint();		//显示提示信息
}

bool Infosys::AddMess()
{
	//创建一个学生结构
	Student student;

L1:
	//输出提示信息，并输入学生信息，输入-1结束输入
	cout << "学号：		"; cin >> student.num;
	if (student.num == "-1") return false;

	//读入学号时，遍历所有的学生学号信息，如果学号相同则输出提示并重新输入
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == student.num)
		{
			cout << endl << "学号信息重复，请重新输入：" << endl << endl;
			goto L1;	//返回到输入的地方
		}

	//返回false则停止添加学生信息
	cout << "姓名：		"; cin >> student.name;
	if (student.name == "-1") return false;
	cout << "年龄：		"; cin >> student.age;
	if (student.age == "-1") return false;
    cout << "学院：		"; cin >> student.college;
    if (student.college == "-1") return false;
    cout << "学历：		"; cin >> student.diploma;
    if (student.diploma == "-1") return false;
	cout << "课程：    	"; cin >> student.lesson_name;
	if (student.lesson_name == "-1") return false;
	cout << "成绩：    	"; cin >> student.score;
	if (student.score == "-1") return false;

	cout << endl;

	studlist.push_back(student);	//将新添加的学生信息尾插到容器中

									//只将新添加的学生信息追加到文件中
									//创建写入流对象
	ofstream ofst;
	//在文件路径中以追加方式打开文件
	ofst.open(path, ios::app);

	//将学生信息按顺序写入到文件中
	ofst << endl << student.num << endl << student.name << endl << student.age << endl << student.college << endl << student.diploma << endl << student.lesson_name << endl << student.score;

	//关闭文件
	ofst.close();

	//返回true继续录入学生信息
	return true;
}

void Infosys::PrintMess()
{
	cout << endl;
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
	{
		cout << "学号：		" << it->num << endl;
		cout << "姓名：		" << it->name << endl;
		cout << "年龄：		" << it->age << endl;
        cout << "学院：		" << it->college << endl;
        cout << "学历：		" << it->diploma << endl;
		cout << "课程：	    " << it->lesson_name << endl;
		cout << "成绩：    	" << it->score << endl << endl;
	}
}

void Infosys::FindMess()
{
	char key;
	cout << "输入1代表按学号查找，其他代表按姓名查找" << endl;
	cin >> key;

	//按学号查找
	if (key == '1')
	{
		string findnum;
		cout << "请输入需要查找的学生序号：";
		cin >> findnum;

		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->num == findnum)
			{
				cout << "学号：		" << it->num << endl;
				cout << "姓名：		" << it->name << endl;
				cout << "年龄：		" << it->age << endl;
                cout << "学院：		" << it->college << endl;
                cout << "学历：		" << it->diploma << endl;
                cout << "课程：    	" << it->lesson_name << endl;
                cout << "成绩：    	" << it->score << endl << endl;
				return;		//因为学号具有唯一性，所以找到后输出完信息直接返回
			}

		//函数没有结束执行到这里说明没有找到学号，输出提示信息
		cout << "没有找到学号为“ " << findnum << " ”的学生" << endl;
	}
	//按姓名查找
	else
	{
		string findname;
		cout << "请输入需要查找的学生姓名：";
		cin >> findname;
		bool sign = false;	//标记是否找到学生

							//输出所有名为findname的学生信息
		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->name == findname)
			{
				cout << "学号：		" << it->num << endl;
				cout << "姓名：		" << it->name << endl;
				cout << "年龄：		" << it->age << endl;
                cout << "学院：		" << it->college << endl;
                cout << "学历：		" << it->diploma << endl;
                cout << "课程：	    " << it->lesson_name << endl;
                cout << "成绩：	    " << it->score << endl << endl;
				sign = true;
			}

		//如果没有找到则输出提示信息
		if (!sign)
			cout << "没有找到名为“" << findname << "”的学生" << endl;
	}
}

bool Infosys::Studentrule_1_1::operator()(Student& p1, Student& p2)
{
	//将属性字符转换为数字，然后根据数字排序
	int temp_1;  stringstream ss_1; ss_1 << p1.num; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.num; ss_2 >> temp_2;
	return temp_1 < temp_2;
}

bool Infosys::Studentrule_1_2::operator()(Student& p1, Student& p2)
{
	//将属性字符转换为数字，然后根据数字排序
	int temp_1;  stringstream ss_1; ss_1 << p1.num; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.num; ss_2 >> temp_2;
	return temp_1 > temp_2;
}

bool Infosys::Studentrule_2_1::operator()(Student& p1, Student& p2)
{
	//将属性字符转换为数字，然后根据数字排序
	int temp_1;  stringstream ss_1; ss_1 << p1.score; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.score; ss_2 >> temp_2;
	return temp_1 < temp_2;
}
bool Infosys::Studentrule_2_2::operator()(Student& p1, Student& p2)
{
	//将属性字符转换为数字，然后根据数字排序
	int temp_1;  stringstream ss_1; ss_1 << p1.score; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.score; ss_2 >> temp_2;
	return temp_1 < temp_2;
}

void  Infosys::SortMess()
{
    string lesson;
	char key_1 = '0';
	cout << "输入1代表按学号排序，输入2代表按成绩排序" << endl;
	cin >> key_1;		//接收键值执行不同的排序规则
	cout << "输入1代表升序排序，其他代表降序排序" << endl;
	char key_2 = '0';
	cin >> key_2;
	switch (key_1)
	{
	case '1':
	    key_2 == '1' ? studlist.sort(Studentrule_1_1()) : studlist.sort(Studentrule_1_2()); break;
	case '2':
	    cout << "学科:        "; cin >> lesson;
	    key_2 == '1' ? studlist.sort(Studentrule_2_1()) : studlist.sort(Studentrule_2_2()); break;
	}

	//将容器中内容写入文件中
	ofsallMess();

	cout << "已排序" << endl;
}

void Infosys::InsertMess()
{
	string instudnum = "0";
	bool sign = false;
L1:
	cout << "请输入需要插入在学生前面的该学生的学号：" << endl;
	cin >> instudnum;
	list<Student>::const_iterator it;
	for (it = studlist.begin(); it != studlist.end(); it++)
		if (instudnum == it->num) break;

	//如果it==容器末尾迭代器了，则说明没有找到该学号
	if (it == studlist.end())
	{
		cout << "没有找到该学号" << endl;
		goto L1;
	}

	//创建一个学生结点，将该结点信息，插入到容器中
	Student student;

L2:
	//输出提示信息，并输入学生信息
	cout << "学号：		"; cin >> student.num;

	//读入学号时，遍历所有的学生学号信息，如果学号相同则输出提示并重新输入
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == student.num)
		{
			cout << "学号信息重复，请重新输入：" << endl;
			goto L2;	//返回到输入的地方
		}

	//输入这个学生的信息
	cout << "姓名：		"; cin >> student.name;
	cout << "年龄：		"; cin >> student.age;
    cout << "学院：		"; cin >> student.college;
    cout << "学历：		"; cin >> student.diploma;
    cout << "课程：    	"; cin >> student.lesson_name;
    cout << "成绩：	    "; cin >> student.score;

	//将该结点插入到容器中
	studlist.insert(it, student);

	//将容器中内容写入文件中
	ofsallMess();
	cout << "已插入" << endl;
}
void Infosys::DeteleMess()
{
	char key = '0';
	cout << "输入1代表按学号删除单个学生数据，其他代表按姓名删除所有学生数据" << endl;
	cin >> key;

	if (key == '1')
	{
		//从容器中查找和需要删除和学生的学号一样的学号，找到则删除，并刷新文件内容
		string detestunum;
		cout << "请输入需要删除的学生的学号：" << endl;
		cin >> detestunum;
		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->num == detestunum)
			{
				studlist.erase(it);
				ofsallMess();
				cout << "已删除" << endl;
				return;
			}
		cout << "没有找到该学号的学生" << endl;
	}
	else
	{
		string detestuname;
		cout << "请输入需要删除的学生的姓名：" << endl;
		cin >> detestuname;
		bool sign = false;

		//遍历容器寻找与需要删除姓名的学生相同名的学生，找到了则删除
		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->name == detestuname)
			{
				//这里有点问题，连续的重名无法清除，只能先用笨办法解决了
				it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				ofsallMess();	//刷新文件
				sign = true;
			}
		//输出提示信息
		if (sign == false)
			cout << "没有找到该姓名的学生" << endl;
		else
			cout << "已删除" << endl;
	}
}

void Infosys::ModifyMess()
{
	string Modstudentnum;
L1:
	cout << "请输入需要修改的学生的学号：" << endl;
	cin >> Modstudentnum;

	//接收学号后，先遍历一遍容器查看是否有该学号，如果没有则重新输入
	list<Student>::const_iterator it;
	for (it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == Modstudentnum) break;
	if (it == studlist.end())
	{
		cout << "没有找到该学号";
		goto L1;
	}

	//修改迭代器指向结点的值
	for (list<Student>::iterator it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == Modstudentnum)
		{
			//先输出原信息
			cout << endl << "该学生原信息：" << endl << endl;
			cout << "学号：		" << it->num << endl;
			cout << "姓名：		" << it->name << endl;
			cout << "年龄：		" << it->age << endl;
            cout << "学院：		" << it->college << endl;
            cout << "学历：		" << it->diploma << endl;
            cout << "课程：    	" << it->lesson_name << endl;
            cout << "成绩：    	" << it->score << endl << endl;
			//再修改
			cout << "需要修改信息：" << endl << endl;
			cout << "学号：		"; cin >> it->num;
			cout << "姓名：		"; cin >> it->name;
			cout << "年龄：		"; cin >> it->age;
            cout << "学院：		"; cin >> it->college;
            cout << "学历：		"; cin >> it->diploma;
            cout << "课程：    	"; cin >> it->lesson_name;
            cout << "成绩：	    "; cin >> it->score;
			break;
		}

	//刷新文件中的信息
	ofsallMess();
	cout << endl << "已修改" << endl;
}
void Infosys::StatMess()
{
	//功能：返回学生的总个数
	//所有学生各成绩的总分、平均分
	//年龄和、平均年龄

	int scoresum = 0; 	//成绩和
	int scoreave = 0; 	//成绩平均值
	int agesum = 0, ageave = 0, num = 0;	//年龄和、年龄平均值、学生数
	for (list<Student>::iterator it = studlist.begin(); it != studlist.end(); it++)
	{
		//将C++成绩转换为数字
		int stemp;
		stringstream ss_1;
		ss_1 << it->score;
		ss_1 >> stemp;

		scoresum += stemp;		//统计成绩

		int Agetemp;
		stringstream ss_3;
		ss_3 << it->age;
		ss_3 >> Agetemp;

		agesum += Agetemp;			//统计年龄

		num++;
	}

	//平均成绩
	scoreave = scoresum / num;

	//平均年龄
	ageave = agesum / num;

	cout << "总学生数：" << num << endl << endl;
	cout << "平均成绩：" << scoreave << "  总成绩：" << scoresum << endl << endl;
	cout << "平均年龄：" << ageave << endl << endl;
}