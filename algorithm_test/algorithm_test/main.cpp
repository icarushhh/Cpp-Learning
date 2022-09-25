//
//  main.cpp
//  algorithm_test
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

// compare function; using for decending sort
extern bool cmp(int a, int b){
    return a>b;
}

// class SEQ defination
class SEQ{
public:
    
    SEQ(void){
        for (int i = 0; i < 10; i++) {
            num[i] = 10 - i;
        }
        
        std::random_device rd;
        std::shuffle(num, num+10, rd);              // 将容器中数据随机打乱
    }
    
    void acending_sort(){
        sort(num, num+10);
        return;
    }
    
    void decending_sort(){
        sort(num, num+10, cmp);
        return;
    }
        
    
    void reverse(){
        std::reverse(num, num+10);
        return;
    }
    
    friend ostream& operator<<(ostream &output, SEQ seq);
    
private:
    int num[10];
};


// operate << overload
ostream& operator<<(ostream &output, SEQ seq){
    for (int i = 0; i < 10; i++) {
        output << seq.num[i] << ' ';
    }
    output << endl;
    
    return output;
}


int main() {
    SEQ seq;
    cout << "原数组：" << endl;
    cout << seq;
    
    seq.acending_sort();
    cout << "升序排序后：" << endl;
    cout << seq;
    
    seq.decending_sort();
    cout << "降序排序后：" << endl;
    cout << seq;
    
    seq.reverse();
    cout << "倒序后：" << endl;
    cout << seq;

    
    return 0;
}
