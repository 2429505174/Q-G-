# QG训练营组第一周周记：
2021年3月27日-2021年4月4日

## 生活随记：

### 研究课题学习：

#### 人工势能法 Artifical Potential Field：

人工势场包括引力场和斥力场，其中目标点对物体产生引力，引导物体朝向其运 动（这一点有点类似于 A*算法中的启发函数 h）。

[csdn]: https://blog.csdn.net/u012814946/article/details/107321747?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161691395316780357270070%2522%252C%2522scm%25
[详细]: https://blog.csdn.net/weixin_36815313/article/details/111592477?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161691395316780357270070%2522%252C%2522s

**电势场与重力势场作用机制类似**

##### 引力场和斥力场

引力场

维基百科说：“人工势场法（Artificial Potential Field， APF）是一种将机器人的外形视为势场中的一个点，这个势场结合了对目标的吸引力和对障碍物的排斥力。得到的轨迹作为路径输出。该方法具有计算量小、容易理解等优点。然而，它们可能陷入势场的局部极小值而无法找到路径，或者无法找到最优路径。人工势场可以被视为与静电势场类似的连续方程(将机器人视为点电荷)，或者通过场的运动可以使用一组语言规则进行离散化。”



常用的引力函数：
$$
U 
att
​	
 (q)= 
1
/
2
​	
 ξρ 
2
 (q,q 
goal
​	
 )
$$
这里的 ξ 是尺度因子，
$$
ρ ( q , q g o a l )
	
 )
$$
表示物体当前状态与目标的距离。引力场有了，那么引力就是引力场对距离的导数（类比物理里面 W = F X W=FX W=FX）：

总结：这里uatt 就类似势能的东西  mgh 势能  f=mg； 对mgh 求导 则 得到F；

 			取负的原因是，这里Uatt 是下降的趋势 所以导数小于0.但这是引力。



$$
F 
att
	
 (q)=−∇U 
att
	
 (q)=ξ(q 
goal
	
 −q)
$$








斥力场

​	传统的斥力场公式
$$
U 
rep
​	
 (q)= 1/
2
​	
 η( 
ρ(q,q 
obs
​	
 )
1
​	
 − 
ρ 
0
​	
 
1
​	
 ) 
2
 ,
 
 
 ；；if ρ(q,q 
obs
​	
 )≤ρ 
0
​
$$
​	当超出障碍物影响半径p0 时 U为0；与引力场不同。这里越近，斥力越大。



​	斥力就是斥力场的**梯度**：即负导数



所以合力就是两个U相加的梯度。（带方向）

##### 二、存在的问题

（a） 当物体离目标点比较远时，引力将变的特别大，相对较小的斥力在甚至可以忽略的情况下，物体路径上可能会碰到障碍物
（b）当目标点附近有障碍物时，斥力将非常大，引力相对较小，物体很难到达目标点
（c）在某个点，引力和斥力刚好大小相等，方向想反，则物体容易陷入局部最优解或震荡

##### 三、解决方法

1对于可能会碰到障碍物的问题，可以通过修正引力函数来解决，避免由于离目标点太远导致引力过大

对引力场函数 加个范围 加个新函数

2目标点附近有障碍物导致目标不可达的问题，引入一种新的斥力函数.乘上距离的平方 距离越小 平方越小 减小斥力。

物体靠近目标时，虽然斥力场要增大，但是距离在减少，所以在一定程度上可以起到对斥力场的拖拽作用

斥力：所以可以看到这里引力分为两个部分，编程时要格外注意

梯度求导，复合函数求导。两个部分。

疑问：这时会不会导致 斥力不够 撞上呢。





#### matlab安装：

1.安装成功

2.阅览师兄matlab代码

#### pro：

1.安装成功

2.找到网课资源

[]: https://www.bilibili.com/video/BV1ut411S7j7?t=278&p=3

3.动手进行了视频合成

#### ros安装：

1.ros安装



2.还未使用。



### 零碎知识：

1. ADT(抽象数据类型)： 一旦定义了一个抽象数据类型及具体实现，程序设计中就可以像使用基本数据类型那样，十分方便地使用抽象数据类型。

2. ### 代码复用性：

   > 复用的好处：
   >
   > 1.较高的生产效率。（以及随之而来的成本降低）
   >
   > 2.较高的软件质量。（错误可以更快的被纠正）
   >
   > 3.恰当的使用复用可以改善系统的可维护性。

   因此我们要支持可维护性的复用，即在保持甚至提高系统的可维护性的同时，实现系统的复用。

   抽象层次应是较为稳定的，是复用的重点。**抽象层次的模块相对独立于具体层次**。这样具体层次内部的变化就不会影响到抽象层次，抽象层次的模块复用会较为容易。

   []: https://baike.baidu.com/item/%E5%A4%8D%E7%94%A8%E6%80%A7/12719815?fr=aladdin



