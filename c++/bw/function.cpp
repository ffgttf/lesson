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
        cout << "                �� �� ����";
        cin >> name;
        cout << "                ��    �룺";
        cin >> temp;
        if (name != username || temp != password)
        {
            number--;
            if (number >0)
            {
                cout << "          �û���/�������!�㻹��" << number << "�λ���" << endl;
            }
            else
                cout << "�û���/�������!" << endl, exit(0);

        }
        else
        {
            cout << "********************������ȷ********************" << endl<<endl;
            return 1;
        }
    }

}
void Infosys::ofsallMess()
{
	ofstream ofst;
	//�����Դ�ļ����ݷ�ʽ���ļ�
	ofst.open(path, ios::trunc);

	//�ж��ļ��Ƿ�򿪳ɹ�
	if (!ofst.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//�������е�������Ϣд�뵽�ļ���
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
		ofst << endl << it->num << endl << it->name << endl << it->age << endl << it->college << endl << it->diploma << endl << it->lesson_name << endl << it->score;

	//�ر��ļ�
	ofst.close();
}
void Infosys::Hint()
{
	cout << "--------ѧ����Ϣ����ϵͳ--------" << endl << endl;
	cout << "1 ���ѧ����Ϣ��β����ӣ�" << endl;
	cout << "2 �鿴����ѧ����Ϣ" << endl;
	cout << "3 ����ѧ����Ϣ��ѧ�š�������" << endl;
	cout << "4 ����ѧ����Ϣ��ѧ�š��ɼ������򡢽���" << endl;
	cout << "5 ����ѧ����Ϣ��������ѧ����Ϣǰ���룩" << endl;
	cout << "6 ɾ��ѧ�����ݣ�ѧ�š�������" << endl;
	cout << "7 �޸�ѧ�����ݣ�ѧ�ţ�" << endl;
	cout << "8 ���ͳ�����ݣ��ܺ͡�ƽ��ֵ�ȣ�" << endl;
	cout << "9 �˳�����" << endl << endl;
	cout << "���й�����ִ����Ϻ󣬶����Զ�����ǰ��Ϣ������ļ�" << endl << endl;
}
Infosys::Infosys()
{
	cout << "��������ļ�·�����Ӻ�׺����һ��Ϊtxt�ļ���û���򴴽����ļ�����" << endl;
	cin >> path;
    cin.ignore(100, '\n'); //��ֹ·��������ɵ��Զ�����

	ifstream ifstr;
	ifstr.open(path, ios::in);		//���ļ�·���е��ļ��������ʧ���򴴽����ļ�
	if (!ifstr.is_open())
	{
		ofstream temp(path);		//�����ļ�
		temp.open(path, ios::out);
		if (!temp.is_open())		//����Ƿ񴴽��ɹ�
		{
			cout << "�����ļ�ʧ�ܣ��˳�����" << endl;
			exit(-1);
		}
		//�ļ��ɹ�������ر��ļ�
		temp.close();
	}
	system("cls");

	//���ļ����������ݶ�ȡ��list������
	ifstream ifst;
	ifst.open(path, ios::in);

	char line[14];		//����������ַ�����
	Student temp;

	//�ն�ȡһ����Ϊ���ļ���һ�в���������
	ifst.getline(line, sizeof(line));

	//���ж�ȡ�ļ��е�����
	//ѭ����ȡ������Ϣ��ÿ���н���Ϣ���뵽������
	while (!ifst.eof())
	{
		//���浽��ʱѧ��temp��
		ifst.getline(line, sizeof(line));
		temp.num = line;		//ѧ��
		ifst.getline(line, sizeof(line));
		temp.name = line;		//����
		ifst.getline(line, sizeof(line));
		temp.age = line;		//����
        ifst.getline(line, sizeof(line));
        temp.college = line;		//ѧԺ
        ifst.getline(line, sizeof(line));
        temp.diploma = line;		//ѧ��
		ifst.getline(line, sizeof(line));
		temp.lesson_name = line;        //�γ�
		ifst.getline(line, sizeof(line));
		temp.score = line;      //�ɼ�

								//��temp���뵽ѧ��������
		studlist.push_back(temp);
	}
	sleep(1);
	Systemdoor();   // ��¼
	Hint();		//��ʾ��ʾ��Ϣ
}

bool Infosys::AddMess()
{
	//����һ��ѧ���ṹ
	Student student;

L1:
	//�����ʾ��Ϣ��������ѧ����Ϣ������-1��������
	cout << "ѧ�ţ�		"; cin >> student.num;
	if (student.num == "-1") return false;

	//����ѧ��ʱ���������е�ѧ��ѧ����Ϣ�����ѧ����ͬ�������ʾ����������
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == student.num)
		{
			cout << endl << "ѧ����Ϣ�ظ������������룺" << endl << endl;
			goto L1;	//���ص�����ĵط�
		}

	//����false��ֹͣ���ѧ����Ϣ
	cout << "������		"; cin >> student.name;
	if (student.name == "-1") return false;
	cout << "���䣺		"; cin >> student.age;
	if (student.age == "-1") return false;
    cout << "ѧԺ��		"; cin >> student.college;
    if (student.college == "-1") return false;
    cout << "ѧ����		"; cin >> student.diploma;
    if (student.diploma == "-1") return false;
	cout << "�γ̣�    	"; cin >> student.lesson_name;
	if (student.lesson_name == "-1") return false;
	cout << "�ɼ���    	"; cin >> student.score;
	if (student.score == "-1") return false;

	cout << endl;

	studlist.push_back(student);	//������ӵ�ѧ����Ϣβ�嵽������

									//ֻ������ӵ�ѧ����Ϣ׷�ӵ��ļ���
									//����д��������
	ofstream ofst;
	//���ļ�·������׷�ӷ�ʽ���ļ�
	ofst.open(path, ios::app);

	//��ѧ����Ϣ��˳��д�뵽�ļ���
	ofst << endl << student.num << endl << student.name << endl << student.age << endl << student.college << endl << student.diploma << endl << student.lesson_name << endl << student.score;

	//�ر��ļ�
	ofst.close();

	//����true����¼��ѧ����Ϣ
	return true;
}

