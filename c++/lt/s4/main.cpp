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
    //账户总数
    const int n = sizeof(accounts) / sizeof(SavingsAccount);
    //11月的几笔账目
    accounts[0].deposit(Date(2008,11,5), 5000, "salary");
    ca.withdraw(Date(2008, 11, 15), 2000, "buy a cell");
    accounts[1].deposit(Date(2008,11,25), 10000, "sell stock 0323");
    //结算信用卡
    ca.settle(Date(2008, 12, 1));
    //12月的几笔账目
    ca.deposit(Date(2008, 12, 1), 2016, "repay the credit");
    accounts[0].deposit(Date(2008, 12, 5), 5500, "salary");
    //结算所有的账户并输出各个账户信息
    for (int i = 0;i < n;i++) {
        accounts[i].settle(Date(2009, 1, 1));
    }

    accounts[0].settle(Date(2009, 1, 1));
    accounts[1].settle(Date(2009, 1, 1));
    ca.settle(Date(2009, 1, 1));
    cout << endl;
    accounts[0].show();cout << endl;
    accounts[1].show();cout << endl;
    ca.show();cout << endl;

    cout << "Total: " << Account::getTotal() << endl;
    return 0;
}