#include <iostream>
#include <fstream>
#include <list>
#include <sstream>		//�ַ���ת��

using namespace std;

//��Ϣ����ϵͳ��
class Infosys
{
private:
    //ѧ��ȫ�ֽṹ
    struct Student
    {//��Ȼѧ�����Զ����ַ������ͣ����Ǻ�������ݽ��д���ʱ��
        //Ҳ�Ὣ�����ַ�������ת��Ϊ�������ͽ��в���
        string name;		//����
        string age;			//����
        string num;			//ѧ��
        string college;     //ѧԺ
        string diploma;     //ѧ��
        string lesson_name;     //�γ���
        string score;       //�ɼ�
    };
    list<Student> studlist;	//�洢����ѧ����Ϣ������
    string path;			//�ļ�·��
    //��������������Ϣд�뵽�ļ���
    void ofsallMess();
    //ͨ����Ԫν�ʸı�list.stor()���������
    class Studentrule_1_1
    {//����ѧ����������
    public:
        bool operator()(Student& p1, Student& p2);
    };
    class Studentrule_1_2
    {//����ѧ�Ž�������
    public:
        bool operator()(Student& p1, Student& p2);
    };
    class Studentrule_2_1
    {//���ճɼ���������
    public:
        bool operator()(Student& p1, Student& p2);
    };
    class Studentrule_2_2
    {//���ճɼ���������
    public:
        bool operator()(Student& p1, Student& p2);
    };

public:
    //���캯�����ڽ��ļ��е����ݰ���ʽ��ȡ��list<Student>��
    Infosys();
    int Systemdoor();
    //�����ʾ��Ϣ��Ա����
    void Hint();
    //���ѧ����Ϣ
    bool AddMess();
    //�鿴����ѧ����Ϣ
    void PrintMess();
    //���ң�����||ѧ�ţ�
    void FindMess();
    //ָ���������
    //1������ѧ������
    //����
    void  SortMess();
    //���м����ѧ������
    void InsertMess();
    //ɾ��ѧ��������
    void DeteleMess();
    //�޸�ѧ������Ϣ
    void ModifyMess();
    //ͳ��ѧ������
    void StatMess();
};
