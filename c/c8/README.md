# 一. 建立一个字符栈（参考书上栈的实例，将整数栈换成字符栈即可）

在main函数中，要求用户输入一串圆括号或花括号，然后指出它们之间的嵌套是否正确：（嵌套正确和不正确的情形都要测试一次，两种运行结果分两个截图在下方贴出）

Enter parenteses and/or brace: ((){}{()})

Parenteses/braces are nested properly

 

tips: 读入左圆括号或左花括号时，把它们像字符一样压入栈中。当读入右圆括号或右花括号时，把栈顶的项弹出，并且检查弹出项是否是匹配的圆括号或花括号。（如果不是，那么圆括号或花括号嵌套不正确。）当程序读入换行符时，检查栈是否为空。如果为空，那么圆括号或花括号匹配；如果栈不为空（或者如果曾经调用stack_underflow函数），那么圆括号或花括号不匹配。如果调用stack_overflow函数，程序显示信息Stack overflow，并且立刻终止。



# 二. 有些计算器（尤其是惠普的计算器）使用逆波兰表示法（Reverse Polish Notation, RPN）

来书写数学表达式。在这一表示法中，运算符放置在操作数的后面而不是放在操作数中间。例如，在逆波兰表示法中1+2将表示为1 2+，而1+2*3将表示为1 2 3 * +。逆波兰表达式可以很方便地用栈求值。算法从左向右读取运算符和操作数，并执行下列步骤。

（1）当遇到操作数时，将其压入栈中。

（2）当遇到运算符时，从栈中弹出它的操作数，执行运算并把结果压入栈中。

编写程序对逆波兰表达式求值。操作数都是个位的整数，运算符为+、-、*、/和=。遇到运算符=时，将显示栈顶项，随后清空栈并提示用户计算新的表达式。这一过程持续进行，直到用户输入一个既不是运算符也不是操作数的字符为止：

Enter an RPN expression: 1 2 3 * + =

Value of expression: 7

Enter an RPN expression: 5 8 * 4 9 - / =

Value of expression: -8

Enter an RPN expression: q

​       

tips: 如果栈出现上溢，程序将显示消息Expression is too complex并终止。如果栈出现下溢（例如遇到表达式1 2 + +），程序将显示消息Not enough operands in expression并终止。使用字符栈实现程序中的栈操作，并使用scanf ( “ %c” , &ch)读取运算符和操作数。

 

# 三. 编写程序，提示用户输入一个数并显示该数，使用字符模拟七段显示器的效果

tips: 非数字的字符都将被忽略。在程序中用一个名为MAX_DIGITS的宏来控制数的最大位数，MAX_DIGITS的值为10。如果数中包含的数位大于这个数，多出来的数位将被忽略。使用两个外部数组，一个是segments数组（见第八章的练习题6），用于存储表示数字和段之间的对应关系的数据；另一个是digits数组，这是一个3行（因为现实出来的每个数字高度都是3个字符）、MAX_DIGITS×4列（数字的宽度是3个字符，但为了可读性需要在数字之间增加一个空格）的字符数组。编写4个函数：main、clean_digits_array、process_digit和print_digits_array。下面是后3个函数的原型：

void clear_digits_array(void);

void process_digit ( int digit , int position ) ;

void print_digits_array (void) ; 

 

clear_digits_array函数在digits数组的所有元素中存储空白字符。process_digit函数把digit的七段表示存储到digits数组的指定位置（位置从0到MAX_DIGITS-1）。print_digits_array函数分行显示digits数组的每一行，产生出像示例图那样的输出。

 