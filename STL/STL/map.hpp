//
//  map.h
//  STL
//
//  Created by 朱仕哲 on 2022/9/27.
//
//  Map所有的元素都是pair,同时拥有实值和键值，pair的第一元素被视为键值，第二元素被视为实值，map不允许两个元素有相同的键值。
//  Map的特性是，所有元素都会根据元素的键值自动排序。
//  我们不可以通过map的迭代器改变map的键值,如果想要修改元素的实值，那么是可以的。
//  Multimap和map的操作类似，唯一区别multimap键值可重复。

//  map的使用场景：比如按ID号存储十万个用户，想要快速要通过ID查找对应的用户。二叉树的查找效率，这时就体现出来了。
//  如果是vector容器，最坏的情况下可能要遍历完整个容器才能找到该用户。

#include <map>

//  map构造函数
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数

//  map赋值操作
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器

//  map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

//  map插入数据元素操作
map.insert(); //往容器插入元素，返回pair<iterator,bool>

map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";

//  map删除操作
clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);//删除容器中key为keyElem的对组。

//  map查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。



