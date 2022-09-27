//
//  bind_test.cpp
//  algorithm_test
//
//  Created by 朱仕哲 on 2022/9/27.
//

#include "bind_test.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;


//函数适配器bind1st bind2nd
//现在我有这个需求 在遍历容器的时候，我希望将容器中的值全部加上100之后显示出来，怎么做？
//我们直接给函数对象绑定参数 编译阶段就会报错
//for_each(v.begin(), v.end(), bind2nd(myprint(),100));
//如果我们想使用绑定适配器,需要我们自己的函数对象继承binary_function 或者 unary_function
//根据我们函数对象是一元函数对象 还是二元函数对象

//但现在已经没有bind1st / bind2nd了，只有bind

class MyPrint :public binary_function<int,int,void>
{
public:
    void operator()(int v1,int v2) const
    {
        cout << "v1 = : " << v1 << " v2 = :" <<v2  << " v1+v2 = :" << (v1 + v2) << endl;
    }
};

//1、函数适配器
void bind_test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << "请输入起始值：" << endl;
    int x = 0;
    cin >> x;
    
    
    // 把bind返回的函数的第一个参数传递给MyPrint的第1个参数
//    for_each(v.begin(), v.end(), bind(MyPrint(), placeholders::_1, x));
    
    // 把bind返回的函数的第一个参数传递给MyPrint的第2个参数
    for_each(v.begin(), v.end(), bind(MyPrint(), x, placeholders::_1));
    
    // 这里不能用placeholder::_2 因为for_each函数只接受一元函数
}



class GreaterThenFive:public unary_function<int,bool>
{
public:
    bool operator ()(int v) const
    {
        return v > 5;
    }
};



//2、取反适配器
void bind_test02()
{
    vector <int> v;
    for (int i = 0; i < 10;i++)
    {
        v.push_back(i);
    }

//     vector<int>::iterator it =  find_if(v.begin(), v.end(), GreaterThenFive()); //返回第一个大于5的迭代器
//    vector<int>::iterator it = find_if(v.begin(), v.end(),  not1(GreaterThenFive())); //返回第一个小于5迭代器
    //自定义输入
    vector<int>::iterator it = find_if(v.begin(), v.end(), bind(greater<int>(), placeholders::_1, 5));
    if (it == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到" << *it << endl;
    }

    //排序  二元函数对象
    sort(v.begin(), v.end(), not2(less<int>()));
    for_each(v.begin(), v.end(), [](int val){cout << val << " "; });

}
//not1 对一元函数对象取反
//not2 对二元函数对象取反


void MyPrint03(int v,int v2)
{
    cout << v + v2<< " ";
}

//3、函数指针适配器   ptr_fun
void bind_test03()
{
    vector <int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // ptr_fun( )把一个普通的函数指针适配成函数对象
    // C11取消了这个函数，直接用函数名就行

    for_each(v.begin(), v.end(), bind( MyPrint03, placeholders::_1, 100));
}


//4、成员函数适配器
class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    //打印函数
    void ShowPerson(){
        cout << "成员函数:" << "Name:" << m_Name << " Age:" << m_Age << endl;
    }
    void Plus100()
    {
        m_Age += 100;
    }
public:
    string m_Name;
    int m_Age;
};

void MyPrint04(Person &p)
{
    cout << "姓名：" <<  p.m_Name << " 年龄：" << p.m_Age << endl;

};

//void test04()
//{
//    vector <Person>v;
//    Person p1("aaa", 10);
//    Person p2("bbb", 20);
//    Person p3("ccc", 30);
//    Person p4("ddd", 40);
//    v.push_back(p1);
//    v.push_back(p2);
//    v.push_back(p3);
//    v.push_back(p4);
//
//    //for_each(v.begin(), v.end(), MyPrint04);
//    //利用 mem_fun_ref 将Person内部成员函数适配
//    for_each(v.begin(), v.end(), mem_fun_ref(&Person::ShowPerson));
////     for_each(v.begin(), v.end(), mem_fun_ref(&Person::Plus100));
////     for_each(v.begin(), v.end(), mem_fun_ref(&Person::ShowPerson));
//}
//
void bind_test05(){

    vector<Person*> v1;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);
    v1.push_back(&p4);

    for_each(v1.begin(), v1.end(), mem_fn(&Person::ShowPerson));
}

//如果容器存放的是对象指针，  那么用mem_fun     C17是 mem_fn
//如果容器中存放的是对象实体，那么用mem_fun_ref      C17 removed

