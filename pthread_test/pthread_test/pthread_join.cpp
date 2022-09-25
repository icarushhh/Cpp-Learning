//
//  pthread_join.cpp
//  pthread_test
//
//  Created by 朱仕哲 on 2022/9/25.
//
// 当A线程调用线程B并 pthread_join() 时，A线程会处于阻塞状态，直到B线程结束后，A线程才会继续执行下去。

#include "pthread_join.hpp"

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
 
using namespace std;
 
#define NUM_THREADS     5
 
void *wait(void *t)
{
   int* tid;
 
   tid = (int *)t;
 
//   sleep(1);
   cout << "Sleeping in thread " << endl;
   cout << "Thread with id : " << *tid << "  ...exiting " << endl;
   pthread_exit(NULL);
}
 
int pthread_join_test()
{
   int rc;
   int i;
   pthread_t threads[NUM_THREADS];
    
   pthread_attr_t attr;
   void *status;
 
   // 初始化并设置线程为可连接的（joinable）
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
   for( i=0; i < NUM_THREADS; i++ ){
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, wait, (void *)&i );
       
       // 创建失败
       if (rc){
          cout << "Error:unable to create thread," << rc << endl;
          exit(-1);
       }
       
       // 等待线程结束
       rc = pthread_join(threads[i], &status);
       
       // join 失败
       if (rc){
          cout << "Error:unable to join thread," << rc << endl;
          exit(-1);
       }
       
      
   }
 
   // 删除属性
   pthread_attr_destroy(&attr);
    
   cout << "Main: program exiting." << endl;
    
   pthread_exit(NULL);
}
