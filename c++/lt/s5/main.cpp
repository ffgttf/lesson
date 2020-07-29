#include<iostream>
#include"Account.h"
using namespace std;

int main()
{
    Date date(2008,11,1);
    //建立几个账户
    SavingsAccount accounts[]{
            SavingsAccount (date, "S3755217", 0.015),
            SavingsAccount (date, "02342342", 0.015)
    };
    CreditAccount ca(date, "C5392394", 10000, 0.0005, 50);

    Account* p[] = { &accounts[0],&accounts[1],&ca };
    //账户总数
    const int n = sizeof(p) / sizeof(Account*);
    cout << "please input your selection: (d)deposit (w)withdraw (s)show (c)change day (n)next month (e)exit" << endl;
    char cmd;
    do
    {
        date.show();
        cout << "\tTotal:" << Account::getTotal()<< "\tcommand>:";

        int index, day;
        string desc;
        double amount;

        cin >> cmd;
        switch (cmd)
        {
            case 'd':       //存钱
                cin >> index >> amount;
                getline(cin, desc);
                p[index]->deposit(date, amount, desc);//(*P[index]).deposit(date, amount, desc);
                break;
            case 'w':       //取钱
                cin >> index >> amount;
                getline(cin, desc);
                p[index]->withdraw(date, amount, desc);
                break;
            case 's':       //查看账户信息
                for (int i = 0;i < n;i++)
                {
                    cout << "[" << i << "]";
                    p[i]->show();
                    cout << endl;
                }
                break;
            case 'c':       //改变日期
                cin >> day;
                if (day == date.getDay())
                    cout << "you cann't specify a previous day";
                else if (day > date.getMaxDay())
                    cout << "Invalid day";
                else
                    date = Date(date.getYear(), date.getMonth(), day);
                break;
            case 'n':       //查看下个月
                if (date.getMonth() == 12)
                    date = Date(date.getYear() + 1, 1, 1);
                else
                    date = Date(date.getYear(), date.getMonth()+1, 1);
                for (int i = 0;i < n;i++)
                    p[i]->settle(date);
                break;
        }
    } while (cmd != 'e');
    return 0;
}