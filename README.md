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
