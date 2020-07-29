# 一. 修改程序27，使其包含下列函数：

void rea_word( int counts[26] ) ;

bool equal_array( int couns1[26] , int counts2[26] ) ;

 

tips: main函数将调用read_word两次，每次用于读取用户输入的一个单词。读取单词时，read_word用单词中的字母更新counts数组，详见原题的描述。（main将声明两个数组，每个数组用于一个单词。这些数组用于跟踪单词中每个字母出现的次数。）接下来，main函数调用equal_array函数，以前面提到的两个数组作为参数。如果两个数组中的元素相同（表明这两个单词是变位词），equal_array返回true，否则返回false。注意：在C89标准下由于没有bool类型，还要注意该类型的处理方法。

 

# 二. 修改程序28，使其包含下列函数：

void create_magic_square( int n , char magic_square[99][99] ) ; 

void print_magic_square( int n , char magic_square[99][99] ) ;

 

tips：获得用户输入的数n之后，main函数调用create_magic_square函数，另一个调用参数时在main函数内部声明的n×n的数组。create_magic_square函数用1，2，…，n2填充数组，如原图所述。接下来，main函数调用print_magic_square，按原题描述的格式显示数组。

 

# 三. 如果换一种方法计算xn，9.6节的power函数速度可以更快。

tips: 如果n是2的幂，则可以通过自乘的方法计算xn。如，x4是x2的平方，所以x4可以用两次乘法计算，而不需要三次乘法。这种方法甚至可以用于n不是2的幂的情况。如果n是偶数，可以用公式![img](file:///C:/Users/xixin/AppData/Local/Temp/msohtmlclip1/01/clip_image002.gif) ;如果n是奇数，则![img](file:///C:/Users/xixin/AppData/Local/Temp/msohtmlclip1/01/clip_image004.gif) 。编写计算xn的递归函数（递归在n=0时结束，此时函数返回1）。为了测试该函数，写一个程序要求用户输入x和n的值，调用power计算xn，然后显示函数的返回值。



# 四. 编写程序模拟掷骰子的游戏（两个骰子）

第一次掷的时候，如果点数之和为7或11则获胜；如果点数之和为2、3或12则落败；其他情况下的点数之和称为“目标”，游戏继续。在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出7则落败，其他情况都忽略，游戏继续进行。每局游戏结束时，程序询问用户是否再玩一次，如果用户输入的回答不是y或Y，程序会显示胜败的次数然后终止。



You rolled: 8

Your point is 8

You rolled: 3

You rolled: 10

You rolled: 8

You win!

 

Play again? y

 

You rolled: 6

Your point is 6

You rolled: 5

You rolled: 12

You rolled: 7

You lose!

 

Play again? y

 

You rolled: 11

You win!

 

Play again? n

 

Wins: 2   loses: 1

 

tips: 编写三个函数：main、roll_dice和play_game。下面给出后两个函数的原型：

int roll_dice(void) ;

bool play_game(void) ;

roll_dice应生成两个随机数（每个都在1和6之间）（使用rand函数生成随机数，参考8.2节deal.c），并返回它们的和。play_game应进行一次掷骰子游戏（调用roll_dice确定每次掷的点数），如果玩家获胜则返回true，如果玩家落败则返回false。play_game函数还要显示玩家每次掷骰子的结果。main函数反复调用paly_game函数，记录获胜和落败的次数，并显示“You win!”和“You lose!”消息。