### 关于大组作业知识盲点：

1. 二级指针

   

   ```c
    typedef struct LNode {
   	ElemType data;
   	struct LNode* next;
   } LNode, * LinkedList;//前面加* 代表这是个指针
   LinkedList *L；//二重指针 用于传递  
   Status InitList(LinkedList* L){}；//LinkedList* L 
       //值传递，
   ```

   

   ```c
   LinkedList L =NULL;//头尾指针
   LNode* pEnd = NULL;
   
   InitList(&L);
   
   //可以采用这种方法代替二级指针的使用
   ```

2. 参数传递

   

   ```c
   Status DeleteList(LNode* p, ElemType* e) {
   	LNode* pTemp = p->next;
   	*e = (pTemp->data);  //这里如果e = (pTemp->data);  则不改变 实参e  
   	p->next = pTemp->next;
   	free(pTemp);
   }
   ```

   

3. enum

   

   ```c
   typedef enum Status {
   	ERROR=0,//加了个0
   	SUCCESS
   } Status;
   ```

   学会使用

4. 反转链表

5. []: https://blog.csdn.net/qq_42351880/article/details/88637387?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161682729316780357228899%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&amp;request_id=161682729316780357228899&amp;biz_id=0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-88637387.first_rank_v2_pc_rank_v29&amp;utm_term=%E5%8F%8D%E8%BD%AC%E5%8D%95%E9%93%BE%E8%A1%A8

6. 函数指针  不太理解

   []: https://blog.csdn.net/viafcccy/article/details/102765886?ops_request_misc=&amp;request_id=&amp;biz_id=102&amp;utm_term=c%E8%AF%AD%E8%A8%80visit%E5%87%BD%E6%95%B0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-102765886.first_rank_v2_pc_rank_v29

7. 判断链表循环

   快慢指针法：这种方法的时间复杂度是O（n），空间复杂度是O（1）。且不会修改原来的链表。倘若不要求O（1）的空间复杂度，还有其他的解法

   []: https://blog.csdn.net/s674334235/article/details/90516334?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161683193716780262518772%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&amp;request_id=161683193716780262518772&amp;biz_id=0&amp;utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-90516334.first_rank_v2_pc_rank_v29&amp;utm_term=%E5%88%A4%E6%96%AD%E9%93%BE%E8%A1%A8%E5%BE%AA%E7%8E%AF

   快慢指针一定会相遇。

   首先两者要相遇，肯定是在那个环里面（比如最好情况慢的指针一踏入环就和快指针相遇）。

   然后我们要明确快慢指针的速度差为1，两者每移动一下，距离减1，而这个环的最小划分单位就是1，所以显然会相遇。

8. scanf函数对异常输入的处理：
   	封装成一个函数 

   ```c
   void SCANF(ElemType* e) {
   int ret;
   	ret = scanf("%d",e);
   	while (ret != 1)
   	{
   		while (getchar() != '\n');
   		//printf("||-->永远信任用户！\n");
   		printf("||-->请规范输入：");
   		ret = scanf("%d", e);
   	}
   }
   ```

   scanf读取方式:

![scanf](D:\nootbook\周记\scanf.png)

​				输入缓存：

​		（**fflush 操作输入流是对 C 标准的扩充**）。

​		（**fflush 操作输入流是对 C 标准的扩充**）。

 			**fflush**(stdin);使用格式

```c
include <stdio.h>
int main()
{
char c;
scanf("%c", &c);
printf("%d\n", c);
fflush(stdin); // 冲掉“马桶”中的无用值 去掉看作用
scanf("%c", &c);
printf("%d\n", c);

return 0;
}
```

​	9.异常捕获和处理：健壮性 控制流

1. 异常处理的核心思想是，把功能模块代码与系统中可能出现错误的处理代码分离开来，以此来达到使我们的代码组织起来更美观、逻辑上更清晰，并且同时从根本上来提高我们软件系统长时间稳定运行的可靠性。

2. goto语句另外一个最重要的作用就是，它实际上是一种对异常处理编程，最初也最原始的支持手段或方法。它能把错误处理模块的代码有效与其它代码分离开来。

3. 为什么不建议使用goto语句来实现异常处理编程 

   　　虽然goto 语句能有效地支持异常处理编程的实现。但是没有人却建议使用它，即便是在C语言中。因为： 
      　　（1） goto语句能破坏程序的结构化设计，使代码难于测试，且包含大量goto的代码模块不易理解和阅读。它一直遭结构化程序设计思想所抛弃，强烈建议程序员不易使用它； 
      　　（2） 与C++语言中提供的异常处理编程模型相比，它的确是太弱了一些。例如，它一般只能是在某个函数的局部作用域内跳转，也即它不能有效和方便地实现程序控制流的跨函数远程的跳转。 

      　　（3） 如果在C++语言中，用goto语句来实现异常处理，那么它将给面向对象构成极大破坏，并影响到效率。这一点，以后会继续深入阐述。

