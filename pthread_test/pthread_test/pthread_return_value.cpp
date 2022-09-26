//
//  pthread_return_value.cpp
//  pthread_test
//
//  Created by 朱仕哲 on 2022/9/26.
//
// 用phread_exit(void* ret)返回参数

#include "pthread_return_value.hpp"

#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* thread_task(void* thread_args){
    
    int input = *(int*)thread_args;
    int* output = new int;          // 用pthread_exit返回的指针一定要new分配内存，否则线程结束后释放内存
    
    *output = (rand()%10 + 1) * input;
//    sleep(5);
    
    *(int*)thread_args = 1000;      // 用指针改变调用函数中的参数
    
    pthread_exit((void*)output);           // 用pthread_exit向调用函数返回参数
}

int pthread_return_value(void){
    pthread_t tid;
    int* output = 0;
    int input = 100;
    
    pthread_create(&tid, NULL, thread_task, (void*)&input);
    pthread_join(tid, (void**)&output);         // 用 int** output 来接受返回值
    
    cout << "changed input: " << input << endl;
    cout << "output: " << *output << endl;
    
    delete output;                  // 释放线程中分配的内存
    pthread_exit(NULL);
    
    return 0;
}
