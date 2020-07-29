#include "date.h"
using namespace std;

class SavingsAccount {
private:
    std::string id; //账号
    double balance; //余额
    double rate; //存款的年利率
    Date lastDate; //上次变更余额的日期
    double accumulation; //余额按日累加之和
    static double total; //所有账户的总金额

    void record(const Date &date, double amount,const string &desc);   //记录一笔账，date为日期，desc为说明
    void error(const std::string &msg)const;  //报告错误信息
    double accumulate(const Date &date) const {     //获得到指定日期为止的存款金额按日累积值
        return accumulation + balance*date.distance(lastDate);
    }
public:
    SavingsAccount(const Date &date, const std::string &id, double rate);     //构造函数
    const std::string &getId() const { return id; }
    double getBalance() const { return balance; }
    double getRate() const { return rate; }
    static double getTotal() { return total; }
    void deposit(const Date &date, double amount,const std::string &desc); //存入现金
    void withdraw(const Date &date, double amount,const std::string &desc); //取出现金
    void settle(const Date &date);   //结算利息，每年1月1日调用一次该函数
    void show() const;  //显示账户信息
};