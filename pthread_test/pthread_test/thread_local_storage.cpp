//
//  thread_local_storage.cpp
//  pthread_test
//
//  Created by 朱仕哲 on 2022/9/26.
//
//  int pthread_key_create(pthread_key_t *key, void (*destructor)(void*));
//  int pthread_key_delete(pthread_key_t key);
//  void* pthread_getspecific(pthread_key_t key);
//  int pthread_setspecific(pthread_key_t key, const void *value);
//
//不论哪个线程调用了 pthread_key_create()，所创建的 key 都是所有线程可以访问的，但各个线程可以根据自己的需要往 key 中填入不同的值，相当于提供了一个同名而不同值的全局变量



#include "thread_local_storage.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define THREAD_COUNT 2

using namespace std;

pthread_key_t g_key;                // 定义线程本地存储区的id，全局变量，所有线程均能访问

typedef struct thread_data{
    int thread_no;
} thread_data_t;                    // thread arg 结构体

void show_thread_data()
{
    // pthread_getspecific() 函数从本地存储区读取数据
    thread_data_t *data = (thread_data_t*)pthread_getspecific( g_key );
    printf( "Thread %d \n", data->thread_no );
}

void* thread( void *arg )
{
    thread_data_t *data = (thread_data_t *)arg;
    printf( "Start thread %d\n", data->thread_no );
    pthread_setspecific( g_key, (void*)data );      //pthread_setspecific()函数向本地存储区写入数据
    
    if (data->thread_no == 0) {
        sleep(5);
        cout << "\nthread 0 awake\n" << endl;
    }
    
    show_thread_data();
    printf( "Thread %d exit\n", data->thread_no );
    
    pthread_exit(NULL);
}

void free_thread_data( void *arg )
{
    thread_data_t *data = (thread_data_t*)arg;
    printf( "Free thread %d data\n", data->thread_no );
    free( data );
}

int thread_local_storage_test()
{
    int i;
    pthread_t pth[THREAD_COUNT];
    thread_data_t *data = NULL;
    
    pthread_key_create( &g_key, free_thread_data);     // 创建本地存储区，第二个参数是析构函数
    
    for( i = 0; i < THREAD_COUNT; ++i ) {
        data = (thread_data_t*) malloc( sizeof( thread_data_t ) );
        data->thread_no = i;
        pthread_create( &pth[i], NULL, ::thread, data );
    }
    
    for( i = 0; i < THREAD_COUNT; ++i ){
        pthread_join( pth[i], NULL );
    }
    
    pthread_key_delete( g_key );
    
    return 0;
}

