//
//  minus_overload.cpp
//  operator_overloading
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include "minus_overload.hpp"

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
      // 显示距离的方法
      void displayDistance()
      {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      // 重载负运算符（ - ）
      Distance operator- ()
      {
         feet = -feet;
         inches = -inches;
//         return Distance(feet, inches);
          return *this;
      // 两种return等价
      }
};

int minus_overload_test()
{
    Distance D1(11, 10), D2;
    D2 = Distance(-5,11);           // 这种初始化方法也可以，相当于拷贝构造函数
 
   D2 = -D1;                 // D1取相反数且赋值给D2
   D1.displayDistance();    // 距离 D1
 
   -D2;                     // 取相反数
   D2.displayDistance();    // 距离 D2
 
   return 0;
}
