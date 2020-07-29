#include<iostream>
#include"LinearEqu.h"
using namespace std;
int main(){
    int i, j, n;
    cout << "Enter the Num of equations: "<<endl;
    cin >> n;
    double a[n*n],b[n];
    cout <<"left matrix: "<<endl;
    for (i=0;i<n*n;i++)
        cin>>a[i];
    cout<<"right matrix: "<<endl;
    for (j=0;j<n;j++)
        cin>>b[j];
    LinearEqu equ(n);
    equ.setLinearEqu(a, b);
    equ.printLinearEqu();
    if (equ.solve())
        equ.printSolution();
    else
        cout << "Fail" << endl;
    return 0;
}
