//
//  set_test.cpp
//  STL
//
//  Created by 朱仕哲 on 2022/9/27.
//

#include "set_test.hpp"
#include <iostream>
#include <set>

using namespace std;

//插入操作返回值
void set_test01(){

    set<int> s;
    pair<set<int>::iterator,bool> ret = s.insert(10);       // s.insert(elm) 的返回值格式
    
    if (ret.second){
        cout << "插入成功:" << *ret.first << endl;
    }
    else{
        cout << "插入失败:" << *ret.first << endl;
    }
    
    ret = s.insert(10);                                     // 插入失败，因为键值不能重复
    
    if(ret.second){
        cout << "插入成功:" << *ret.first << endl;
    }
    else{
        cout << "插入失败:" << *ret.first << endl;
    }

}

// 自定义比较函数
struct MyCompare02{
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};

//set从大到小
void set_test02(){

    srand((unsigned int)time(NULL));
    
    //我们发现set容器的第二个模板参数可以设置排序规则，默认规则是less<_Kty>
    set<int, MyCompare02> s;
    for (int i = 0; i < 10;i++){
        s.insert(rand() % 100);
    }
    
    for (set<int, MyCompare02>::iterator it = s.begin(); it != s.end(); it ++){
        cout << *it << " ";
    }
    cout << endl;
}

//set容器中存放对象
class Person{
public:
    Person(string name,int age){
        this->mName = name;
        this->mAge = age;
    }
public:
    string mName;
    int mAge;
};


struct MyCompare03{
    bool operator()(const Person& p1,const Person& p2){
        return p1.mAge > p2.mAge;
    }
};

void set_test03(){

    set<Person, MyCompare03> s;

    Person p1("aaa", 20);
    Person p2("bbb", 30);
    Person p3("ccc", 40);
    Person p4("ddd", 50);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, MyCompare03>::iterator it = s.begin(); it != s.end(); it++){
        cout << "Name:" << it->mName << " Age:" << it->mAge << endl;
    }

}

