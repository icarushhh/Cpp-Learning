//
//  main.cpp
//  new_delete
//
//  Created by 朱仕哲 on 2022/9/25.
//
//  实现了一个链表

#include<iostream>
using namespace std;

struct node
{
    //链表的节点
    int data;//数据
    int num;//节点编号
    struct node *next;//指向下一个节点
};

int main()
{
    struct node *head/*头节点*/, *p, *q;
    head = NULL;
    p = NULL;
    q = new node;
    q->next = NULL;
    q->num = 1;
    int a = -1;
    cout << "请输入第1个数字:";
    cin >> a;
    q->data = a;
    head = q;
    while (a != 0)
    {
        p = q;
        q = new node;
        q->next = NULL;
        p->next = q;
        q->num = p->num + 1;
        cout << "请输入第" << q->num << "个数字:";
        cin >> a;
        q->data = a;
    }

    //前面都是输入,这以下都是输出

    q = head;
    p = NULL;
    while (1)
    {
        printf("%d %d\n", q->num, q->data);
        if (q->data == 0)
            break;
        q = q->next;
    }

    //释放内存

    q = head;
    p = q;
    while (1)
    {
        p = q->next;
        delete[]q;
        q = p;
        if (!q)
            break;
    }
    return 0;
}
