//
//  main.cpp
//  pthread_test
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include <iostream>
#include "pthread_helloworld.hpp"
#include "pthread_args.hpp"
#include "pthread_more_args.hpp"
#include "pthread_join.hpp"

int main() {
    
//    pthread_hello();
//    pthread_args_test();
//    pthread_more_args_test();
    pthread_join_test();
    

    return 0;
}
