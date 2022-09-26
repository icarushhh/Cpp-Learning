//
//  queue.hpp
//  STL
//
//  Created by 朱仕哲 on 2022/9/26.
//
//  Queue所有元素的进出都必须符合”先进先出”的条件，只有queue的顶端元素，才有机会被外界取用。Queue不提供遍历功能，也不提供迭代器。

//queue构造函数

#include <queue>

queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue &que);//拷贝构造函数

//queue存取、插入和删除操作

push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素

//queue赋值操作

queue& operator=(const queue &que);//重载等号操作符

//queue大小操作

empty();//判断队列是否为空
size();//返回队列的大小


