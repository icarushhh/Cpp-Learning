//
//  operater+_overload.cpp
//  operator_overloading
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include "operator_plus_overload.hpp"

#include <iostream>
using namespace std;
 
class Box
{
   public:
 
      double getVolume(void)
      {
         return length * breadth * height;
      }
      void setLength( double len )
      {
          length = len;
      }
 
      void setBreadth( double bre )
      {
          breadth = bre;
      }
 
      void setHeight( double hei )
      {
          height = hei;
      }
    
      // 重载 + 运算符，用于把两个 Box 对象相加
      // 在类内随便访问private变量
      // 包括在类外用 box：：声明作用域的函数
//      Box operator+(const Box& b)
//      {
//         Box box;
//         box.length = this->length + b.length;
//         box.breadth = this->breadth + b.breadth;
//         box.height = this->height + b.height;
//         return box;
//      }
    
    friend Box operator+(Box& box1, Box& box2);
    
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};

// 在类外定义运算符重载函数，无法直接访问private变量，只能声明为友元函数访问private变量。
Box operator+(Box& box1, Box& box2){
    Box temp;
    temp.length = box1.length + box2.length;
    temp.breadth = box1.breadth + box2.breadth;
    temp.height = box1.height + box2.height;
    
    return temp;
}

// 程序的主函数
int operator_plus_test( )
{
   Box Box1;                // 声明 Box1，类型为 Box
   Box Box2;                // 声明 Box2，类型为 Box
   Box Box3;                // 声明 Box3，类型为 Box
   double volume = 0.0;     // 把体积存储在该变量中
 
   // Box1 详述
   Box1.setLength(6.0);
   Box1.setBreadth(7.0);
   Box1.setHeight(5.0);
 
   // Box2 详述
   Box2.setLength(12.0);
   Box2.setBreadth(13.0);
   Box2.setHeight(10.0);
 
   // Box1 的体积
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // Box2 的体积
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
 
   // 把两个对象相加，得到 Box3
   Box3 = Box1 + Box2;
   //用一个Box实例对另一个Box实例赋值，实际上调用了拷贝构造函数
    //虽然没有显式定义，但编译器自己会定义
 
   // Box3 的体积
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
 
   return 0;
}