4. setjmp函数有何作用？ 
   　　前面刚说了，setjmp是C标准库中提供的一个函数，它的作用是保存程序当前运行的一些状态。它的函数原型如下： 
   int setjmp( jmp_buf env ); 

5. 　这是MSDN中对它的评论，如下： 
   　　setjmp函数用于保存程序的运行时的堆栈环境，接下来的其它地方，你可以通过调用longjmp函数来恢复先前被保存的程序堆栈环境。当setjmp和longjmp组合一起使用时，它们能提供一种在程序中实现“非本地局部跳转”（"non-local goto"）的机制。并且这种机制常常被用于来实现，把程序的控制流传递到错误处理模块之中；或者程序中不采用正常的返回（return）语句，或函数的正常调用等方法，而使程序能被恢复到先前的一个调用例程（也即函数）中。 
     　对setjmp函数的调用时，会保存程序当前的堆栈环境到env参数中；接下来调用longjmp时，会根据这个曾经保存的变量来恢复先前的环境，并且当前的程序控制流，会因此而返回到先前调用setjmp时的程序执行点。此时，在接下来的控制流的例程中，所能访问的所有的变量（除寄存器类型的变量以外），包含了longjmp函数调用时，所拥有的变量。 

6. 与goto语句不同，在C语言中，setjmp()与longjmp()的组合调用，为程序员提供了一种更优雅的异常处理机制。它具有如下特点： 
   　　 （1） goto只能实现本地跳转，而setjmp()与longjmp()的组合运用，能有效的实现程序控制流的非本地（远程）跳转； 
      　　 （2）与goto语句不同，setjmp()与longjmp()的组合运用，提供了真正意义上的异常处理机制。

7. setjmp与longjmp结合使用时，它们必须有严格的先后执行顺序，也即先调用setjmp函数，之后再调用longjmp函数，以恢复到先前被保存的“程序执行点”。否则，如果在setjmp调用之前，执行longjmp函数，将导致程序的执行流变的不可预测，很容易导致程序崩溃而退出。

8. **控制流：**C语言控制流主要是顺序，分支，循环。这三种方式基本上是语言学上必须提供的三种方式，还有一种特殊的方式是在函数层面，就是递归。

   本以为

   https://blog.csdn.net/yucan1001/article/details/7014277

10.全局变量管理与使用

在子文件声明全局变量

```c
extern i_count;
extern DuLNode* posNodeFront;
extern DuLNode* pEnd;
```

然后如果在main文件

```c
int i_count = 0; //计数
DuLNode* posNodeFront = NULL;
DuLinkedList head = NULL;
//DuLNode* pEnd = NULL;
int main()
{
    DuLNode* pEnd = NULL;  //放这里就报错
    int menu1 = 1;//菜单选项
    int num;
```

严重性	代码	说明	项目	文件	行	禁止显示状态
错误	LNK2001	无法解析的外部符号 _pEnd	Project1	D:\cnb\Project1\duLinkedList.obj	1	

严重性	代码	说明	项目	文件	行	禁止显示状态
错误	LNK1120	1 个无法解析的外部命令	Project1	D:\cnb\Project1\Debug\Project1.exe	1	



### git学习：

1. github提示：

   echo "# Q-G-" >> README.md
   git init
   1.git add README.md
   2.git commit -m "first commit"
   git branch -M main
   git remote add origin https://github.com/2429505174/Q-G-.git
   3.git push -u origin main

2. 

## 一周总结：



## 存在问题：



1. 1.这里的二重指针应用不熟练，会出现空指针报错等问题，有待探索完善。

   ```c
   typedef struct LNode {
   	ElemType data;
   	struct LNode* next;
   } LNode, * LinkedList;//前面加* 代表这是个指针
   LinkedList *L；//二重指针 用于传递  
   Status InitList(LinkedList* L){}；//LinkedList* L 
       //值传递，
   ```

   

2. 参数传递  

   ```c
   1. Status DeleteList(LNode* p, ElemType* e) {
      	LNode* pTemp = p->next;
      	*e = (pTemp->data);  //改变了e地址所存的值  但是 e = (pTemp->data)改变了e的地址 为什么不行呢？ 
      	p->next = pTemp->next;
      	free(pTemp);
      }
   
   ​	
   //感觉如果是int 型指针 或许可以改变  但这里我定义的是常量e 地址不能变
   	scanf("%d", &e);
   	//FindPre(L,Index);
   	SearchList(L, e);
   	DeleteList(Pre, &e);//删除pre下一个节点 并返回data
   	printf("删除节点内的data：%d\n", e);
   ```

   



## 下周规划：

1. python系统全面学习。
2. 全局变量优化，以及使用细节。
3. 机器学习数学公式推导，并记录笔记。
4. 爬虫环境配置

