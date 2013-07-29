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
int n;
struct node {
    long long  need;
    int pos;
};
list<node> l;
int main()
{
    while (cin >> n) {
        if (n == 0) break;
        int i;
        l.clear();
        for (i = 1; i <= n; i++) {
            node * tmp = new node;
            cin >> tmp->need;
            tmp->pos = i;
            l.push_back(*tmp);
        }
        unsigned long long sum = 0;
        list<node>::iterator it = l.begin();
        list<node>::iterator next = l.begin();
        next++;
        for (; next != l.end(); it++, next++) {
                sum += abs(it->need);
                next->need += it->need;
        }
        cout << sum << endl;
    }
}



