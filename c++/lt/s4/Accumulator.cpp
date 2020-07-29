#include "Accumulator.h"
using namespace std;

Accumulator::Accumulator (const Date&date,double value):lastDate(date),value(value),sum(0){};
void Accumulator::change(const Date&date, double value) {
    sum = getSum(date);
    lastDate = date;
    this->value = value;
}
void Accumulator::reset(const Date&date, double value) {
    lastDate = date;
    this->value = value;
    sum = 0;
}