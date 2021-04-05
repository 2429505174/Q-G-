# QG训练营xx组第二周周记：

2021年4月x日

## 生活随记

博客：http://www.ruanyifeng.com/blog/2021/04/weekly-issue-152.html

[持续学习]: https://junglecoder.com/blog/learning-without-burnout

**但是，这个故事真正打动我的地方，不是他选择哪一条道路，而是他敢于去选择，不跟现状妥协。** 那一种自己把握命运的主动性和勇气，我不能这样过下去，这不是我要的路，我必须改变人生的方向，然后毅然决然付诸行动。

著名的美国科幻小说作家罗伯特·海因莱因（Robert A. Heinlein），给有志于写作的年轻人，传授过五条写作规则，帮助他们入门。

我觉得这些规则，不仅适用于作家，也同样适用于程序员。

**规则一：你必须动手写**

听起来很明显，是吗？但是，很多人只是想想而已，并没有真的动手写任何东西。成为作家的唯一途径是将自己放在键盘前，开始工作。

**规则二：完成草稿**

你开始写的前几页，可能很糟糕，你可能会想将它们扔掉。不要这样做，继续下去把草稿写完。一旦有了初稿，包括开头、中间和结尾，你会惊讶地发现，哪些是有用的部分，哪些是没用的部分。

**规则三：不要无休止地修改**

你应该不断修改你的草稿，但是一旦发现，修改后的效果没有比原来有太大的提升，就应该结束修改了。有句老话说，故事永远不会结束，只会被放弃。你要学习到了某个点，不再对这个作品投入时间。

**规则四：你必须将作品推向市场**

写完之后，放在书桌上是没有用的。即使你对自己没有信心，也应该把作品发布出去，看看外界的反应。不要胆怯，没有发表过的作品，等于没有写。

**规则五：你必须努力推广作品，直到售出为止**

一个事实是，你的作品几乎肯定会被拒绝，最大的可能是根本没有反响。不要为这种事情烦恼，很多伟大的作家都收过很多拒稿信。如果那些拒绝当中包含你认为不错的建议，请修改你的作品，然后再次发布。如果得不到什么建议，那就转向其他市场发布。你要坚持让更多的人看到你的作品。

最后，不管上一部作品得到什么样的成绩，你开始准备下一部作品。

取舍要学的东西

随着时间的推移保持学习速度

随着时间的推移保持学习速度

尝试找到乐趣，以及一个可持续的长期动机。寻找权衡，而不是教条。使用二进制搜索调试。倾听你的身体，对自己诚实

### PYTHON学习：



### 

#### python基础：

> 编码格式
>
> !/usr/bin/env python3
>
> -*- coding: utf-8 -*

1.  format()格式化输出

2. `f`开头的字符串，称之为`f-string`#自动代替变量

   

   1. #### 数据类型：

      list是一个可变的有序表

      list里面的元素的数据类型也可以不同

      list append insert pop

      只有1个元素的tuple定义时必须加一个逗号`,`，

      Python内置了字典：dict的支持，dict全称dictionary，在其他语言中也称为map，使用键-值（key-value）存储，具有极快的查找速度。

      需要牢记的第一条就是dict的key必须是**不可变对象**。

      set add remove 

      字符串是不可变的 replace 对字符串操作，返回新的字符串，但是不改变原字符串。

       isinstance  数据类型检查可以用内置函数`isinstance()`

      在语法上，返回一个tuple可以省略括号，而多个变量可以同时接收一个tuple，按位置赋给对应的值

      函数可以同时返回多个值，但其实就是一个tuple。

   2. ### 函数：

      ```python
      def calc(*numbers):#这里* 代表可以传入多个可变参数  无* 只能穿一个tuple or list and。。。
          sum = 0
          for n in numbers:
              sum = sum + n * n
          return sum
      num=(1,2,3,4)
      calc(*num) #这里* 可以将元祖变成多个可变参数传入
      ```

      

   3. 

   4. 




### 大组作业：

1. 链栈头指针问题 

   初始化 申请空间为链栈头指针 

   > 若这样：
   >
   > ```c
   > LinkStackPtr stack;//= (LinkStackPtr)malloc(sizeof(StackNode)); 
   > 
   > ```
   >
   > 严重性	代码	说明	项目	文件	行	禁止显示状态
   > 错误	C4700	使用了未初始化的局部变量“stack”	栈	D:\cnb\栈\LinkStack.c	68	
   >
   > 若这样：
   >
   > ```c
   > //LinkStackPtr stack= (LinkStackPtr)malloc(sizeof(StackNode));
   > ```
   >
   > 则初始化不成功。内存总是被释放。

2. 针对师兄提出的健壮性解答**

> **一亿：**
>
> typedef int ElemType; 改动int 为 longlong int 
>
> **1a 1aa  1， ：**
>
> ```c
>    
> if (ret == 1) {
>         ch = getchar();
>         if (ch == ' ' || ch == '\n') {
>             
>         }
>     else {
>         printf("||-->输入有异常!\n");
>         while (getchar() != '\n');
>         printf("||-->是否忽略(Y):");
>         scanf("%c", &ch);
>         if (ch == 'Y')
>         {
>                          //选择忽略后面的异常字符
>         }
>         else {
>             ret = 0;  //重新循环 
> 
>         }
>     }
> ```
> 加入这串代码 用选择是否忽略错误输入来解决问题。

## 一周总结



## 存在问题

 isinstance  这个函数的学习



```python
def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x
```

如果 *classinfo* 是类型对象元组（或由其他此类元组递归组成的元组），那么如果 *object* 是其中任何一个类型的实例就返回 `True`。 如果 *classinfo* 既不是类型，也不是类型元组或类型元组的元组，则将引发 [`TypeError`](https://docs.python.org/zh-cn/3/library/exceptions.html#TypeError) 异常。

解决！！！



## 下周规划

