//
//  sort.hpp
//  algorithm_test
//
//  Created by 朱仕哲 on 2022/9/28.
//

#include <algorithm>

/*
    merge算法 容器元素合并，并存储到另一容器中
    @param beg1 容器1开始迭代器
    @param end1 容器1结束迭代器
    @param beg2 容器2开始迭代器
    @param end2 容器2结束迭代器
    @param dest  目标容器开始迭代器
    @param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
// merge 两个有序序列后，目标容器也有序，否则会混乱
// 两个序列升序，则_callback填写 less<T>()
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest, _callback)

/*
    sort算法 容器元素排序
    注意:两个容器必须是有序的
    @param beg 容器1开始迭代器
    @param end 容器1结束迭代器
    @param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
sort(iterator beg, iterator end, _callback)

/*
    sort算法 对指定范围内的元素随机调整次序
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
*/
random_shuffle(iterator beg, iterator end)
//  C17貌似没有了
//  用如下两行代替
//  random_device rd;
//  shuffle(iterator beg, iterator end, rd);

/*
    reverse算法 反转指定范围的元素
    @param beg 容器开始迭代器
    @param end 容器结束迭代器
*/
reverse(iterator beg, iterator end)

