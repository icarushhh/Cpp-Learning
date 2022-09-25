//
//  assign_overload.cpp
//  operator_overloading
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include "assign_overload.hpp"

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
    
    // 事实上没有必要,不定义也能直接用=赋值
      void operator=(const Distance &D )
      {
         feet = D.feet;
         inches = D.inches;
      }
    
    void operator+=(const Distance& D){
        feet += D.feet;
        inches += D.inches;
    }
    
      // 显示距离的方法
      void displayDistance()
      {
         cout << "F: " << feet <<  " I:" <<  inches << endl;
      }
      
};
int assign_overload_test()
{
   Distance D1(11, 10), D2(5, 11);
 
   cout << "First Distance : ";
   D1.displayDistance();
   cout << "Second Distance :";
   D2.displayDistance();
 
   // 使用赋值运算符
   D1 += D2;
   cout << "First Distance :";
   D1.displayDistance();
 
   return 0;
}
