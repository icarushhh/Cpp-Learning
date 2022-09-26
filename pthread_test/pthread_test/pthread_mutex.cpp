//
//  pthread_mutex.cpp
//  pthread_test
//
//  Created by 朱仕哲 on 2022/9/26.
//
//  int pthread_mutex_init(pthread_mutex_t *restrict mutex,const pthread_mutexattr_t *restrict attr);
//  int pthread_mutex_destory(pthread_mutex_t *mutex );
//  int pthread_mutex_lock(pthread_mutex_t *mutex);
//  int pthread_mutex_trylock(pthread_mutex_t *mutex);
//  int pthread_mutex_unlock(pthread_mutex_t *mutex);



#include "pthread_mutex.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t g_mutex;                    // mutex 变量
int g_lock_var = 0;

void* thread1( void *arg )
{
    int ret;
    time_t end_time;
    end_time = time(NULL) + 10;
    
    while( time(NULL) < end_time ) {
        
        ret = pthread_mutex_trylock( &g_mutex );            // try_lock, 若失败则返回 EBUSY，线程不会被阻塞
        
        if( EBUSY == ret ) {
            printf( "thread1: the varible is locked by thread2.\n" );
        }
        else {
            printf( "thread1: lock the variable!\n" );
            ++g_lock_var;
            pthread_mutex_unlock( &g_mutex );
        }
        sleep(1);
    }
    
    pthread_exit(NULL);
}

void* thread2( void *arg )
{
    time_t end_time;
    end_time = time(NULL) + 10;
    
    while( time(NULL) < end_time ) {
        
        pthread_mutex_lock( &g_mutex );             // lock，若已经加锁，则此进程被阻塞，直到锁被释放
        
        printf( "thread2: lock the variable!\n" );
        ++g_lock_var;
        sleep(1);
        pthread_mutex_unlock( &g_mutex );
    }
    
    pthread_exit(NULL);
}

int mutex_test()
{
    pthread_t pth1,pth2;
    
    pthread_mutex_init( &g_mutex, NULL );               // mutex init, 第二个参数是属性设置，一般填NULL
    
    pthread_create( &pth1, NULL, thread1, NULL );
    pthread_create( &pth2, NULL, thread2, NULL );
    pthread_join( pth1, NULL );
    pthread_join( pth2, NULL );
    
    pthread_mutex_destroy( &g_mutex );                  // 删除 mutex
    
    printf( "g_lock_var = %d\n", g_lock_var );
    
    pthread_exit(NULL);
    return 0;
}

