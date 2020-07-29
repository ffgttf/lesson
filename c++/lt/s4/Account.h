#include"Accumulator.h"
#include<string>
using namespace  std;

//基类 Account
class Account {
private:
    std::string id; //账号
    double balance; //余额
    static double total; //所有账户的总金额
protected:
    Account(const Date&date, const std::string &id);
    //记录一笔账，date为日期，desc为说明,amount为金额
    void record(const Date &date, double amount, const std::string &desc);
    //报告错误信息
    void error(const std::string &msg)const;
public:
    //构造函数
    const std::string &getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }
    void show() const;//显示账户信息
};

//派生类 SavingsAccount
class SavingsAccount:public Account {
private:
    Accumulator ac;
    double rate;
public:
    SavingsAccount(const Date &date, const std::string &id, double rate);
    double getRate() const { return rate; }
    void deposit(const Date &date, double amount, const std::string &desc); //存入现金
    void withdraw(const Date &date, double amount, const std::string &desc); //取出现金
    void settle(const Date &date);//结算利息，每年1月1日调用一次该函数
};

//派生类 CreditAccount
class CreditAccount :public Account {
private:
    Accumulator ac;
    double credit;
    double rate;
    double fee;
    double getDebt()const {
        double balance = getBalance();
        return(balance < 0 ? balance : 0);
    }
public:
    CreditAccount(const Date &date, const std::string &id, double credit, double rate, double fee);
    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getAvailableCredit() const {
        if (getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }
    void deposit(const Date &date, double amount, const std::string &desc); //存入现金
    void withdraw(const Date &date, double amount, const std::string &desc); //取出现金
    void settle(const Date &date);//结算利息，每年1月1日调用一次该函数
    void show() const;//显示账户信息
};