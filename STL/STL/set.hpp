//
//  set.hpp
//  STL
//
//  Created by 朱仕哲 on 2022/9/27.
//
//  Set的特性是。所有元素都会根据元素的键值自动被排序。
//  set的元素即是键值又是实值。Set不允许两个元素有相同的键值。
//  我们不可以通过set的迭代器改变set元素的值.如果任意改变set元素值，会严重破坏set组织。
//
//  multiset特性及用法和set完全相同，唯一的差别在于它允许键值重复。set和multiset的底层实现是红黑树.

#include <set>

//  set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数

//  set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器

//  set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

//  set插入和删除操作
insert(elem);//在容器中插入元素。返回pair<iterator,bool>
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。

//  set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。


