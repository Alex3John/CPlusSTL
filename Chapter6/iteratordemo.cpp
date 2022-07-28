#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>
using namespace std;
template <typename T>
void ShowDeque(deque<T>& dq)
{
    auto iter = dq.begin();
    for(;iter!=dq.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

template <typename T2>
void ShowVector(vector<T2>& vt)
{
    auto iter = vt.begin();
    for(; iter!=vt.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}
/*
²âÊÔ²åÈëµü´úÆ÷
    Test1(): ²âÊÔfront_insert_iterator
    Test2(): ²âÊÔback_insert_iterator
    Test3(): ²âÊÔinsert_iterator
²âÊÔÁ÷µü´úÆ÷
    Test4(): ²âÊÔistream_iterator
    Test5(): ²âÊÔostream_iterator
²âÊÔÒÆ¶¯µü´úÆ÷
    Test6(): ²âÊÔmake_move_iterator
*/
void Test1()
{
    deque<int> dq1,dq2;
    for(int i=1; i<=3; i++)
    {
        dq1.push_back(i);
        dq2.push_back(i*10);
    }
    front_insert_iterator<deque<int>> front_it(dq1);
    copy(dq2.begin(), dq2.end(), front_it);
    ShowDeque(dq1);
}

void Test2()
{
    deque<int> dq1, dq2;
    for(int i=1; i<=3; i++)
    {
        dq1.push_back(i);
        dq2.push_back(i*10);
    }
    back_insert_iterator<deque<int>> back_it(dq1);
    copy(dq2.begin(), dq2.end(), back_it);
    ShowDeque(dq1);
}

void Test3()
{
    deque<int> dq1,dq2;
    for(int i=1; i<=3; i++)
    {
        dq1.push_back(i);
        dq2.push_back(i*10);
    }
    auto iter = dq1.begin();
    advance(iter, 2);  // µü´úÆ÷ÒÆ¶¯º¯Êý, iter = iter + 2;
    insert_iterator<deque<int>> insert_it(dq1, iter);
    copy(dq2.begin(), dq2.end(), insert_it);
    ShowDeque(dq1);
}

void Test4()
{
    vector<double> v;
    istream_iterator<double> eos;
    istream_iterator<double> iter(std::cin);
    for(int i=0; i<5; i++)
    {
        if(iter!=eos)
        {
            v.push_back(*(++iter));
        }
    }
    cout << "Î´ÅÅÐòÇ°: " << endl;
    ShowVector(v);
    cout << "ÅÅÐòÖ®ºó: " << endl;
    sort(v.begin(), v.end());
    ShowVector(v);
}

void Test5()
{
    vector<int> vt;
    for(int i=0; i<5; i++)
    {
        vt.push_back(i*5);
    }
    ostream_iterator<int> iter(std::cout, ",");
    copy(vt.begin(), vt.end() - 1, iter);
    cout << *(vt.end() - 1) << endl;
}

void Test6()
{
    vector<string> v1(3);
    vector<string> v2 = {"zhw", "dyl", "lzz"};
    copy(make_move_iterator(v2.begin()), make_move_iterator(v2.end()), v1.begin());

    ShowVector<string>(v1);
}
int main()
{
    Test6();
    return 0;
}
