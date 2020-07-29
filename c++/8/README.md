# 编写C++程序实现高斯消去法解线性方程组

要求：

1、	矩阵类Matrix作为基类，线性方程组类LinearEqu由Matrix类派生而来。

2、	Matrix类只处理n*n型的方阵，方阵用一个一维数组来存放

3、	Matrix的数据成员包括数组的首地址和n；Matrix的功能有设置矩阵的值setMatrix（）和显示矩阵printMatrix（）等

4、	LinearEqu类的数据除了由Matrix类继承过来用于存放系数矩阵A的成员外，还应该包括存放解向量x和方程右端向量b的数组的首地址。LinearEqu类的主要操作有setLinearEqu（），显示printLinearEqu（），求解solve（）以及输出方程的解printSolution（）。通过定义LinearEqu的新增成员函数来实现针对方程求解的功能。

5、	类的声明放在一个单独的文件中，类的实现放在一个单独的文件中，主函数放在一个单独的文件中。这样该题目共有5个程序文件分别是：Matrix.h，Matrix.cpp，LinearEqu.h, LinearEqu.cpp, main.cpp
