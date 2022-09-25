//
//  operator_io_overload.cpp
//  operator_overloading
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include "operator_io_overload.hpp"

#include <iostream>
using namespace std;
 
class Distance
{
   private:
      int feet;             // 0 到无穷
      int inches;           // 0 到 12
   public:
      // 所需的构造函数
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
    
    // 这里定义friend函数而不是成员函数的原因：
    // 如果定义为成员函数，就不能把自身放进参数列表。参数顺序是 D << cout,就很奇怪
    // 但是定义成friend函数，就相当于类外的函数，就可以把自身放进参数列表，然后自定义参数顺序
    // 实现成cout << D
    // friend函数事实上是类外的函数
      friend ostream &operator<<( ostream &output,
                                       const Distance &D )
      {
         output << "F : " << D.feet << " I : " << D.inches;
         return output;
      }
 
      friend istream &operator>>( istream  &input, Distance &D )
      {
         input >> D.feet >> D.inches;
         return input;
      }
};

int operator_io_test()
{
   Distance D1(11, 10), D2(5, 11), D3;
 
   cout << "Enter the value of object : " << endl;
   cin >> D3;
   cout << "First Distance : " << D1 << endl;
   cout << "Second Distance :" << D2 << endl;
   cout << "Third Distance :" << D3 << endl;
 
 
   return 0;
}