void Infosys::PrintMess()
{
	cout << endl;
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
	{
		cout << "ѧ�ţ�		" << it->num << endl;
		cout << "������		" << it->name << endl;
		cout << "���䣺		" << it->age << endl;
        cout << "ѧԺ��		" << it->college << endl;
        cout << "ѧ����		" << it->diploma << endl;
		cout << "�γ̣�	    " << it->lesson_name << endl;
		cout << "�ɼ���    	" << it->score << endl << endl;
	}
}

void Infosys::FindMess()
{
	char key;
	cout << "����1����ѧ�Ų��ң�����������������" << endl;
	cin >> key;

	//��ѧ�Ų���
	if (key == '1')
	{
		string findnum;
		cout << "��������Ҫ���ҵ�ѧ����ţ�";
		cin >> findnum;

		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->num == findnum)
			{
				cout << "ѧ�ţ�		" << it->num << endl;
				cout << "������		" << it->name << endl;
				cout << "���䣺		" << it->age << endl;
                cout << "ѧԺ��		" << it->college << endl;
                cout << "ѧ����		" << it->diploma << endl;
                cout << "�γ̣�    	" << it->lesson_name << endl;
                cout << "�ɼ���    	" << it->score << endl << endl;
				return;		//��Ϊѧ�ž���Ψһ�ԣ������ҵ����������Ϣֱ�ӷ���
			}

		//����û�н���ִ�е�����˵��û���ҵ�ѧ�ţ������ʾ��Ϣ
		cout << "û���ҵ�ѧ��Ϊ�� " << findnum << " ����ѧ��" << endl;
	}
	//����������
	else
	{
		string findname;
		cout << "��������Ҫ���ҵ�ѧ��������";
		cin >> findname;
		bool sign = false;	//����Ƿ��ҵ�ѧ��

							//���������Ϊfindname��ѧ����Ϣ
		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->name == findname)
			{
				cout << "ѧ�ţ�		" << it->num << endl;
				cout << "������		" << it->name << endl;
				cout << "���䣺		" << it->age << endl;
                cout << "ѧԺ��		" << it->college << endl;
                cout << "ѧ����		" << it->diploma << endl;
                cout << "�γ̣�	    " << it->lesson_name << endl;
                cout << "�ɼ���	    " << it->score << endl << endl;
				sign = true;
			}

		//���û���ҵ��������ʾ��Ϣ
		if (!sign)
			cout << "û���ҵ���Ϊ��" << findname << "����ѧ��" << endl;
	}
}

