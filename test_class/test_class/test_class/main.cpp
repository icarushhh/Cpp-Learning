//
//  main.cpp
//  test_class
//
//  Created by 朱仕哲 on 2022/9/22.
//
// 拷贝构造函数：当定义一个新对象并用一个同类型的对象对它进行初始化时，将显示使用拷贝构造函数。当该类型的对象传递给函数或从函数返回该类型的对象时，将隐式调用拷贝构造函数。


#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      int getLength( void );
      Line( int len );             // 简单的构造函数
      Line( const Line &obj);      // 拷贝构造函数
      ~Line();                     // 析构函数
 
   private:
      int *ptr;
};
 
// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
 
Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}
 
Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}
 
void display(Line obj)
{
   cout << "line 大小 : " << obj.getLength() <<endl;
}
 
// 程序的主函数
int main( )
{
   Line line1(10);
    
   Line line2(line1); // 这里也调用了拷贝构造函数
//   Line line2 = line1; // the same result
    
   display(line1);
   display(line2);
    
 
   return 0;
}
