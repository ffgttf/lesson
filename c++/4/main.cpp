#include <iostream>
using namespace std;
class shop
{
public:
    shop(int n, int q, double p):num(n), quantity(q), price(p) {};
    void SUM();
    static double average();
    static void display();
private:
    int num;
    int quantity;
    double price;
    static double sum;
    static int n;
};
void shop::SUM()
{
    float rate=1.0;
    if(quantity>10)
        rate = 0.98 * rate;
    sum += quantity * rate * price;
    n += quantity;
}
void shop::display()
{
    cout<<"sum: "<<sum<<endl;
    cout<<"average: "<<average()<<endl;
}
double shop::average()
{
    return (sum/n);
}
double shop::sum=0;
int shop::n=0;
int main()
{
    int i;
    shop s[3]={
            shop(101,5,23.5),
            shop(102,12,24.56),
            shop(103,100,21.5)
    };
   for(i=0;i<3;i++)
       s[i].SUM();
   shop::display();
   return 0;
}