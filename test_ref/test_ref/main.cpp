//
//  main.cpp
//  TEST
//
//  Created by 朱仕哲 on 2022/9/20.
//

#include <iostream>
using namespace std;

extern int f;
extern int printa();
 
// 函数声明
void swap_ref(int& x, int& y);
void swap_ptr(int* x, int* y);
int& change_value(int& a);
 
int main ()
{
   // 局部变量声明
    int a = 100;
    int b = 200;
    change_value(b) = 150;
 
    cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;
 
   /* 调用函数来交换值 */
   swap_ref(a, b);
 
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
   
   swap_ptr(&a, &b);
  
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
  
    
   return 0;
}
 
// 函数定义
void swap_ref(int& x, int& y)
{
   int temp;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
   return;
}

void swap_ptr(int *x, int *y)
{
   int temp;
   temp = *x; /* 保存地址 x 的值 */
   *x = *y;    /* 把 y 赋值给 x */
   *y = temp; /* 把 x 赋值给 y  */
   return;
}

int& change_value(int& a){
    int& r = a;
    return r;
}
