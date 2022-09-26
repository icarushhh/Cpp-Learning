//
//  list_iterator.cpp
//  STL
//
//  Created by 朱仕哲 on 2022/9/26.
//
//  list 迭代器是循环的
//  list 的迭代操作和 vector 并无区别

#include "list_iterator.hpp"

#include<iostream>
#include<list>
#include <vector>
using namespace std;

int list_iterator_test(){

    list<int> myList;
    for (int i = 0; i < 10; i ++){
        myList.push_back(i);
    }

    list<int>::iterator node =  myList.begin();

    for (int i = 0; i < myList.size() * 2;i++){
        cout << "Node:" << *node << endl;
        node++;
        if (node == myList.begin()){
            node++;
        }
    }

    return EXIT_SUCCESS;
}

