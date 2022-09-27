//
//  find_test.cpp
//  algorithm_test
//
//  Created by 朱仕哲 on 2022/9/28.
//

#include "find_test.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;


class vector_print: public unary_function<int, void>{
public:
    void operator()(int val){
        cout << val << " ";
        return;
    }
};

class vector_duplicate: public binary_function<int, vector<int>&, void>{
public:
    void operator()(int val, vector<int>& v){
        v.push_back(val);
        return;
    }
};


int find_test01(){
    vector<int> v;
    
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        v.push_back(rand()%10);
    }
    
    
    cout << "vector initialized" << endl;
    
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), vector_print());
    cout << endl;
    
    
    
    vector<int>::iterator it =  find(v.begin(), v.end(), 5);
    
    it = find_if(v.begin(), v.end(), bind(less<int>(), placeholders::_1, 5));
    cout << *(it+1) << endl;
    
    it = adjacent_find(v.begin(), v.end(), bind(equal_to<int>(), placeholders::_1, 5));
    cout << *(it+1) << endl;
    
    int n = count(v.begin(), v.end(), 5);
    cout << n << endl;
    cout << *(it+n-1) << " " << *(it+n) << endl;
    
    n = count_if(v.begin(), v.end(), bind(less<int>(), placeholders::_1, 5));
    cout << n << endl;

    return 0;
}
