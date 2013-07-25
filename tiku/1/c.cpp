
/*
ID: lisendo1
PROG: rockers
LANG: C++
 */
#include<iostream>
#include<fstream>
#include<algorithm>
#include<assert.h>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
#define MAXN 25
using namespace std;
deque<int> a, b;
stack<int> c;
int N, M;
int result_num = 0;
deque<int> result[50000];
int cmp(deque<int> a, deque<int> b) {
    deque<int>::iterator ita = a.begin();
    deque<int>::iterator itb = b.begin();
    for (; ita != a.end(), itb != b.end(); ita++, itb++) {
        if (*ita < *itb) return 1;
        if (*ita > *itb) return 0;
    }
}
void add_result(deque<int> result_try) {
    int i;
    for (i = 0; i < result_num; i++) {
        if (result[i] == result_try) return;
        if (cmp(result_try, result[i]) < 0) break;
    }
    int k;
    for(k = result_num - 1; k >= i; k--) {
        result[k+1] = result[k];
    }
    result[i] = result_try;
    result_num++;
    cout << result_num << endl;
}
void dfs(int last_way) {
    if (b.size() == N) {
        //add_result(b);
        result[result_num++] = b;
    }
    if (!a.empty()) {
        //a -> b
        int a_from = a.front();
        a.pop_front();
        b.push_back(a_from);
        dfs(2);
        b.pop_back();
        a.push_front(a_from);
    }
    if (!a.empty() && c.size() < M) {
        //a->c
        int a_from = a.front();
        a.pop_front();
        c.push(a_from);
        dfs(1);
        c.pop();
        a.push_front(a_from);
    }
    if (last_way != 2 && last_way != 4 && !b.empty() && c.size() < M) {
        //b -> c
        int b_from = b.back();
        b.pop_back();
        c.push(b_from);
        dfs(3);
        c.pop();
        b.push_back(b_from);
    }
    if (last_way != 1 && last_way != 3 && !c.empty()) {
        // c-> b
        int c_from = c.top();
        c.pop();
        b.push_back(c_from);
        dfs(4);
        b.pop_back();
        c.push(c_from);
    }
}
void output(deque<int> s) {
    while (!s.empty()) {
        cout << s.front();
        s.pop_front();
    }
}
int main()
{
    cin >> N >> M;
    int i;
    for (i = 1; i <= N; i++) {
        a.push_back(i);
    }
    dfs(0);
    sort(result, result + result_num, cmp);
    for (i = 0; i < result_num; i++) {
        output(result[i]);
        cout << endl;
    }
    cout << result_num << endl;
}


