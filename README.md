# 剑指offer解答
----
在这里记录一下剑指offer的答案吧。<br>
其实很多只是比对着书本敲下来的。<br>
大约看了两遍可总是会忘，或许是根本就没有理解解题方法吧。<br>
c++真的是好难啊，更难的或许是算法吧，总是无法搞定递归，无法搞定树。<br>
总之，还是记录下来好了，就多看几遍吧，慢慢补充理解好了。<br>
### 1：[赋值运算符函数](https://github.com/Tramac/CodingInterviews/blob/master/01_AssignmentOperator/main.cpp)
* 把返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用（即*this）。只有返回一个引用，才可以允许连续赋值。
* 把传入的参数的类型声明为常量引用。
* 判断传入的参数和当前的实例（*this）是否为同一个实例。
* 释放实例自身已有的内存。
* 注意如何释放自身内存，如何分配新的空间，如何实现字符串的赋值。
### 3：[二维数组中的查找](https://github.com/Tramac/CodingInterviews/tree/master/03_FindInPartiallySortedMatrix)
* 数组代替二维数组。
* 注意边界条件，循环的停止条件。
### 4：[替换空格](https://github.com/Tramac/CodingInterviews/tree/master/04_ReplaceBlank)
* 传入的length并不是字符串长度，只是字符串的最大容量。
* 字符串的长度需要计算。
* 注意判断新的字符串的长度是否会大于最大容量。
### 5：[从尾到头打印链表](https://github.com/Tramac/CodingInterviews/tree/master/05_PrintListReversedOrder)
* 在链表的插入与删除操作中，传入的pHead需要是一个指向指针的指针，因为有可能对pHead作出更改。
* 插入与删除操作中，首先要判断插入或删除的是否为头结点。
* 插入新结点时需要先分配内存，ListNode* pNew = new ListNode();
* 可以用栈实现从尾到头打印链表，也可以用递归实现。
### 6：[重建二叉树]()
* 熟悉二叉树中递归的使用。
* 使用四个指针。
* 由先序遍历确定根节点的值，创建根节点。
* 注意判断序列中是否只有一个元素，并且输入是否合法。
* 在中序遍历中寻找根节点，判断是否找到了根节点。
* 找到根节点后，判断是否有左子树（通过元素个数判断），如果有，递归调用求左子树的根节点。
* 同理判断右子树。
