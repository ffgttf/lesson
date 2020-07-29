# 一.编写一个程序，要求用户输入一个美金数量，然后显示出如何用最少的20美元 、10美元、5美元和1美元来付款，具体格式如下：

Enter a dollar amount：93

 

$20 bills：4

$10 bills：1

$5 bills：0

$1 bills：3

 

tips：将付款金额除以20，确定20美元的数量，然后从付款金额中减去20美元的总金额。对其他面额的钞票重复该操作。确保在程序中使用整数值，不要用浮点数。



# 二.编程计算第一、第二、第三个月还贷后剩余的贷款金额，具体格式如下：

Enter amount of loan：20000.00

Enter interest rate：6.0

Enter monthly payment：386.66

 

Balance remaining after first payment：$19713.34

Balance remaining after second payment：$19425.25

Balance remaining after third payment：$19135.71

 

在显示每次还款后的余额时保留两位小数。

tips：每个月的贷款余额减去还款金额后，还需要加上贷款余额与月利率的乘积。月利率的计算方法式把用户输入的利率转换成百分数再除以12。

# 三.编写一个程序，对用户录入的产品信息进行格式化。程序会话应类似如下这样：

Enter item number: 583

Enter unit price: 13.5

Enter purchase date (mm/dd/yyyy): 3/8/2018

 

Item    Unit            Pruchase

​        Price           Date

583     $  13.50        3/8/2018

 

其中，产品编号和日期项采用左对齐方式，单位价格采用右对齐方式，允许最大取值为9999.99的美元。

tips: 各个列使用制表符控制。



# 四.编写一个程序，要求用户（按任意次序）输入从1到16的所有整数，然后用4×4矩阵的形式将它们显示出来，再计算出每行、每列和每条对角线上的和：

16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1

16   3   2  13

 5  10  11   8

 9   6   7  12

 4  15  14   1

 

Row sums: 34 34 34 34

Column sums: 34 34 34 34

Diagonal sums: 34 34

 

如果行、列和对角线上的和都一样（如本例所示），则称这些数组成一个幻方（magic square）。这里给出的幻方出现于艺术家和数学家 Albrecht Dürer 在1514年的一幅画中。（注意，矩阵的最后一行中间的两个数给出了该画的创作年代。）

 

tips：使用具有一定意义的变量名，如r1c1，r1c2等；行、列和对角线的和的计算可以参考程序“分数相加”。确保在程序中使用整数值，不要用浮点数。