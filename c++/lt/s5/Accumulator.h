#include"date.h"
class Accumulator {
private:
    Date lastDate;
    double value;
    double sum;
public:
    Accumulator(const Date&date,double value);
    double getSum(const Date &date)const {
        return sum + value*(date - lastDate);
    }
    void change(const Date&date, double value);
    void reset(const Date&date, double value);
};