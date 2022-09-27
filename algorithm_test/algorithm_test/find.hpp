//
//  find.hpp
//  algorithm_test
//
//  Created by 朱仕哲 on 2022/9/28.
//
//

#include <algorithm>

/*
    find算法 查找元素
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
    @param value 查找的元素
    @return 返回查找元素的位置
*/
find(iterator beg, iterator end, value)

/*
    find_if算法 条件查找
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
    @param  callback 回调函数或者谓词(返回bool类型的函数对象)
    @return 返回查找元素的位置(迭代器)
*/
find_if(iterator beg, iterator end, _callback);

/*
    adjacent_find算法 查找相邻重复元素
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
    @param  _callback 回调函数或者谓词(返回bool类型的函数对象)
    @return 返回相邻元素的第一个位置的迭代器
*/
adjacent_find(iterator beg, iterator end, _callback);

/*
    binary_search算法 二分查找法
    注意: 在无序序列中不可用
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
    @param value 查找的元素
    @return bool 查找返回true 否则false
*/
bool binary_search(iterator beg, iterator end, value);

/*
    count算法 统计元素出现次数
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
    @param  value回调函数或者谓词(返回bool类型的函数对象)
    @return int返回元素个数
*/
count(iterator beg, iterator end, value);

/*
    count算法 统计元素出现次数
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
    @param  callback 回调函数或者谓词(返回bool类型的函数对象)
    @return int返回元素个数
*/
count_if(iterator beg, iterator end, _callback);



