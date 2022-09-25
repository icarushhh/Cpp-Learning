//
//  main.cpp
//  test_string
//
//  Created by 朱仕哲 on 2022/9/22.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string astring(10, 'a');                // str initialize
    cout << astring << endl;
    cout << astring.length() << endl;
    
    string str1("hello world!");            // C style: str = "hello world"
    string str2(str1);                      // strcpy
    cout << str2 << endl;
    
    str2 += astring;                        // += str connection
    // == str2.append(astring);
    cout << str2 << endl;
    
    string str3 = str2 + "bbb";             // str connection
    cout << str3 << endl;
    
    cout << str3.append("cccc") << endl;
    
    cout << str2.substr(6,5) << endl;       // substring(startposition, len)
    
    // inpput
    
    char arr[10];
    cin.get(arr,10);
//    cin.get();              // 用于吃掉回车，相当于getchar(); 现在把这行注释掉试试看
    cin.ignore(1024,'\n');  // 用于吃掉回车。第一个参数是忽略字符个数，第二个参数是读到后停止
    cout<<arr<<endl;
    
    string arr_str(arr);                // 可以用char[]来初始化string
    
    cin.getline(arr,5);                 // 不需要吃掉回车
    
    cout<<arr<<endl;
    
    return 0;
}
