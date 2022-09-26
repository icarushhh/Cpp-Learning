//
//  condition_variable.cpp
//  pthread_test
//
//  Created by 朱仕哲 on 2022/9/26.
//
//  int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
//  int pthread_cond_destory(pthread_cond_t *cond);
//  int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
//  int pthread_cond_timedwait(pthread_cond_t *cond,pthread_mutex_t *mutex, const timespec *abstime);   // 有限时间等待
//  int pthread_cond_signal(pthread_cond_t *cond);
//  int pthread_cond_broadcast(pthread_cond_t *cond);


#include "condition_variable.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define BUFFER_SIZE 5

extern pthread_mutex_t g_mutex;
pthread_cond_t g_cond;

typedef struct{
    char buf[BUFFER_SIZE];
    int count;
} buffer_t;

buffer_t g_share = {"", 0};
char g_ch = 'A';

void* producer( void *arg ){
    
    sleep(2);                                           // 防止producer先抢占mutex，否则先signal，consumer永远等不到
    printf( "Producer starting.\n" );
    
    while( g_ch != 'Z' ) {
        pthread_mutex_lock( &g_mutex );
        
        if( g_share.count < BUFFER_SIZE ) {
            g_share.buf[g_share.count++] = g_ch++;
            printf( "Prodcuer got char[%c]\n", g_ch - 1 );
            
            if( BUFFER_SIZE == g_share.count ) {
                printf( "Producer signaling full.\n" );
                pthread_cond_signal( &g_cond );        // signal只通知一个线程，broadcast通知所有进程
                                                        // 经测试，consumer1 和 consumer2 轮流来
//                pthread_cond_broadcast(&g_cond);        // broadcast 也是轮流来
            }
        }
        pthread_mutex_unlock( &g_mutex );
    }
    printf( "Producer exit.\n" );
    return NULL;
}

void* consumer1( void *arg ){
    int i;
    printf( "consumer1 starting.\n" );
    
    while( g_ch != 'Z' ) {
        pthread_mutex_lock( &g_mutex );
        
        printf( "consumer1 waiting\n" );
        pthread_cond_wait( &g_cond, &g_mutex);          // wait函数将mutex解锁后等待，等到signal后重新加锁，继续执行
        
        printf( "consumer1 writing buffer\n" );
        
        for( i = 0; g_share.buf[i] && g_share.count; ++i ) {
            putchar( g_share.buf[i] );
            --g_share.count;
        }
        putchar('\n');
        pthread_mutex_unlock( &g_mutex );
    }
    printf( "consumer1 exit.\n" );
    return NULL;
}

void* consumer2( void *arg ){
    int i;
    printf( "consumer2 starting.\n" );
    
    while( g_ch != 'Z' ) {
        pthread_mutex_lock( &g_mutex );
        
        printf( "consumer2 waiting\n" );
        pthread_cond_wait( &g_cond, &g_mutex);          // wait函数将mutex解锁后等待，等到signal后重新加锁，继续执行
        
        printf( "consumer2 writing buffer\n" );
        
        for( i = 0; g_share.buf[i] && g_share.count; ++i ) {
            putchar( g_share.buf[i] );
            --g_share.count;
        }
        putchar('\n');
        pthread_mutex_unlock( &g_mutex );
    }
    printf( "consumer2 exit.\n" );
    return NULL;
}

int condition_variable(){
    pthread_t ppth, cpth1, cpth2;
    
    pthread_mutex_init( &g_mutex, NULL );
    pthread_cond_init( &g_cond, NULL );
    
    pthread_create( &cpth1, NULL, consumer1, NULL );
    pthread_create( &cpth2, NULL, consumer2, NULL );
    pthread_create( &ppth, NULL, producer, NULL );
    pthread_join( ppth, NULL );
    pthread_join( cpth1, NULL );
    pthread_join( cpth2, NULL );
    
    
    pthread_mutex_destroy( &g_mutex );
    pthread_cond_destroy( &g_cond );
    
    
    return 0;
}


