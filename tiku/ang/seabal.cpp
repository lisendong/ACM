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
#define MAXN 100010
#define typev int
using namespace std;
typev ar[MAXN];
int lowb(int t) { return t&(-t); }
void add(int i, typev v) {
    for ( ; i < MAXN; ar[i] += v, i+= lowb(i));
}
typev sum(int i) {
    typev s = 0;
    for (; i > 0; s += ar[i], i-= lowb(i));
    return s;
}
struct _box {
    list<int> r_section;
    int rest;
};
_box box[MAXN];
struct _section{
    //bool *isempty;
    int rest;
};
_section section[MAXN];
int main()
{
    int n, m;
    int left, right;
    while (EOF != scanf("%d%d", &n, &m)) {
        int i, j;
        memset(ar, 0, sizeof(ar));
        for (i = 1; i <= n; i++) {
            scanf("%d", &(box[i].rest));
            box[i].r_section.clear();
            //add(i, box[i].rest);
        }
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &left, &right);
            section[i].rest = right - left + 1;
            //section[i].isempty = (bool*)malloc(sizeof(bool)*(right-left+1));
            //int j;
            //for (j = 0; j < (right-left+1); j++) {
            //    section[i].isempty[j] = false;
            //}
            for (j = left; j <= right; j++) {
                box[j].r_section.push_back(i);
            }
        }
        int ans = 0;
        int newadd = 0;
        int K;
        int k;
        int x, y;
        int section_num;
        scanf("%d", &K);
        for (k = 1; k <= K; k++) {
            scanf("%d", &x);
            y = x + ans;
            if (box[y].rest <= 0) continue;
            box[y].rest--;
            //add(y, -1);
            newadd = 0;
            if (box[y].rest == 0) {//弄空了。。 
                for (list<int>::iterator j = box[y].r_section.begin(); j != box[y].r_section.end();) {
                    section_num = (int)(*j);
                    section[section_num].rest--;
                    if (section[section_num].rest == 0) {
                        newadd++;
                        j = box[y].r_section.erase(j);   
                    }
                    else j++;
                }
            }
            ans += newadd;
            printf("%d\n", ans);
        }
    }
}



