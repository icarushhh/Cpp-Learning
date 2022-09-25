//
//  main.cpp
//  abstract_class
//
//  Created by 朱仕哲 on 2022/9/25.
//
// 设计抽象类（通常称为ABC）的目的，是为了给其他类提供一个可以继承的适当的基类。抽象类不能被用于实例化对象，它只能作为接口使用。如果试图实例化一个抽象类的对象，会导致编译错误。
//因此，如果一个 ABC 的子类需要被实例化，则必须实现每个虚函数

#include <iostream>
 
using namespace std;
 
// 基类
class Shape
{
public:
   // 提供接口框架的纯虚函数
   virtual int getArea() = 0;
   void setWidth(int w)
   {
      width = w;
   }
   void setHeight(int h)
   {
      height = h;
   }
protected:
   int width;
   int height;
};
 
// 派生类
class Rectangle: public Shape
{
public:
    // 多态，虚函数实现
   int getArea()
   {
      return (width * height);
   }
};

class Triangle: public Shape
{
public:
   int getArea()
   {
      return (width * height)/2;
   }
};
 
int main(void)
{
   Rectangle Rect;
   Triangle  Tri;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
   // 输出对象的面积
   cout << "Total Rectangle area: " << Rect.getArea() << endl;
 
   Tri.setWidth(5);
   Tri.setHeight(7);
   // 输出对象的面积
   cout << "Total Triangle area: " << Tri.getArea() << endl;
 
   return 0;
}
