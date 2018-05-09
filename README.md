# 剑指offer
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
### 6：[重建二叉树](https://github.com/Tramac/CodingInterviews/tree/master/06_ConstructBinaryTree)
* 熟悉二叉树中递归的使用。
* 使用四个指针。
* 由先序遍历确定根节点的值，创建根节点。
* 注意判断序列中是否只有一个元素，并且输入是否合法。
* 在中序遍历中寻找根节点，判断是否找到了根节点。
* 找到根节点后，判断是否有左子树（通过元素个数判断），如果有，递归调用求左子树的根节点。
* 同理判断右子树。
### 7：[用两个栈实现队列](https://github.com/Tramac/CodingInterviews/tree/master/07_QueueWithTwoStacks)
* 熟悉两个栈实现队列的逻辑。
* 模板的使用。
* 栈的压入与弹出，栈顶元素的获取。push(T), pop(),top()。
* 栈的大小的获取。stack.size()。
### 8：[旋转数组的最小数字](https://github.com/Tramac/CodingInterviews/tree/master/08_MinNumberInRotatedArray)
* 熟悉二分查找的思想。
* 注意旋转0个元素的特殊情况以及解决方法(将indexmin初始化为0)。
* 注意中间元素与两侧元素相等时的特殊情况，此时需要添加顺序查找。
### 9: [斐波那契数列](https://github.com/Tramac/CodingInterviews/tree/master/09_Fibonacci)
* 熟悉递归的思想。
* 递归代码简洁，但效率较低，并且容易栈溢出。
* 熟悉实用的Fibnacci的求解方法。
* 数值类型注意用long long型。
### 10.[二进制中1的个数](https://github.com/Tramac/CodingInterviews/tree/master/10_NumberOf1)
* 如果将输入的数字右移与1作与运算可能导致陷入死循环。
* 将1左移与输入的数字做与运算是一种解法。注意while循环的停止条件。
* 新颖的解法：把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变为0。
### 11.[数值的整数次方](https://github.com/Tramac/CodingInterviews/tree/master/11_Power)
* 设置全局变量，判断输入是否有效。
* 注意base为0，指数为负数的特殊情况。
* 注意判断两个小数是否相等时的函数。
### 12：[打印1到最大的n位数](https://github.com/Tramac/CodingInterviews/tree/master/12_Print1ToMaxOfNDigits)
* 该问题为大数问题，用字符串或者数组表达大数解决。
* 字符串的初始化，memset()的使用。
* 熟悉字符串表达的数字上模拟加法。判断是否溢出，是否进位。字符间的计算。
* 把字符串表达的数字打印出来。开头的0不打印，设置bool变量判断。
### 13.[在O(1)时间删除链表结点]()
* 从链表的头结点开始，顺序遍历查找要删除的结点的时间复杂度为O(n)。
* 可以把要删除结点的下一个结点的内容复制到需要删除的结点上覆盖原有的内容，再把下一个结点删除。此时的时间复杂度为O(1)。
* 如果要删除的结点位于链表的尾部，仍然要从链表的头结点开始，顺序遍历得到该结点的前序结点，并完成删除操作。
* 如果链表中只有一个结点，删除的既是头结点也是尾结点，所以传入的需要是指向头结点的指针而不是头结点，即指针的指针。
* 结点的删除操作。delete pNode; pNode = NULL;
* 理清情况分类：删除的不是尾结点，链表只有一个结点，删除的为头结点也是尾结点，链表有多个结点，删除的是尾结点。
### 14.[调整数组顺序使得奇数位于偶数前面]()
* 设置两个指针，第一个从前往后pBegin，第二个从后往前pEnd。
* 三个while循环。其中两个寻找奇数和偶数。
* 注意每次操作时需要判断pBegin < pEnd。
* 了解可扩展性。
### 15.[链表中倒数第k个结点]()
* 为了实现只遍历一次链表，定义两个指针，第一个指针从链表的头指针开始向前走k-1,第二个指针保持不动，从第k步开始，两个指针同时前进，当第一个指针到达末尾时，第二个指针正好指向倒数第k个结点。
* 注意判断传入的是否为空链表，k值是否大于链表的长度。
* 相关题目有：求链表额中间节点(一个指针走两步，另一个走一步)。判断一个单向链表是否形成了环形结构(一个指针走一步，另一个走两步，是否会相遇)。
### 16.[反转链表]()
* 需要三个指针，分别指向当前结点，前一个结点，后一个结点。
* 当后一个结点为空时，那么当前结点就是反转后的头结点，记得顺表将其设为头结点。
* 递归反转链表也要熟悉（没看懂，还要再看）。
### 17.[合并两个排序的链表]()
* 首先处理其中一个是空链表时的情况。
* 返回的是合并后的新的头结点，所以要声明新的头结点。
* 头结点的下一个结点由递归获得。
* 典型的递归题目，要多看。
### 18.[树的子结构]()
* 首先判断两个结构的根节点是否相同。
* 如果根节点相同，定义判断子树是否相同的函数，递归判断左子树根节点和右子树根节点时候同时相同。
* 如果根节点不相同，递归判断左子树和右子树是否相同。
* 注意边界条件的检查，当两个数为空的时候，定义相应的输出。
* 树结构典型的递归题，多看。
### 19.[二叉树的镜像]()
* 熟悉求镜像的过程。
* 交换两个结点的方式和交换两个常数的方式相同。
* 递归调用交换左子树和右子树。
### 20.[顺时针打印矩阵]()
* 按圈打印。
* 按圈打印的循环继续条件columns>startX*2 && rows>startY*2。
* 按圈打印分四步，熟悉每步的执行条件。
### 21.[包含min函数的栈]()
* 设置一个数据栈，一个辅助栈。压入元素时，辅助栈每次压入之前最小值和压入数据之间的较小值。
* 删除操作同时删除栈顶元素。
* 去最小值时返回辅助栈的栈顶元素即可。
* 熟悉模板的定义及声明，使用。
* 注意判断栈的size()是否为空。
### 22.[栈的压入、弹出序列]()
* 需要一个辅助栈。
* 如果下一个弹出的数字刚好是栈顶元素，那么直接弹出，如果下一个弹出的数字不在栈顶，把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止。如果所有的数字都压入栈了仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列。
* 熟悉逻辑以及栈的操作。
* 我觉得这道题在栈的题目中挺重要的，多看多看。
### 23:[从上往下打印二叉树]()
* 广度优先遍历二叉树问题，用队列作为辅助数据结构。
* STL中队列容器deque,入队操作push_back(),取队首元素front(),弹出队首元素pop_front()，判断队列是否为空size()是否为0。
* 首先将根节点压入队列，while循环，弹出队结点并打印，然后判断该是否有左右子结点，如果有依次压入队列，如果队列为空结束循环。
### 24.[二叉搜索树的后序遍历序列]()
* 二叉搜索树的左子树结点的值均小于根节点，右子树结点的值均大于根节点。
* 后序遍历的最后一个数字是树的根节点的值。
* 首先确定根节点的值（即序列最后一个数）。
* 设i=0,从头遍历二叉搜索树的左子树（即判断结点值是否小于根节点），得到左子树最后结点的索引i。
* 设j=i,从左子树最后索引i开始到length-1,此部分应该是右子树，遍历是否全部大于根节点，如果不满足，则无法构成二叉搜索树,返回false。
* 如果都满足，当i>0,递归调用左子树。当j<length-1，递归调用右子树。返回left&&right。
### 25.[二叉树中和为某一值的路径]()
* 用到树结构，要首先想到是否可以使用递归。
* 路径是从根结点触发到叶结点，所以从根结点开始。
* 路径上的结点需要保存下来，用什么保存路径呢？栈。
* 首先判断当前是否到达叶结点，如果是，判断当前路径的和是否为期望值，如果是，打印。
* 如果没达到叶结点，递归遍历它的子结点。
* 最后返回到父节点，记得从路径中删除当前结点（因为路径传入时是引用传入的）。（这里要多多理解）。
* 本题用STL中的vector实现的栈，压入操作与弹出操作分别为push_back(),pop_back()。因为我们需要打印操作，如果用stack，只能得到栈顶元素。
* 二叉树的递归使用，多多看看这道题。
### 26.[复杂链表的复制]()
* 将过程分为三个部分。
* 克隆结点并连接在后面。
* 设置复制出来的结点的m_pSibling。这里注意设置前检查是否为空。
* 把得到的长链表拆分为连个链表。主要首先设置复制链表的头指针并返回。
* 将三个部分合并。
### 28.[字符串的排列]()
* 把字符串看成由两部分组成：第一部分为它的第一个字符，第二部分是后面的所有字符。
* 两步：首先把第一个字符和后面的所有的字符交换（包括自身）（循环实现）。然后递归求后面所有字符串的排列。
* 函数的参数有字符串指针以及开始位置的指针。
* 如果开始位置为字符串末尾，打印字符串。否则执行上面所说的两步。
* 注意递归调用之后，在下一次循环交换之前需要恢复字符串的原状，即交换回来。因为我们需要的是在原字符串上做交换。
### 29.[数组中出现次数超过一半的数字]()
* 两种解决方案.
* 解法一:基于Partition函数的O(n)算法,因为该数超过了一般,那么经过Partition()函数后位于中间的数字一定是该数字.当index=mid时,返回该数字,否则递归调用Partition()函数,直到index=mid.
* 解法二:根据数组特点,遍历数组保存两个值:一个是数组中的一个数字,一个是次数.当遍历到下一个数字时,如果下一个数字和之前保存的数字相同,则次数加1,否则减1,如果次数减为0,保存的数字设为当前数字,并把次数设为1.由于要找的数字出现的次数比其他所有数字出现的次数之和还要多,那么要找的数字肯定是最后一次把次数设为1时对应的数字.
* 两个解法的思路都比较容易理解,要多看一下.
* 注意检查输入的数组是否有效,检查找到的数字是否超过了一半.
### 30.[最小的k个数]()
* 该题的一个解题思路和29题一样,基于Partition()求解,当index为k时,其左侧的就是最小的k个值.
* 注意函数需要传入一个指向输出的指针,并且函数最后需要将最小的k个数对其赋值.
* 这种解题方法对数组做了修改.
* 另外的一种适合处理海量数据的方法没有看.
### 31.[连续子数组的最大和]()
* 根据数组的规律求解
* 设置两个变量,一个保存当前数组和,一个保存最大和.
* 利用for循环,当当前和小于0时,则把之前的子数组舍弃,并把和设为当前值.
* 如果不小于0,则加上当前的值,然后判断和最大和的大小,如果大于最大和,则将其赋给最大和.
* 另外该题有动态规划解法与递归解法,后面要看一下.
### 32.[从1到n整数中1出现的次数]()
* 首先将数字转换为字符串，```char strN[50]; sprintf(strN, "%d", n);```。
* 判断字符串的首位是否介于字符1和9之间,如果不是,则不是个数字,退出。
* 取数字的首位first。
* 取数字的长度,这里用到了类型强制转换```static_cast```。即```unsigned int length = static_cast<unsigned int>(strlen(strN));```。
* 判断长度和首位,先把特殊情况搞定。比如长度为1,首位为0,或者长度为1,首位不为0。
* 然后按位(从高到低)计算1的个数. 这里还用到一个求10的指数次方的函数. 这部分比较麻烦,再多看几次.
* 对首位判断时要分为大于1和等于1两种情况.大于1时,最高位1的次数就是powerbase10(length - 1).否则就是去除最高位后的数字加1,这里操作时有一个技巧,```atoi(strN+1)+1```,其中```strN+1```去掉了最高位,因为```strN```是字符串,指针后移一位.然后利用字符串转整数函数```atoi()```。
* 要理解并记住最高位大于1和小于1时两种不同的情况以及求解方法。
* 求完最高位之后,再求次高位,次高位同样分为两部分,其中一部分为除了第一位之外的数位中的数目,这里的公式不理解,再看看,另外一部分通过递归解决.
* 最终将三部分相加.
### 33.[把数组排成最小的数]()
* 这题c++解决太麻烦了,用python写好了.
* 注意由于大数问题,比较之前要先将整数数组转化为字符串数组.
* 需要自定义比较方式.python中lambda的使用方法要熟悉,sorted()函数使用方法,以及输出结果时join的使用方法.
### 34.[丑数]()
* 首先要知道如何判断一个数是不是丑数,简单说就是用三个while循环.
* 丑数应该是另一个丑数乘以2,3,5的结果.因此可以创建一个数组,里面的数字是排序好的丑数,每一个都是前面的丑数乘以2,3,5得到.
* 问题在于如何确保得到的丑数是排序好的?
* 首先创建一个数组指针.并初始化第一个丑数为1,以及一个指向下一个丑数的索引nextUglyIndex.
* 创建三个指针,分别代表三个乘数指向的数字.
* ```while(nextUglyIndex < 1500)```, 分别求三个指针指向的数字与2,3,5相乘的结果,并选取最小值最为下一个丑数.注意这里需要写一个判断三个数字取最小的函数.
* 然后判断这个数字是来自哪一个指针相乘的结果,并更新该指针以及下一个丑数的索引.
* 最终可得到整个丑数数组,记得返回后删除动态数组,因为是动态分配的.
### 35.[第一个只出现一次的字符]()
* 用哈希表解决(数组代替),由于字符类型一共有256中可能,穿件一个大小为256的数组.
* 扫描两次,第一次计算出现的次数,第二次找出第一个为1的字符.
### 37.[两个链表的第一个公共结点]()
* 如果两个单向链表有公共的结点，又由于每个结点只有一个m_pNext,因此从第一个公共结点开始，之后它们所有的结点都是重合的。
* 首先分别遍历两个链表得到它们的长度，计算出长的链表比短的链表多出几个结点。
* 再次遍历，在较长的链表上先走若干步，接着再同时自两个链表上遍历，找到第一个相同的结点就是它们的第一个公共结点。
### 38.[数字在排序数组中出现的次数]()
* 如果用二分查找找到第一个目标然后向两侧遍历，复杂度为O(n)，相对于直接顺序遍历没有优势，此方法不行。
* 算法应该致力于直接找到第一个k以及最后一个k。所以问题转化为如何用二分查找在数组中找到第一个k。最后一个同理。
* 如果用二分查找，中间的数字大于k那么继续检查前半段，如果小于k则继续查找后半段。如果等于k呢？确定是不是第一个k，如果左侧的一个数字不是k，那么就是第一个，如果是，继续在前半段二分查找。
* 按照上面思路可以容易写出找第一个k和找最后一个K的代码，注意边界条件，mid需要大于0以及小于length。
### 39_1.[二叉树的深度]()
* 如果二叉树的根节点为空，那么深度为0。
* 如果根结点不为空，分别递归求出左子树的深度和右子树的深度。
* 二叉树的深度等于左子树深度与右子树深度中较大的一个加1。
* 代码很简洁，要熟悉二叉树中这种递归方法，很多都有类似的操作。
### 39_2.[判断是否为平衡二叉树问题]()
* 其中的一个解法是利用上一题求左右子树的深度的方法，如果两个子树的深度差大于1那么不是平衡二叉树，否则递归判断左右子树是否都是平衡二叉树。
* 上述方法存在重复计算的问题，效率不高。
* 考虑用后续遍历的方式遍历二叉树，遍历到每个结点的时候已经遍历了它的左右子树，此时我们需要记录该结点的深度，如何记录？引用。一面遍历一面判断每个结点是不是平衡的。
* 难点是如何记录深度。
* 递归的运用，（多看此题）。
### 40.[数组中只出现一次的数字]()
* 任何一个数字异或自己都等于0，如果从头到尾一次异或数组中的每一个数字，那么最终的结果刚好就是只出现一次的数字。
* 所以问题转化为了如何将数组分为两部分，每部分只包含一个只出现一次的数字，另外的均出现两次。
* 可以从头到尾依次异或数组中的每一个数字，那么最终得到的结果就是两个只出现一次的数字的异或结果。由于两个数字不同，那么结果的二进制表达中至少有一位为1，我们可以找到第一个为1的位置，即为n，然后根据每个数字的第n位是不是1将数组分为两部分。
* 由于分组的标准是第n位是1还是0，那么出现了两次的的数字肯定被分为同一组，因为他们的每一位都一样。
* 此时的问题是如何找第一个为1的位置。单独写一个函数来求解，通过将数字右移与1做与运算判断。
* 需要定义两个指针用于保存两个数字（作为主函数的参数已传入）。
* 定义一个函数，判断第n为是不是1。直接将数字右移n位与1做与运算。
### 41.[和为s的两个数]()
* 设置两个指针分别指向开头和末尾，即为小数指针与大数指针。
* 当当前的和小于s时，右移小数指针，大于s时，左移大数指针。等于s时输出。
### 41_2.[和为s的连续正数序列]()
* 由上题的经验，仍然设两个数small,big分别表示序列的最小值和最大值，初始化为1和2。
* 由于序列中至少有两个数字，所以增加到small到（1+s）/2为止。
### 42_1.[翻转单词顺序]()
* 第一步翻转句子中所有的字符。
* 第二步再翻转每个单词中字符的顺序。
* 要确定的是翻转字符串的起始位置与结束位置，这需要循环得到。注意循环的条件。
### 42_2.[左旋转字符串]()
* 这个题目和上面的题目类似。
* 首先确定两个子串的起始位置和结束位置，分别翻转。
* 然后翻转整个字符串。
* 注意的是要自己求解字符串的长度```int length = static_cast<int>(strlen(pStr));```。
* 注意空指针的检查等。
### 43.[n个骰子的点数]()
* 基于递归求骰子点数，时间效率不够高。
* 假设有n个骰子，最小点数为n，最大点数为6n，定义一个大小为6n-n+1的数组用于保存为一种可能性出现的次数。
* 问题归结为n的骰子的和为s时所有的可能数。可用递归求解，两个函数看着难以理解，多看看。模拟一下有助于理解。
* 另一种解法是基于循环的，时间性能较好。
* 用两个数组来存储骰子点数的每一个总数s出现的次数。
* 在一次循环中，第一个数组中的第n个数字表示骰子和为n出现的次数。
* 在下一循环中，我们加上一个新的骰子，此时和为n的骰子出现的次数应该等于上一次循环中骰子点数和为n-1、n-2、n-3、n-4、n-5、n-6的次数的总和。所以把另一个数组的第n个数字设为前一个数组对应的6项的和。
* 流程如下（要理清楚就不会那么难）：<br>
1.设置一个大小为2数组指针，将每一个大小均设为6n+1。<br>
2.循环初始化两个数组的值为0。<br>
3.设置一个flag用于两个数组之间的状态转换。<br>
4.对第一个数组设置，当第一个骰子的时候，1~6的情况初始化为1。<br>
5.循环k从2到n表示其他的骰子，由于k个骰子的时候和的范围为k-6k。所以需要先对0-k-1设置为0。<br>
6.然后设置k-6k，思路上面已经说明。<br>
* 注意两个数组之间的转换。
### 44.[扑克牌的顺子]()
