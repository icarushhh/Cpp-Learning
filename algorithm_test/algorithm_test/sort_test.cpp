//
//  main.cpp
//  algorithm_test
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <functional>
#include <cstdlib>
#include <ctime>

using namespace std;


// compare function; using for decending sort
extern bool cmp(int a, int b){
    return a>b;
}

class cmp2{
public:
    bool operator()(int a, int b){
        return a>b;
    }
};

// class SEQ defination
class SEQ{
public:
    
    SEQ(void){
    
        for (int i = 0; i < 10; i++) {
            num.push_back(rand()%20);
        }
        
        it = num.begin();
        
        random_device rd;
        shuffle(it, it+10, rd);              // 将容器中数据随机打乱
        
    }
    
    void acending_sort(){
        sort(it, it+10);
        return;
    }
    
    void decending_sort(){
//        两种方式等价，一种用比较函数，一种用仿函数类
//        第二种直接调用<functional>中的函数模版作为cmp
//        sort(it, it+10, cmp2());
        sort(it, it+10, greater<int>());
//        sort(it, it+10, cmp);
        return;
    }
        
    
    void reverse(){
        ::reverse(it, it+10);
        return;
    }
    
    SEQ operator+(SEQ another_seq){
        SEQ sum;
        sum.num.resize(this->num.size() + another_seq.num.size());
        merge(this->num.begin(), this->num.end(), another_seq.num.begin(), another_seq.num.end(), sum.num.begin(),
              less<int>());
        return sum;
    }
    
    friend ostream& operator<<(ostream &output, SEQ seq);
    
private:
    vector<int> num;
    vector<int>::iterator it;
};


// operate << overload
ostream& operator<<(ostream &output, SEQ seq){
    for (vector<int>::iterator it = seq.num.begin(); it < seq.num.end(); it++) {
        output << *it << ' ';
    }
    output << endl;
    
    return output;
}


int sort_test() {
    
    srand(time(NULL));
    
    SEQ seq;
    SEQ seq2;
    
    
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
    
    seq2.acending_sort();
    cout << "seq2 升序排序： " << endl;
    cout << seq2;
    
    cout << "after merge: " << endl;
    cout << (seq + seq2);
   
    
    return 0;
}