bool Infosys::Studentrule_1_1::operator()(Student& p1, Student& p2)
{
	//�������ַ�ת��Ϊ���֣�Ȼ�������������
	int temp_1;  stringstream ss_1; ss_1 << p1.num; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.num; ss_2 >> temp_2;
	return temp_1 < temp_2;
}

bool Infosys::Studentrule_1_2::operator()(Student& p1, Student& p2)
{
	//�������ַ�ת��Ϊ���֣�Ȼ�������������
	int temp_1;  stringstream ss_1; ss_1 << p1.num; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.num; ss_2 >> temp_2;
	return temp_1 > temp_2;
}

bool Infosys::Studentrule_2_1::operator()(Student& p1, Student& p2)
{
	//�������ַ�ת��Ϊ���֣�Ȼ�������������
	int temp_1;  stringstream ss_1; ss_1 << p1.score; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.score; ss_2 >> temp_2;
	return temp_1 < temp_2;
}
bool Infosys::Studentrule_2_2::operator()(Student& p1, Student& p2)
{
	//�������ַ�ת��Ϊ���֣�Ȼ�������������
	int temp_1;  stringstream ss_1; ss_1 << p1.score; ss_1 >> temp_1;
	int temp_2; stringstream ss_2; ss_2 << p2.score; ss_2 >> temp_2;
	return temp_1 < temp_2;
}

void  Infosys::SortMess()
{
    string lesson;
	char key_1 = '0';
	cout << "����1����ѧ����������2�����ɼ�����" << endl;
	cin >> key_1;		//���ռ�ִֵ�в�ͬ���������
	cout << "����1��������������������������" << endl;
	char key_2 = '0';
	cin >> key_2;
	switch (key_1)
	{
	case '1':
	    key_2 == '1' ? studlist.sort(Studentrule_1_1()) : studlist.sort(Studentrule_1_2()); break;
	case '2':
	    cout << "ѧ��:        "; cin >> lesson;
	    key_2 == '1' ? studlist.sort(Studentrule_2_1()) : studlist.sort(Studentrule_2_2()); break;
	}

	//������������д���ļ���
	ofsallMess();

	cout << "������" << endl;
}

void Infosys::InsertMess()
{
	string instudnum = "0";
	bool sign = false;
L1:
	cout << "��������Ҫ������ѧ��ǰ��ĸ�ѧ����ѧ�ţ�" << endl;
	cin >> instudnum;
	list<Student>::const_iterator it;
	for (it = studlist.begin(); it != studlist.end(); it++)
		if (instudnum == it->num) break;

	//���it==����ĩβ�������ˣ���˵��û���ҵ���ѧ��
	if (it == studlist.end())
	{
		cout << "û���ҵ���ѧ��" << endl;
		goto L1;
	}

	//����һ��ѧ����㣬���ý����Ϣ�����뵽������
	Student student;

L2:
	//�����ʾ��Ϣ��������ѧ����Ϣ
	cout << "ѧ�ţ�		"; cin >> student.num;

	//����ѧ��ʱ���������е�ѧ��ѧ����Ϣ�����ѧ����ͬ�������ʾ����������
	for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == student.num)
		{
			cout << "ѧ����Ϣ�ظ������������룺" << endl;
			goto L2;	//���ص�����ĵط�
		}

	//�������ѧ������Ϣ
	cout << "������		"; cin >> student.name;
	cout << "���䣺		"; cin >> student.age;
    cout << "ѧԺ��		"; cin >> student.college;
    cout << "ѧ����		"; cin >> student.diploma;
    cout << "�γ̣�    	"; cin >> student.lesson_name;
    cout << "�ɼ���	    "; cin >> student.score;

	//���ý����뵽������
	studlist.insert(it, student);

	//������������д���ļ���
	ofsallMess();
	cout << "�Ѳ���" << endl;
}
void Infosys::DeteleMess()
{
	char key = '0';
	cout << "����1����ѧ��ɾ������ѧ�����ݣ�������������ɾ������ѧ������" << endl;
	cin >> key;

	if (key == '1')
	{
		//�������в��Һ���Ҫɾ����ѧ����ѧ��һ����ѧ�ţ��ҵ���ɾ������ˢ���ļ�����
		string detestunum;
		cout << "��������Ҫɾ����ѧ����ѧ�ţ�" << endl;
		cin >> detestunum;
		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->num == detestunum)
			{
				studlist.erase(it);
				ofsallMess();
				cout << "��ɾ��" << endl;
				return;
			}
		cout << "û���ҵ���ѧ�ŵ�ѧ��" << endl;
	}
	else
	{
		string detestuname;
		cout << "��������Ҫɾ����ѧ����������" << endl;
		cin >> detestuname;
		bool sign = false;

		//��������Ѱ������Ҫɾ��������ѧ����ͬ����ѧ�����ҵ�����ɾ��
		for (list<Student>::const_iterator it = studlist.begin(); it != studlist.end(); it++)
			if (it->name == detestuname)
			{
				//�����е����⣬�����������޷������ֻ�����ñ��취�����
				it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				if (it->name == detestuname) it = studlist.erase(it);
				ofsallMess();	//ˢ���ļ�
				sign = true;
			}
		//�����ʾ��Ϣ
		if (sign == false)
			cout << "û���ҵ���������ѧ��" << endl;
		else
			cout << "��ɾ��" << endl;
	}
}

