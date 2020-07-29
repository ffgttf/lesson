# 一. 修改程序5，使其包含下列函数：

void pay_amount ( int dollars , int *twenties , int *tens , int *fives , int *ones ) ;

 

tips: 函数需要确定：为支付参数dollars表示的付款金额，所需20美元、10美元、5美元和1美元的最小数目。twenties参数所指向的变量存储所需20美元的数目，tens、fives和ones参数类似。



# 二. 修改程序16，使其包含下列函数：

void reduce ( int numerator , int denominator , 

int *reduced_numerator , int *reduced_denominator ) ;

​       

tips: numerator和denominator分别是分数的分子和分母。reduced_numerator和reduced_denominator是指向变量的指针，相应变量中分别存储把分数化为最简形式后的分子和分母。

 

# 三. 编写程序读一条消息，然后检查这条消息是否是回文（消息中的字母从左往右看和从右往左看是一样的）：

Enter a message : He lived as a devil , eh?

Palidrome

 

Enter a message : Madam , I am Adam.

Not a palindrome

 

tips: 忽略所有不是字母的字符，用数组保存输入的信息。

（a）    用整型变量来跟踪数组中的位置

（b）   用指针代替整数来追踪数组中的位置

（c）    利用数组名可以用作指针的事实简化（b）

即在一个程序中用三种方法进行判断。