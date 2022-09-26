//
//  stack.hpp
//  STL
//
//  Created by 朱仕哲 on 2022/9/26.
//
//  Stack所有元素的进出都必须符合”先进后出”的条件，只有stack顶端的元素，才有机会被外界取用。Stack不提供遍历功能，也不提供迭代器。

//stack构造函数

#include <stack>

stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
stack(const stack &stk);//拷贝构造函数

//stack赋值操作

stack& operator=(const stack &stk);//重载等号操作符

//stack数据存取操作

push(elem);//向栈顶添加元素
pop();//从栈顶移除第一个元素
top();//返回栈顶元素

//stack大小操作

empty();//判断堆栈是否为空
size();//返回堆栈的大小
