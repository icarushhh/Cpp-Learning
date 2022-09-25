//
//  pthread_more_args.cpp
//  pthread_test
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include "pthread_more_args.hpp"

#include <iostream>
#include <cstdlib>
#include <pthread.h>
 
using namespace std;
 
#define NUM_THREADS     5
 
// 用来传参数的结构体定义
struct thread_data{
   int  thread_id;
   char* message;
};
 
void* PrintHello2(void* threadarg)
{
   struct thread_data* my_data;
 
   my_data = (struct thread_data*) threadarg;
 
   cout << "Thread ID : " << my_data->thread_id ;
   cout << " Message : " << my_data->message << endl;
 
   pthread_exit(NULL);
}
 
int pthread_more_args_test()
{
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];          // 传参结构体数组
   int rc;
   int i;
 
   for( i=0; i < NUM_THREADS; i++ ){
      cout <<"main() : creating thread, " << i << endl;
       
      td[i].thread_id = i;
      td[i].message = (char*)"This is a message";
       
      rc = pthread_create(&threads[i], NULL, PrintHello2, (void*)&td[i]);
       
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
    
   pthread_exit(NULL);
}
