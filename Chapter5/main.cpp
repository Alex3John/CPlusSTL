#include <iostream>
#include <queue>
#include <functional>
#include <iterator>
#include <vector>
#include <algorithm>
#include <bitset>
#include "LinearCounting.h"
#include <fstream>
#include <cstring>
using namespace std;

template <class T>
void Display_Queue(priority_queue<T>& Q)
{
    vector<T> vt;
    cout << "堆中目前有: " << Q.size() << "个元素." << endl;
    while(Q.size())
    {
        T top = Q.top();
        vt.push_back(top);
        Q.pop();
    }
    ostream_iterator<T> oiter(std::cout, " ");
    copy(vt.begin(), vt.end(), oiter);

}

template <typename T>
void Display_Vector(vector<T>& vt)
{
    ostream_iterator<T> oiter(std::cout, " ");
    copy(vt.begin(), vt.end(), oiter);
    cout << endl;
}

template <typename T>
void init(priority_queue<T>& Q)
{
    //  23, 5, 66, 12, 34
    vector<int> vt = {23, 5, 66, 12, 34};
    /*
    for(auto x: vt)
    {
        Q.push(x);
    }
    */
    priority_queue<T> Q_new(vt.begin(), vt.end());
    Q = Q_new;
}
/*
   Test1(): 测试prior_queue的成员api
   Test2(): 模拟prior_queue
         make_heap--->初始化堆
         push_heap--->插入元素后调整堆
         pop_heap--->删除元素后调整堆
    Test3(): 测试bitset的初始化
    Test4(): 访问bitset的位元素
    Test5(): 测试bitset的位运算
    Test6(): 测试LinearCounting算法
*/

void Test1()
{
    priority_queue<int> que;
    init<int>(que);
    Display_Queue<int>(que);
}

void Test2()
{
    vector<int> vt = {23, 5, 66, 12, 34};
    make_heap(vt.begin(), vt.end());
    Display_Vector<int>(vt);

    vt.push_back(8);
    push_heap(vt.begin(), vt.end());
    Display_Vector<int>(vt);

    cout << "删除堆的过程: " << endl;
    for(int i=0; i<vt.size(); i++)
    {
        pop_heap(vt.begin(), vt.end() - i);
        Display_Vector(vt);
    }
}

void Test3()
{
    bitset<2> b0;
    cout << "b0<2>: " << b0 << endl;   // 00
    bitset<6> b1(11);
    cout << "b1<6>: " << b1 << endl;  // 001011
    bitset<3> b2(11);
    cout << "b2<3>: " << b2 << endl; // 011
    bitset<7> b3("1001001");
    cout << "b3<7>: " << b3 << endl; // 1001001
    string s1("10011");
    bitset<5> b4(s1);
    cout << "b4<5>: " << b4 << endl; // 10011
    string s2("1110011011");
    bitset<7> b5(s2, 5, 4);
    cout << "b5<7>: " << b5 << endl; // 0001101
    bitset<5> b6(s2, 5);
    cout << "b6<5>: " << b6 << endl; // 11011
    cout << "b0<2>的大小是: " <<sizeof(b0) << endl;
}

void Test4()
{
    bitset<6> b0("101110");
    cout << "b0<6>的size: " << b0.size() << endl;
    cout << "b0中1元素的个数: " << b0.count() << endl;
    cout << "设置b0<6>的第1号元素为1: " << endl;
    b0[1] = true;
    cout << "b0<6>: " << b0 << endl;
    cout << "设置b0<6>的第1号元素为0: " << endl;
    b0.set(1, false);
    cout << "b0<6>: " << b0 << endl;
    cout << "调用to_string得到字符串类型数据: " << endl;
    cout << b0.to_string() << endl;
    cout << "设置为全1bit串: " << endl;
    b0.set();
    cout << "b0<6>: " << b0 << endl;
}

void Test5()
{
    bitset<5> b0("11001");
    bitset<5> b1("01110");
    cout << "b0 & b1 = \n";
    cout << (b0 & b1) << endl;
    cout << "b0 | b1 = \n";
    cout << (b0 | b1) << endl;
    cout << "b0 ^ b1 = \n";
    cout << (b0 ^ b1) << endl;
    cout << "b0<<=1" << endl;
    b0 <<=1;
    cout << b0 << endl;
    cout << "b1>>=1\n";
    b1 >>=1;
    cout << b1 << endl;
}

void Test6()
{
    string ipsrc;
    ifstream in;
    in.open("F:\\001.txt");
    #define key_len 24
    #define mem_in_bytes 1024
    LinearCounting<mem_in_bytes, key_len>* lc = new LinearCounting<mem_in_bytes, key_len>();
    while(in)
    {
        uint8_t key[key_len] = {0};
        in >> ipsrc;
        memcpy(key, ipsrc.c_str(), ipsrc.size());
        lc->insert(key);
    }
    int cardinality = lc->get_cardinality();
    cout << cardinality << endl;
    in.close();
}
int main()
{
    Test6();
    return  0 ;
}
