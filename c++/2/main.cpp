#include <iostream>
#include <string.h>
using namespace std;
class Stock
{
private:
    char company[50];//公司名称
    long shares;//所持股票的数量
    double share_val;//每股的价格
    double total_val;//股票总值
    void set_tot()
    {total_val=shares*share_val;}
public:
    void acquire(char co[50],long n,double pr);//获得股票
    void buy(long num, double price);//增持
    void sell(long num, double price);//卖出股票
    void update(double price);//更新股票价格
    void show();//显示所持股票信息
};
void Stock::acquire(char co[50],long n,double pr)
{
    strcpy(company, co);
    if(n<0)
    {
        cout<<"Number of shares can not be negative;"<<company<<"  share set to 0.\n";
        shares=0;
    }
    else
        shares=n;
    share_val=pr;
    set_tot();
}
void Stock::buy(long num,double price)
{
    if(num<0)
        cout<<"Number of shares purchased can not be negative. Transaction is aborted.\n";
    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}
void Stock::sell(long num,double price)
{
    if (num<0)
        cout<<"Number of shares sold can not be negative. Transaction is aborted.\n";

    else if (num>shares)
        cout<<"You can not sell more than you have! Transaction is aborted.\n";
    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val=price;
    set_tot();
}
void Stock::show()
{
    cout<<"Company: "<<company<<"   Shares:"<<shares<<endl;
    cout<<"Share Price"<<share_val<<"$"<<"  Total worth:"<<total_val<<endl;
}
int main()
{
    Stock stockl;
    stockl.acquire("NanoSmart", 20,12.50);
    stockl.buy(15,18.25);
    stockl.show();
    stockl.sell(400,20.00);
    stockl.show();
    return 0;
}