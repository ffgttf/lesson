#include <iostream>
#include <unistd.h>
#include "SInfo.h"
using namespace std;

int main()
{
    //���ÿ���̨����
    system("title C++ ѧ����Ϣ����ϵͳ");
    cout <<"   ******************************************" << endl;
    cout <<"   ******************************************" << endl;
    cout <<"   ******                              ******" << endl;
    cout <<"   ******   ���ϴ�ѧѧ����Ϣ����ϵͳ   ******" << endl;
    cout <<"   ******                              ******" << endl;
    cout <<"   ******************************************" << endl;
    cout <<"   ******************************************" << endl;
    //��������ϵͳ����
    Infosys mamasys;
    sleep(1);
    //key����һ��ֵ������key��ִֵ�в�ͬ�Ĺ���
    char key = '0';
    cout << endl << "��������Ҫִ�еĹ��ܣ�" << endl;
    cin >> key;
    cout << endl;

    while (key !=0)
    {
        switch (key)
        {
            case '1':		//���ѧ����Ϣ
                cout << "�Զ�ѭ��������ݣ��������������-1" << endl << endl;
                while (mamasys.AddMess());
                cout << endl << "�����" << endl << endl;
                break;
            case '2':		//���������Ϣ
                mamasys.PrintMess();
                break;
            case '3':		//���� ����||ѧ��
                mamasys.FindMess();
                break;
            case '4':		//���� ѧ�š��ɼ������򡢽���
                mamasys.SortMess();
                break;
            case '5':		//���м����ѧ������
                mamasys.InsertMess();
                break;
            case '6':		//ɾ��ѧ��������
                mamasys.DeteleMess();
                break;
            case '7':		//�޸�ѧ��������
                mamasys.ModifyMess();
                break;
            case '8':		//�޸�ѧ��������
                mamasys.StatMess();
                break;
            case '9':		//�˳�����
                return 0;
        }

        system("pause");

        system("cls");			//ÿ�ι���ִ���꣬�����������ʾ��Ϣ
        sleep(1);
        mamasys.Hint();

        //����ִ����ϣ�key�ٽ���һ��ֵ
        cout << endl << "��������Ҫִ�еĹ��ܣ�" << endl;
        cin >> key;
        cout << endl;
    }
    return 0;
}