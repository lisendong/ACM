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
#include<map>
#include<deque>
#include<list>
#include<vector>
#define oo 0x7FFFFFF
#define MAXN 25
typedef unsigned long long ull;
using namespace std;
const unsigned long long B = 100000007;
vector<int> wl;
//map<string, int> m;
struct str{
    char s[5010];
    unsigned long long hash;
    unsigned long long count;
};
struct hashnode {
    //int str_len;
    vector<str> vs;
};
hashnode hn[5010];
//vector<string> word;
int result[5010][2];
ull gethash(char a[], int N) {
    ull ah = 0;
    for (int i = 0; i < N; i++) ah = ah * B + a[i];
    return ah;
}
int main()
{
    int num_words;
    scanf("%d", &num_words);
    int i, j;
    char a[5010];
    for (i = 0; i < num_words; i++) {
        scanf("%s", a);
        str tmps;
        int len = strlen(a);
        tmps.hash = gethash(a, len);
        tmps.count = 0;
        strcpy(tmps.s, a);
        int found = 0;
        for (j = 0; j < hn[len].vs.size(); j++) {
            if(hn[len].vs[j].hash = tmps.hash) {found = 1; break;}
        }
        if (found == 0) {
            hn[len].vs.push_back(tmps);
            result[i][0] = len;//长度
            result[i][1] = hn[len].vs.size()-1;//编号
        }
        else {
            result[i][0] = len;
            result[i][1] = j;
        }
        if (find(wl.begin(), wl.end(), len) == wl.end()) {
            wl.push_back(len);
        }
    }
    int num_str;
    scanf("%d", &num_str);
    char b[50010];
    for (i = 0; i < num_str; i++) {
        scanf("%s", b);
        int bl = strlen(b);
        for (int jk = 0; jk < wl.size(); jk++) {
            j = wl[jk];
            if (hn[j].vs.size() == 0) continue;
            ull t = 1;
            for (int k = 0; k < j; k++) t *= B;
            ull bh = 0;
            bh = gethash(b, j);
            for (int l = 0; l + j <= bl; l++) {
                for (int m = 0; m < hn[j].vs.size(); m++) {
                    if (bh == hn[j].vs[m].hash) {hn[j].vs[m].count++;}
                }
                if (l + j < bl) bh = bh * B + b[l + j] - b[l] * t;
            }
        }
    }
    for (i = 0; i < num_words; i++) {
        printf("%lld\n", hn[result[i][0]].vs[result[i][1]].count);
    }
}



