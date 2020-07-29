#include"Matrix.h"
class LinearEqu :public Matrix{
public:
    LinearEqu(int size);
    ~LinearEqu();
    void setLinearEqu(const double* a, const double* b);
    bool solve();
    void printLinearEqu() const;
    void printSolution() const;
private:
    double* sums;
    double* solution;
};
