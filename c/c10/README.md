# 一. 编写程序找出一组单词中“最小”单词和“最大”单词

用户输入单词后，程序根据字典顺序决定排在最前面和最后面的单词。当用户输入4个单词时，程序停止读入。假设所有单词都不超过20个字母。程序会话如下：

Enter word: dog

Enter word: zebra

Enter word: rabbit

Enter word: catfish

Enter word: walrus

Enter word: cat

Enter word: fish

 

Smallest word: cat

Largest word: zebra

 

tips: 使用两个名为smallest_word和largest_word的字符串来分别记录所有输入中的“最小”单词和“最大”单词。用户每输入一个新单词，都要用strcmp函数把它与smallest_word进行比较，如果新的单词比samllest_word“小”，就用strcpy函数把新单词保存到smallest_word中。用类似的方法与largest_word进行比较。用strlen函数来判断用户是否输入了4个字母的单词。



# 二. 编写程序，要求用户录入一串字符（把这些字符存储在数组中，并假定录入的都是小写英文字母)

然后通过调用selection_sort函数按照字典顺序来排序这些字符。在给定n个字符的数组后，selection_sort函数必须做下列工作：

  (1) 搜索数组找出最大的字符，然后把它移到数组的最后；

  (2) 递归地调用函数本身来对前n-1个数组元素进行排序。

 