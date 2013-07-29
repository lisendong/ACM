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
    int need;
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
        while (l.size() > 0) {
            list<node>::iterator it = l.begin();
            list<node>::iterator next = l.begin();
            next++;
            for (; next != l.end(); it++, next++) {
                if (it->need < 0 && next->need > 0) {
                    int trade = min(-it->need, next->need);
                    it->need += trade;
                    next->need -= trade;
                    sum += trade * (next->pos - it->pos);
                }
                else if (it -> need > 0 && next ->need < 0) {
                    int trade = min(it->need, -next->need);
                    it->need -= trade;
                    next->need += trade;
                    sum += trade * (next->pos - it->pos);
                }
            }
            for (list<node>::iterator it = l.begin(); it != l.end();) {
                //cout << it->need << endl;
                if (it->need == 0) it = l.erase(it);
                else it++;
            }
        }
        cout << sum << endl;
    }
}



