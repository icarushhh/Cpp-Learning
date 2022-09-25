//
//  main.cpp
//  fstream_test
//
//  Created by 朱仕哲 on 2022/9/25.
//

#include <iostream>
#include <fstream>
using namespace std;

//向文件内部写入数据，并将数据读出
void file_wr(void)
{
    char data[100];
    //向文件写入数据
    ofstream outfile;
    outfile.open("/Users/icarus/Library/Mobile Documents/com~apple~CloudDocs/2022秋季学期/C++/TEST/fstream_test/fstream_test/test.txt", ios::out | ios::trunc);
    cout << "Write to the file" << endl;
    cout << "Enter your name:" << endl;
    cin.getline(data, 100);
    outfile << data << endl;
    cout << "Enter your age:" << endl;
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();
    //从文件读取数据
    ifstream infile;
    infile.open("/Users/icarus/Library/Mobile Documents/com~apple~CloudDocs/2022秋季学期/C++/TEST/fstream_test/fstream_test/test.txt", ios::in);
    cout << "Read from the file" << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile.close();
}


//将数据从一文件复制到另一文件中
void file_copy(void)
{
    char data[100];
    ifstream infile;
    ofstream outfile;
    infile.open("/Users/icarus/Library/Mobile Documents/com~apple~CloudDocs/2022秋季学期/C++/TEST/fstream_test/fstream_test/test.txt", ios::in);
    outfile.open("/Users/icarus/Library/Mobile Documents/com~apple~CloudDocs/2022秋季学期/C++/TEST/fstream_test/fstream_test/test_1.txt", ios::trunc);
    cout << "copy from test.txt to test_1.txt" << endl;
    
    // 文件读完时，eof_bit还没有被置为1；直到读不出来了才置为1
    // infile.eof() 返回eof_bit
//    infile >> data;
//    while (!infile.eof())
//    {
//        cout << data << endl;
//        outfile << data << endl;
//        infile >> data;
//    }
    
    // 或者这样
    while (infile >> data) {
        cout << data << endl;
        outfile << data;
    }
    
    infile.close();
    outfile.close();
}

//测试上述读写文件，与文件数据复制
int main(void)
{
    system("pwd\n");            // test.txt 文件位置
    file_wr();
    file_copy();
    
    return 0;
}
