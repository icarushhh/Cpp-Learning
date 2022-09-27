//
//  Traversal_test.cpp
//  algorithm_test
//
//  Created by 朱仕哲 on 2022/9/27.
//

#include "Traversal_test.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

/*
    遍历算法 遍历容器元素
    @param beg 开始迭代器
    @param end 结束迭代器
    @param _callback  函数回调或者函数对象
    @return 函数对象
*/
//for_each(iterator beg, iterator end, _callback);

/*
    transform算法 将指定容器区间元素搬运到另一容器中
    注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
    @param beg1 源容器开始迭代器
    @param end1 源容器结束迭代器
    @param beg2 目标容器开始迭代器
    @param _cakkback 回调函数或者函数对象
    @return 返回目标容器迭代器
*/
//transform(iterator beg1, iterator end1, iterator beg2, _callbakc)


//for_each:
/*

template<class _InIt,class _Fn1> inline
void for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
{
    for (; _First != _Last; ++_First)
        _Func(*_First);
}

*/

//普通函数
void print01(int val){
    cout << val << " ";
}

//函数对象
struct print001{
    void operator()(int val){
        cout << val << " ";
    }
};

//for_each算法基本用法
void for_each_test01(){
    
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }

    //遍历算法
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), print001());
    cout << endl;

}

struct print02{
    print02(){
        mCount = 0;
    }
    void operator()(int val){
        cout << val << " ";
        mCount++;
    }
    int mCount;
};

//for_each返回值: 仿函数对象
void for_each_test02(){

    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    print02 p = for_each(v.begin(), v.end(), print02());
    cout << endl;
    cout << p.mCount << endl;
}

struct print03 : public binary_function<int, int, void>{
    void operator()(int val,int bindParam) const{
        cout << val + bindParam << " ";
    }
};

//for_each绑定参数输出
void for_each_test03(){
    
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), bind(print03(), 100, placeholders::_1));
}


//transform:
//transform 将一个容器中的值搬运到另一个容器中
/*
    template<class _InIt, class _OutIt, class _Fn1> inline
    _OutIt _Transform(_InIt _First, _InIt _Last,_OutIt _Dest, _Fn1 _Func)
    {

        for (; _First != _Last; ++_First, ++_Dest)
            *_Dest = _Func(*_First);
        return (_Dest);
    }

    template<class _InIt1,class _InIt2,class _OutIt,class _Fn2> inline
    _OutIt _Transform(_InIt1 _First1, _InIt1 _Last1,_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
    {
        for (; _First1 != _Last1; ++_First1, ++_First2, ++_Dest)
            *_Dest = _Func(*_First1, *_First2);
        return (_Dest);
    }
*/

struct transformTest01{
    int operator()(int val){
        return val + 100;
    }
};

struct print04: public unary_function<int, void>{
    void operator()(int val){
        cout << val << " ";
    }
};

void transform_test01(){

    vector<int> vSource;
    for (int i = 0; i < 10;i ++){
        vSource.push_back(i + 1);
    }

    //目标容器
    vector<int> vTarget;
    //给vTarget开辟空间
    vTarget.resize(vSource.size());
    //将vSource中的元素搬运到vTarget
    vector<int>::iterator it = transform(vSource.begin(), vSource.end(), vTarget.begin(), transformTest01());
    //打印
    for_each(vTarget.begin(), vTarget.end(), print04());
    cout << endl;
    
}

//将容器1和容器2中的元素相加放入到第三个容器中
struct transformTest02: public binary_function<int, int, int>{
    int operator()(int v1,int v2){
        return v1 + v2;
    }
};

void transform_test02(){

    vector<int> vSource1;
    vector<int> vSource2;
    for (int i = 0; i < 10; i++){
        vSource1.push_back(i + 1);
    }

    //目标容器
    vector<int> vTarget;
    //给vTarget开辟空间
    vTarget.resize(vSource1.size());
    transform(vSource1.begin(), vSource1.end(), vSource2.begin(),vTarget.begin(), transformTest02());
    //打印
    for_each(vTarget.begin(), vTarget.end(), print04()); cout << endl;
}

