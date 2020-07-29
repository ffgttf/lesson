# 一. 编写函数，用牛顿方法计算正浮点数的平方根：

Enter a positive number: 3

Square root: 1.73205

 

tips: 设x是用户输入的数。牛顿方法需要先给出x平方根的猜测值（我们使用1）。后续的猜测值通过计算y和x/y的平均值得到。下表给出了求解3的平方根的过程。

​         x                                 y                                 x/y                            y和x/y的平均值

​         3                                1                                3                                         2

​         3                                2                                1.5                                     1.75

​         3                                1.75                          1.71429                          1.73214

​         3                                1.73214                  1.73196                          1.73205

​         3                                1.73205                  1.73205                          1.73205

注意，y的值逐渐接近x的平方根。为了获得更高的精度，程序中应使用double类型的变量代替float类型的变量。当y的新旧值之差的绝对值小于0.00001和y的乘积时程序终止。调用fabs函数求double类型数值的绝对值。（#include <math.h>）



# 二. 已知的最古老的一种加密技术是凯撒加密（得名于Julius Caesar）

该方法把一条消息中的每个字母用字母表中固定距离之后的那个字母来替代。（如果越过了字母Z，会绕回字母表的起始位置。例如，如果每个字母都用字母表中两个位置之后的字母代替，那么Y就被替换为A，Z就被替换为B），编写函数用凯撒加密方法对消息进行加密。用户在主函数里输入待加密的消息和移位计数（字母移动的位置数目），调用加密函数进行消息加密：

Enter message to be encrypted: Go ahead, make my day.

Enter shift amount (1-25): 3

Encrypted message: Jr dkhdg, pdnh pd gdb.

​       

注意，当用户输入26与移位计数的差值时，解密函数可以对消息进行解密：

Enter message to be encrypted: Jr dkhdg, pdnh pd gdb.

Enter shift amount (1-25): 23

Encrypted message: Go ahead, make my day.

 

可以假定消息的长度不超过80个字符。不是字母的那些字符不要改动。此外，加密时不要改变字母的大小写。

tips：为了解决绕回问题，可以用表达式 ( ( ch – ‘A’ ) + n ) % 26 + ‘A’计算大写字母的密码，其中ch存储字母，n存储移位计数。（小写字母也需要一个类似的表达式）

 

# 三. 编写函数，根据用户输入的英文名和姓，先显示姓氏，其后跟一个逗号，然后显示名的首字母，最后加一个点：

Enter a first and last name: Lloyd Fosdick

You entered the name: Fosdick, L.

 

tips: 程序需要将姓氏存储在一个字符数组中。可以假定姓氏的长度不超过20个字符。

 

# 四. 编写程序，要求用户录入一串整数

（把这串整数存储在数组中）

然后通过调用selection_sort函数来排序这些整数。在给定n个元素的数组后，selection_sort函数必须做下列工作：

（a）搜索数组找出最大的元素，然后把它移到数组的最后；

（b）递归地调用函数本身来对前n-1个数组元素进行排序。

 