void Infosys::ModifyMess()
{
	string Modstudentnum;
L1:
	cout << "��������Ҫ�޸ĵ�ѧ����ѧ�ţ�" << endl;
	cin >> Modstudentnum;

	//����ѧ�ź��ȱ���һ�������鿴�Ƿ��и�ѧ�ţ����û������������
	list<Student>::const_iterator it;
	for (it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == Modstudentnum) break;
	if (it == studlist.end())
	{
		cout << "û���ҵ���ѧ��";
		goto L1;
	}

	//�޸ĵ�����ָ�����ֵ
	for (list<Student>::iterator it = studlist.begin(); it != studlist.end(); it++)
		if (it->num == Modstudentnum)
		{
			//�����ԭ��Ϣ
			cout << endl << "��ѧ��ԭ��Ϣ��" << endl << endl;
			cout << "ѧ�ţ�		" << it->num << endl;
			cout << "������		" << it->name << endl;
			cout << "���䣺		" << it->age << endl;
            cout << "ѧԺ��		" << it->college << endl;
            cout << "ѧ����		" << it->diploma << endl;
            cout << "�γ̣�    	" << it->lesson_name << endl;
            cout << "�ɼ���    	" << it->score << endl << endl;
			//���޸�
			cout << "��Ҫ�޸���Ϣ��" << endl << endl;
			cout << "ѧ�ţ�		"; cin >> it->num;
			cout << "������		"; cin >> it->name;
			cout << "���䣺		"; cin >> it->age;
            cout << "ѧԺ��		"; cin >> it->college;
            cout << "ѧ����		"; cin >> it->diploma;
            cout << "�γ̣�    	"; cin >> it->lesson_name;
            cout << "�ɼ���	    "; cin >> it->score;
			break;
		}

	//ˢ���ļ��е���Ϣ
	ofsallMess();
	cout << endl << "���޸�" << endl;
}
void Infosys::StatMess()
{
	//���ܣ�����ѧ�����ܸ���
	//����ѧ�����ɼ����ܷ֡�ƽ����
	//����͡�ƽ������

	int scoresum = 0; 	//�ɼ���
	int scoreave = 0; 	//�ɼ�ƽ��ֵ
	int agesum = 0, ageave = 0, num = 0;	//����͡�����ƽ��ֵ��ѧ����
	for (list<Student>::iterator it = studlist.begin(); it != studlist.end(); it++)
	{
		//��C++�ɼ�ת��Ϊ����
		int stemp;
		stringstream ss_1;
		ss_1 << it->score;
		ss_1 >> stemp;

		scoresum += stemp;		//ͳ�Ƴɼ�

		int Agetemp;
		stringstream ss_3;
		ss_3 << it->age;
		ss_3 >> Agetemp;

		agesum += Agetemp;			//ͳ������

		num++;
	}

	//ƽ���ɼ�
	scoreave = scoresum / num;

	//ƽ������
	ageave = agesum / num;

	cout << "��ѧ������" << num << endl << endl;
	cout << "ƽ���ɼ���" << scoreave << "  �ܳɼ���" << scoresum << endl << endl;
	cout << "ƽ�����䣺" << ageave << endl << endl;
}